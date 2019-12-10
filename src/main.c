#include "ft_select.h"
/*
int		init_term()
{
	int		ret;
	char	*term_type;

	if (!(term_type=getenv("TERM")))
	{
		ft_putendl_fd("TERM must be set (see 'env').", (int)stderr);
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		ft_putendl_fd("Could not access to the termcap database..", (int)stderr);
        return -1;
	}
	else if (ret == 0)
	{
		ft_putendl_fd("Terminal type '%s' is not defined in termcap database (or have too few informations).", stderr);
        return -1;
	}
	return (0);
}
*/

void	reset_input_mode (void)
{
  tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
}

void	set_input_mode (void)
{
  struct	termios tattr;
  //char		*name;

  /* Make sure stdin is a terminal. */
  if (!isatty (STDIN_FILENO))
    {
      ft_putendl_fd("Not a terminal.\n", (int)stderr);
      exit (EXIT_FAILURE);
    }

  /* Save the terminal attributes so we can restore them later. */
  tcgetattr (STDIN_FILENO, &saved_attributes);
  atexit (reset_input_mode);

  /* Set the funny terminal modes. */
  tcgetattr (STDIN_FILENO, &tattr);
  tattr.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
  tattr.c_cc[VMIN] = 1;
  tattr.c_cc[VTIME] = 0;
  tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}

size_t    wcharlen(char c)
{
  if (c == 27)
    return (5);
  if ((c & 0xF0) == 0xF0)
    return (4);
  else if ((c & 0xE0) == 0xE0)
    return (3);
  else if ((c & 0xC0) == 0xC0)
    return (2);
  return (1);
}

int		main (int ac, char ** av)
{
  long    buffer;
  int     ret;
  ssize_t j;

  if (ac <= 1 || av == NULL)
    return -1;
  int i = 1;
  while (i < ac)
  {
    if (i%3 == 0)
      ft_putchar('\n');
    ft_putstr(av[i]);
    ft_putchar(' ');
    ++i;
  }
  ret = 0;
  set_input_mode();
  while (1)
  {
    buffer = 0;
    j = read(0, &buffer, 1);
    if (j != 1)
      j += read(0, (char *)(&buffer) + 1, wcharlen(buffer) - 1);
    ft_putchar(buffer);

  }
  //ft_bzero(buff, 1024);
  reset_input_mode();
  return EXIT_SUCCESS;
}
