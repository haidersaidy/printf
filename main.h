#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list args);
int print_s(va_list args);
int print_int(va_list args);
int print_percent(va_list args);
int print_number(int n);
int print_int_helper(int n);

/* Structure for specifiers and corresponding functions */
typedef struct specifier {
    char spec;
    int (*func)(va_list args);
} specifier_t;

#endif /* MAIN_H */
