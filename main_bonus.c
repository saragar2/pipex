/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:07:21 by saragar2          #+#    #+#             */
/*   Updated: 2024/09/19 20:07:24 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *arg)
{
	perror(arg);
	exit(1);
}

void	for_mid(int argc, char **argv, t_pp g, char **envp)
{
	int	i;

	i = 3;
	while (i < (argc - 2))
	{
		if (pipe(g.pipefd) == -1)
			print_error("Error creating the pipe");
		g.pid[1] = fork();
		if (g.pid[1] == 0)
			cpidmid(g, argv, i, envp);
		close(g.prev_pipefd[0]);
		close(g.pipefd[1]);
		g.prev_pipefd[0] = g.pipefd[0];
		i++;
	}
}

void    hdoc(t_pp g, char *kword)
{
	char	*kword_sn;
	g.hp_fd = open("here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (g.hd_fd < 1)
		print_error("Error while opening here_doc");
	kword_sn = ft_strjoin(kword, '\n');
    while(1)
	{
		
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pp	g;
	int		status;

	status = 0;
	if (argc < 5)
		print_error("invalid amount of argument");
	// if (f_strcmp(argv[1], "here_doc"))
	//     hdoc(g, argv[2]);
	if (pipe(g.pipefd) == -1)
		print_error("Error creating the pipe");
	g.pid[0] = fork();
	if (g.pid[0] == 0)
		cpid1(g, argv, envp);
	close(g.pipefd[1]);
	g.prev_pipefd[0] = g.pipefd[0];
	for_mid(argc, argv, g, envp);
	g.pid[2] = fork();
	if (g.pid[2] == 0)
		cpid2(g, argc, argv, envp);
	close(g.prev_pipefd[0]);
	while (waitpid(-1, &status, 0) > 0)
		;
	return (WEXITSTATUS(status));
}
