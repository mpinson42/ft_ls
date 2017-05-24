#include "ft_ls.h"

void ft_mod(struct stat s, int *mode)
{
    if (S_ISREG (s.st_mode))
        printf ("-");
    if (S_ISLNK (s.st_mode))
        printf ("l");
	if (S_ISDIR (s.st_mode))
    {
        mode[0] = 1;
        printf ("d");
    }
    if (S_ISFIFO (s.st_mode))
        printf ("p");
    if (S_ISBLK (s.st_mode))
        printf ("b");
    if (S_ISCHR (s.st_mode))
        printf ("c");






    if (s.st_mode & S_IRUSR)
        printf ("r");
    else
    	printf("-");
    if (s.st_mode & S_IWUSR)
        printf ("w");
    else
    	printf("-");



    if(s.st_mode & S_ISUID)
    {
        if(s.st_mode & S_IXUSR)
            printf("s");
        else
            printf("S");
    }
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
    if(s.st_mode & S_ISGID)
    {
        if(s.st_mode & S_IXGRP)
            printf("s");
        else
            printf("S");
    }
    else if (s.st_mode & S_IXGRP)
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
    if(s.st_mode & S_ISVTX)
    {
        if(s.st_mode & S_IXOTH)
            printf("t");
        else
            printf("T");
    }
    else if (s.st_mode & S_IXOTH)
        printf ("x");
    else
    	printf("-");


}
