/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:28:38 by jibang            #+#    #+#             */
/*   Updated: 2022/06/26 16:02:32 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_utils.c"

void	ft_child_proc1(char **av, char **env, int *fd, char **paths)
{
	int		pid;
	char	**cmd_args;
	char	*cmd;

	pid = fork();
	waitpid(pid, NULL, WNOHANG);
	if (pid < 0)
		ft_handle_error("fork error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		close(fd[1]);
		cmd_args = ft_split(av[3], ' ');
		cmd = ft_getcmd(paths, cmd_args[0]);
		if (!cmd)
			ft_handle_error("No such command");
		execve(cmd, cmd_args, env);
	}
}

void	ft_child_proc2(char **av, char **env, int *fd, char **paths)
{
	int		pid;
	char	**cmd_args;
	char	*cmd;

	pid = fork();
	waitpid(pid, NULL, WNOHANG);
	if (pid < 0)
		ft_handle_error("fork error");
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		close(fd[0]);
		cmd_args = ft_split(av[3], ' ');
		cmd = ft_getcmd(paths, cmd_args[0]);
		if (!cmd)
			ft_handle_error("No such command");
		execve(cmd, cmd_args, env);
	}
}

int	main(int ac, char **av, char **env)
{
	t_info	file;
	int		fd[2];
	char	*pathenv;
	char	**cmd_paths;

	if (ac != 5)
		ft_handle_error("Invalid argument number");
	file.in = av[1];
	file.out = av[ac - 1];
	file.fdin = ft_fileopen(file.in, INFILE);
	file.fdout = ft_fileopen(file.out, OUTFILE);
	dup2(file.fdin, STDIN);
	dup2(file.fdout, STDOUT);
	if (pipe(fd) == FAIL)
		ft_handle_error("piping failed");
	pathenv = ft_pathenv(env);
	cmd_paths = ft_split(pathenv, ':');
	ft_child_proc1(av, env, fd, cmd_paths);
	ft_child_proc2(av, env, fd, cmd_paths);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
