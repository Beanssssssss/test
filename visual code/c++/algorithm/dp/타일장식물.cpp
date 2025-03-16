#include <iostream>
#include <vector>
using namespace std;
vector<long long> dp;

int main(){
    int n;
    cin >> n;
    dp.resize(n + 3, 0);
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n + 2; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    if(n == 1){
        cout << 4 << endl;
    } else{
        cout << dp[n + 1] * 2 + dp[n] * 2 << endl;
    }
    return 0;
}
