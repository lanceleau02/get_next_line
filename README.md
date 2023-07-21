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

Let's starts by the `ft_printf()` function:

```C
int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_program	data;
	int		i;

	if (format == NULL)
		return (-1);
	data.written = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			define_type(format[i + 1], &data, ap);
			i++;
		}
		else
			ft_putchar(format[i], &data);
		i++;
	}
	va_end(ap);
	return (data.written);
}
```

The `ft_printf()` function takes in a `format` string and a variable number of arguments. It returns an integer representing the total number of characters written.

The function begins by initializing a `va_list` variable named `ap` to handle the variable arguments. It also declares a structure `t_program` named `data` to store information about the program's execution. An integer variable `i` is declared for looping through the `format` string.

> 💡 I recommend you to inform yourself on the `va_arg` macro.

The code checks if the `format` string is not `NULL`. If it is `NULL`, the function returns `-1` to indicate an error.

A variable written in the `data` structure is set to `0`, representing the initial count of written characters.

The `va_start` macro initializes the `ap` variable to handle the variable arguments based on the format string.

A `while()` loop iterates through each character of the `format` string. Inside the loop, it checks if the current character is `%` and if the next character exists. If both conditions are met, it calls a function `define_type()` to handle the conversion specifier and corresponding argument. The `define_type()` function modifies the `data` structure accordingly.

If the current character is not `%`, it calls a function `ft_putchar()` to output the character to the console or another output stream, updating the `data` structure.

After processing the `format` string, the `va_end` macro is called to clean up the variable argument handling.

Finally, the function returns the total number of characters written.
	
<br>

Now let's see this `define_type()` function:

```C
static void	define_type(char c, t_program *data, va_list ap)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), data);
	if (c == 's')
		ft_putstr(va_arg(ap, char *), data);
	if (c == 'p')
		ft_putadd(va_arg(ap, void *), data);
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(ap, int), 10, "0123456789", data);
	if (c == 'u')
		ft_putunbr_base(va_arg(ap, unsigned int), 10, "0123456789", data);
	if (c == 'x')
		ft_putunbr_base(va_arg(ap, unsigned int), 16, "0123456789abcdef", data);
	if (c == 'X')
		ft_putunbr_base(va_arg(ap, unsigned int), 16, "0123456789ABCDEF", data);
	if (c == '%')
		ft_putchar('%', data);
}
```

The define_type function takes in three parameters: a character `c`, a pointer to a `t_program` structure named `data`, and a variable argument list `ap`.

Inside the function, there are several `if()` statements that check the value of the character `c` to determine the appropriate action for each conversion specifier.

- If `c` is 'c', prints the associated character thanks to the `ft_putchar()` function.
- If `c` is 's', prints the associated string thanks to the `ft_putstr()` function.
- If `c` is 'p', prints the associated address thanks to the `ft_putadd()` function.
- If `c` is 'd' or 'i', prints the associated value in base 10 thanks to the `ft_putnbr_base()` function.
- If `c` is 'u', prints the associated unsigned value in base 10 thanks to the `ft_putnbr_base()` function.
- If `c` is 'x', prints the associated value in base 16 and in lowercase thanks to the `ft_putnbr_base()` function.
- If `c` is 'X', prints the associated value in base 16 and in uppercase thanks to the `ft_putnbr_base()` function.
- If `c` is '%', prints the `%` character thanks to the `ft_putchar()` function.

> ⚠️ Beware of the type you pass in parameter!

---

<h3>File: ft_printf_utils.c</h3>

This is where the magic happens! Let's starts by the simplest function:

```C
void	ft_putchar(char c, t_program *data)
{
	data->written += write(1, &c, 1);
}
```

The `ft_putchar()` function calls the `write()` function to print the `c` character and save the amount of written characters in the `written` variable of the `data` structure.

<br>

Now let's see the `ft_putstr()` function:

```C
void	ft_putstr(char *str, t_program *data)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)", data);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		data->written += write(1, &str[i], 1);
		i++;
	}
}
```

The `ft_putstr()` function starts by checking if the input string `str` is `NULL`. If it is, it recursively calls `ft_putstr()` with the string "(null)" and the same `data` structure. Then, it exits the function.

If the input string is not `NULL`, the function initializes a variable `i` to `0`.

It enters a loop that continues until it reaches the end of the string.

Within the loop, it writes the current character to the standard output using the `write()` function and increments the written field of the `data` structure.

After each character is written, it increments `i` to move to the next character in the string.

Once the loop reaches the end of the string, the function exits.

<br>

Here is the function which permit to prints a memory address in hexadecimal:

```C
void	ft_putadd(void *nb, t_program *data)
{
	if (nb == 0)
	{
		ft_putstr("(nil)", data);
		return ;
	}
	ft_putstr("0x", data);
	ft_putunbr_base((unsigned long)nb, 16, "0123456789abcdef", data);
}
```

It checks if the input `void` pointer `nb` is equal to `0`. If it is, it recursively calls `ft_putstr()` with the string "(nil)" and the same `data` structure. Then, it exits the function.

If the input `void` pointer is not equal to `0`, the function proceeds.

It calls the `ft_putstr()` function to output the string "0x" to the standard output, which is a common prefix for representing memory addresses in hexadecimal format.

It calls the `ft_putunbr_base()` function to convert the memory address represented by the `void` pointer to a hexadecimal string and output it to the standard output.

<br>

It makes a perfect transition to talk about the `ft_putnbr_base()` function:

```C
void	ft_putnbr_base(__intmax_t n, int base, char *cbase, t_program *data)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', data);
	}
	if (n >= (__intmax_t)base)
		ft_putnbr_base(n / base, base, cbase, data);
	ft_putchar(cbase[n % base], data);
}
```

It first checks if the input integer `n` is negative. If it is, it multiplies it by `-1` to make it positive and calls the `ft_putchar()` function to output a '-' character to indicate the negative sign. The `ft_putchar()` function likely takes the character and the `data` structure as input.

Next, it checks if the absolute value of `n` is greater than or equal to the base value. If it is, the function recursively calls itself with the quotient of `n` divided by the base, the same base value, the character base array, and the `data` structure.

After the recursive call, the function calls the `ft_putchar()` function to output the character at the index `n % base` in the character base array. This represents the remainder of `n` divided by the base and corresponds to a digit in the desired base.

<br>

And here is the final function:

```C
void	ft_putunbr_base(__uintmax_t n, int base, char *cbase, t_program *data)
{
	if (n >= (__uintmax_t)base)
		ft_putunbr_base(n / base, base, cbase, data);
	ft_putchar(cbase[n % base], data);
}
```

It checks if the unsigned integer `n` is greater than or equal to the base value. If it is, the function recursively calls itself with the quotient of `n` divided by the base, the same base value, the character base array, and the `data` structure.

After the recursive call, the function calls the `ft_putchar()` function to output the character at the index `n % base` in the character base array. This represents the remainder of `n` divided by the base and corresponds to a digit in the desired base.

> 💡 The difference between `ft_putnbr_base()` and `ft_putunbr_base()` is that the first prints **signed** numbers and the second prints **unsigned** numbers.

<h2>🧰 Toolbox</h2>

- [printfTester](https://github.com/Tripouille/printfTester)
- [ft_printf tester](https://github.com/paulo-santana/ft_printf_tester)

<h2>📚 Resources</h2>

- [printf Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg Manual](https://man7.org/linux/man-pages/man3/va_arg.3.html)
