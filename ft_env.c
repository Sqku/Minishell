/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:43:03 by ahua              #+#    #+#             */
/*   Updated: 2015/07/28 12:43:06 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	*get_env(char **envp)
{
	int		i;
	t_elem	*elem;
	char	*ptr;
	t_list	*env;

	elem = malloc(sizeof(t_elem));
	env = NULL;
	i = 0;
	while (envp[i])
	{
		ptr = ft_strchr(envp[i], '=');
		elem->key = ft_strsub(envp[i], 0, ptr - envp[i]);
		elem->data = ft_strdup(ptr + 1);
		ft_lstsmartpushback(&env, ft_lstnew(elem, sizeof(t_elem)));
		i++;
	}
	return (env);
}

void	ft_env(t_list **env)
{
	t_list *tmp;

	tmp = *env;
	while (tmp)
	{
		ft_putstr(((t_elem *)tmp->content)->key);
		ft_putchar('=');
		ft_putstr(((t_elem *)tmp->content)->data);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

char	**env_to_str(t_list *env)
{
	t_list		*tmp;
	char		**env_str;
	int			i;
	t_elem		*var;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!(env_str = malloc(sizeof(char **) * i + 1)))
		return (NULL);
	env_str[i] = 0;
	i = 0;
	while (env)
	{
		var = env->content;
		env_str[i] = ft_burger(var->key, '=', var->data);
		i++;
		env = env->next;
	}
	return (env_str);
}
