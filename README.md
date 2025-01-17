<div align="center">

![](https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/get_next_linee.png)

# **get_next_line**

**Reading a line from a fd is way too tedious.**

</div>

## Features

- Reads files or input line by line.
- Handles multiple file descriptors simultaneously.
- Adapts to a user-defined `BUFFER_SIZE`.
- Manages memory dynamically for arbitrary line lengths.
- Detects and handles end-of-file properly.
- Supports any valid file descriptor (files, stdin, sockets).
- Provides a simple function: `char *get_next_line(int fd);`.

## Installation

There’s no installation process for this project. Simply clone the repository in your project directory.

1. Clone the repository:

```bash
git clone https://github.com/lanceleau02/get_next_line.git
```

## Usage

1. Compile the source files:

Ensure the `get_next_line.c` file is included during compilation. For example:

```bash
gcc -Wall -Wextra -Werror -o my_program my_program.c get_next_line.c
```

3. Include the header file:

Add the following line in your source files to use the `get_next_line()` function:

```c
#include "get_next_line.h"
```

Once compiled, you can call the `get_next_line()` function in your program to read input line by line.

## License

This project is licensed under the **42 School** License.

- **Educational Use Only**: This project is intended for educational purposes at the 42 School as part of the curriculum.
- **Non-commercial Use**: The code may not be used for commercial purposes or redistributed outside of the 42 School context.
- **No Warranty**: The project is provided "as-is", without any warranty of any kind.

For more details, see the [LICENSE](https://github.com/lanceleau02/get_next_line/blob/main/LICENSE) file.

## Resources

- [gnlTester](https://github.com/Tripouille/gnlTester)
- [Video tutorial (in french)](https://www.youtube.com/watch?v=-Mt2FdJjVno)
- [Video tutorial (in english)](https://www.youtube.com/watch?v=8E9siq7apUU)
