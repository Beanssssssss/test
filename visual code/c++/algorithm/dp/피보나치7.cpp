#include <iostream>
#define MAX 1000001
using namespace std;

long long d[MAX];
long long dp(int x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(d[x] != 0) return d[x];
    return d[x] = (dp(x - 1) + dp(x - 2)) % 1000000007;
}

int main(){
    int n;
    cin >> n;
    cout << dp(n) << endl;
    return 0;
}

