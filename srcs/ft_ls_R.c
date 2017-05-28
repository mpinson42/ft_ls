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

int		print_ft_rr(t_glob *g, char *str,
	struct dirent	*fichierlu[ft_test(str) + 1])
{
	int i;

	i = -1;
	while (fichierlu[++i] != NULL && g->flag_d == 0 &&
		ft_non(str, fichierlu, i) == 0)
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

int		print_ft_rr2(t_glob *g, char *str,
	struct dirent	*fichierlu[ft_test(str) + 1])
{
	int i;

	i = ft_test(str);
	while (i >= 0 && fichierlu[--i] != NULL && g->flag_d == 0)
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

void	ft_cast(char *str, t_glob *g,
	struct dirent	*fichierlu[ft_test(str) + 1])
{
	int j;

	j = 0;
	while (fichierlu[j] != NULL)
		j++;
	j--;
	while (j >= 0 && g->flag_r == 1 && fichierlu[j] != NULL
		&& g->flag_d == 0 &&
		ft_strncmp(fichierlu[j]->d_name, "man", 3) != 0)
	{
		if (ft_non(str, fichierlu, j) == 0)
			recur_ft_rr(str, fichierlu, g, j);
		j--;
	}
	j = 0;
	while (g->flag_r == 0 && fichierlu[j] != NULL && g->flag_d == 0 &&
		ft_strncmp(fichierlu[j]->d_name, "man", 3) != 0)
	{
		if (ft_non(str, fichierlu, j) == 0)
			recur_ft_rr(str, fichierlu, g, j);
		j++;
	}
}

int		ft_rr(char *str, t_glob *g)
{
	DIR				*rep;
	struct dirent	*fichierlu[ft_test(str) + 1];
	int				j;
	char			*test[2];

	rep = NULL;
	if (err_ft_rr(str, g, &rep) == 0)
		return (0);
	assigne_ft_rr(str, &fichierlu, g, &rep);
	if (g->flag_f == 0)
		ft_trie(str, &fichierlu);
	if (g->flag_t == 1 || g->flag_g == 1)
		ft_t(str, &fichierlu, g);
	if (g->flag_r == 1)
		print_ft_rr2(g, str, fichierlu);
	else
		print_ft_rr(g, str, fichierlu);
	ft_cast(str, g, fichierlu);
	closedir(rep);
	return (0);
}
