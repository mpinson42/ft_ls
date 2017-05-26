/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_R.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:45:48 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 14:45:49 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_test(char *str)
{
	int i;
	struct dirent* fichierLu[2];
	DIR *rep = NULL;

	i = 0;
	if (str == NULL || !(rep = opendir(str)))
		return (0);
	while ((fichierLu[0] = readdir(rep)) != NULL)
    	i++;
    closedir(rep);
    return (i);
}

int ft_test2(char *str, t_glob *g)
{
	int i;
	int rendu;
	DIR *rep = NULL;
	struct dirent* fichierLu[ft_test(str) + 1];

	i = 0;
	rendu = 0;
	if (str == NULL || !(rep = opendir(str)))
		return (0);
	while ((fichierLu[i] = readdir(rep)) != NULL)
	{
		if(fichierLu[i]->d_name[0] != '.' || g->flag_a == 1)
			rendu++;
    	i++;
	}
    closedir(rep);
    return (rendu);
}

int ft_R(char *str, t_glob *g)
{
	DIR *rep = NULL;
	struct dirent* fichierLu[ft_test(str) + 1];
	int i;
	int j;
	char *test;
	char *test2;

	j = 0;
	i = 0;
	if (g->flag_d == 1)
    	ft_affiche("./", str,g);
    ft_putendl(str);
	if (str == NULL || !(rep = opendir(str)))
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
		ft_putchar('\n');;
	}
	if (g->flag_l == 1 && ft_strcmp(str, "/dev") == 0 && g->flag_d == 0)
		ft_putstr("total : 0\n");
	while ((fichierLu[i] = readdir(rep)) != NULL)
	{
		if (ft_max_l(str, fichierLu[i]->d_name) > g->max_lien)
			g->max_lien = ft_max_l(str, fichierLu[i]->d_name);
		if (ft_max_size(str, fichierLu[i]->d_name) > g->max_size)
			g->max_size = ft_max_size(str, fichierLu[i]->d_name);
		if (ft_max_name(str,fichierLu[i]->d_name) > g->max_name)
			g->max_name = ft_max_name(str, fichierLu[i]->d_name);
		if (ft_max_name(str, fichierLu[i]->d_name) < g->min_name)
			g->min_name = ft_max_name(str, fichierLu[i]->d_name);
		if (ft_max_group(str, fichierLu[i]->d_name) > g->max_group)
			g->max_group = ft_max_group(str, fichierLu[i]->d_name);
		if (ft_max_dev(str, fichierLu[i]->d_name) > g->max_dev)
			g->max_dev = ft_max_dev(str, fichierLu[i]->d_name);
		if (ft_max_dev4(str, fichierLu[i]->d_name) > g->max_dev2)
			g->max_dev2 = ft_max_dev4(str, fichierLu[i]->d_name);
    	i++;
	}
	if (g->flag_f == 0)
     ft_trie(str, &fichierLu);
    if (g->flag_t == 1 || g->flag_g == 1)
   		ft_t(str, &fichierLu, g);
    if (g->flag_r == 1)
   		ft_r(str, &fichierLu, i -1);
    i = -1;
	while (fichierLu[++i] != NULL && g->flag_d == 0)
	{
		if ((fichierLu[i]->d_name[0] != '.' || g->flag_a == 1) && g->flag_l == 0)
		{
    		ft_color(str, fichierLu[i]->d_name);
    		ft_putendl(fichierLu[i]->d_name);
    		write(1, "\e[0;m", 6);
		}
    	else if ((fichierLu[i]->d_name[0] != '.' || g->flag_a == 1) && g->flag_l == 1 && str != NULL && ft_isprint(fichierLu[i]->d_name[0]) && is_open(str, fichierLu[i]->d_name) != -1)
    	{
    		ft_affiche(str, fichierLu[i]->d_name, g);
    		ft_color(str, fichierLu[i]->d_name);
    		ft_putendl(fichierLu[i]->d_name);
    		write(1, "\e[0;m", 6);
    	}
	}
	while (fichierLu[j] != NULL && j < i && j < 50000 && g->flag_d == 0)
	{
		if (fichierLu[j] != NULL && (fichierLu[j]->d_type == 4  || fichierLu[j]->d_type == 10) && fichierLu[j]->d_type != 8 && ft_strcmp(fichierLu[j]->d_name, ".") != 0 && ft_strcmp(fichierLu[j]->d_name, "..") != 0 && (fichierLu[j]->d_name[0] != '.' || g->flag_a == 1))
		{
			if (str[0] == '/' && str[1] == 0)
			{
				ft_putstr("\n\n");
				test = ft_strjoin(str, fichierLu[j]->d_name);
    			ft_R(test, g);
    			free(test);
			}
    		else
    		{
    			ft_putstr("\n\n");
    			test = ft_strjoin(str, "/");
    			test2 = ft_strjoin(test, fichierLu[j]->d_name);
    			free(test);
    			ft_R(test2, g);
    			free(test2);
    		}
		}
		j++;
	}
	closedir(rep);
	return (0);
}
