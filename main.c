/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:42:45 by ahua              #+#    #+#             */
/*   Updated: 2015/07/28 12:42:47 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		exec(char **argv, t_list *env)
{
	pid_t		father;
	t_elem		*var;
	char		*gp;

	var = good_var(env, "PATH");
	gp = good_path(argv[0], var);
	if (gp)
	{
		father = fork();
		if (father > 0)
			waitpid(father, 0, 0);
		else if (father == 0)
		{
			if (execve(gp, argv, env_to_str(env)) < 0)
			{
				ft_putstr("exec format error: ");
				ft_putstr(argv[1]);
				ft_putstr("\n");
				exit(2);
			}
		}
	}
	return (0);
}

int		main(int ac, char **av, char **envp)
{
	t_list	*env;
	char	*line;
	char	**argv;

	(void)ac;
	(void)av;
	env = get_env(envp);
	while (42)
	{
		ft_putstr("ft_minishell1_$> ");
		get_next_line(0, &line);
		argv = ft_strsplit(ft_strtrim(line), ' ');
		if (!ft_command(argv, &env))
			exec(argv, env);
	}
	return (0);
}
