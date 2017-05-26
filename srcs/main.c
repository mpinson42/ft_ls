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
			ft_R(g->path[i], g);
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
	system("leaks ft_ls");
	return (0);
}
