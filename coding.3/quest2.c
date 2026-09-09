#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t p = fork();

    if (p < 0) {
        perror("fork");
        return 1;
    }
    else if (p == 0) {
        // Child
        write(fd, "Child\n", 6);
    }
    else {
        // Parent
        write(fd, "Parent\n", 7);
    }

    close(fd);
    return 0;
}
//Ku Htoo
// Question 2: This program shows how a parent and child process can write to the same file description 
// after a fork. The child inherits the file descriptor from the parent, and both processes can write to the same file.
//cat output.txt will show the output of both processes, but the order may vary depending on the scheduling of the processes.