#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];

    pipe(pipefd);

    pid_t p1 = fork();

    if (p1 == 0) {
        // First child: writes to the pipe
        close(pipefd[0]);              // Close read end
        dup2(pipefd[1], STDOUT_FILENO); // stdout -> pipe
        close(pipefd[1]);

        printf("Hello from child 1!\n");
        return 0;
    }

    pid_t p2 = fork();

    if (p2 == 0) {
        // Second child: reads from the pipe
        close(pipefd[1]);             // Close write end
        dup2(pipefd[0], STDIN_FILENO); // stdin -> pipe
        close(pipefd[0]);

        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);
        printf("Child 2 received: %s", buffer);

        return 0;
    }

    // Parent
    close(pipefd[0]);
    close(pipefd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
//Question 8:The result shows that child 2 was able to read the message sent by child 1
// the pipe allows for inter-process communication between the two child processes.
// Result : Child 2 received: Hello from child 1!