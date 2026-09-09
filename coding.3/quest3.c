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
        printf("hello\n");
    }
    else {
        // Parent
        sleep(1);
        printf("goodbye\n");
    }

    return 0;
}
//Question 3:This can be done without the wait()