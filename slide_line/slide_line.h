#ifndef SLIDE_LINE
#define SLIDE_LINE

#include <stddef.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT -1

int slide_line(int *line, size_t size, int direction);
void print_array(int const *array, size_t size);

#endif  /* SLIDE_LINE */