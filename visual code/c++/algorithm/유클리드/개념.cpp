#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;

    cin >> a >> b;
    
    cout << "최대공약수: " << gcd(a, b) << endl;
    return 0;
}