#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - Custom implementation of printf for Task One.
 * @format: The format string containing characters and specifiers.
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int count = 0; 
    va_list args;
    const char *ptr;
    char *buffer;

    if (format == NULL)
        return (-1);

  
    buffer = malloc(1024 * sizeof(char));
    if (buffer == NULL)
        return (-1); 

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++; 
            if (*ptr == 'c') 
            {
                char c = va_arg(args, int);
                buffer[count++] = c;
            }
            else if (*ptr == 's')
            {
                char *str = va_arg(args, char *);
                int i;

                if (str == NULL)
                    str = "(null)";
                for (i = 0; str[i] != '\0'; i++, count++)
                    buffer[count] = str[i];
            }
            else if (*ptr == '%') 
            {
                buffer[count++] = '%';
            }
            else 
            {
                free(buffer);
                return (-1);
            }
        }
        else 
        {
            buffer[count++] = *ptr;
        }

        if (count >= 1024)
        {
            char *new_buffer = realloc(buffer, 2048); 
            if (new_buffer == NULL)
            {
                free(buffer);
                return (-1); 
            }
            buffer = new_buffer;
        }
    }

  
    write(1, buffer, count);
    free(buffer);

    va_end(args);
    return (count);
}
