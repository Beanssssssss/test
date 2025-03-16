#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(abs(x - s));
    }
    if(n == 1) cout << v[0] << endl;
    else{
        for(int i = 1; i < v.size(); i++){
            v[i] = gcd(v[i], v[i - 1]);
        }
        cout << v.back() << endl;
    }
    return 0;
}