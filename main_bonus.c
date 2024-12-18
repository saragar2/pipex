/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:07:21 by saragar2          #+#    #+#             */
/*   Updated: 2024/12/18 15:44:07 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *arg)
{
	perror(arg);
	exit(1);
}

void	for_mid(int argc, char **argv, t_pp *g, char **envp)
{
	int	i;

	i = 3;
	if (g->hd_flag == 1)
		i++;
	while (i < (argc - 2))
	{
		if (pipe(g->pipefd) == -1)
			print_error("Error creating the pipe");
		g->pid[1] = fork();
		if (g->pid[1] == 0)
			cpidmid(*g, argv, i, envp);
		close(g->prev_pipefd[0]);
		close(g->pipefd[1]);
		g->prev_pipefd[0] = g->pipefd[0];
		i++;
	}
}

void	hdoc(t_pp *g, char *kword)
{
	char	*kword_sn;
	char	*line;

	g->hd_fd = open(".here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (g->hd_fd < 1)
		print_error("Error while opening here_doc");
	kword_sn = ft_strjoin(kword, "\n");
	while (1)
	{
		write(1, "here_doc>", 9);
		line = get_next_line(0);
		if (!line || !f_strcmp(line, kword_sn))
			break ;
		write(g->hd_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(g->hd_fd);
	g->fd_in = open(".here_doc", O_RDONLY);
	if (g->fd_in < 0)
		print_error("Error opening .here_doc file");
	g->hd_flag = 1;
}

void	error_handle(int argc, char **argv, char **envp)
{
	if (!*envp)
		print_error("no envp detected");
	if (argc < 5 || (!f_strcmp(argv[1], "here_doc") && argc < 6))
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
	g.hd_flag = 0;
	error_handle(argc, argv, envp);
	if (!f_strcmp(argv[1], "here_doc"))
		hdoc(&g, argv[2]);
	if (pipe(g.pipefd) == -1)
		print_error("Error creating the pipe");
	g.pid[0] = fork();
	if (g.pid[0] == 0)
		cpid1(g, argv, envp);
	close(g.pipefd[1]);
	g.prev_pipefd[0] = g.pipefd[0];
	for_mid(argc, argv, &g, envp);
	g.pid[2] = fork();
	if (g.pid[2] == 0)
		cpid2(g, argc, argv, envp);
	close(g.prev_pipefd[0]);
	while (waitpid(-1, &status, 0) > 0)
		;
	if (g.hd_flag)
		unlink(".here_doc");
	return (WEXITSTATUS(status));
}
