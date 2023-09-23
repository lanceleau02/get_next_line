<div align="center">

<h1>get_next_line</h1>

<a href="https://imgflip.com/i/7tasl3"><img src="https://i.imgflip.com/7tasl3.jpg" width="300px" title="meme"/></a>

</div>

<p>Description:</p>

> Write a function that returns a line read from a file descriptor.

<h2>✔️ Project's requirements</h2>

- Repeated calls (e.g., using a loop) to your `get_next_line()` function should let
you read the text file pointed to by the file descriptor, one line at a time.
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

The `get_next_line()` function reads the next line from the specified file descriptor `fd` and returns it. It reads until it encounters a newline character `\n` or reaches the end of the file. This project therefore includes memory and files management. <br>
In the bonus part, the implementation of the `get_next_line()` function must be done with only one static variable and it must be able to manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd.

<h2>📝 Code explanation</h2>

<h3>File: get_next_line.c</h3>

Let's starts by the `get_next_line()` function:

```C
char	*get_next_line(int fd)
{
	char		*buf;
	int			read_bytes;
	static char	*line = NULL;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buf[read_bytes] = '\0';
		line = join(line, buf);
		if (check_nl(line) == 1)
			break ;
	}
	free(buf);
	buf = NULL;
	if (line != NULL)
		read_bytes = cut(line, &buf);
	if (read_bytes == 1)
	{
		free(line);
		line = NULL;
	}
	return (buf);
}
```

The function begins by initializing a `buf` variable for storing data read from the file descriptor.

It declares an integer variable `read_bytes` to keep track of the number of characters read in each read operation.

It declares a static character pointer `line` and initializes it to `NULL`. This pointer is used to accumulate the contents of the current line.

Inside a `while(1)` loop, the function reads data from the file descriptor into the buffer in chunks of size `BUFFER_SIZE` (that is initialized in the header file). It continues reading until it encounters the end of the file or a newline character.

After each read operation, the function calls the `join()` function to concatenate the newly read data in `buf` with the existing `line` string.
The `join()` function allocates memory as needed and appends the data to `line`.

After concatenating data, the function checks if the line contains a newline character using the `check_nl()` function. If a newline is found, it breaks out of the loop to process the line.

Once a line is processed, the function calls the `cut()` function to separate the line and prepare it for return.
The `cut()` function splits the line and stores the remainder back in the `line` variable.
If there are more lines to read in the `line` variable, the function continues processing them.

The function frees the memory allocated for the `buf` variable and sets it to `NULL` to avoid memory leaks.
If the line variable is not `NULL`, the `cut()` function has allocated memory for a line. It returns `1` to indicate more lines may be available.
If there are no more lines to read, the `line` variable is freed and set to `NULL`.

Finally, the function returns the `buf` variable.

And... Here it is! We have a good working `get_next_line()` function! I'm not going to explain the others functions because `join()` is a simple adapted versions of the C function `strjoin()`, the `cut()` function is a protein-boosted version of the `strcpy()` function and the `check_nl()` function... does it make any sense to explain that?

---

<h3>File: get_next_line_bonus.c</h3>

Now, let's discover the bonus version of the code! In this file, nothing has changed except in the `get_next_line()` function:

```C
char	*get_next_line(int fd)
{
	char		*buf;
	int			read_bytes;
	static char	*line[1024];

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buf[read_bytes] = '\0';
		line[fd] = join(line[fd], buf);
		if (check_nl(line[fd]) == 1)
			break ;
	}
	free(buf);
	buf = NULL;
	if (line[fd] != NULL)
		read_bytes = cut(line[fd], &buf);
	if (read_bytes == 1)
	{
		free(line[fd]);
		line[fd] = NULL;
	}
	return (buf);
}
```

In this version, the `line` variable becomes a pointer to array with a maximum size of 1024 to be able to read from several file descriptors. Why 1024? Because on Linux OS, the maximum number of file descriptors available and user processes is 1024. You can know it by using the `ulimit -n` command in your terminal.

Since the `line` variable now stores an array of file descriptors, it would be a good idea to specify which fd we want to process. To do this, at each point where the `line` variable is called, we simply add `[fd]` after it.

<h2>🧰 Toolbox</h2>

- [gnlTester](https://github.com/Tripouille/gnlTester)

<h2>📚 Resources</h2>

- [Video tutorial (in french)](https://www.youtube.com/watch?v=-Mt2FdJjVno)
- [Video tutorial (in english)](https://www.youtube.com/watch?v=8E9siq7apUU)
