#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int i, j;

    for (i = 1; i <= 100000; i++) {
        int temp = (int)sqrt(i);
        int flag = 0;
        for (j = 1; j <= temp; j++) {
            if(i % j != 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout << i << endl;
    }
}