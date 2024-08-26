#include "pipex.h"

char	*check_com(char *com, char **envp)
{
	int		i;
	int		j;
	char	**routes;
	char	*new_com;

	i = 0;
	j = 0;
	if (ft_strchr(com, '/'))
		return (com);
	while(envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if(envp[i] == 0)
		return (com);
	envp[i] += 5;
	routes = ft_split(envp[i], ':');
	while (routes[j++])
	{
		new_com = ft_strjoin(routes[i], "/");
		new_com = ft_strjoin(new_com, com);
		if (access(new_com, X_OK) == 0)
			return (new_com);
	}
	return(com);
}

void	cpid1(t_pp g, char **argv, char **envp)
{
	g.com = ft_split(argv[2], ' ');
	g.exec = check_com(g.com[0], envp);
	g.fd_in = open(argv[1], O_RDONLY);
	
}