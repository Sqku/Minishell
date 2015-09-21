/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsmartpushback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 17:58:30 by ahua              #+#    #+#             */
/*   Updated: 2015/05/10 17:58:32 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsmartpushback(t_list **start, t_list *new)
{
	static t_list	*memstart = NULL;
	static t_list	*memend = NULL;

	if (memstart && *start == memstart)
	{
		memend->next = new;
		memend = new;
	}
	else
	{
		ft_lstpushback(start, new);
		memstart = *start;
		memend = new;
	}
}
