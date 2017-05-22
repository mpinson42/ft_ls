#include "ft_ls.h"

void ft_mod(struct stat s)
{
	if (S_ISDIR (s.st_mode))
        printf ("d");
 /*   else if (S_IFLNK (s.st_mode))
        printf ("l");*/
    else
    	printf("-");






    if (s.st_mode & S_IRUSR)
        printf ("r");
    else
    	printf("-");
    if (s.st_mode & S_IWUSR)
        printf ("w");
    else
    	printf("-");
    if (s.st_mode & S_IXUSR)
        printf ("x");
    else
    	printf("-");

    if (s.st_mode & S_IRGRP)
        printf ("r");
    else
    	printf("-");
    if (s.st_mode & S_IWGRP)
        printf ("w");
    else
    	printf("-");
    if (s.st_mode & S_IXGRP)
        printf ("x");
    else
    	printf("-");

    if (s.st_mode & S_IROTH)
        printf ("r");
    else
    	printf("-");
    if (s.st_mode & S_IWOTH)
        printf ("w");
    else
    	printf("-");
    if (s.st_mode & S_IXOTH)
        printf ("x\t");
    else
    	printf("-\t");	
}
