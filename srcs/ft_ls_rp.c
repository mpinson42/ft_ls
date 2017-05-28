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

int		ft_chr(char *ptr[4])
{
	if (ft_atoi(ptr[2] + 20) > ft_atoi(ptr[3] + 20))
		return (1);
	if (ft_atoi(ptr[2] + 20) < ft_atoi(ptr[3] + 20))
		return (0);
	if (ft_mois(ptr[2] + 4, ptr[3] + 4) == 1)
		return (1);
	if (ft_mois(ptr[2] + 4, ptr[3] + 4) == -1)
		return (0);
	if (ft_atoi(ptr[2] + 8) > ft_atoi(ptr[3] + 8))
		return (1);
	if (ft_atoi(ptr[2] + 8) < ft_atoi(ptr[3] + 8))
		return (0);
	if (ft_atoi(ptr[2] + 11) > ft_atoi(ptr[3] + 11))
		return (1);
	if (ft_atoi(ptr[2] + 11) < ft_atoi(ptr[3] + 11))
		return (0);
	if (ft_atoi(ptr[2] + 14) > ft_atoi(ptr[3] + 14))
		return (1);
	if (ft_atoi(ptr[2] + 14) < ft_atoi(ptr[3] + 14))
		return (0);
	if (ft_atoi(ptr[2] + 17) > ft_atoi(ptr[3] + 17))
		return (1);
	if (ft_atoi(ptr[2] + 17) < ft_atoi(ptr[3] + 17))
		return (0);
	return (-1);
}

int		return_f4(char *(*ptr4)[4], int i)
{
	free(ptr4[0][0]);
	free(ptr4[0][1]);
	free(ptr4[0][2]);
	free(ptr4[0][3]);
	return (i);
}

int		ft_time(char *str, char *str2, char *str3, t_glob *g)
{
	struct stat t;
	char		*ptr[4];

	if (!(ptr[2] = malloc(sizeof(char) * 52)) ||
		!(ptr[3] = malloc(sizeof(char) * 52)))
		return (-1);
	ptr[1] = ft_strjoin(str, "/");
	ptr[0] = ft_strjoin(ptr[1], str2);
	if (lstat(ptr[0], &t) == -1)
		return (return_f4(&ptr, 0));
	ptr[3] = ft_strcpy(ptr[3], ctime(&t.st_mtime));
	return_f2(0, &ptr[0], &ptr[1]);
	ptr[1] = ft_strjoin(str, "/");
	ptr[0] = ft_strjoin(ptr[1], str3);
	if (lstat(ptr[0], &t) == -1)
		return (return_f4(&ptr, -1));
	ptr[2] = ft_strcpy(ptr[2], ctime(&t.st_mtime));
	return_f2(0, &ptr[0], &ptr[1]);
	if ((g->ret1 = ft_chr(ptr)) == 1)
		return (return_f2(1, &ptr[2], &ptr[3]));
	else if (g->ret1 == 0)
		return (return_f2(0, &ptr[2], &ptr[3]));
	if (ft_strcmp(str2, str3) > 0)
		return (return_f2(1, &ptr[2], &ptr[3]));
	return (return_f2(0, &ptr[2], &ptr[3]));
}

void	*ft_t(char *str,
	struct dirent *(*fichierlu)[ft_test(str) + 1], t_glob *g)
{
	int i;
	int bol;

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
