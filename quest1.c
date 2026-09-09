#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample() {
    int x = 1;
    pid_t p = fork();

    if (p < 0) {
        perror("Fork failed");
        exit(1);
    } else if (p == 0) {
        // Child process
        x += 99;
        printf("Child Process: x = %d\n", x);
    } else {
        // Parent process
        printf("Parent Process: x = %d\n", x);
    }
}

int main(void) {
    forkexample();
    return 0;
}


//Ku Htoo
//Question: The value of the parent process is 1 and the child process is 100. This is because when the fork() function is called, 
//it creates a new process (the child) that is a copy of the parent process. The variable x is initialized to 1 in both processes. 
//In the child process, x is incremented by 99, resulting in a value of 100. In the parent process, x remains unchanged at 1.