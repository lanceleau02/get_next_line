<div align="center">

<h1>get_next_line</h1>

<a href="https://imgflip.com/i/7tasl3"><img src="https://i.imgflip.com/7tasl3.jpg" width="300px" title="meme"/></a>

<a><img src="https://badge42.vercel.app/api/v2/clj4r0l4t004008mgcfxas4fw/project/2877915" title="score" /></a>

</div>

<p>Description:</p>

> Write a function that returns a line read from a file descriptor.

<h2>✔️ Project's requirements</h2>

- Repeated calls (e.g., using a loop) to your `get_next_line()` function should let
you read the text file pointed to by the file descriptor, **one line at a time**.
- Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return `NULL`.
- Make sure that your function works as expected both when reading a file and when
reading from the standard input.
- **Please note** that the returned line should include the terminating `\n` character,
except if the end of file was reached and does not end with a `\n` character.
- Your header file `get_next_line.h` must at least contain the prototype of the
`get_next_line()` function.
- Add all the helper functions you need in the `get_next_line_utils.c` file.
- Because you will have to read files in `get_next_line()`, add this option to your compiler call: `-D BUFFER_SIZE=n`. It will define the buffer size for `read()`. The buffer size value will be modified by your peer-evaluators and the Moulinette in order to test your code.
- You will compile your code as follows (a buffer size of 42 is used as an example): <br>`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`
- We consider that `get_next_line()` has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas `read()` didn’t reach the end of file.
- We also consider that `get_next_line()` has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.
- You are not allowed to use your `libft` in this project.
- `lseek()` is forbidden.
- Global variables are forbidden.

<h2>🧬 Theory</h2>



<h2>📝 Code explanation</h2>

<h3>File: ft_printf.c</h3>

<h2>🧰 Toolbox</h2>

- [gnlTester](https://github.com/Tripouille/gnlTester)

<h2>📚 Resources</h2>

- [Tutorial (in french)](https://www.youtube.com/watch?v=-Mt2FdJjVno)
