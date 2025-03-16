#include <iostream>

using namespace std;

long d[36];
long dp(int x){
    if(x == 0) return 1;
    if(d[x]!=0) return d[x];
    long result = 0;
    for(int i = 0; i < x; i++){
        result += dp(i) * dp(x - i - 1);
    }
    return d[x] = result;
}
int main(){
    int n;
    cin >> n;
    cout << dp(n) << endl;
}