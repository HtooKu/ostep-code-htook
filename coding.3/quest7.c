#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t p = fork();

    if (p < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (p == 0) {
        // Child
        close(STDOUT_FILENO);

        printf("Child: Hello!\n");
    }
    else {
        // Parent
        printf("Parent: Hello!\n");
    }

    return 0;
}
//Question 7: The child calling printf will not do anything because the standard output has been closed. 
//The parent will still be able to print to the standard output because it has not closed it.
