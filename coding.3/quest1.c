#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int x = 100;

    pid_t p = fork();

    if (p < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (p == 0) {
        // Child
        printf("Child: x = %d\n", x);
        x = 200;
        printf("Child after changing x: %d\n", x);
    }
    else {
        // Parent
        printf("Parent: x = %d\n", x);
        x = 300;
        printf("Parent after changing x: %d\n", x);
    }

    return 0;
}
//Ku Htoo
// Question 1: After the fork the child process gets a copy of parent
// memory, such as x. When both processes change x they will get their own
// copies of x. These variables are independent of each other.