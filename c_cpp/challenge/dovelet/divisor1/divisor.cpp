#include <iostream>
#include <math.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    
    unsigned long long int input1;
    unsigned long long int input2;

    cin >> input1;
    cin >> input2;

    unsigned long long int root1 = ceil(sqrt(input1));
    unsigned long long int root2 = floor(sqrt(input2));
    
    unsigned long long int count = root2 - root1 + 1;
    unsigned long long int sum = 0;
    for(int i = root1; i <= root2; i++) {
        sum += pow(i, 2);
        sum %= 1000000003;
    }

    cout << count << " " << sum << endl;

    return 0;
}