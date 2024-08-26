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

void print_error(char *arg)
{
    perror(arg);
    exit(1);
}

int main(int argc, char **argv, char **envp)
{
	t_pp g;

	printf("%s\n", *argv);
	exit(0);
	if (argc != 5)
		print_error("invalid amount of argument");
	if (pipe(g.pipefd) == -1)
		print_error("Error creating the pipe");
	if (g.pid[0] == 0)
		cpid1(g, argv, envp);
	else if (g.pid[0] < 0)
		print_error("Error creating pid1");
	g.pid[1] = fork();
	if (g.pid[1] == 0)
		cpid2(g, argv, envp);
	else if (g.pid[1] < 0)
		print_error("Error creating pid2");
}

// int	main(int argc, char **argv, char **envp)
// {
// 	if(argc == 1)
// 	{
// 		printf("%s\n\n", *argv);
// 		while (envp)
// 		{
// 			printf("%s", *envp);
// 			(envp)++;
// 		}
// 		check_com("hola", envp);
// 	}
// 	return (0);
// }
