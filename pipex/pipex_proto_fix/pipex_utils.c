/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:10:11 by jibang            #+#    #+#             */
/*   Updated: 2022/06/26 15:14:50 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_handle_error(const char *str)
{
	ft_printf("%s\n", str);
	perror("following error occurs");
	exit(1);
}

int	ft_fileopen(char *filename, int mode)
{
	int		fd;
	int		flag;

	if (mode == INFILE)
	{
		if (access(filename, F_OK) == SUCCESS)
		{
			fd = open(filename, O_RDONLY);
			return (fd);
		}
		else if (access(filename, F_OK) == FAIL)
			ft_handle_error("infile does not exist");
	}
	flag = O_CREAT | O_WRONLY | O_TRUNC;
	fd = open(filename, flag, 0744);
	if (fd == FAIL)
		ft_handle_error("outfile open failed");
	return (fd);
}

char	*ft_pathenv(char **env)
{
	int		i;
	char	*pathenv;

	i = 0;
	while (ft_strncmp("PATH", env[i], 4) != 0)
		i++;
	pathenv = &env[i][5];
	return (pathenv);
}

char	*ft_getcmd(char **cmd_path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*cmddir;

	i = 0;
	while (cmd_path[i])
	{
		tmp = ft_strjoin(cmd_path[i], "/");
		cmddir = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmddir, F_OK) == SUCCESS)
			return (cmddir);
		free(cmddir);
		i++;
	}
	return (NULL);
}
