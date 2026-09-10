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

        pid_t result = waitpid(p, &status, 0);

        printf("Parent: child finished\n");
        printf("waitpid() returned: %d\n", result);
    }

    return 0;
}
//Question 6: Waitpid() returns 31741. This is the process Id of the child process 
//that has finished executing. Its similar to wait but waitpid allows you to e specifically wait 
//for a particular child process to finish.

//Child: running
//Child: finished
//Parent: child finished
//waitpid() returned: 35819