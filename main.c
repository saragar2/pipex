/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:25:18 by saragar2          #+#    #+#             */
/*   Updated: 2024/06/24 17:25:23 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *arg)
{
	perror(arg);
	exit(1);
}

void	error_handle(int argc, char **argv, char **envp)
{
	if (!*envp)
		print_error("no envp detected");
	if (argc != 5)
		print_error("invalid amount of argument");
	if (open(argv[1], O_RDONLY) < 0 || open(argv[argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0644) < 0)
		print_error("invalid fd");
}

int	main(int argc, char **argv, char **envp)
{
	t_pp	g;
	int		status;

	status = 0;
	error_handle(argc, argv, envp);
	if (pipe(g.pipefd) == -1)
		print_error("Error creating the pipe");
	g.pid[0] = fork();
	if (g.pid[0] == 0)
		cpid1(g, argv, envp);
	else if (g.pid[0] < 0)
		print_error("Error creating pid1");
	g.pid[1] = fork();
	if (g.pid[1] == 0)
		cpid2(g, argc, argv, envp);
	else if (g.pid[1] < 0)
		print_error("Error creating pid2");
	close(g.pipefd[0]);
	close(g.pipefd[1]);
	waitpid(g.pid[0], NULL, 0);
	waitpid(g.pid[1], &status, 0);
	return (WEXITSTATUS(status));
}
