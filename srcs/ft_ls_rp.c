#include "ft_ls.h"

void *ft_r(char *str, struct dirent *(*fichierLu)[ft_test(str) + 1], int max)
{
	int i;
	int y;

	i = 0;
	y = max;
	while(i < max / 2)
	{
		ft_swap(&fichierLu[0][i], &fichierLu[0][y]);
		i++;
		y--;
	}

	return(fichierLu);
}
int ft_mois(char *str1, char *str2)
{
	int a = 0;
	int b = 0;

	str2[3] = 0;
	str1[3] = 0;
	if(ft_strncmp(str1, str2, 3) == 0)
		return(0);
	if((ft_strncmp(str1, "jan", 3)) == 0)
		a = 1;
	if((ft_strncmp(str1, "Feb", 3)) == 0)
		a = 2;
	if((ft_strncmp(str1, "Mar", 3)) == 0)
		a = 3;
	if((ft_strncmp(str1, "Apr", 3)) == 0)
		a = 4;
	if((ft_strncmp(str1, "May", 3)) == 0)
		a = 5;
	if((ft_strncmp(str1, "Jun", 3)) == 0)
		a = 6;
	if((ft_strncmp(str1, "Jul", 3)) == 0)
		a = 7;
	if((ft_strncmp(str1, "Aug", 3)) == 0)
		a = 8;
	if((ft_strncmp(str1, "Sep", 3)) == 0)
		a = 9;
	if((ft_strncmp(str1, "Oct", 3)) == 0)
		a = 10;
	if((ft_strncmp(str1, "Nov", 3)) == 0)
		a = 11;
	if((ft_strncmp(str1, "Dec", 3)) == 0)
		a = 12;

	if((ft_strncmp(str2, "jan", 3)) == 0)
		b = 1;
	if((ft_strncmp(str2, "Feb", 3)) == 0)
		b = 2;
	if((ft_strncmp(str2, "Mar", 3)) == 0)
		b = 3;
	if((ft_strncmp(str2, "Apr", 3)) == 0)
		b = 4;
	if((ft_strncmp(str2, "May", 3)) == 0)
		b = 5;
	if((ft_strncmp(str2, "Jun", 3)) == 0)
		b = 6;
	if((ft_strncmp(str2, "Jul", 3)) == 0)
		b = 7;
	if((ft_strncmp(str2, "Aug", 3)) == 0)
		b = 8;
	if((ft_strncmp(str2, "Sep", 3)) == 0)
		b = 9;
	if((ft_strncmp(str2, "Oct", 3)) == 0)
		b = 10;
	if((ft_strncmp(str2, "Nov", 3)) == 0)
		b = 11;
	if((ft_strncmp(str2, "Dec", 3)) == 0)
		b = 12;
	if(a > b)
		return(1);
	return(-1);
}

int ft_time(char *str, char *str2, char *str3, t_glob *g)
{
	struct stat s;
	struct stat t;
	char *test;
	char *test2;
	char *a;
	char *b;


//	if(str == NULL || str2 == NULL|| str3 == NULL)
//		return (-1);
	if(!(a = malloc(sizeof(char) * 52)))
		return (-1);
	if(!(b = malloc(sizeof(char) * 52)))
		return (-1);

	test2 = ft_strjoin(str, "/");
	


	test = ft_strjoin(test2, str2);

	if(stat(test, &t) == -1)
	{
		free(a);
		free(b);
		free(test2);
		free(test);
		return (-1);
	}
	if(g->flag_u == 0)
		b = ft_strcpy(b, ctime(&t.st_ctime));
	else
		b = ft_strcpy(b, ctime(&t.st_atime));
	b[24] = 0;

	free(test);

	int i = 0;
	while(i < 500)
		i++;
	free(test2);
	test2 = ft_strjoin(str, "/");
	test = ft_strjoin(test2, str3);
	//printf("%s\n", test);
	if(stat(test, &t) == -1)
	{
		free(a);
		free(b);
		free(test2);
		free(test);
		return (-1);
	}
	if(g->flag_u == 0)
		a = ft_strcpy(a, ctime(&t.st_ctime));
	else
		a = ft_strcpy(b, ctime(&t.st_atime));
	a[24] = 0;

	free(test);



	free(test2);
//	printf("%s\n", a + 8);
//	write(1, a + 11, 2);
	a[24] = 0;
	b[24] =0;
	//printf("-->%s -- %s\n", a, b);
	if(ft_atoi(a + 20) > ft_atoi(b + 20))
	{

		free(a);
		free(b);
		return (1);
	}
	else if(ft_atoi(a + 20) < ft_atoi(b + 20))
	{
		free(a);
		free(b);
		return (0);
	}
	//printf("%s\n", a + 4);
	if(ft_mois(a + 4, b + 4) == 1)
	{

		free(a);
		free(b);
		return (1);
	}
	else if(ft_mois(a + 4, b + 4) == -1)
	{
		free(a);
		free(b);
		return (0);
	}


	if(ft_atoi(a + 8) > ft_atoi(b + 8))
	{
		free(a);
		free(b);
		return (1);
	}
	else if(ft_atoi(a + 8) < ft_atoi(b + 8))
	{
		free(a);
		free(b);
		return (0);
	}

	//printf("%s > %s\n", a + 11, b + 11);
	if(ft_atoi(a + 11) > ft_atoi(b + 11))
	{
		free(a);
		free(b);
		return (1);
	}
	else if(ft_atoi(a + 11) < ft_atoi(b + 11))
	{
		free(a);
		free(b);
		return (0);
	}


	if(ft_atoi(a + 14) > ft_atoi(b + 14))
	{
		free(a);
		free(b);
		return (1);
	}
	else if(ft_atoi(a + 14) < ft_atoi(b + 14))
	{
		free(a);
		free(b);
		return (0);
	}


	if(ft_atoi(a + 17) > ft_atoi(b + 17))
	{
		free(a);
		free(b);
		return (1);
	}
	else if(ft_atoi(a + 17) < ft_atoi(b + 17))
	{
		free(a);
		free(b);
		return (0);
	}
	if(ft_strcmp(str2 ,str3) > 0)
	{
		free(a);
		free(b);
		return(1);
	}
	free(a);
	free(b);
	return(0);
}


void *ft_t(char *str, struct dirent *(*fichierLu)[ft_test(str) + 1], t_glob *g)
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
			if(ft_time(str, fichierLu[0][i]->d_name, fichierLu[0][i + 1]->d_name, g) == 1)
			{
				ft_swap(&fichierLu[0][i], &fichierLu[0][i+1]);
				bol = 0;
			}
			i++;
		}
	}
	return(fichierLu);
}