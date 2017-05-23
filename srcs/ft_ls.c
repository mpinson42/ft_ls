#include "ft_ls.h"

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
    if(g->flag_t == 1)
   		ft_t(str, &fichierLu);
    if(g->flag_r == 1)
   		ft_r(str, &fichierLu, i -1);
    i = 0;
	while (fichierLu[i] != NULL)
	{
		if(fichierLu[i]->d_name[0] != '.' || g->flag_a == 1)
    		printf("%s\n", fichierLu[i]->d_name);
    	i++;
	}
	if (closedir(rep) == -1)
        exit(-1);
}