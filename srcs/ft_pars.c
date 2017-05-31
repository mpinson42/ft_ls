/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:46:12 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 15:05:33 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_non(char *str, struct dirent	*fichierlu[ft_test(str) + 1], int j)
{
	if (ft_strcmp(fichierlu[j]->d_name, fichierlu[j - 1]->d_name) == 0)
		return (1);
	return (0);
}

int		ft_assigne(char **argv, int i, int x, t_glob *g)
{
	if (argv[i][x] == 'R')
		g->flag_gr = 1;
	else if (argv[i][x] == 'r')
		g->flag_r = 1;
	else if (argv[i][x] == 'l')
		g->flag_l = 1;
	else if (argv[i][x] == 'a')
		g->flag_a = 1;
	else if (argv[i][x] == 't')
		g->flag_t = 1;
	else if (argv[i][x] == 'f')
		g->flag_f = 1;
	else if (argv[i][x] == 'g')
		g->flag_g = 1;
	else if (argv[i][x] == 'd')
		g->flag_d = 1;
	else
	{
		ft_putstr("usage: ./ft_ls [-adfglrRt] [file ...]\n");
		return (-1);
	}
	return (0);
}

void	pars(int i, t_glob *g, int argc, char **argv)
{
	int j;

	j = 0;
	g->leng_path = argc - i;
	if (i == argc)
	{
		g->leng_path = 1;
		g->path[0] = ".";
	}
	else
	{
		while (i < argc)
			g->path[j++] = argv[i++];
	}
}

int		edit(t_glob *g, int argc, char **argv)
{
	int i;
	int x;

	i = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		x = 0;
		while (argv[i][++x])
		{
			if(ft_strncmp(argv[i], "--", 2) == 0)
				break;
			if (ft_assigne(argv, i, x, g) == -1)
				return (-1);
		}
	}
	if (!(g->path = (char **)malloc(sizeof(char *) * (argc - i))))
		return (-1);
	pars(i, g, argc, argv);
	return (0);
}
