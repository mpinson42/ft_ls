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

	ft_bzero(&g, sizeof(t_glob));
	if(edit(&g, argc, argv) == -1)
		return (0);
	if(g.flag_gr == 1)
		ft_R(g.path[0], &g);
	if(g.flag_gr == 0 && g.flag_l == 0)
		ft_ls(&g, g.path[0]);
	if(g.flag_gr == 0 && g.flag_l == 1)
		ft_ls_l(g.path[0], &g);
	//printf("oui\n");
	ft_liber(&g);
	return (0);
}
