#include <stdio.h>
#include <math.h>
#include <getopt.h>

#define BUFFER_SIZE 2048

size_t get_input(int*);
size_t print_output(int*, size_t);
void run();
void print_start();
void print_end();

static int prints;
static int colors;

int main(int argc, char** argv) {
    int c;
    while(1) {
        static struct option long_options[] = {
            {"print", no_argument, &prints, 0},
            {"color", no_argument, &colors, 1}
        };
        int option_index = 0;
        c = getopt_long(argc, argv, "cp", long_options, &option_index);
        if (c == -1)
            break;
        else if (c == 'p')
            prints = 1;
        else if (c == 'c') 
            colors = 1;
    }
    run();
}

void run() {
    int buffer[BUFFER_SIZE];
    size_t n;
    if (colors)
        fputs("\e[90;2m", stderr);
    if (prints)
        print_start();


    while((n = get_input(buffer)) != 0)
        print_output(buffer, n);

    putc('\n', stdout);
    putc('\n', stderr);
    if (prints)
        print_end();
    if (colors)
        fputs("\e[0m", stderr);
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
    fprintf(stderr, "----- p end   -----\n");
}

