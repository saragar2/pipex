#include "pipex.h"

void print_error(char *arg)
{
    perror(arg);
    exit(1);
}

// ERRORES: ENTRA DOS VECES AL PRINTF DE PID2 CUANDO TIENE DOS COMANDOS, Y NOSE ALGO MAS HABRA


// void	check_pid(t_pp g,int argc, char **argv, char **envp)
// {
// 	g.pid[0] = fork();
// 	if (g.pid[0] == 0)
// 		cpid1(g, argv, envp);
// 	else if (g.pid[0] < 0)
// 		print_error("Error creating pid");
// 	while ((argc--) - 5 > 0 )
// 	{
// 		g.pid[1] = fork();
// 		if (g.pid[1] == 0)
// 			cpidmid(g, argv, envp);
// 		else if (g.pid[1] < 0)
// 			print_error("Error creating pid");
// 	}
// 	g.pid[2] = fork();
// 	if (g.pid[2] == 0)
// 		{printf("si, "); cpid2(g, argc, argv, envp);}
// 	else if (g.pid[2] < 0)
// 		print_error("Error creating pid");
// }

void	check_pid(t_pp g, int argc, char **argv, char **envp)
{
	g.aux_argc = argc;
	g.pid[0] = fork();
	if (g.pid[0] == 0)
	{
		cpid1(g, argv, envp);
		exit(0);
	}
	else if (g.pid[0] < 0)
		print_error("Error creating pid");
	while ((g.aux_argc--) - 5 > 0 )
	{
		g.pid[1] = fork();
		if (g.pid[1] == 0)
		{
			cpidmid(g, argv, envp);
			exit(0);
		}
		else if (g.pid[1] < 0)
			print_error("Error creating pid");
	}
	g.pid[2] = fork();
	if (g.pid[2] == 0)
	{
		printf("si, ");
		cpid2(g, argc, argv, envp);
		exit(0);
	}
	else if (g.pid[2] < 0)
		print_error("Error creating pid");
	waitpid(g.pid[0], NULL, 0);
	while ((g.aux_argc++) - 5 > 0)
		waitpid(g.pid[1], NULL, 0);
	waitpid(g.pid[2], NULL, 0);
}



int main(int argc, char **argv, char **envp)
{
	t_pp 	g;
	int		status;

	status = 0;
	if (argc < 5)
		print_error("invalid amount of argument");
	if (pipe(g.pipefd) == -1)
		print_error("Error creating the pipe");
	check_pid(g, argc, argv, envp);
	close(g.pipefd[0]);
	close(g.pipefd[2]);
	waitpid(g.pid[0], NULL, 0);
	waitpid(g.pid[2], &status, 0);
	return (WEXITSTATUS(status));
}

