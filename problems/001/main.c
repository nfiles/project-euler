/*
    Usage:
    $ gcc main.c -o sln
    $ ./sln
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    const int MAX = 1000;
    int sum = 0;
    int i;

    for (i = 1; i < MAX; ++i) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }

    printf("%d\n", sum);
    return 0;
}
