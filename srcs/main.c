/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 13:48:18 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 15:16:54 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap(struct dirent **a, struct dirent **b)
{
	struct dirent *c;
	struct dirent *d;

	c = *a;
	*a = *b;
	*b = c;
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
	g->count = i;
}

void	ft_go(t_glob *g, int i)
{
	DIR		*rep;

	rep = NULL;
	while (++i < g->leng_path)
	{
		if (i != 0)
			ft_putchar('\n');
		if ((rep = opendir(g->path[i])) == NULL)
		{
			if (ft_strcmp(strerror(errno), "Not a directory") != 0)
			{
				perror("");
				continue;
			}
		}
		else
			closedir(rep);
		if (g->flag_gr == 1)
			ft_rr(g->path[i], g);
		else if (g->flag_gr == 0 && g->flag_l == 0)
			ft_ls(g, g->path[i]);
		else if (g->flag_gr == 0 && g->flag_l == 1)
			ft_ls_l(g->path[i], g);
	}
}

int		main(int argc, char **argv)
{
	DIR		*rep;
	t_glob	g;

	rep = NULL;
	ft_bzero(&g, sizeof(t_glob));
	if (edit(&g, argc, argv) == -1)
		return (0);
	ft_go(&g, -1);
	free(g.path);
	return (0);
}
