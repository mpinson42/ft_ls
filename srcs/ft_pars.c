#include "ft_ls.h"

int edit(t_glob *g, int argc, char **argv)
{
	int i;
	int j;
	int x;

	i = 1;
	j = 0;
	while(i < argc && argv[i][0] == '-')
	{
		x = 1;
		while(argv[i][x])
		{
			if (argv[i][x] == 'R')
				g->flag_gr = 1;
			if (argv[i][x] == 'r')
				g->flag_r = 1;
			if (argv[i][x] == 'l')
				g->flag_l = 1;
			if (argv[i][x] == 'a')
				g->flag_a = 1;
			if (argv[i][x] == 't')
				g->flag_t = 1;
			x++;
		}
		i++;
	}
	if(!(g->path = (char **)malloc(sizeof(char *) * (argc - i))))
		return (-1);
	g->leng_path = argc - i;
	if(i == argc)
	{
		g->leng_path = 1;
		g->path[0] = ".";
	}
	else
	{
		while(i < argc)
		{
			g->path[j] = argv[i];
			j++;
			i++;
		}
	}
/*	printf("R:%d\nr:%d\na:%d\nl:%d\nt:%d\n", g->flag_gr, g->flag_r, g->flag_a, g->flag_l, g->flag_t);
	i = 0;
	while (i < g->leng_path)
	{
		printf("%d = %s\n", i, g->path[i]);
		i++;
	}*/
	return (0);
}