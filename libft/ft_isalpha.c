#include "libft.h"

/*
 * ft_isalpha - check for alphabetic character
 * Returns non-zero if c is a letter (A-Z or a-z), 0 otherwise.
 */
int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}