#include <stdarg.h>
#include "main.h"

/**
 * print_c - Prints a single character.
 * @args: The arguments list containing the character to print.
 *
 * Return: The number of characters printed (1).
 */
int print_c(va_list args)
{
    char c = va_arg(args, int);

    return (_putchar(c));
}

/**
 * print_s - Prints a string.
 * @args: The arguments list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_s(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (str == NULL)
    {
        str = "(null)";
    }

    while (str[len])
    {
        _putchar(str[len]);
        len++;
    }
    return (len);
}

/**
 * print_int - Prints an integer.
 * @args: The arguments list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
    int num = va_arg(args, int);

    return (print_number(num));
}

/**
 * print_percent - Prints a percent sign.
 * @args: Unused argument.
 *
 * Return: The number of characters printed (1).
 */
int print_percent(va_list args)
{
    (void)args;

    return (_putchar('%'));
}

/**
 * print_number - Helper function to print numbers.
 * @n: The number to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
    int len = 0;

    if (n == 0)
    {
        len += _putchar('0');
    }
    else if (n < 0)
    {
        len += _putchar('-');
        n = -n;
    }

    len += print_int_helper(n);
    return (len);
}

/**
 * print_int_helper - Helper function to print each digit of an integer.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int_helper(int n)
{
    int len = 0;

    if (n / 10 != 0)
    {
        len += print_int_helper(n / 10);
    }
    len += _putchar((n % 10) + '0');
    return (len);
}

