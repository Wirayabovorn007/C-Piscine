#include <unistd.h>

int len(char *c)
{
    int i;

    i = 0;
    while (c[i])
        i++;
    return (i);
}

int main(int argc, char *argv[])
{
    int i;
    int j;

    i = argc - 1;
    while (i > 0)
    {
        j = 0;
        while (j < len(argv[i]))
        {
            write(1, &argv[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i--;
    }
}
