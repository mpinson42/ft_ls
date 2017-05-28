/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_1_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:02:17 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/27 14:02:25 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_return_f1(int i, char **str)
{
	free(str[0]);
	return (i);
}

int		ft_max_li(int nbr)
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

int		is_open(char *str, char *str2)
{
	struct stat	s;
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

int		ft_max_l(char *str, char *str2)
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
		s.st_nlink = s.st_nlink / 10;
		i++;
	}
	return (i);
}

int		ft_max_size(char *str, char *str2)
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
		s.st_size = s.st_size / 10;
		i++;
	}
	return (i);
}
