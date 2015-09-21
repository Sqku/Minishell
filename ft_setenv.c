/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:43:15 by ahua              #+#    #+#             */
/*   Updated: 2015/07/28 12:43:17 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		valid_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	ft_setenv_1(char **arg, t_list **env)
{
	t_elem	*elem;

	if (valid_arg(arg[1]))
	{
		elem = malloc(sizeof(t_elem));
		elem->key = arg[1];
		elem->data = NULL;
		ft_lstsmartpushback(env, ft_lstnew(elem, sizeof(t_elem)));
	}
	else
		ft_putstr("setenv: Syntax Error.\n");
}

void	ft_setenv(char **arg, t_list **env)
{
	t_elem	*elem;

	if (!arg[1])
		ft_env(env);
	else if (arg[1] && !arg[2])
		ft_setenv_1(arg, env);
	else if (arg[3])
		ft_putstr("setenv: Too many arguments.\n");
	else if (arg[2])
	{
		if (valid_arg(arg[1]))
		{
			elem = malloc(sizeof(t_elem));
			elem->key = arg[1];
			elem->data = arg[2];
			ft_lstsmartpushback(env, ft_lstnew(elem, sizeof(t_elem)));
		}
		else
			ft_putstr("setenv: Syntax Error.\n");
	}
}
