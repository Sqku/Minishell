/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:43:29 by ahua              #+#    #+#             */
/*   Updated: 2015/07/28 12:43:31 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_burger(const char *s1, char c, const char *s2)
{
	char	*ret;
	char	*tmp;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	tmp = ret;
	if (!ret)
		exit(1);
	while (*s1)
		*tmp++ = *s1++;
	*tmp++ = c;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = 0;
	return (ret);
}

char	*ft_strrcut(char *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (!c)
		return (str);
	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] && str[i] != c)
		i--;
	if (i == -1)
		return (str);
	ret = malloc((sizeof(char) * i));
	ret[i] = 0;
	while (i--)
		ret[i] = str[i];
	return (ret);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

char	*ft_trim(char *s)
{
	int		start;
	char	*ret;
	int		len;

	start = 0;
	while (ft_isspace(s[start]))
		start++;
	len = ft_strlen(s) - 1;
	while (ft_isspace(s[len]))
		len--;
	ret = ft_strsub(s, start, len - start + 1);
	return (ret);
}

char	*ft_strcut(char *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (!c)
		return (str);
	while (str[i] && str[i] != c)
		i++;
	ret = malloc((sizeof(char) * i) + 1);
	ret[i] = 0;
	while (i--)
		ret[i] = str[i];
	return (ret);
}
