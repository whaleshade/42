/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:56:50 by jibang            #+#    #+#             */
/*   Updated: 2022/06/26 21:15:00 by jibang           ###   ########.fr       */
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
		cmd_args = ft_split(av[2 + hd], ' '); //av[2 + j]로 한다음 j값을 정해줘야함.
		cmd = ft_getcmd(cmd_paths, cmd_args[0]);
		if (!cmd)
			ft_handle_error("No such command");
		execve(cmd, cmd_args, env);
	}
	exit(0);
}

void	ft_multi_cmd_exec(char **av, char **env, t_pipex *proc, int hd)
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

	i = 0;
	int		next_pipe = OFF;
	while (i < proc->num - 1)
	{
		//다음 파이프를 미리 만들어놔야하는지 체크
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
		{
			//파이프로부터 받아옴
			close(proc->fd[i][1]);
			dup2(proc->fd[i][0], STDIN);
			close(proc->fd[i][0]);
			//다음 파이프 있는지 체크하고 다음 파이프에 데이터 건네줌
			if (i + 1 < proc->num - 1)
			{
				close(proc->fd[i + 1][0]);
				dup2(proc->fd[i + 1][1], STDOUT);
				close(proc->fd[i + 1][1]);
			}
			//명령어 실행
			cmd_args = ft_split(av[3 + hd + i], ' ');
			proc->cmd = ft_getcmd(cmd_paths, cmd_args[0]);
			if (!proc->cmd)
				ft_handle_error("No such command");
			execve(proc->cmd, cmd_args, env);
		}
		close(proc->fd[i][0]);
		close(proc->fd[i][1]);
		i++;
	}
}


int	main(int ac, char **av, char **env)
{
	t_info	file;
	int		i;
	int		hd;
	t_pipex	proc;



	proc.num = ac - 3;
	/* heredoc 구현 */
	hd = OFF;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		char	*limiter;
		char	buff;
		char	*line;
		int		doc_fd;

		hd = ON;
		limiter = av[2];
		buff = '\0';
		if (!limiter)
			ft_handle_error("No limiter error");
		doc_fd = ft_fileopen(".here_doc", OUTFILE); //나중에 unlink로 파일 삭제해줘야 함.
		while (1)
		{
			ft_putstr_fd("heredoc> ", 2);
			line = get_next_line(0);
			if (!line)
				ft_handle_error("\nUnexpected EOF");
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				break ;
			ft_putstr_fd(line, doc_fd);
		}
		if (ac == 3)
			exit(0);
	}

	if (hd == ON)
	{
		file.out = av[ac - 1];
		file.fdin = ft_fileopen(".here_doc", INFILE);
		file.fdout = ft_fileopen(file.out, APPD_OUT);
	}
	else
	{
		file.in = av[1];
		file.out = av[ac - 1];
		file.fdin = ft_fileopen(file.in, INFILE);
		file.fdout = ft_fileopen(file.out, OUTFILE);
	}

	dup2(file.fdin, STDIN);
	dup2(file.fdout, STDOUT);

	proc.fd = (int **)malloc(sizeof(int *) * (proc.num - 1 - hd));
	i = 0;
	while (i < proc.num - 1 - hd)
	{
		proc.fd[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	/////
	proc.pid = (int *)malloc(sizeof(int) * (proc.num - hd));
	if (proc.num == 0)
		ft_handle_error("No command");
	if (proc.num == 1 + hd)
		ft_one_cmd_exec(av, env, proc.pid, hd);
	if (proc.num >= 2 + hd)
		ft_multi_cmd_exec(av, env, &proc, hd);
	i = 0;
	while (i < proc.num - 1 - hd)
	{
		free(proc.fd[i]);
		i++;
	}
	free(proc.fd);
	free(proc.pid);


	/* unlink fixing .. */
	/////.here_doc 파일을 /temp/.here_doc에 저장하는 방법도 있음
	// char	*pathenv;
	// char	**paths;
	// char	*to_be_deleted;

	// pathenv = ft_pathenv(env, "PWD");
	// paths = ft_split(pathenv, ':');
	// //ft_getcmd(paths, args[0]);
	// to_be_deleted = ft_strjoin(paths[0], "/.here_doc");
	// ft_putstr_fd("\n", 2);
	// ft_putstr_fd("test1 : ", 2);
	// ft_putstr_fd(to_be_deleted, 2);
	// ft_putstr_fd("\n", 2);

	// if (unlink(to_be_deleted) != 0)
	// 	ft_handle_error("unlink error");
	// 	close(file.fdin);
	// close(file.fdout);
	return (0);
}
