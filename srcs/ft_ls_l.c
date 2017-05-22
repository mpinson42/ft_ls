#include "ft_ls.h"

void ft_affiche(char *str, char *str2, t_glob *g)
{
	struct stat s;
	struct passwd *uid;
	struct group *gid;
	char *str3; 
	char *test;
	char *test2;
	int mode;

	if(!(test = ft_strjoin(str, "/")))
		return ;
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return ;
	}
	free(test);
	if(lstat(str, &s) == -1)
	{
		free(str);
		return ;
	}
	free(str);

	uid = getpwuid(s.st_uid);
	if(!(gid = getgrgid(s.st_gid)))
		return ;
	/*if(!(ctime(&s.st_ctime)))

		return ;*/

	ft_mod(s, &mode);


	if(mode == 1)
		str3 = ctime(&s.st_mtime);
	else if(mode == 2)
		str3 = ctime(&s.st_mtime);
	else
		str3 = ctime(&s.st_mtime);
	str3[strlen(str3) - 9] = 0;
	printf("%d\t", s.st_nlink);
	printf("%s\t", uid->pw_name);
	printf("%s\t", gid->gr_name);
	printf("%lld\t", s.st_size);
	printf("%s ", str3);
//	ft_putstr("oui2\n");
//	ft_putstr("oui3\n");
	//printf("%s\t", ctime(&s.st_ctime));*/
}

void ft_affiche2(char *str)
{
	struct stat s;
	struct passwd *uid;
	struct group *gid;
	char *str3; 
	char *test;
	char *test2;
	int mode;

	if(lstat(str, &s) == -1)
		return ;
	uid = getpwuid(s.st_uid);
	gid = getgrgid(s.st_gid);
	/*if(!(ctime(&s.st_ctime)))
		return ;*/
	ft_mod(s, &mode);



	str3 = ctime(&s.st_ctime);
	str3[strlen(str3) - 9] = 0;

	printf("%d\t", s.st_nlink);
	printf("%s\t", uid->pw_name);
	printf("%s\t", gid->gr_name);
	printf("%lld\t", s.st_size);
	printf("%s ", str3);
	//printf("%s\t", ctime(&s.st_ctime));
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
	while(bol == 0)
	{
		bol = 1;
		i = 0;
		while(fichierLu[0][i + 1] != NULL)
		{
			y = 0;
			while(fichierLu[0][i]->d_name[y + 1]  != 0 && fichierLu[0][i + 1]->d_name[y + 1] != 0)
			{
				if(fichierLu[0][i]->d_name[0] > fichierLu[0][i + 1]->d_name[0])
				{
					ft_swap(&fichierLu[0][i], &fichierLu[0][i + 1]);
					//sleep(1);
					bol = 0;
				}
				y++;
			}
			i++;
		}
	}
	return(fichierLu);
}

void ft_ls_l(char *str, t_glob *g)
{
	DIR *rep = NULL;
	struct dirent *fichierLu[ft_test(str) + 1];
	int i;
	struct dirent *c[3];

	i = 0;
	if(str == NULL || !(rep = opendir(str)))
	{
		if(g->flag_l && str != NULL)
			ft_affiche2(str);
		printf("%s\n", str);
		return;
	}
	//printf("%s\n", str);
	printf("total : %d\n", ft_test2(str, g));
	while ((fichierLu[i] = readdir(rep)) != NULL)
    	i++;
   	ft_trie(str, &fichierLu);
   	if(g->flag_t == 1)
   		ft_t(str, &fichierLu);
   	if(g->flag_r == 1)
   		ft_r(str, &fichierLu, i -1);
    i = 0;
	while (fichierLu[i] != NULL)
	{
		if(fichierLu[i]->d_name[0] != '.' || g->flag_a == 1)
		{
			ft_affiche(str, fichierLu[i]->d_name, g);
    		printf("%s\n", fichierLu[i]->d_name);
		}
    	i++;
	}
	if (closedir(rep) == -1)
        exit(-1);
}