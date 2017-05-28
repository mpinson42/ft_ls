/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_2_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:04:57 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/27 14:04:59 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_max_name(char *str, char *str2)
{
	struct stat		s;
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

int		ft_max_dev(char *str, char *str2)
{
	struct stat		s;
	int				i;
	char			*test;

	if (!(test = ft_strjoin(str, "/")))
		return (-1);
	if (!(str = ft_strjoin(test, str2)))
		return (ft_return_f1(-1, &test));
	free(test);
	if (lstat(str, &s) == -1)
		return (ft_return_f1(-1, &str));
	free(str);
	i = ft_max_li(major(s.st_rdev)) + 2;
	return (i);
}

int		ft_max_dev4(char *str, char *str2)
{
	struct stat		s;
	int				i;
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

int		ft_max_dev2(struct stat s)
{
	int				i;

	i = ft_max_li(major(s.st_rdev)) + 2;
	return (i);
}

int		ft_max_dev3(struct stat s)
{
	int				i;

	i = ft_max_li(minor(s.st_rdev));
	return (i);
}
