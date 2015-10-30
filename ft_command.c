/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:41:59 by ahua              #+#    #+#             */
/*   Updated: 2015/07/28 12:42:03 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_command(char **arg, t_list **env)
{
	if (!arg[0])
		return (1);
	if (ft_strcmp(arg[0], "env") == 0)
		ft_env(env);
	else if (ft_strcmp(arg[0], "setenv") == 0)
		ft_setenv(arg, env);
	else if (ft_strcmp(arg[0], "unsetenv") == 0)
		ft_unsetenv(arg, env);
	else if (ft_strcmp(arg[0], "exit") == 0)
		ft_exit(arg);
	else if (ft_strcmp(arg[0], "cd") == 0)
		ft_cd(arg, env);
	else
		return (0);
	return (1);
}

void	ft_exit(char **arg)
{
	if (arg[1])
		exit(ft_atoi(arg[1]));
	exit(0);
}

t_elem	*good_var(t_list *env, char *key)
{
	t_elem			*var;
	t_list			*tmp;
	static t_elem	*no_var;

	if (!(no_var = (t_elem *)malloc(sizeof(*no_var))))
		return (NULL);
	no_var->key = NULL;
	no_var->data = NULL;
	tmp = env;
	if (env)
		var = tmp->content;
	while (env && tmp && ft_strcmp(var->key, key))
	{
		tmp = tmp->next;
		if (tmp)
			var = tmp->content;
	}
	if (!env || !tmp)
		return (no_var);
	return (var);
}
