# Project Overview 📄:

This project provides a custom implementation of the standard C library function printf. The goal of the project is to demonstrate an understanding of variadic functions in C, custom string formatting, and how the printf function works under the hood. The custom function, _printf, supports basic format specifiers for printing characters (%c), strings (%s), and the percent sign (%%).

# Table of Contents
<ul>
 <li> Features </li>
 <li> Dependencies </li>
 <li> Installation </li>
 <li> Usage </li>
 <li> Functionality </li>
 <li> Description </li>
 <li> Return Value </li>
 <li> Authors </li>
 <li> Acknowledgements</li>

</ul>

# Features
 Implements a custom version of the printf function.
Supports the following format specifiers:
 <ul>
 <li> %c: Print a character.</li>
 <li> %s: Print a string.</li> 
 <li> %d and %i - Prints integers.</li>
 <li> %%: Print a literal percent sign.</li>
 <li> Returns the number of characters printed (excluding the null byte).</li>
</ul>

# Dependencies 👫
The _printf function was coded on an Ubuntu 24.04.1 LTS machine with gcc version 13.2.0.

# Installation 
<h3>Prerequisites</h3>
<ul>
 <li>  GCC (GNU Compiler Collection).</li>
 <li> A C development environment (e.g., Linux or macOS terminal, or Windows with WSL).</li>
</ul>

<h3>Steps to Install</h3>
Clone the repository:

bash
Copier le code 
git clone https://github.com/your-username/holbertonschool-printf.git

Change into the project directory:

bash
Copier le code
cd holbertonschool-printf

Compile the project with gcc:

bash
Copier le code
gcc -Wall -Werror -Wextra -pedantic *.c -o my_printf

Now the project is ready for use! The compiled program is named my_printf.

# Usage 🏃
To use the custom _printf function in your project, simply include the appropriate header and call the function as you would with the standard printf. Below is an example of how to use _printf:

Copier le code
#include "main.h"

int main(void)
{
    int len;

    // Print a simple sentence and store the number of characters printed
    len = _printf("Let's try to printf a simple sentence.\n");

    // Print the number of characters printed by _printf
    _printf("Printed %d characters.\n", len);

    return 0;
}

In this example, _printf is used to print a string and the program outputs the number of characters printed.

# Functionality
The custom _printf function supports the following format specifiers:

%c: Prints a single character.</br>
%s: Prints a string.</br>
%d and %i - Prints integers.</br>
%%: Prints a literal percent sign.</br>
The function will return the total number of characters printed (excluding the null byte used to end the string). The return value can be used to display or log the number of characters printed.

Example of Output:
bash
Copier le code
Let's try to printf a simple sentence.</br>
Printed 42 characters.

# Description 💬
The function _printf writes output to standard output. The function writes under the control of a format string that specifies how subsequent arguments (accessed via the variable-length argument facilities of stdarg) are converted for output.


Prototype: int _printf(const char *format, ...);


# Return Value
Upon successful return, _printf returns the number of characters printed (excluding the terminating null byte used to end output to strings). If an output error is encountered, the function returns -1.


# Authors ✒️
Ichraq Najjar <a href="https://github.com/Ichnajj/">ichnajj</a> <br>
Haider Saidy  <a href="https://github.com/haidersaidy/">haidersaidy</a>

# Acknowledgements 🙏
The _printf function emulates functionality of the C standard library function printf. This README borrows from the Linux man page printf(3).

This program was written as part of the curriculum for Holberton School. Holberton School is a campus-based full-stack software engineering program that prepares students for careers in the tech industry using project-based peer learning. For more details,  <a href="https://www.holbertonschool.com/programs">Click here</a>
.

<a href="https://www.holbertonschool.com/">
    <img style ="display: flex; height: 80px ; width: 70px; align-items: center; justify-content: center;align-items: center;" src="https://blog.holbertonschool.com/wp-content/uploads/2019/04/instagram_feed180.jpg" alt="Holberton School">
</a>
