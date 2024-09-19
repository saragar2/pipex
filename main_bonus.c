#include "pipex.h"

void print_error(char *arg)
{
    perror(arg);
    exit(1);
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
    g.pid[0] = fork();
    if (g.pid[0] == 0)
        cpid1(g, argv, envp);
    close(g.pipefd[1]);
    g.prev_pipefd[0] = g.pipefd[0];
    for (int i = 3; i < argc - 2; i++) {
        if (pipe(g.pipefd) == -1)
            print_error("Error creating the pipe");
        g.pid[1] = fork();
        if (g.pid[1] == 0)
            cpidmid(g, argv, i, envp);
        close(g.prev_pipefd[0]);
        close(g.pipefd[1]);
        g.prev_pipefd[0] = g.pipefd[0];
    }
    g.pid[2] = fork();
    if (g.pid[2] == 0)
        cpid2(g, argc, argv, envp);
    close(g.prev_pipefd[0]);
    while (waitpid(-1, &status, 0) > 0)
        ;
    return (WEXITSTATUS(status));
}



