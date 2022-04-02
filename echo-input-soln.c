#include <stdio.h>

#define BUF_SIZE 120

int main()
{
    char buf[BUF_SIZE];

    while (1) {
        fgets(buf, BUF_SIZE, stdin);
        printf("You printed %s\n", buf);
    }

}