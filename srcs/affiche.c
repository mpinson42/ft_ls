/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:27:29 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/27 13:27:31 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_affiche1(t_aff a, t_glob *g)
{
	a.yolo = -1;
	while ((int)ft_strlen(a.gid->gr_name) < g->max_group - ++a.yolo)
		ft_putchar(' ');
	if (ft_strcmp(a.test2, "/dev") != 0)
	{
		a.yolo = -1;
		while (ft_absolut(g->max_size -
			ft_max_li(a.s.st_size)) - ++a.yolo + 1 > 0)
			ft_putchar(' ');
		ft_putnbr(a.s.st_size);
	}
	else
	{
		a.yolo = -1;
		while (g->max_dev > ft_max_dev2(a.s) + ++a.yolo)
			ft_putchar(' ');
		ft_putnbr(major(a.s.st_rdev));
		ft_putstr(", ");
		a.yolo = -1;
		while (g->max_dev2 > ft_max_dev3(a.s) + ++a.yolo)
			ft_putchar(' ');
		ft_putnbr(minor(a.s.st_rdev));
	}
}

void	ft_affiche3(t_aff a, t_glob *g)
{
	ft_putnbr(a.s.st_nlink);
	ft_putchar(' ');
	ft_putstr(a.uid->pw_name);
	ft_putchar(' ');
	a.yolo = -1;
	while ((int)ft_strlen(a.uid->pw_name) < g->max_name &&
			(int)ft_strlen(a.uid->pw_name) < g->max_name - ++a.yolo)
		ft_putchar(' ');
	ft_putstr(a.gid->gr_name);
	ft_putchar(' ');
	ft_affiche1(a, g);
	if (a.time1 == 0)
	{
		ft_putstr(a.str3);
		ft_putchar(' ');
	}
	else
	{
		a.str3[ft_strlen(a.str3) - 5] = 0;
		ft_putstr(a.str3);
		ft_putchar(' ');
		ft_putnbr(a.mode);
		ft_putchar(' ');
	}
}

void	ft_affiche4(t_aff a, t_glob *g, char *str)
{
	ft_mod(a.s, &a.mode);
	if (listxattr(str, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putstr("@");
	else if ((a.a = acl_get_file(str, ACL_TYPE_EXTENDED)))
		ft_putstr("+");
	else
		ft_putstr(" ");
	acl_free(a.a);
	if (a.mode == 1)
		a.str3 = ctime(&a.s.st_mtime);
	else if (a.mode == 2)
		a.str3 = ctime(&a.s.st_mtime);
	else
		a.str3 = ctime(&a.s.st_mtime);
	a.str3 = a.str3 + 3;
	a.mode = ft_atoi(a.str3 + 17);
	a.time1 = ft_6month(a.str3, a.mode, a.s);
	a.str3[ft_strlen(a.str3) - 9] = 0;
	a.yolo = -1;
	while (ft_absolut(g->max_lien - ft_max_li(a.s.st_nlink)) - ++a.yolo > 0)
		ft_putchar(' ');
	ft_affiche3(a, g);
}

void	ft_affiche(char *str, char *str2, t_glob *g)
{
	t_aff a;

	a.test2 = str;
	if (!(a.test = ft_strjoin(str, "/")))
		return ;
	if (!(str = ft_strjoin(a.test, str2)))
	{
		free(a.test);
		return ;
	}
	free(a.test);
	if (lstat(str, &a.s) == -1)
	{
		free(str);
		return ;
	}
	free(str);
	if (!(a.uid = getpwuid(a.s.st_uid)))
		return ;
	if (!(a.gid = getgrgid(a.s.st_gid)))
		return ;
	ft_affiche4(a, g, str);
}
