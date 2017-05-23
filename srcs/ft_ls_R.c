#include "ft_ls.h"

int ft_test(char *str)
{
	int i;
	DIR *rep = NULL;

	i = 0;
	if(str == NULL || !(rep = opendir(str)))
		return(0);
	while (readdir(rep) != NULL)
    	i++;
    if (closedir(rep) == -1)
        exit(-1);
    return(i);
}

int ft_test2(char *str, t_glob *g)
{
	int i;
	int rendu;
	DIR *rep = NULL;
	struct dirent* fichierLu[ft_test(str) + 1];

	i = 0;
	rendu = 0;
	if(str == NULL || !(rep = opendir(str)))
		return(0);
	while ((fichierLu[i] = readdir(rep)) != NULL)
	{
		if(fichierLu[i]->d_name[0] != '.' || g->flag_a == 1)
			rendu++;
    	i++;
	}
    if (closedir(rep) == -1)
        exit(-1);
    return(rendu);
}

int ft_R(char *str, t_glob *g)
{
	DIR *rep = NULL;
	struct dirent* fichierLu[ft_test(str) + 1];
	int i;
	int j;
	char *test;
	char *test2;

	j = 0;
	i = 0;
	//ft_putstr("oui\n");
//	if(g->flag_l && str != NULL)
//		ft_affiche2(str);
	printf("%s\n", str);
	if(str == NULL || !(rep = opendir(str)))
	{
		perror("");
		printf("\n\n");
		return(0);
	}
	if(g->flag_l == 1 && ft_strcmp(str, "/dev") != 0)
		printf("total : %d\n", ft_test2(str, g));
	if(g->flag_l == 1 && ft_strcmp(str, "/dev") == 0)
		printf("total : 0\n");
	while ((fichierLu[i] = readdir(rep)) != NULL)
	{
		if(ft_max_l(str, fichierLu[i]->d_name) > g->max_lien)
			g->max_lien = ft_max_l(str, fichierLu[i]->d_name);
		if(ft_max_size(str, fichierLu[i]->d_name) > g->max_size)
			g->max_size = ft_max_size(str, fichierLu[i]->d_name);
		if(ft_max_name(str,fichierLu[i]->d_name) > g->max_name)
			g->max_name = ft_max_name(str, fichierLu[i]->d_name);
		if(ft_max_name(str, fichierLu[i]->d_name) < g->min_name)
			g->min_name = ft_max_name(str, fichierLu[i]->d_name);
		if(ft_max_group(str, fichierLu[i]->d_name) > g->max_group)
			g->max_group = ft_max_group(str, fichierLu[i]->d_name);
    	i++;
	}
    ft_trie(str, &fichierLu);
    if(g->flag_t == 1)
   		ft_t(str, &fichierLu);
    if(g->flag_r == 1)
   		ft_r(str, &fichierLu, i -1);
    i = 0;

	while (fichierLu[i] != NULL)
	{
		if((fichierLu[i]->d_name[0] != '.' || g->flag_a == 1) && g->flag_l == 0)
    		printf("%s\n", fichierLu[i]->d_name);
    	else if ((fichierLu[i]->d_name[0] != '.' || g->flag_a == 1) && g->flag_l == 1 && str != NULL)
    	{
    		ft_affiche(str, fichierLu[i]->d_name, g);
    		printf("%s\n", fichierLu[i]->d_name);
    	}
    	i++;
	}
	
	while(fichierLu[j] != NULL && j < i && j < 50000)
	{
		if(fichierLu[j] != NULL && (fichierLu[j]->d_type == 4  || fichierLu[j]->d_type == 10) && fichierLu[j]->d_type != 8 && ft_strcmp(fichierLu[j]->d_name, ".") != 0 && ft_strcmp(fichierLu[j]->d_name, "..") != 0)
		{
			if(str[0] == '/' && str[1] == 0)
			{
				printf("\n\n");
				test = ft_strjoin(str, fichierLu[j]->d_name);
    			ft_R(test, g);
    			free(test);
			}
    		else
    		{
    			printf("\n\n");
    			test = ft_strjoin(str, "/");
    			test2 = ft_strjoin(test, fichierLu[j]->d_name);
    			free(test);
    			ft_R(test2, g);
    			free(test2);
    		}
		}
		j++;
	}
	if (closedir(rep) == -1)
        return (-1);
	return (0);
}