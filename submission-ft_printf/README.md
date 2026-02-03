This project has been created as part of the 42 curriculum by hshamudh.
# ft_printf

## Description

The **ft_printf** project consists of recreating a simplified version of the standard C library function `printf`.  
The goal of this project is to understand and implement **variadic functions**, handle **formatted output**, and manage low-level input/output using system calls.

This implementation covers only the **mandatory part** of the project and reproduces the behavior of `printf` for a limited set of format specifiers.

## Instructions

### Compilation

To compile the project, run:

```bash
make
make clean
make fclean
make re
#include "ft_printf.h"
gcc main.c libftprintf.a
ft_printf("Hello %s, value: %d\n", "world", 42);
The following format specifiers are implemented:

%c character

%s string

%p pointer address

%d decimal integer

%i integer

%u unsigned integer

%x hexadecimal (lowercase)

%X hexadecimal (uppercase)

%% percent sign
Algorithm

The algorithm is based on sequential parsing of the format string.

Iterate through the format string character by character.

If the current character is not %, print it directly using write.

If % is encountered, analyze the next character to determine the conversion type.

Retrieve the corresponding argument using va_arg.

Convert the argument into its textual representation.

Print the result and increment the total printed character count.

Return the total number of printed characters.

This approach closely follows the behavior of the original printf while remaining simple and efficient.

Data Structures

No complex data structures are used in this project.

va_list is used to manage variadic arguments.

Primitive C types and strings are used for data handling.

Output is written directly using the write system call.

This design minimizes memory usage and respects the constraints of the project.
Justification

Sequential parsing ensures predictable behavior and easy debugging.

Separate functions for each conversion improve code readability and maintainability.

Avoiding unnecessary dynamic memory allocation reduces errors and memory leaks.

Resources
References

42 ft_printf subject (Intranet)

man printf

man stdarg
Use of AI

AI was used for:

Clarifying concepts related to variadic functions and format parsing

Understanding edge cases of printf behavior

Assisting in structuring and writing documentation