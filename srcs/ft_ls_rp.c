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
	int a;
	int b;

	if(ft_strncmp(str1, str2, 3) == 0)
		return(0);
	if((ft_strncmp(str1, "jan", 3)))
		a = 1;
	if((ft_strncmp(str1, "jan", 3)))
		a = 2;
	if((ft_strncmp(str1, "jan", 3)))
		a = 3;
	if((ft_strncmp(str1, "jan", 3)))
		a = 4;
	if((ft_strncmp(str1, "jan", 3)))
		a = 5;
	if((ft_strncmp(str1, "jan", 3)))
		a = 6;
	if((ft_strncmp(str1, "jan", 3)))
		a = 7;
	if((ft_strncmp(str1, "jan", 3)))
		a = 8;
	if((ft_strncmp(str1, "jan", 3)))
		a = 9;
	if((ft_strncmp(str1, "jan", 3)))
		a = 10;
	if((ft_strncmp(str1, "jan", 3)))
		a = 11;
	if((ft_strncmp(str1, "jan", 3)))
		a = 12;

	if((ft_strncmp(str2, "jan", 3)))
		b = 1;
	if((ft_strncmp(str2, "jan", 3)))
		b = 2;
	if((ft_strncmp(str2, "jan", 3)))
		b = 3;
	if((ft_strncmp(str2, "jan", 3)))
		b = 4;
	if((ft_strncmp(str2, "jan", 3)))
		b = 5;
	if((ft_strncmp(str2, "jan", 3)))
		b = 6;
	if((ft_strncmp(str2, "jan", 3)))
		b = 7;
	if((ft_strncmp(str2, "jan", 3)))
		b = 8;
	if((ft_strncmp(str2, "jan", 3)))
		b = 9;
	if((ft_strncmp(str2, "jan", 3)))
		b = 10;
	if((ft_strncmp(str2, "jan", 3)))
		b = 11;
	if((ft_strncmp(str2, "jan", 3)))
		b = 12;
	if(a > b)
		return(1);
	return(-1);
}

int ft_time(char *str, char *str2, char *str3)
{
	struct stat s;
	struct stat t;
	char *test;
	char *test2;
	char *a;
	char *b;



	a = malloc(sizeof(char) * 52);
	b = malloc(sizeof(char) * 52);

	test2 = ft_strjoin(str, "/");
	


	test = ft_strjoin(test2, str2);

	if(stat(test, &t) == -1)
		return (-1);
	b = ft_strcpy(b, ctime(&t.st_ctime));
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
		return (-1);
	a = ft_strcpy(a, ctime(&t.st_ctime));
	a[24] = 0;

	free(test);



	free(test2);
//	printf("%s\n", a + 8);
//	write(1, a + 11, 2);
	a[24] = 0;
	b[24] =0;

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
		return (1);
	if(ft_mois(a + 4, b + 4) == -1)
		return(0);


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
	return(0);
}


void *ft_t(char *str, struct dirent *(*fichierLu)[ft_test(str) + 1])
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
			if(ft_time(str, fichierLu[0][i]->d_name, fichierLu[0][i + 1]->d_name) == 1)
			{
				ft_swap(&fichierLu[0][i], &fichierLu[0][i+1]);
				bol = 0;
			}
			i++;
		}
	}
	return(fichierLu);
}