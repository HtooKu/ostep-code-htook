#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p = fork();

    if (p < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (p == 0) {
        // Child
        printf("Child: running\n");
        sleep(2);
        printf("Child: finished\n");
    }
    else {
        // Parent
        int status;
        pid_t result = wait(&status);

        printf("Parent: child finished\n");
        printf("wait() returned: %d\n", result);
    }

    return 0;
}
//Question 5: Wait() returns 31741. This is the 
// PID of the child process that has finished executing. 
//The parent process waits for the child to finish before continuing its execution.
// If you had wait() in the child and it didn't have another process than it would
//throw an error because there is no child process for the child to wait for.
//Child: finished
//Parent: child finished
//wait() returned: 31741