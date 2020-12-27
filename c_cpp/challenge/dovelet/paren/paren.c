#include <stdio.h>
#include <stdlib.h>

char array[31];

int main() {
    freopen("input.txt", "r", stdin);
    memset(array, 0, 31);

    int i = 0;
    for(i = 0; i <= 30; i++) {
        scanf("%c", &array[i]);
    }

    

    return 0;
}