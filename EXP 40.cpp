#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    // File name to change permissions
    char filename[] = "file.txt";

    // Define the new permissions: rw-rwr-- (user read/write, group read/write, others read)
    int new_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    // Change file permissions using chmod
    if (chmod(filename, new_permissions) == 0) {
        printf("File permissions changed successfully.\n");
    } else {
        perror("chmod");
        return 1;
    }

    return 0;
}
