#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "process.h"

int execute(char **tokens)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        execvp(tokens[0], tokens);

        perror("execvp");
        exit(1);
    }

    waitpid(pid, NULL, 0);

    return 0;
}
