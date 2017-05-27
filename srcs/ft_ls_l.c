/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:45:53 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 19:21:49 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap(struct dirent **a, struct dirent **b)
{
	struct dirent *c;
	struct dirent *d;

	c = *a;
	d = *b;
	*a = d;
	*b = c;
}

void	*ft_trie(char *str, struct dirent *(*fichierlu)[ft_test(str) + 1])
{
	int i;
	int bol;
	int y;

	bol = 0;
	while (bol == 0)
	{
		bol = 1;
		i = -1;
		while (fichierlu[0][++i + 1] != NULL)
		{
			y = -1;
			while (fichierlu[0][i]->d_name[y + 1] != 0
				&& fichierlu[0][i + 1]->d_name[y + 1] != 0)
			{
				if (fichierlu[0][i]->d_name[0] > fichierlu[0][i + 1]->d_name[0])
				{
					ft_swap(&fichierlu[0][i], &fichierlu[0][i + 1]);
					bol = 0;
				}
				y++;
			}
		}
	}
	return (fichierlu);
}

void	ft_assigne_l(DIR *rep, char *str,
	struct dirent *(*fichierlu)[ft_test(str) + 1], t_glob *g)
{
	int i;

	i = 0;
	while ((fichierlu[0][i] = readdir(rep)) != NULL)
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
		i++;
	}
	if (g->flag_f == 0)
		ft_trie(str, fichierlu);
	if (g->flag_t == 1 || g->flag_g == 1)
		ft_t(str, fichierlu, g);
}

void	go_print(char *str,
	struct dirent *fichierlu[ft_test(str) + 1], t_glob *g)
{
	int i;

	i = -1;
	if (g->flag_d == 1)
	{
		ft_affiche("./", fichierlu[i]->d_name, g);
		ft_putendl(fichierlu[i]->d_name);
	}
	while (fichierlu[++i] != NULL && g->flag_d == 0)
	{
		if (fichierlu[i]->d_name[0] != '.' || g->flag_a == 1)
		{
			if (ft_isprint(fichierlu[i]->d_name[0])
				&& is_open(str, fichierlu[i]->d_name) != -1)
			{
				ft_affiche(str, fichierlu[i]->d_name, g);
				ft_color(str, fichierlu[i]->d_name);
				ft_putendl(fichierlu[i]->d_name);
				write(1, "\e[0;m", 6);
			}
		}
	}
}

void	ft_ls_l(char *str, t_glob *g)
{
	DIR				*rep;
	struct dirent	*fichierlu[ft_test(str) + 1];
	struct dirent	*c[3];

	rep = NULL;
	if (str == NULL || !(rep = opendir(str)))
	{
		ft_color(str, fichierlu[0]->d_name);
		ft_putendl(str);
		write(1, "\e[0;m", 6);
		return ;
	}
	if (ft_strcmp(str, "/dev") != 0 && g->flag_d == 0)
	{
		ft_putstr("total : ");
		ft_putnbr(ft_test2(str, g));
		ft_putchar('\n');
	}
	if (ft_strcmp(str, "/dev") == 0 && g->flag_d == 0)
		ft_putstr("total : 0\n");
	ft_assigne_l(rep, str, &fichierlu, g);
	if (g->flag_r == 1)
		ft_r(str, &fichierlu, 0);
	go_print(str, fichierlu, g);
	closedir(rep);
}
