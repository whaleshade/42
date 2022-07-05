/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:56:50 by jibang            #+#    #+#             */
/*   Updated: 2022/06/26 22:22:24 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (mode == APPD_OUT)
		flag = O_CREAT | O_WRONLY | O_APPEND;
	fd = open(filename, flag, 0744);
	if (fd == FAIL)
		ft_handle_error("outfile open failed");
	return (fd);
}

char	*ft_pathenv(char **env, char *key)
{
	int		i;
	char	*pathenv;
	int		len;

	len = ft_strlen(key);
	i = 0;
	while (ft_strncmp(key, env[i], len) != 0)
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

void	ft_one_cmd_exec(char **av, char **env, int *pid, int hd)
{
	char	*pathenv;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;

	pathenv = ft_pathenv(env, "PATH");
	cmd_paths = ft_split(pathenv, ':');
	pid[0] = fork();
	waitpid(pid[0], NULL, WNOHANG);
	if (pid[0] < 0)
		ft_handle_error("fork error");
	if (pid[0] == 0)
	{
		cmd_args = ft_split(av[2 + hd], ' ');
		cmd = ft_getcmd(cmd_paths, cmd_args[0]);
		if (!cmd)
			ft_handle_error("No such command");
		execve(cmd, cmd_args, env);
	}
	exit(0);
}

void	ft_first_proc_exec(char **av, char **env, t_pipex *proc, int hd)
{
	char	*pathenv;
	char	**cmd_paths;
	char	**cmd_args;
	int		i;

	pathenv = ft_pathenv(env, "PATH");
	cmd_paths = ft_split(pathenv, ':');
	i = 0;
	if (pipe(proc->fd[i]) == FAIL)
			ft_handle_error("No pipe generated");
	proc->pid[0] = fork();
	waitpid(proc->pid[0], NULL, WNOHANG);
	if (proc->pid[0] < 0)
		ft_handle_error("fork error");
	if (proc->pid[0] == 0)
	{
		close(proc->fd[0][0]);
		dup2(proc->fd[0][1], STDOUT);
		close(proc->fd[0][1]);
		cmd_args = ft_split(av[2 + hd], ' ');
		proc->cmd = ft_getcmd(cmd_paths, cmd_args[0]);
		if (!proc->cmd)
			ft_handle_error("No such command");
		execve(proc->cmd, cmd_args, env);
	}
}

void	ft_piping_setting(t_pipex *proc, int i)
{
	close(proc->fd[i][1]);
	dup2(proc->fd[i][0], STDIN);
	close(proc->fd[i][0]);
	if (i + 1 < proc->num - 1)
	{
		close(proc->fd[i + 1][0]);
		dup2(proc->fd[i + 1][1], STDOUT);
		close(proc->fd[i + 1][1]);
	}
}

void	ft_multi_child_proc(char **av, char **env, t_pipex *proc, int i)
{
	char	*pathenv;
	char	**cmd_paths;
	char	**cmd_args;

	pathenv = ft_pathenv(env, "PATH");
	cmd_paths = ft_split(pathenv, ':');
	ft_piping_setting(proc, i);
	cmd_args = ft_split(av[3 + proc->hd + i], ' ');
	proc->cmd = ft_getcmd(cmd_paths, cmd_args[0]);
	if (!proc->cmd)
		ft_handle_error("No such command");
	execve(proc->cmd, cmd_args, env);
}

void	ft_multi_cmd_exec(char **av, char **env, t_pipex *proc)
{
	int		i;
	int		next_pipe;

	ft_first_proc_exec(av, env, proc, proc->hd);
	i = 0;
	next_pipe = OFF;
	while (i < proc->num - 1)
	{
		if (i + 1 < proc->num - 1)
		{
			next_pipe = ON;
			if (pipe(proc->fd[i + 1]) == FAIL)
				ft_handle_error("No pipe generated");
		}
		proc->pid[i + 1] = fork();
		if (proc->pid[i + 1] < 0)
			ft_handle_error("No fork generated");
		if (proc->pid[i + 1] == 0)
		ft_multi_child_proc(av, env, proc, i);
		close(proc->fd[i][0]);
		close(proc->fd[i][1]);
		i++;
	}
}

void	ft_heredoc(int ac, char **av, t_pipex *proc)
{
	char	*limiter;
	char	buff;
	char	*line;
	int		doc_fd;

	proc->hd = ON;
	limiter = av[2];
	buff = '\0';
	if (!limiter)
		ft_handle_error("No limiter error");
	doc_fd = ft_fileopen("/tmp/.here_doc", OUTFILE);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 2);
		line = get_next_line(0);
		if (!line)
			ft_handle_error("\nUnexpected EOF");
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break;
		ft_putstr_fd(line, doc_fd);
	}
	if (ac == 3)
		exit(0);
}

void	ft_heredoc_setting(int ac, char **av, t_info *file)
{
	file->out = av[ac - 1];
	file->fdin = ft_fileopen("/tmp/.here_doc", INFILE);
	file->fdout = ft_fileopen(file->out, APPD_OUT);
}

void	ft_no_heredoc_set(int ac, char **av, t_info *file)
{
	file->in = av[1];
	file->out = av[ac - 1];
	file->fdin = ft_fileopen(file->in, INFILE);
	file->fdout = ft_fileopen(file->out, OUTFILE);
}

void	ft_proc_free(t_pipex *proc)
{
	int		i;

	i = 0;
	while (i < proc->num - 1 - proc->hd)
	{
		free(proc->fd[i]);
		i++;
	}
	free(proc->fd);
	free(proc->pid);
}

void	ft_case_by(int ac, char **av, t_info *file, t_pipex *proc)
{
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		ft_heredoc(ac, av, proc);
	if (proc->hd == ON)
		ft_heredoc_setting(ac, av, file);
	else
		ft_no_heredoc_set(ac, av, file);
}

int	main(int ac, char **av, char **env)
{
	t_info	file;
	t_pipex	proc;
	int		i;

	proc.num = ac - 3;
	proc.hd = OFF;
	ft_case_by(ac, av, &file, &proc);
	dup2(file.fdin, STDIN);
	dup2(file.fdout, STDOUT);
	proc.fd = (int **)malloc(sizeof(int *) * (proc.num - 1 - proc.hd));
	i = -1;
	while (++i < proc.num - 1 - proc.hd)
		proc.fd[i] = (int *)malloc(sizeof(int) * 2);
	proc.pid = (int *)malloc(sizeof(int) * (proc.num - proc.hd));
	if (proc.num == 0)
		ft_handle_error("No command");
	if (proc.num == 1 + proc.hd)
		ft_one_cmd_exec(av, env, proc.pid, proc.hd);
	if (proc.num >= 2 + proc.hd)
		ft_multi_cmd_exec(av, env, &proc);
	ft_proc_free(&proc);
	return (0);
}
