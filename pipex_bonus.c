/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:59:45 by saragar2          #+#    #+#             */
/*   Updated: 2024/12/18 15:44:32 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*whl_routes(t_command *c, int *flag)
{
	int	i;

	i = -1;
	*flag = 0;
	while (c->routes[++i])
	{
		c->new_com = ft_strjoin(c->routes[i], "/");
		c->res = ft_strjoin(c->new_com, c->com);
		free(c->new_com);
		c->new_com = c->res;
		if (access(c->new_com, X_OK) == 0)
		{
			c->res = ft_strdup(c->new_com);
			free_split(c->routes);
			*flag = 1;
			return (c->res);
		}
		free(c->new_com);
	}
	free_split(c->routes);
	return (c->res);
}

char	*check_com(char *com, char **envp)
{
	int			i;
	t_command	c;

	c.com = com;
	i = 0;
	if (ft_strchr(c.com, '/'))
		return (c.com);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == 0)
		return (c.com);
	envp[i] += 5;
	c.routes = ft_split(envp[i], ':');
	c.res = whl_routes(&c, &i);
	if (i == 1)
		return (c.res);
	return (ft_strdup(c.com));
}

void	cpid1(t_pp g, char **argv, char **envp)
{
	int	i;

	i = 2;
	if (g.hd_flag == 1)
		i = 3;
	while (argv[i] && ((*argv[i] >= 9 && *argv[i] < 13) || *argv[i] == 32))
		argv[i]++;
	if (*argv[i] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[i], ' ');
	g.exec = check_com(g.com[0], envp);
	if (g.hd_flag == 0)
		g.fd_in = open(argv[1], O_RDONLY);
	if (g.fd_in < 0)
		print_error("error opening fd_in");
	dup2(g.fd_in, STDIN_FILENO);
	dup2(g.pipefd[1], STDOUT_FILENO);
	close(g.pipefd[0]);
	close(g.pipefd[1]);
	execve(g.exec, g.com, envp);
	free_split(g.com);
	free(g.exec);
	print_error("error executing first command");
}

void	cpidmid(t_pp g, char **argv, int i, char **envp)
{
	while (argv[i] && ((*argv[i] >= 9 && *argv[i] <= 13) || *argv[i] == 32))
		argv[i]++;
	if (*argv[i] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[i], ' ');
	g.exec = check_com(g.com[0], envp);
	dup2(g.prev_pipefd[0], STDIN_FILENO);
	dup2(g.pipefd[1], STDOUT_FILENO);
	close(g.prev_pipefd[0]);
	close(g.pipefd[0]);
	close(g.pipefd[1]);
	execve(g.exec, g.com, envp);
	free_split(g.com);
	free(g.exec);
	print_error("Error executing intermediate command");
}

void	cpid2(t_pp g, int argc, char **argv, char **envp)
{
	int	i;

	i = argc - 2;
	while (argv[i] && ((*argv[i] >= 9 && *argv[i] <= 13) || *argv[i] == 32))
		argv[i]++;
	if (*argv[i] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[i], ' ');
	g.exec = check_com(g.com[0], envp);
	g.fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (g.fd_out < 0)
		print_error("error opening or creating fd_out");
	dup2(g.prev_pipefd[0], STDIN_FILENO);
	dup2(g.fd_out, STDOUT_FILENO);
	close(g.pipefd[0]);
	close(g.fd_out);
	execve(g.exec, g.com, envp);
	free_split(g.com);
	free(g.exec);
	print_error("error executing second command");
}
