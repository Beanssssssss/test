#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long N;
    cin >> N;
    bool b[21];
    b[0] = false;
    b[1] = true;
    b[2] = false;
    b[3] = true;
    b[4] = true;
    N = N % 5;
    cout << (b[N] ? "SK" : "CY") << endl;
    return 0;
}