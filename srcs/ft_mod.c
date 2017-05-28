/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:46:05 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/26 14:58:58 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_mode4(struct stat s)
{
	if (s.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (s.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (s.st_mode & S_ISUID)
	{
		if (s.st_mode & S_IXUSR)
			ft_putchar('s');
		else
			ft_putchar('S');
	}
	else if (s.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	ft_mode3(struct stat s)
{
	if (s.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (s.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (s.st_mode & S_ISGID)
	{
		if (s.st_mode & S_IXGRP)
			ft_putchar('s');
		else
			ft_putchar('S');
	}
	else if (s.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	ft_mode2(struct stat s)
{
	if (s.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (s.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (s.st_mode & S_ISVTX)
	{
		if (s.st_mode & S_IXOTH)
			ft_putchar('t');
		else
			ft_putchar('T');
	}
	else if (s.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	ft_mod(struct stat s, int *mode)
{
	if (S_ISREG(s.st_mode))
		ft_putchar('-');
	else if (S_ISLNK(s.st_mode))
		ft_putchar('l');
	else if (S_ISDIR(s.st_mode))
	{
		mode[0] = 1;
		ft_putchar('d');
	}
	else if (S_ISFIFO(s.st_mode))
		ft_putchar('p');
	else if (S_ISBLK(s.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(s.st_mode))
		ft_putchar('c');
	else if (s.st_mode & S_IXUSR)
		ft_putchar('s');
	else
		ft_putchar('-');
	ft_mode4(s);
	ft_mode3(s);
	ft_mode2(s);
}
