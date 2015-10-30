/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 16:18:57 by ahua              #+#    #+#             */
/*   Updated: 2015/05/10 16:19:05 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstdelnode(t_list **node)
{
	if ((*node)->next != NULL)
	{
		(*node)->content = (*node)->next->content;
		(*node)->content_size = (*node)->next->content_size;
		(*node)->next = (*node)->next->next;
	}
	else
		*node = NULL;
}
