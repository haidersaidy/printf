#include "main.h"
#include <stdlib.h>  /* For malloc and free */

/**
 * print_number - Prints an integer to stdout using recursion.
 * @n: The integer to print.
 */
void print_number(int n)
{
    char c;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }

    if (n / 10 != 0)
        print_number(n / 10);

    c = (n % 10) + '0';
    write(1, &c, 1);
}

/**
 * _printf - Custom printf function to handle %c, %s, %d, %i, %%.
 * @format: The format string containing the characters and specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int count = 0, i;
    va_list args;
    const char *ptr;
    char *buffer;
    int buffer_size = 1024;

    /* Allocate memory for the buffer */
    buffer = malloc(buffer_size);
    if (buffer == NULL)
        return (-1);

    va_start(args, format);

    if (format == NULL)
    {
        free(buffer);
        return (-1);
    }

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')  /* Handle %c */
            {
                char c = va_arg(args, int);
                buffer[count++] = c;
            }
            else if (*ptr == 's')  /* Handle %s */
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                for (i = 0; str[i] != '\0'; i++)
                    buffer[count++] = str[i];
            }
            else if (*ptr == '%')  /* Handle %% */
            {
                buffer[count++] = '%';
            }
            else if (*ptr == 'd' || *ptr == 'i')  /* Handle %d and %i */
            {
                int num = va_arg(args, int);
                print_number(num); /* Print the integer directly */
            }
        }
        else
        {
            buffer[count++] = *ptr;
        }

        /* Reallocate buffer if it's full */
        if (count >= buffer_size)
        {
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
            if (buffer == NULL)
            {
                free(buffer);
                return (-1);
            }
        }
    }

    /* Write the formatted output from the buffer */
    write(1, buffer, count);

    va_end(args);
    free(buffer);  /* Free allocated memory */
    return (count);
}
