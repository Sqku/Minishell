/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:43:55 by ahua              #+#    #+#             */
/*   Updated: 2015/07/28 12:51:11 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

typedef struct	s_elem
{
	char	*key;
	char	*data;
}				t_elem;

t_list			*get_env(char **envp);
void			ft_env(t_list **env);
int				ft_isspace(char c);
char			*ft_trim(char *s);
int				ft_command(char **arg, t_list **env);
int				valid_arg(char *arg);
void			ft_setenv(char **arg, t_list **env);
void			ft_unsetenv(char **arg, t_list **env);
void			del_list(t_list **env_list, char *key);
void			free_env_list(t_list *del);
void			ft_exit(char **arg);
void			ft_cd(char **arg, t_list **env);
int				test_cd(char *path);
t_elem			*good_var(t_list *env, char *key);
char			*ft_burger(const char *s1, char c, const char *s2);
char			*ft_strrcut(char *str, char c);
char			*ft_strcut(char *str, char c);
char			*print_error(char *name);
char			*good_path(char *name, t_elem *var);
char			**env_to_str(t_list *env);
int				exec(char **argv, t_list *env);
void			ft_setenv_1(char **arg, t_list **env);
char			*good_path_2(char *name, char *path);
int				test_exist(char *name);
char			*print_error_path(char *path, char *name);
void			good_path_bis(char **path);

#endif
