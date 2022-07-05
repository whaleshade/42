#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_info
{
	char	*in;
	char	*out;
	int		fdin;
	int		fdout;
} t_info;

typedef struct s_pipex
{
	int		*pid;
	int		**fd;
	int		num;
	char	*cmd;
	int		hd;
} t_pipex;

# define STDIN 0
# define STDOUT 1
# define SUCCESS 0
# define FAIL -1
# define INFILE 0
# define OUTFILE 1
# define APPD_OUT 2
# define ON 1
# define OFF 0

#endif
