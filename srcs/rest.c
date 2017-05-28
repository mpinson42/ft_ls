/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:12:58 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/27 14:13:03 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

int		ft_max_group(char *str, char *str2)
{
	struct stat		s;
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

int		ft_count_month(char *str)
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
		return (10);
	if ((ft_strncmp(str, "Nov", 3)) == 0)
		return (11);
	if ((ft_strncmp(str, "Dec", 3)) == 0)
		return (12);
	return (0);
}

int		ft_6month(char *str, int anner, struct stat s)
{
	int				time1;
	int				time2;

	time1 = time(&s.st_mtime);
	time2 = ft_absolut(time1 - (ft_atoi(str + 14) + ft_atoi(str + 11)
		* 60 + ft_atoi(str + 8) * 60 * 60 + ft_atoi(str + 5) * 24 *
		60 * 60 + ft_count_month(str) * 30.5 * 24 * 60 * 60 +
		(anner - 1970) * 12 * 30.5 * 24 * 60 * 60));
	if (time2 > 15811200)
		return (1);
	return (0);
}
