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

    if(S_TYPEISMQ (s))
        printf("@");
}
