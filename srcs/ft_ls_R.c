/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_R.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:45:48 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 20:22:52 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	assigne_ft_rr(char *str,
	struct dirent *(*fichierlu)[ft_test(str) + 1], t_glob *g, DIR **rep)
{
	int i;

	i = -1;
	while ((fichierlu[0][++i] = readdir(rep[0])) != NULL)
	{
		if (ft_max_l(str, fichierlu[0][i]->d_name) > g->max_lien)
			g->max_lien = ft_max_l(str, fichierlu[0][i]->d_name);
		if (ft_max_size(str, fichierlu[0][i]->d_name) > g->max_size)
			g->max_size = ft_max_size(str, fichierlu[0][i]->d_name);
		if (ft_max_name(str, fichierlu[0][i]->d_name) > g->max_name)
			g->max_name = ft_max_name(str, fichierlu[0][i]->d_name);
		if (ft_max_name(str, fichierlu[0][i]->d_name) < g->min_name)
			g->min_name = ft_max_name(str, fichierlu[0][i]->d_name);
		if (ft_max_group(str, fichierlu[0][i]->d_name) > g->max_group)
			g->max_group = ft_max_group(str, fichierlu[0][i]->d_name);
		if (ft_max_dev(str, fichierlu[0][i]->d_name) > g->max_dev)
			g->max_dev = ft_max_dev(str, fichierlu[0][i]->d_name);
		if (ft_max_dev4(str, fichierlu[0][i]->d_name) > g->max_dev2)
			g->max_dev2 = ft_max_dev4(str, fichierlu[0][i]->d_name);
	}
}

int		print_ft_rr(t_glob *g, char *str,
	struct dirent	*fichierlu[ft_test(str) + 1])
{
	int i;

	i = -1;
	while (fichierlu[++i] != NULL && g->flag_d == 0)
	{
		if ((fichierlu[i]->d_name[0] != '.' ||
					g->flag_a == 1) && g->flag_l == 0)
		{
			ft_color(str, fichierlu[i]->d_name);
			ft_putendl(fichierlu[i]->d_name);
			write(1, "\e[0;m", 6);
		}
		else if ((fichierlu[i]->d_name[0] != '.' || g->flag_a == 1) &&
				g->flag_l == 1 && str != NULL &&
				ft_isprint(fichierlu[i]->d_name[0]) &&
				is_open(str, fichierlu[i]->d_name) != -1)
		{
			ft_affiche(str, fichierlu[i]->d_name, g);
			ft_color(str, fichierlu[i]->d_name);
			ft_putendl(fichierlu[i]->d_name);
			write(1, "\e[0;m", 6);
		}
	}
	return (i);
}

int		testyolo(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	recur_ft_rr(char *str,
	struct dirent	*fichierlu[ft_test(str) + 1], t_glob *g, int j)
{
	char *test[2];

	if (fichierlu[j] != NULL && (fichierlu[j]->d_type == 4 ||
				fichierlu[j]->d_type == 10) && fichierlu[j]->d_type != 8 &&
			ft_strcmp(fichierlu[j]->d_name, ".") != 0 &&
			ft_strcmp(fichierlu[j]->d_name, "..") != 0 &&
			(fichierlu[j]->d_name[0] != '.' || g->flag_a == 1))
	{
		ft_putstr("\n\n");
		if (str[0] == '/' && str[1] == 0)
		{
			test[0] = ft_strjoin(str, fichierlu[j]->d_name);
			ft_rr(test[0], g);
			free(test[0]);
		}
		else
		{
			test[0] = ft_strjoin(str, "/");
			test[1] = ft_strjoin(test[0], fichierlu[j]->d_name);
			free(test[0]);
			if (testyolo(str) == 0)
				ft_rr(test[1], g);
			free(test[1]);
		}
	}
}

int		ft_rr(char *str, t_glob *g)
{
	DIR				*rep;
	struct dirent	*fichierlu[ft_test(str) + 1];
	int				j;
	char			*test[2];

	j = 0;
	rep = NULL;
	if (err_ft_rr(str, g, &rep) == 0)
		return (0);
	assigne_ft_rr(str, &fichierlu, g, &rep);
	if (g->flag_f == 0)
		ft_trie(str, &fichierlu);
	if (g->flag_t == 1 || g->flag_g == 1)
		ft_t(str, &fichierlu, g);
	if (g->flag_r == 1)
		ft_r(str, &fichierlu, 0);
	print_ft_rr(g, str, fichierlu);
	while (fichierlu[j] != NULL && g->flag_d == 0)
	{
		recur_ft_rr(str, fichierlu, g, j);
		j++;
	}
	closedir(rep);
	return (0);
}
