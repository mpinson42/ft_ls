/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:45:41 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 14:46:31 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_link(char *str, char *str2)
{
	t_aff	a;
	char	dest[100];

	a.test2 = str;
	ft_putstr(str2);
	ft_putstr(" -> ");
	ft_bzero(dest, 100);
	if (!(a.test = ft_strjoin(str, "/")))
		return ;
	if (!(str = ft_strjoin(a.test, str2)))
	{
		free(a.test);
		return ;
	}
	free(a.test);
	readlink(str, dest, 100);
	ft_putendl(dest);
	free(str);
}

int		is_link(char *str, char *str2)
{
	t_aff a;

	a.test2 = str;
	if (!(a.test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(a.test, str2)))
	{
		free(a.test);
		return (-1);
	}
	free(a.test);
	if (lstat(str, &a.s) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	if (S_ISLNK(a.s.st_mode))
		return (1);
	return (0);
}

void	ft_color(char *str, char *str2)
{
	struct stat	s;
	char		*test;

	if (!(test = ft_strjoin(str, "/")))
		return ;
	if (!(str = ft_strjoin(test, str2)))
		return ;
	free(test);
	if (lstat(str, &s) == -1)
	{
		free(str);
		return ;
	}
	free(str);
	if (S_ISREG(s.st_mode) && s.st_mode & S_IXUSR &&
		s.st_mode & S_IXGRP && s.st_mode & S_IXOTH)
		write(1, "\e[0;31m", 8);
	else if (S_ISDIR(s.st_mode))
		write(1, "\e[1;36m", 8);
	else if (S_ISLNK(s.st_mode))
		write(1, "\e[0;35m", 8);
	else if (S_ISBLK(s.st_mode))
		write(1, "\e[0;34m", 8);
	else if (S_ISCHR(s.st_mode))
		write(1, "\e[1;33m", 8);
}

void	ft_loop_1(t_glob *g, char *str,
	struct dirent *fichierlu[ft_test(str) + 1])
{
	int i;

	i = -1;
	while (fichierlu[++i] != NULL && g->flag_d == 0)
	{
		if ((fichierlu[i]->d_name[0] != '.' || g->flag_a == 1) &&
			ft_isprint(fichierlu[i]->d_name[0]) &&
			is_open(str, fichierlu[i]->d_name) != -1 &&
			ft_non(str, fichierlu, i) == 0)
		{
			ft_color(str, fichierlu[i]->d_name);
			ft_putendl(fichierlu[i]->d_name);
			write(1, "\e[0;m", 6);
		}
	}
}

void	ft_ls(t_glob *g, char *str)
{
	DIR				*rep;
	struct dirent	*fichierlu[ft_test(str) + 1];
	int				i;

	i = 0;
	rep = NULL;
	if (str == NULL || !(rep = opendir(str)))
		return ;
	while ((fichierlu[i] = readdir(rep)) != NULL)
		i++;
	if (g->flag_f == 0)
		ft_trie(str, &fichierlu);
	if (g->flag_t == 1 || g->flag_g == 1)
		ft_t(str, &fichierlu, g);
	if (g->flag_r == 1)
		ft_r(str, &fichierlu, i - 1);
	ft_loop_1(g, str, fichierlu);
	closedir(rep);
}
