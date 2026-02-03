💡 What is this?
The get_next_line project is a classic challenge at 42 School. The goal is simple but tricky: write a function that reads a single line from a file descriptor.

If you call the function in a loop, it returns the entire file, one line at a time, until the end. It’s basically building your own version of the line-reading logic that exists in higher-level languages like Python or Go, but using C.

🛠️ How it Works
Reading a file in C is messy because you don't know where a line ends until you've already read it.

The Stash: The function uses a static variable to act as a "stash."

The Read: It reads from the file in chunks (defined by BUFFER_SIZE).

The Glue: It joins these chunks to the stash until it finds a newline character (\n).

The Clean up: It returns the line it found and keeps the "leftovers" in the stash for the next time you call the function.
Compile with a Buffer Size: You can decide how many bytes the function reads at a time by defining BUFFER_SIZE.

Bash

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
🧠 Skills Learned
Understanding Static Variables (memory that persists between function calls).

Deep diving into File Descriptors and the read() function.

Mastering Dynamic Memory Allocation (making sure every malloc has a free so there are no leaks).

Following the Norminette (strict coding standards).