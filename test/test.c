#include "../prototype00/libft/libft.h"
#include "error.h"
#include <stdio.h>    // perror
#include <stdlib.h>   // exit
#include <string.h>   //strerror
#include <sys/wait.h> // wait, wautpid
#include <unistd.h>   // access, dup, dup2, execve, fork, unlink

char	**find_path(char **envp)
{
	while (**envp)
	{
		if (strncmp("PATH=", *envp, 5) == 0)
		{
			return (ft_split(*envp, ':'));
		}
		envp++;
	}
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	char **mem = find_path(envp);
	int i = 0;

	while (mem[i])
	{
		printf("%s\n", mem[i]);
		mem++;
	}
	return (EXIT_SUCCESS);
}