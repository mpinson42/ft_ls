#include "ft_ls.h"

void ft_color(char *str, char* str2)
{
	struct stat s;
	int i;
	char *test;

	if(!(test = ft_strjoin(str, "/")))
		return ;
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return ;
	}
	free(test);
	//printf("%s", str);
	if(lstat(str, &s) == -1)
	{

		free(str);
		return ;
	}
	free(str);

	if (S_ISREG (s.st_mode))
	{
		if(s.st_mode & S_IXUSR && s.st_mode & S_IXGRP && s.st_mode & S_IXOTH)
    		write(1, "\e[0;31m", 8);
        return ;
	}
	if (S_ISDIR (s.st_mode))
        write(1, "\e[1;36m", 8);
    if (S_ISLNK (s.st_mode))
        write(1, "\e[0;35m", 8);
    if (S_ISBLK (s.st_mode))
        write(1, "\e[0;34m", 8);
    if (S_ISCHR (s.st_mode))
        write(1, "\e[1;33m", 8);
}

void ft_ls(t_glob *g, char *str)
{
	DIR *rep = NULL;
	struct dirent* fichierLu[ft_test(str) + 1];
	int i;

	i = 0;
	printf("%s\n", str);
	if(str == NULL || !(rep = opendir(str)))
		return;
	while ((fichierLu[i] = readdir(rep)) != NULL)
    	i++;
    //ft_t(str, fichierLu[0]->d_name, fichierLu[1]->d_name);
    ft_trie(str, &fichierLu);
    if(g->flag_t == 1)
   		ft_t(str, &fichierLu);
    if(g->flag_r == 1)
  		ft_r(str, &fichierLu, i -1);
    i = 0;
	while (fichierLu[i] != NULL)
	{
		if((fichierLu[i]->d_name[0] != '.' || g->flag_a == 1) &&  ft_isprint(fichierLu[i]->d_name[0]) && is_open(str, fichierLu[i]->d_name) != -1)
		{
			ft_color(str, fichierLu[i]->d_name);
    		printf("%s\n", fichierLu[i]->d_name);
    		write(1, "\e[0;m", 6);
		}
    	i++;
	}
	if (closedir(rep) == -1)
        exit(-1);
}

