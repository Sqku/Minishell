/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:42:28 by ahua              #+#    #+#             */
/*   Updated: 2015/07/28 12:42:31 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_unsetenv(char **arg, t_list **env)
{
	int		i;

	if (!arg[1])
		ft_putstr("unsetenv: Too few arguments.\n");
	else
	{
		i = 1;
		while (arg[i])
		{
			del_list(env, arg[i]);
			i++;
		}
	}
}

void	del_list(t_list **env, char *arg)
{
	t_elem		*elem;
	t_list		*tmp;
	t_list		*del;

	tmp = *env;
	elem = tmp->content;
	if (!ft_strcmp(elem->key, arg))
	{
		*env = tmp->next;
		free_env_list(tmp);
		return ;
	}
	while (tmp->next && ft_strcmp(elem->key, arg))
	{
		elem = tmp->next->content;
		if (ft_strcmp(elem->key, arg))
			tmp = tmp->next;
		else
			break ;
	}
	if (!tmp->next)
		return ;
	del = tmp->next;
	tmp->next = del->next;
	free_env_list(del);
}

void	free_env_list(t_list *del)
{
	free(del->content);
	free(del);
}
