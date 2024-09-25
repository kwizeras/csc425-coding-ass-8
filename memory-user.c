#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num of megabytes to allocate>\n", argv[0]);
        return 1;
    }

    int megabytes = atoi(argv[1]);
    int size = megabytes * 1024 * 1024;  // Convert MB to bytes
    char *array = malloc(size);

    if (array == NULL) {
        perror("malloc");
        return 1;
    }

    // Infinite loop to access memory
    for (int i = 0; i < size; i++) {
        array[i] = i % 256;  // Touch each memory location
    }

    printf("Allocated %d MB and accessing it...\n", megabytes);
    while (1) {
        sleep(1);  // Sleep to keep the program running
    }

    return 0;
}
