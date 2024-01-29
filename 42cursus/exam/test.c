sys/wait.h
string.h
unistd.h

pront 2 "",arg
\n
return 1

excute

arg[i] = NULL
input->tmp_fd
close
excute
return excuteErrer "",arg[0]

int main(int argc, char *argv[], env)
{
	i
	tmp
	fd[2]
	i = 0
	tmp = dup STDIN_FILENO
	while(arg[i] && arg[i+1])
	{
		arg = arg[i+1]
		i = 0
		while(arg[i] || strcmp(arg[i] ';') || strcmp(arg[i] '|'))
			i++
		if (strcmp(argv[0], "cd") == 0) //cd
		{
			if (i != 2)
				ft_putstr_fd2("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				ft_putstr_fd2("error: cd: cannot change directory to ", argv[1]	);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0)) //exec in stdout
		{
			if ( fork() == 0)
			{
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if(i != 0 && strcmp(argv[i], "|") == 0) //pipe
		{
			pipe(fd);
			if ( fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp)


	return 0;
}
