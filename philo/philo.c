
#include "philo.h"

int ft_error(char *msg)
{
    printf("Error : %s\n", msg);
    exit(1);
}

void check_args(int argc, char *argv[])
{
    int index;
    int i;

    if (argc != 5 && argc != 6)
        ft_error("You need more args");
    index = 1;
    while (index < argc)
    {
        i = 0;
        while (argv[index][i] != '\0')
        {
            if (!ft_isspace(argv[index][i]) && !ft_isdigit(argv[index][i]) && argv[index][i] != '+')
                ft_error("You have wrong char in args");
            i++;
        }
        index++;
    }
    
}

int main(int argc, char *argv[])
{
    check_args(argc, argv);
    for (int i = 1; i< argc; i++)
        printf("%s\n", argv[i]);
}