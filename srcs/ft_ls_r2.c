/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_r2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:07:33 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/27 14:07:36 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_test(char *str)
{
	int				i;
	struct dirent	*fichierlu[2];
	DIR				*rep;

	i = 0;
	rep = NULL;
	if (str == NULL || !(rep = opendir(str)))
		return (0);
	while ((fichierlu[0] = readdir(rep)) != NULL)
		i++;
	closedir(rep);
	return (i);
}

int		ft_poid(char *str, char *str2)
{
	struct stat		s;
	char			*test;

	if (!(test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	return (s.st_blocks);
}

int		ft_test2(char *str, t_glob *g)
{
	int				i;
	int				rendu;
	DIR				*rep;
	struct dirent	*fichierlu[ft_test(str) + 1];

	i = 0;
	rendu = 0;
	rep = NULL;
	if (str == NULL || !(rep = opendir(str)))
		return (0);
	while ((fichierlu[i] = readdir(rep)) != NULL)
	{
		if (fichierlu[i]->d_name[0] != '.' || g->flag_a == 1)
			rendu += ft_poid(str, fichierlu[i]->d_name);
		i++;
	}
	closedir(rep);
	return (rendu);
}

int		err_ft_rr(char *str, t_glob *g, DIR **rep)
{
	if (g->flag_d == 1)
		ft_affiche("./", str, g);
	ft_putendl(str);
	if (str == NULL || !(rep[0] = opendir(str)))
	{
		if (ft_strcmp(strerror(errno), "Not a directory") != 0)
		{
			perror("");
			ft_putstr("\n\n");
		}
		return (0);
	}
	if (g->flag_l == 1 && ft_strcmp(str, "/dev") != 0 && g->flag_d == 0)
	{
		ft_putstr("total : ");
		ft_putnbr(ft_test2(str, g));
		ft_putchar('\n');
	}
	if (g->flag_l == 1 && ft_strcmp(str, "/dev") == 0 && g->flag_d == 0)
		ft_putstr("total : 0\n");
	return (1);
}
