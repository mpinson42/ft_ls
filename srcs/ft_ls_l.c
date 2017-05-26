/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:45:53 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 14:45:54 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_return_f1(int i, char **str)
{
	free(str[0]);
	return (i);
}

int ft_max_li(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
int is_open(char *str, char *str2)
{
	struct stat	s;
	int			i;
	char		*test;

	if (!(test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	return (1);
}

int ft_max_l(char *str, char *str2)
{
	struct stat	s;
	int			i;
	char		*test;

	if (!(test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	i = 0;
	while (s.st_nlink > 0)
	{
		s.st_nlink = s.st_nlink /10;
		i++;
	}
	return (i);
}


int ft_max_size(char *str, char *str2)
{
	struct stat	s;
	int			i;
	char		*test;

	if (!(test = ft_strjoin(str, "/")))
		return (1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	i = 0;
	while (s.st_size > 0)
	{
		s.st_size = s.st_size /10;
		i++;
	}
	return (i);
}

int ft_max_name(char *str, char *str2)
{
	struct stat		s;
	int				i;
	struct passwd	*uid;
	char			*test;

	if (!(test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	if (!(uid = getpwuid(s.st_uid)))
		return (0);
	return (ft_strlen(uid->pw_name));
}

int ft_max_dev(char *str, char *str2)
{
	struct stat		s;
	int				i;
	struct passwd	*uid;
	char			*test;

	if (!(test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	i = ft_max_li(major(s.st_rdev)) +2;
	return (i);
}

int ft_max_dev4(char *str, char *str2)
{
	struct stat		s;
	int				i;
	struct passwd	*uid;
	char			*test;

	if (!(test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	i = ft_max_li(minor(s.st_rdev));
	return (i);
}

int ft_max_dev2(struct stat s)
{
	int				i;
	struct passwd	*uid;
	char			*test;

	i = ft_max_li(major(s.st_rdev)) + 2;
	return (i);
}

int ft_max_dev3(struct stat s)
{
	int				i;
	struct passwd	*uid;
	char			*test;

	i = ft_max_li(minor(s.st_rdev));
	return (i);
}

int ft_max_group(char *str, char *str2)
{
	struct stat		s;
	int				i;
	struct group	*gid;
	char			*test;

	if (!(test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	if (!(gid = getgrgid(s.st_gid)))
		return (0);
	return (ft_strlen(gid->gr_name));
}

int ft_count_month(char *str)
{
	if ((ft_strncmp(str, "jan", 3)) == 0)
		return (1);
	if ((ft_strncmp(str, "Feb", 3)) == 0)
		return (2);
	if ((ft_strncmp(str, "Mar", 3)) == 0)
		return (3);
	if ((ft_strncmp(str, "Apr", 3)) == 0)
		return (4);
	if ((ft_strncmp(str, "May", 3)) == 0)
		return (5);
	if ((ft_strncmp(str, "Jun", 3)) == 0)
		return (6);
	if ((ft_strncmp(str, "Jul", 3)) == 0)
		return (7);
	if ((ft_strncmp(str, "Aug", 3)) == 0)
		return (8);
	if ((ft_strncmp(str, "Sep", 3)) == 0)
		return (9);
	if ((ft_strncmp(str, "Oct", 3)) == 0)
	{
		//printf("oui\n");
		return (10);
	}
	if ((ft_strncmp(str, "Nov", 3)) == 0)
		return (11);
	if ((ft_strncmp(str, "Dec", 3)) == 0)
	{
		//printf("oui\n");
		return (12);
	}
	return (0);
}

int ft_6month(char *str, int anner, struct stat s)
{
	int				time1;
	int				time2;
	struct time_t	*t;

	time1 = time(&s.st_mtime);
	time2 = ft_absolut(time1 - (ft_atoi(str + 14) + ft_atoi(str + 11) * 60 + ft_atoi(str + 8) * 60 * 60 + ft_atoi(str + 5) * 24 * 60 * 60 + ft_count_month(str) * 30.5 * 24 * 60 * 60 + (anner - 1970) * 12 * 30.5 * 24 * 60 * 60)); 
	if (time2 > 15811200)
		return (1);
	return (0);
}

void ft_affiche(char *str, char *str2, t_glob *g)
{
	struct stat		s;
	struct passwd	*uid;
	struct group 	*gid;
	char			*str3; 
	char			*test;
	char			*test2;
	int				mode;
	int				time1;
	acl_t			a;
	int				yolo;

	test2 = str;
	if (!(test = ft_strjoin(str, "/")))
		return ;
	if (!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return ;
	}
	free(test);
	if (lstat(str, &s) == -1)
	{
		free(str);
		return ;
	}
	free(str);
	if (!(uid = getpwuid(s.st_uid)))
		return ;
	if (!(gid = getgrgid(s.st_gid)))
		return ;
	ft_mod(s, &mode);
	if(listxattr(str, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if ((a = acl_get_file(str, ACL_TYPE_EXTENDED)))
		ft_putchar('+');
	else
		ft_putchar(' ');
	acl_free(a);
	if (mode == 1)
		str3 = ctime(&s.st_mtime);
	else if (mode == 2)
		str3 = ctime(&s.st_mtime);
	else
		str3 = ctime(&s.st_mtime);
	str3 = str3 + 3;
	mode = ft_atoi(str3 + 17);
	time1 = ft_6month(str3, mode, s);
	str3[strlen(str3) - 9] = 0;
	yolo = -1;
	while (ft_absolut(g->max_lien - ft_max_li(s.st_nlink)) - ++yolo > 0)
		ft_putchar(' ');
	ft_putnbr(s.st_nlink);
	ft_putstr(uid->pw_name);
	ft_putstr("  ");
	yolo = -1;
	while (ft_strlen(uid->pw_name) < g->max_name && ft_strlen(uid->pw_name) < g->max_name - ++yolo)
		ft_putchar(' ');
	ft_putstr(gid->gr_name);
	ft_putchar(' ');
	if (ft_strcmp(test2, "/dev") != 0)
	{
		yolo = -1;
		while (strlen(gid->gr_name) < g->max_group - ++yolo)
			ft_putchar(' ');
		yolo = -1;
		while (ft_absolut(g->max_size - ft_max_li(s.st_size)) - ++yolo + 1 > 0)
			ft_putchar(' ');
		ft_putnbr(s.st_size);
	}
	else
	{
		yolo = -1;
		while (strlen(gid->gr_name) < g->max_group - ++yolo)
			ft_putchar(' ');
		yolo = -1;
		while (g->max_dev > ft_max_dev2(s) + ++yolo)
			ft_putchar(' ');
		ft_putnbr(major(s.st_rdev));
		ft_putstr(", ");
		yolo = -1;
		while (g->max_dev2 > ft_max_dev3(s) + ++yolo)
			ft_putchar(' ');
		ft_putnbr(minor(s.st_rdev));
	}
	if (time1 == 0)
	{
		ft_putstr(str3);
		ft_putchar(' ');
	}
	else
	{
		str3[strlen(str3) - 5] = 0;
		ft_putstr(str3);
		ft_putnbr(mode);
		ft_putchar(' ');
	}
}

void	ft_swap(struct dirent** a, struct dirent** b)
{
	struct dirent *c;
	struct dirent *d;

	c = *a;
	d = *b;
	*a = d;
	*b = c;
}

void *ft_trie(char *str, struct dirent *(*fichierLu)[ft_test(str) + 1])
{
	int i;
	int bol;
	int y;

	bol = 0;
	while (bol == 0)
	{
		bol = 1;
		i = -1;
		while (fichierLu[0][++i + 1] != NULL)
		{
			y = -1;
			while (fichierLu[0][i]->d_name[y + 1]  != 0 && fichierLu[0][i + 1]->d_name[y + 1] != 0)
			{
				if (fichierLu[0][i]->d_name[0] > fichierLu[0][i + 1]->d_name[0])
				{
					ft_swap(&fichierLu[0][i], &fichierLu[0][i + 1]);
					bol = 0;
				}
				y++;
			}
		}
	}
	return (fichierLu);
}

void ft_ls_l(char *str, t_glob *g)
{
	DIR				*rep;
	struct dirent	*fichierLu[ft_test(str) + 1];
	int				i;
	struct dirent	*c[3];

	i = 0;
	rep = NULL;
	if (str == NULL || !(rep = opendir(str)))
	{
		ft_color(str, fichierLu[i]->d_name);
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
    if (g->flag_d == 1)
    {
    	ft_affiche("./", fichierLu[i]->d_name, g);
    	ft_putendl(fichierLu[i]->d_name);
    }
	while (fichierLu[++i] != NULL && g->flag_d == 0)
	{
		if (fichierLu[i]->d_name[0] != '.' || g->flag_a == 1)
		{
			if (ft_isprint(fichierLu[i]->d_name[0]) && is_open(str, fichierLu[i]->d_name) != -1)
			{
				ft_affiche(str, fichierLu[i]->d_name, g);
				ft_color(str, fichierLu[i]->d_name);
				ft_putendl(fichierLu[i]->d_name);
    			write(1, "\e[0;m", 6);
    		}
		}
	}
	closedir(rep);
}
