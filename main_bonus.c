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




int main(int argc, char **argv, char **envp)
{
    t_pp 	g;
    int 	status;
    int 	pipefd[2];   // Variable temporal para la pipe
    int 	prev_pipefd[2]; // Para guardar el pipe anterior

    status = 0;
    if (argc < 5)
        print_error("invalid amount of argument");

    // Crear la primera pipe para el primer proceso
    if (pipe(pipefd) == -1)
        print_error("Error creating the pipe");

    g.pid[0] = fork();
    if (g.pid[0] == 0) {
        // Primer proceso lee desde el archivo y escribe en la pipe
        dup2(pipefd[1], STDOUT_FILENO);   // Redirigir salida a la pipe
        close(pipefd[0]);
        close(pipefd[1]);
        cpid1(g, argv, envp);
    }
    close(pipefd[1]);  // El padre no escribe en esta pipe
    prev_pipefd[0] = pipefd[0];  // Guardamos la lectura de la primera pipe

    // Procesos intermedios
    for (int i = 3; i < argc - 2; i++) {
        if (pipe(pipefd) == -1)
            print_error("Error creating the pipe");

        g.pid[1] = fork();
        if (g.pid[1] == 0) {
            // Leer desde la pipe anterior y escribir en la nueva pipe
            dup2(prev_pipefd[0], STDIN_FILENO);   // Leer de la pipe anterior
            dup2(pipefd[1], STDOUT_FILENO);       // Escribir en la nueva pipe
            close(prev_pipefd[0]);
            close(pipefd[0]);
            close(pipefd[1]);
            cpidmid(g, argv, i, envp);
        }
        close(prev_pipefd[0]);   // Cerramos el lado de lectura anterior
        close(pipefd[1]);        // El padre no escribe en esta nueva pipe
        prev_pipefd[0] = pipefd[0];  // Actualizamos la pipe anterior
    }

    // Último proceso
    g.pid[2] = fork();
    if (g.pid[2] == 0) {
        // Leer desde la pipe anterior y escribir en el archivo
        dup2(prev_pipefd[0], STDIN_FILENO);  // Leer de la última pipe
        close(prev_pipefd[0]);
        cpid2(g, argc, argv, envp);
    }
    close(prev_pipefd[0]);  // El padre no lee en la última pipe

    // Esperar todos los procesos
    while (waitpid(-1, &status, 0) > 0)
        ;
    return (WEXITSTATUS(status));
}



