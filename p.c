#include <stdio.h>
#include <math.h>

#define BUFFER_SIZE 2048

size_t get_input(int*);
size_t print_output(int*, size_t);

void print_start();
void print_end();

int main() {
    int buffer[BUFFER_SIZE];
    size_t n;
    print_start();

    while((n = get_input(buffer)) != 0)
        print_output(buffer, n);

    print_end();
}

size_t get_input(int* buffer) {
    int c;
    size_t i = 0;
    while((c = getc(stdin)) != EOF &&
            i < BUFFER_SIZE) {
        buffer[i++] = c;
    }
    return i == 0 ? 0 : i-1;
}

size_t print_output(int* buffer, size_t n) {
    printf("Printing %zu bytes.\n", n);
    for (size_t i = 0; i < n; i++) {
        putc(buffer[i], stderr);
        putc(buffer[i], stdout);
    }
    return n;
}

void print_start() {
    fprintf(stderr, "----- p begin -----\n");
}

void print_end() {
    fprintf(stderr, "\n----- p end   -----\n");
}

