/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 13:48:18 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/21 13:48:20 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_liber(t_glob *g)
{
	free(g->path);
}

int	main(int argc, char **argv)
{
	t_glob g;
	DIR *rep = NULL;
	int i;

	i = 0;
	ft_bzero(&g, sizeof(t_glob));
	if(edit(&g, argc, argv) == -1)
		return (0);
	while (i < g.leng_path)
	{
		if(i != 0)
			printf("\n");
		if(g.flag_gr == 1)
		{
			//printf("%s\n", g.path[i]);
			ft_R(g.path[i], &g);
		}
		else if(g.flag_gr == 0 && g.flag_l == 0)
			ft_ls(&g, g.path[i]);
		else if(g.flag_gr == 0 && g.flag_l == 1)
			ft_ls_l(g.path[i], &g);
		i++;
	}
	//printf("iy,t\n");
	ft_liber(&g);
//	while(1);
	return (0);
}
