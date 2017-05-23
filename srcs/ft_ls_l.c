#include "ft_ls.h"

int ft_max_li(int nbr)
{
	int i;

	i = 0;
	if(nbr == 0)
		return (1);
	while(nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return(i);
}
int is_open(char *str, char *str2)
{
	struct stat s;
	int i;
	char *test;

	if(!(test = ft_strjoin(str, "/")))
		return (-1);
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return (-1);
	}
	free(test);
	//printf("%s", str);
	if(lstat(str, &s) == -1)
	{

		free(str);
		return (-1);
	}
	free(str);
	return(1);
}

int ft_max_l(char *str, char *str2)
{
	struct stat s;
	int i;
	char *test;

	if(!(test = ft_strjoin(str, "/")))
		return (-1);
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return (-1);
	}
	free(test);
	if(lstat(str, &s) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);




	i = 0;
	while(s.st_nlink > 0)
	{
		s.st_nlink = s.st_nlink /10;
		i++;
	}
	return(i);
}


int ft_max_size(char *str, char *str2)
{
	struct stat s;
	int i;
	char *test;

	if(!(test = ft_strjoin(str, "/")))
		return (1);
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return (1);
	}
	free(test);
	//printf("%s", str);
	if(lstat(str, &s) == -1)
	{

		free(str);
		return (1);
	}
	free(str);
	if(s.st_size == 0)
		i++;

	i = 0;
	while(s.st_size > 0)
	{
		s.st_size = s.st_size /10;
		i++;
	}
	return(i);
}

int ft_max_name(char *str, char *str2)
{
	struct stat s;
	int i;
	struct passwd *uid;
	char *test;

	if(!(test = ft_strjoin(str, "/")))
		return (-1);
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return (-1);
	}
	free(test);
	if(lstat(str, &s) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	if(!(uid = getpwuid(s.st_uid)))
		return(0);



	return(ft_strlen(uid->pw_name));
}

int ft_max_dev(char *str, char *str2)
{
	struct stat s;
	int i;
	struct passwd *uid;
	char *test;

	if(!(test = ft_strjoin(str, "/")))
		return (-1);
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return (-1);
	}
	free(test);
	if(lstat(str, &s) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	i = ft_max_li(major(s.st_rdev)) +2;


	return(i);
}

int ft_max_dev4(char *str, char *str2)
{
	struct stat s;
	int i;
	struct passwd *uid;
	char *test;

	if(!(test = ft_strjoin(str, "/")))
		return (-1);
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return (-1);
	}
	free(test);
	if(lstat(str, &s) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	i = ft_max_li(minor(s.st_rdev));


	return(i);
}

int ft_max_dev2(struct stat s)
{
	int i;
	struct passwd *uid;
	char *test;


	i = ft_max_li(major(s.st_rdev)) + 2;



	return(i);
}

int ft_max_dev3(struct stat s)
{
	int i;
	struct passwd *uid;
	char *test;


	i = ft_max_li(minor(s.st_rdev));



	return(i);
}

int ft_max_group(char *str, char *str2)
{
	struct stat s;
	int i;
	struct group *gid;
	char *test;

	if(!(test = ft_strjoin(str, "/")))
		return (-1);
	if(!(str = ft_strjoin(test, str2)))
	{
		free(test);
		return (-1);
	}
	free(test);
	if(lstat(str, &s) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);



	if(!(gid = getgrgid(s.st_gid)))
		return (0);

	return(ft_strlen(gid->gr_name));
}

int ft_count_month(char *str)
{
	if((ft_strncmp(str, "jan", 3)))
		return(1);
	if((ft_strncmp(str, "Feb", 3)))
		return(2);
	if((ft_strncmp(str, "Mar", 3)))
		return(3);
	if((ft_strncmp(str, "Apr", 3)))
		return(4);
	if((ft_strncmp(str, "May", 3)))
		return(5);
	if((ft_strncmp(str, "Jun", 3)))
		return(6);
	if((ft_strncmp(str, "Jul", 3)))
		return(7);
	if((ft_strncmp(str, "Aug", 3)))
		return(8);
	if((ft_strncmp(str, "Sep", 3)))
		return(9);
	if((ft_strncmp(str, "Oct", 3)))
		return(10);
	if((ft_strncmp(str, "Nov", 3)))
		return(11);
	if((ft_strncmp(str, "Dec", 3)))
		return(12);
	return(0);
}

int ft_6month(char *str, int anner, struct stat s)
{
	int time1;
	int time2;
	struct time_t *t;

	time1 = time(&s.st_mtime);

	time2 = ft_absolut(time1 - (ft_atoi(str + 14) + ft_atoi(str + 11) * 60 + ft_atoi(str + 8) * 60 * 60 + ft_atoi(str + 5) * 24 * 60 * 60 + ft_count_month(str) * 30.5 * 24 * 60 * 60 + (anner - 1970) * 12 * 30.5 * 24 * 60 * 60)); // segonde en (anner - 1990) + (mois) en segonde + (jour) segonde + (heur) segonde + (minute) segonde 
	
	if(time2 > time1)
		return (1);
//	printf("-->%d  > %d", time2, 15811200);
//	printf("-->%s", str);
	return(0);
}

void ft_affiche(char *str, char *str2, t_glob *g)
{
	struct stat s;
	struct passwd *uid;
	struct group *gid;
	char *str3; 
	char *test;
	char *test2;
	int mode;
	int time1;
	int yolo = 0;

	test2 = str;
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

	if(!(uid = getpwuid(s.st_uid)))
		return ;
	if(!(gid = getgrgid(s.st_gid)))
		return ;
	/*if(!(ctime(&s.st_ctime)))

		return ;*/

	ft_mod(s, &mode);

	//printf("--->%d\n", major(s.st_rdev));
	//printf("-->%d\n", s.st_rdev);
	if(mode == 1)
	{
	//	time = time(s.st_mtime);
		str3 = ctime(&s.st_mtime);
	}
	else if(mode == 2)
	{
	//	time = time(s.st_mtime)
		str3 = ctime(&s.st_mtime);
	}
	else
	{
	//	time = time(s.st_mtime)
		str3 = ctime(&s.st_mtime);
	}
	str3 = str3 + 3;
	mode = ft_atoi(str3 + 17);
	time1 = ft_6month(str3, mode, s);
	str3[strlen(str3) - 9] = 0;
	
	yolo = 0;
	while(ft_absolut(g->max_lien - ft_max_li(s.st_nlink)) - yolo + 1 > 0)
	{
		printf(" ");
		yolo++;
	}
	printf("%d ", s.st_nlink);
	yolo = 0;
//	while(ft_absolut(g->max_name - ft_strlen(uid->pw_name)) - yolo > 0)
//	{
//		printf(" ");
//		yolo++;
//	}
	printf("%s  ", uid->pw_name);
	yolo = 0;
	//printf("->%d", ft_absolut(ft_strlen(uid->pw_name) - g->max_name));
	while(ft_strlen(uid->pw_name) < g->max_name && ft_strlen(uid->pw_name) < g->max_name - yolo)
	{
		printf(" ");
		yolo++;
	}
	printf("%s ", gid->gr_name);
	//printf("-->%s|,", test2);






	if (ft_strcmp(test2, "/dev") != 0)
	{
		yolo = 0;
		while(ft_absolut(g->max_size - ft_max_li(s.st_size)) - yolo + 1 > 0)
		{
			printf(" ");
			yolo++;
		}

			printf("%lld", s.st_size);
	}
	else
	{
		yolo = 0;
		//printf("-->%d\n", g->max_dev);
		while(strlen(gid->gr_name) < g->max_group - yolo)
		{
			printf(" ");
			yolo++;
		}
		yolo = 0;
		//printf("-->%d\n", g->max_dev);
		while(g->max_dev > ft_max_dev2(s) + yolo)
		{
			printf(" ");
			yolo++;
		}
		printf("%d, ", major(s.st_rdev));
		//printf("%d, %d", major(s.st_rdev), minor(s.st_rdev));


		//printf("->%d -- %d\n", ft_max_dev3(s), minor(s.st_rdev));
		yolo = 0;
		while(g->max_dev2 > ft_max_dev3(s) + yolo)
		{
			printf(" ");
			yolo++;
		}
		printf("%d", minor(s.st_rdev));


	}









	if(time1 == 0)
		printf("%s ", str3);
	else
	{
		str3[strlen(str3) - 5] = 0;
		printf("%s", str3);
		printf("%d ", mode);
	}
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



	if(mode == 1)
		str3 = ctime(&s.st_mtime);
	else if(mode == 2)
		str3 = ctime(&s.st_mtime);
	else
		str3 = ctime(&s.st_mtime);
	str3 = str3 + 3;
	mode = ft_atoi(str3 + 17);
		ft_6month(str3, mode, s);
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
	if(ft_strcmp(str, "/dev") != 0)
		printf("total : %d\n", ft_test2(str, g));
	if(ft_strcmp(str, "/dev") == 0)
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
		if(ft_max_dev(str, fichierLu[i]->d_name) > g->max_dev)
			g->max_dev = ft_max_dev(str, fichierLu[i]->d_name);
		if(ft_max_dev4(str, fichierLu[i]->d_name) > g->max_dev2)
			g->max_dev2 = ft_max_dev4(str, fichierLu[i]->d_name);
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
		if(fichierLu[i]->d_name[0] != '.' || g->flag_a == 1)
		{
			if(ft_isprint(fichierLu[i]->d_name[0]) && is_open(str, fichierLu[i]->d_name) != -1)
			{
				ft_affiche(str, fichierLu[i]->d_name, g);
    			printf("%s\n", fichierLu[i]->d_name);
    		}
    		//printf("\n");
		}
    	i++;
	}
	if (closedir(rep) == -1)
        exit(-1);
}