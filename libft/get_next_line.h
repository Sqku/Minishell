/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:15:04 by ahua              #+#    #+#             */
/*   Updated: 2015/11/25 15:15:29 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 8

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);

typedef struct	s_gnl
{
	t_list		*lst;
	char		*pos;
}				t_gnl;

#endif
