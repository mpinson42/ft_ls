/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_rp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:45:58 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 14:46:00 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_r(char *str, struct dirent *(*fichierlu)[ft_test(str) + 1], int max)
{
	int i;
	int y;

	i = 0;
	y = max;
	while (i < max / 2 + 0.5)
	{
		ft_swap(&fichierlu[0][i], &fichierlu[0][y]);
		i++;
		y--;
	}
	return (fichierlu);
}

int		ft_mois(char *str1, char *str2)
{
	int a;
	int b;

	if (ft_strncmp(str1, str2, 3) == 0)
		return (0);
	a = ft_count_month(str1);
	b = ft_count_month(str2);
	if (a > b)
		return (1);
	return (-1);
}

int		return_f2(int i, char **str2, char **str1)
{
	free(str1[0]);
	free(str2[0]);
	return (i);
}

int		ft_time(char *str, char *str2, char *str3, t_glob *g)
{
	struct stat t;
	char		*test;
	char		*test2;
	char		*a;
	char		*b;

	if (!(a = malloc(sizeof(char) * 52)))
		return (-1);
	if (!(b = malloc(sizeof(char) * 52)))
		return (-1);
	test2 = ft_strjoin(str, "/");
	test = ft_strjoin(test2, str2);
	if (lstat(test, &t) == -1)
	{
		free(a);
		free(b);
		free(test2);
		free(test);
		return (0);
	}
	if (g->flag_u == 0)
		b = ft_strcpy(b, ctime(&t.st_mtime));
	else
		b = ft_strcpy(b, ctime(&t.st_mtime));
	b[24] = 0;
	free(test);
	free(test2);
	test2 = ft_strjoin(str, "/");
	test = ft_strjoin(test2, str3);
	if (lstat(test, &t) == -1)
	{
		free(a);
		free(b);
		free(test2);
		free(test);
		return (-1);
	}
	if (g->flag_u == 0)
		a = ft_strcpy(a, ctime(&t.st_mtime));
	else
		a = ft_strcpy(b, ctime(&t.st_mtime));
	free(test);
	free(test2);
	a[24] = 0;
	b[24] = 0;
	if (ft_atoi(a + 20) > ft_atoi(b + 20))
		return (return_f2(1, &a, &b));
	if (ft_atoi(a + 20) < ft_atoi(b + 20))
		return (return_f2(0, &a, &b));
	if (ft_mois(a + 4, b + 4) == 1)
		return (return_f2(1, &a, &b));
	if (ft_mois(a + 4, b + 4) == -1)
		return (return_f2(0, &a, &b));
	if (ft_atoi(a + 8) > ft_atoi(b + 8))
		return (return_f2(1, &a, &b));
	if (ft_atoi(a + 8) < ft_atoi(b + 8))
		return (return_f2(0, &a, &b));
	if (ft_atoi(a + 11) > ft_atoi(b + 11))
		return (return_f2(1, &a, &b));
	if (ft_atoi(a + 11) < ft_atoi(b + 11))
		return (return_f2(0, &a, &b));
	if (ft_atoi(a + 14) > ft_atoi(b + 14))
		return (return_f2(1, &a, &b));
	if (ft_atoi(a + 14) < ft_atoi(b + 14))
		return (return_f2(0, &a, &b));
	if (ft_atoi(a + 17) > ft_atoi(b + 17))
		return (return_f2(1, &a, &b));
	if (ft_atoi(a + 17) < ft_atoi(b + 17))
		return (return_f2(0, &a, &b));
	if (ft_strcmp(str2, str3) > 0)
		return (return_f2(1, &a, &b));
	return (return_f2(0, &a, &b));
}

void	*ft_t(char *str,
	struct dirent *(*fichierlu)[ft_test(str) + 1], t_glob *g)
{
	int i;
	int bol;
	int y;

	bol = 0;
	while (bol == 0)
	{
		bol = 1;
		i = 0;
		while (fichierlu[0][i + 1] != NULL)
		{
			if (ft_time(str, fichierlu[0][i]->d_name,
				fichierlu[0][i + 1]->d_name, g) == 1)
			{
				ft_swap(&fichierlu[0][i], &fichierlu[0][i + 1]);
				bol = 0;
			}
			i++;
		}
	}
	return (fichierlu);
}
