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

# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <dirent.h>
# include <errno.h>
# include "libft.h"
# include <stdio.h>
# include <sys/xattr.h>

# define SIX_MONTH_SEGOND 15811200

typedef struct	s_glob
{
	int			flag_l;
	int			flag_gr;
	int			flag_a;
	int			flag_r;
	int			flag_t;
	int			flag_u;
	int			flag_f;
	int			flag_g;
	int			flag_d;
	char		**path;
	int			leng_path;
	int			bol;
	int			max_lien;
	int			max_name;
	int			max_group;
	int			min_name;
	int			max_size;
	int			max_dev;
	int			max_dev2;
	int			boll;
	int			ret1;
	int			ret2;
	int			j;

}				t_glob;

typedef struct	s_aff
{
	struct stat		s;
	struct passwd	*uid;
	struct group	*gid;
	char			*str3;
	char			*test;
	char			*test2;
	int				mode;
	int				time1;
	acl_t			a;
	int				yolo;
}				t_aff;

int				return_f2(int i, char **str2, char **str1);
int				ft_mois(char *str1, char *str2);
int				err_ft_rr(char *str, t_glob *g, DIR **rep);
int				ft_return_f1(int i, char **str);
int				ft_6month(char *str, int anner, struct stat s);
int				ft_max_li(int nbr);
int				ft_max_dev3(struct stat s);
int				ft_max_dev2(struct stat s);
int				ft_count_month(char *str);
void			ft_color(char *str, char *str2);
int				is_open(char *str, char *str2);
int				ft_max_dev(char *str, char *str2);
int				ft_max_dev4(char *str, char *str2);
int				ft_max_group(char *str, char *str2);
int				ft_max_name(char *str, char *str2);
int				ft_max_size(char *str, char *str2);
int				ft_max_l(char *str, char *str2);
void			ft_affiche2(char *str);
void			ft_mod(struct stat s, int *mode);
int				edit(t_glob *g, int argc, char **argv);
void			ft_ls(t_glob *g, char *str);
int				ft_test(char *str);
int				ft_rr(char *str, t_glob *g);
void			ft_ls_l(char *str, t_glob *g);
void			ft_affiche(char *str, char *str2, t_glob *g);
int				ft_test2(char *str, t_glob *g);
void			*ft_trie(char *str,
	struct dirent *(*fichierlu)[ft_test(str) + 1]);
void			*ft_r(char *str, struct
	dirent *(*fichierlu)[ft_test(str) + 1], int max);
void			ft_swap(struct dirent **a, struct dirent **b);
int				ft_time(char *str, char *str2, char *str3, t_glob *g);
void			*ft_t(char *str,
	struct dirent *(*fichierlu)[ft_test(str) + 1], t_glob *g);

#endif
