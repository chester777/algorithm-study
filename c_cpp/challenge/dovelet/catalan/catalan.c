#include <stdio.h>
#include <stdlib.h>

int catalan_flag = 1;

int main() {
    freopen("input.txt", "r", stdin);
    
    int n;
    scanf("%d", &n);

    int array[n];
    memset(array, 0x00, n);

    int i, j;
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int start_index = 0;

    for(i = 0; i < n-1; i++) {
        if(array[i] < array[i+1]) {
            for(j = start_index; j < i; j++) {
                if(array[j]-1 != array[j+1]) {
                    catalan_flag = 0;
                    break;
                }
            }
            start_index = i+1;    
        }
        if(catalan_flag == 0) {
                break;
        }
    }

    if(catalan_flag == 0) printf("NO");
    else printf("YES");

    return 0;
}