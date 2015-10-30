/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:41:43 by ahua              #+#    #+#             */
/*   Updated: 2015/07/28 12:41:53 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	test_exist_d(char *name)
{
	DIR				*dirp;

	dirp = opendir(name);
	if (dirp == NULL)
		return (0);
	closedir(dirp);
	return (1);
}

static int	if_cd_1(char **argv, t_elem *old, t_elem *pwd)
{
	char	*mem;

	if (!ft_strcmp(argv[1], "..") && !ft_strcmp(pwd->data, "/"))
		old->data = pwd->data;
	else if (!ft_strcmp(argv[1], "..") && !ft_strcmp(pwd->data, "/nfs"))
	{
		old->data = pwd->data;
		pwd->data = ft_strdup("/");
	}
	else if (!ft_strcmp(argv[1], ".."))
	{
		old->data = pwd->data;
		pwd->data = ft_strrcut(pwd->data, '/');
	}
	else if (!ft_strcmp(argv[1], "-"))
	{
		mem = ft_strdup(old->data);
		old->data = pwd->data;
		pwd->data = mem;
	}
	else if (!ft_strcmp(argv[1], "."))
		old->data = pwd->data;
	else
		return (0);
	return (1);
}

static int	if_cd_2(char **argv, t_elem *old, t_elem *pwd,
	t_elem *home)
{
	if (argv[1][0] == '~')
	{
		old->data = pwd->data;
		pwd->data = ft_burger(home->data, '/', &argv[1][1]);
	}
	else if (argv[1][0] == '/' && test_exist_d(argv[1]))
	{
		old->data = pwd->data;
		pwd->data = argv[1];
	}
	else if (!test_cd(argv[1]))
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putstr(argv[1]);
		ft_putchar('\n');
	}
	else
		return (0);
	return (1);
}

void		ft_cd(char **arg, t_list **env)
{
	t_elem	*old;
	t_elem	*pwd;
	t_elem	*home;

	old = good_var(*env, "OLDPWD");
	pwd = good_var(*env, "PWD");
	home = good_var(*env, "HOME");
	if ((!arg[1]) || (!ft_strcmp(arg[1], "HOME")))
	{
		old->data = pwd->data;
		pwd->data = home->data;
	}
	else if (if_cd_1(arg, old, pwd))
		;
	else if (if_cd_2(arg, old, pwd, home))
		;
	else
	{
		old->data = pwd->data;
		pwd->data = ft_burger(pwd->data, '/', arg[1]);
	}
	if ((!pwd->data) || (!ft_strcmp(pwd->data, "")))
		pwd->data = ft_strdup("/");
	chdir(pwd->data);
}

int			test_cd(char *path)
{
	DIR *dirp;

	dirp = opendir(path);
	if (dirp == NULL)
		return (0);
	(void)closedir(dirp);
	return (1);
}
