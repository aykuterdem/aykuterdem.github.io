#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int transform(int num) {
    num <<= 2;
    num++;
    if (num > 50) {
        num--;
    }
    return num;
}

bool escape_room(char *a) {
    int num = atoi(a);
    num = transform(num);

    if (num % 2 == 0) {
        return true;
    }

    return false;
}

int main(int argc, char *argv[]) {
    bool result = escape_room(argv[1]);
    if (result) {
        printf("You escaped!!\n");
    } else {
        printf("Incorrect.\n");
    }

    return 0;
}
