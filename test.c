#include "file.h"


int main()
{
    char **tab;

    tab = (char **)malloc(sizeof(char *) * 2);
    tab[0] = ft_strdup("ameno");
    tab[1] = NULL;
    free(tab);
    free(tab[0]);
    free(tab[1]);
}