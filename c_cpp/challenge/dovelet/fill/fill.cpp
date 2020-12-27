#include <iostream>
#include <math.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    float speed;
    float weight;
    float power;

    cin >> speed;
    cin >> weight;
    cin >> power;

    if(speed <= 4.5) {
        if(150 <= weight < 300) {
            if(200 <= power < 500) {
                cout << "Wide Receiver" << endl;
            }
            else if(500 <= power) {
                cout << "Lineman" << endl;
            }
        }
    }

    return 0;
}