#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

extern char **environ;

int main() {
    pid_t p = fork();

    if (p < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (p == 0) {
        // Child process
        printf("Child: running /bin/ls\n");

        execvpe("ls", args, environ);

        // Only reached if exec() fails
        perror("exec failed");
        return 1;
    }
    else {
        // Parent
        printf("Parent: child created\n");
    }

    return 0;
}// Question 4:There are so many variants because its up to the programmer
// to decide what to use. execvpe() is a variant that allows you to specify the environment for the new process, 
//which can be useful in certain situations.