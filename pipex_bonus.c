#include "pipex.h"

char	*check_com(char *com, char **envp)
{
	int		i;
	int		j;
	char	**routes;
	char	*new_com;

	i = 0;
	j = -1;
	if (ft_strchr(com, '/'))
		return (com);
	while(envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if(envp[i] == 0)
		return (com);
	envp[i] += 5;
	routes = ft_split(envp[i], ':');
	while (routes[++j])
	{
		new_com = ft_strjoin(routes[j], "/");
		new_com = ft_strjoin(new_com, com);
		if (access(new_com, X_OK) == 0)
			return (new_com);
	}
	return(com);
}

void	cpid1(t_pp g, char **argv, char **envp)
{
	while (argv[2] && ((*argv[2] >= 9 && *argv[2] < 13) || *argv[2] == 32))
		argv[2]++;
	if (*argv[2] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[2], ' ');
	g.exec = check_com(g.com[0], envp);
	g.fd_in = open(argv[1], O_RDONLY);
	if (g.fd_in < 0)
		print_error("error opening fd_in");
	dup2(g.pipefd[1], STDOUT_FILENO);
	dup2(g.fd_in, STDIN_FILENO);
	close(g.pipefd[0]);
	close(g.pipefd[1]);
	close(g.fd_in);
	execve(g.exec, g.com, envp);
	print_error("error executing first command");

}

void	cpidmid(t_pp g, char **argv, char **envp)
{
	while (argv[g.curr_arg] && ((*argv[g.curr_arg] >= 9 && *argv[g.curr_arg] <= 13) || *argv[g.curr_arg] == 32))
        argv[g.curr_arg]++;
    if (*argv[g.curr_arg] == '\0')
        print_error("Empty argument");
    g.com = ft_split(argv[g.curr_arg], ' ');
    g.exec = check_com(g.com[0], envp);
    // Proceso intermedio: leemos del pipe anterior y escribimos en el nuevo pipe.
    dup2(g.pipefd[0], STDIN_FILENO);  // Leemos desde el pipe anterior
    dup2(g.pipefd[1], STDOUT_FILENO); // Escribimos al pipe siguiente
    close(g.pipefd[0]);
    close(g.pipefd[1]);
    execve(g.exec, g.com, envp);
    print_error("Error executing intermediate command");
}

void	cpid2(t_pp g, int argc, char **argv, char **envp)
{
	while (argv[argc - 2] && ((*argv[argc - 2] >= 9 && *argv[argc - 2] <= 13) || *argv[argc - 2] == 32))
		argv[argc - 2]++;
	if (*argv[argc - 2] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[argc - 2], ' ');
	g.exec = check_com(g.com[0], envp);
	g.fd_out = open(argv[argc - 1],  O_WRONLY | O_CREAT, 0644);
	if (g.fd_out < 0)
		print_error("error opening or creating fd_out");
	dup2(g.pipefd[0], STDIN_FILENO);
	dup2(g.fd_out, STDOUT_FILENO);
	close(g.pipefd[0]);
	close(g.pipefd[1]);
	close(g.fd_out);
	execve(g.exec, g.com, envp);
	print_error("error executing second command");
}
