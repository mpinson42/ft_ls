/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 13:46:32 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/21 20:09:34 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <sys/stat.h> 
#include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include "libft.h"
#include <stdio.h>

typedef struct	s_glob
{
	int			flag_l;
	int			flag_gr;
	int			flag_a;
	int			flag_r;
	int			flag_t;
	char		**path;
	int			leng_path;
	int 		bol;
}				t_glob;

void ft_mod(struct stat s);
int edit(t_glob *g, int argc, char **argv);
void ft_ls(t_glob *g, char *str);
int ft_test(char *str);
int ft_R(char *str, t_glob *g);
void ft_ls_l(char *str, t_glob *g);
void ft_affiche(char *str, char *str2, t_glob *g);
int ft_test2(char *str, t_glob *g);
void *ft_trie(char *str, struct dirent *(*fichierLu)[ft_test(str) + 1]);
void *ft_r(char *str, struct dirent *(*fichierLu)[ft_test(str) + 1], int max);
void	ft_swap(struct dirent** a, struct dirent** b);
int ft_time(char *str, char *str2, char *str3);
void *ft_t(char *str, struct dirent *(*fichierLu)[ft_test(str) + 1]);

#endif
