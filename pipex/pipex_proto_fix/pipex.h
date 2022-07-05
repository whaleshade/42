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

# define STDIN 0
# define STDOUT 1
# define SUCCESS 0
# define FAIL -1
# define INFILE 0
# define OUTFILE 1
# define ON 1
# define OFF 0

void	ft_handle_error(const char *str);
int		ft_fileopen(char *filename, int mode);
char	*ft_pathenv(char **env);
char	*ft_getcmd(char **cmd_path, char *cmd);

#endif
