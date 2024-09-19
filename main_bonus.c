#include "pipex.h"

void print_error(char *arg)
{
    perror(arg);
    exit(1);
}

void    for_mid(int argc, char **argv, t_pp g, char **envp)
{
    int i;

    i = 3;
    while (i < (argc - 2))
    {
        if (pipe(g.pipefd) == -1)
            print_error("Error creating the pipe");
        if ((g.pid[1] = fork()) == 0)
            cpidmid(g, argv, i, envp);
        close(g.prev_pipefd[0]);
        close(g.pipefd[1]);
        g.prev_pipefd[0] = g.pipefd[0];
        i++;
    }
}

int main(int argc, char **argv, char **envp)
{
    t_pp 	g;
    int 	status;

    status = 0;
    if (argc < 5)
        print_error("invalid amount of argument");
    if (pipe(g.pipefd) == -1)
        print_error("Error creating the pipe");
    if ((g.pid[0] = fork()) == 0)
        cpid1(g, argv, envp);
    close(g.pipefd[1]);
    g.prev_pipefd[0] = g.pipefd[0];
    for_mid(argc, argv, g, envp);
    if ((g.pid[2] = fork()) == 0)
        cpid2(g, argc, argv, envp);
    close(g.prev_pipefd[0]);
    while (waitpid(-1, &status, 0) > 0)
        ;
    return (WEXITSTATUS(status));
}



