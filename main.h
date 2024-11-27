#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list args);
int print_s(va_list args);
int print_int(va_list args);
int print_percent(va_list args);
int print_number(int n);
int print_int_helper(int n);

typedef struct specifier {
    char spec;
    int (*func)(va_list args);
} specifier_t;

#endif 
