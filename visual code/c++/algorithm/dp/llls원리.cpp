#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v(1001);
vector<int> dp(1001, 1);
void dpdp(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    dpdp(n);
    cout << *max_element(&dp[0], &dp[n]) << '\n';
    return 0;
}