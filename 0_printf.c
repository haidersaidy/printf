#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function that handles format specifiers.
 * @format: The format string containing the characters and specifiers.
 *
 * Return: The number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
    specifier_t spec_table[] = {
        {'c', print_c},
        {'s', print_s},
        {'i', print_int},
        {'d', print_int},
        {'%', print_percent},
        {0, NULL}
    };
    va_list args;
    int i = 0, len = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            int j = 0;

            while (spec_table[j].spec != 0)
            {
                if (spec_table[j].spec == format[i + 1])
                {
                    len += spec_table[j].func(args);
                    break;
                }
                j++;
            }
            if (spec_table[j].spec == 0)
                len += _putchar('%');
            i++;
        }
        else
        {
            len += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return (len);
}
