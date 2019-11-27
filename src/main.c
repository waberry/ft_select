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

int		main (void)
{
  char		c;
  char		buff[1024];

  set_input_mode();
  while (1)
    {
		read (STDIN_FILENO, &c, 1);
		ft_strcat(buff, &c);
		if (ft_strcmp(buff,"^[[A") == 0)
			ft_putendl("UP");
		else
			putchar (c);
    }

  return EXIT_SUCCESS;
}
