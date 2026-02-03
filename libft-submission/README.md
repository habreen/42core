This project has been created as part of the 42 curriculum by <hshamudh>

# Libft

## Description
Libft is a custom C library developed as one of the core projects of the 42 curriculum.  
Its objective is to rebuild a set of essential standard C library functions, as well as create
additional utility functions that will be reused in later projects.

The project helps students:
- Understand low-level memory management
- Improve their mastery of pointers, strings, and linked lists
- Build a reliable personal library of functions for future 42 projects

Libft includes:
- Part 1: Re-implementations of libc functions (`memset`, `strlen`, `strlcpy`, etc.)
- Part 2: Additional functions for strings and memory management
- Bonus: A full set of linked list manipulation utilities

## Instructions

### Requirements
- A C compiler (42 uses `clang`)
- A Unix-like environment (Linux/macOS)
- A Makefile is provided to compile the library

### Compilation
To compile the library:
```sh
makefile

#character checks

| Function            | Purpose                                                        |
| ------------------- | -------------------------------------------------------------- |
| `ft_isalpha(int c)` | Returns non-zero if `c` is a letter (a–z or A–Z).              |
| `ft_isdigit(int c)` | Returns non-zero if `c` is a digit (0–9).                      |
| `ft_isalnum(int c)` | Returns non-zero if `c` is a letter or digit.                  |
| `ft_isascii(int c)` | Returns non-zero if `c` is an ASCII character (0–127).         |
| `ft_isprint(int c)` | Returns non-zero if `c` is printable (including space).        |
| `ft_toupper(int c)` | Converts lowercase letter to uppercase; otherwise returns `c`. |
| `ft_tolower(int c)` | Converts uppercase letter to lowercase; otherwise returns `c`. |

#string manipulation
| Function                                                   | Purpose                                                              |
| ---------------------------------------------------------- | -------------------------------------------------------------------- |
| `ft_strlen(const char *s)`                                 | Returns the length of the string (excluding `\0`).                   |
| `ft_strchr(const char *s, int c)`                          | Returns pointer to first occurrence of `c` in `s` (or NULL).         |
| `ft_strrchr(const char *s, int c)`                         | Returns pointer to last occurrence of `c` in `s` (or NULL).          |
| `ft_strncmp(const char *s1, const char *s2, size_t n)`     | Compares at most `n` characters of two strings.                      |
| `ft_strlcpy(char *dst, const char *src, size_t dstsize)`   | Copies string safely, returns length of `src`.                       |
| `ft_strlcat(char *dst, const char *src, size_t dstsize)`   | Appends string safely, returns length `dst + src`.                   |
| `ft_strdup(const char *s)`                                 | Allocates new memory and copies string into it.                      |
| `ft_substr(char const *s, unsigned int start, size_t len)` | Allocates substring starting at `start` with max `len` characters.   |
| `ft_strjoin(char const *s1, char const *s2)`               | Allocates a new string containing `s1` + `s2`.                       |
| `ft_strtrim(char const *s1, char const *set)`              | Returns a copy of `s1` without leading/trailing characters in `set`. |
| `ft_split(char const *s, char c)`                          | Splits `s` into an array of strings using `c` as delimiter.          |
| `ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies function `f` to each char of `s`, returns new string.        |

#Memory functions
| Function                                              | Purpose                                                                       |
| ----------------------------------------------------- | ----------------------------------------------------------------------------- |
| `ft_memset(void *b, int c, size_t len)`               | Fills `len` bytes of memory with byte `c`.                                    |
| `ft_bzero(void *s, size_t n)`                         | Sets `n` bytes to zero (same as `ft_memset(s, 0, n)`).                        |
| `ft_memcpy(void *dst, const void *src, size_t n)`     | Copies `n` bytes from `src` to `dst` (no overlap handling).                   |
| `ft_memmove(void *dst, const void *src, size_t n)`    | Copies `n` bytes safely even if memory overlaps.                              |
| `ft_memchr(const void *s, int c, size_t n)`           | Returns pointer to first occurrence of byte `c` in first `n` bytes (or NULL). |
| `ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares first `n` bytes of memory areas.                                     |
| `ft_calloc(size_t count, size_t size)`                | Allocates memory for `count * size` bytes, initialized to 0.                  |

| Function                   | Purpose                                       |
| -------------------------- | --------------------------------------------- |
| `ft_atoi(const char *str)` | Converts string to integer.                   |
| `ft_itoa(int n)`           | Converts integer to a newly allocated string. |


| Function                         | Purpose                                               |
| -------------------------------- | ----------------------------------------------------- |
| `ft_putchar_fd(char c, int fd)`  | Writes character `c` to file descriptor `fd`.         |
| `ft_putstr_fd(char *s, int fd)`  | Writes string `s` to file descriptor `fd`.            |
| `ft_putendl_fd(char *s, int fd)` | Writes string `s` + newline to file descriptor `fd`.  |
| `ft_putnbr_fd(int n, int fd)`    | Writes integer `n` as string to file descriptor `fd`. |

linked lists
| Function                   | Purpose                                                |
| -------------------------- | ------------------------------------------------------ |
| `ft_lstnew(void *content)` | Creates a new node with `content`, `next` set to NULL. |
| Function                                     | Purpose                                           |
| -------------------------------------------- | ------------------------------------------------- |
| `ft_lstadd_front(t_list **lst, t_list *new)` | Adds `new` node at the **beginning** of the list. |
| `ft_lstadd_back(t_list **lst, t_list *new)`  | Adds `new` node at the **end** of the list.       |
| Function                  | Purpose                                      |
| ------------------------- | -------------------------------------------- |
| `ft_lstsize(t_list *lst)` | Returns the **number of nodes** in the list. |
| `ft_lstlast(t_list *lst)` | Returns the **last node** in the list.       |
| Function                                         | Purpose                                                   |
| ------------------------------------------------ | --------------------------------------------------------- |
| `ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees **one node** using function `del` on its content.   |
| `ft_lstclear(t_list **lst, void (*del)(void *))` | Frees **all nodes** in the list and sets pointer to NULL. |
| Function                                                          | Purpose                                                                                        |
| ----------------------------------------------------------------- | ---------------------------------------------------------------------------------------------- |
| `ft_lstiter(t_list *lst, void (*f)(void *))`                      | Applies function `f` to **each node’s content**.                                               |
| `ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates a **new list** by applying `f` to each content; frees if allocation fails using `del`. |


