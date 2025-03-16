#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<int> dp;

int main() {
    int n;
    cin >> n;
    v.resize(n);
    dp.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = n - 1; i >= 0; i--) {
        int time = v[i].first;
        int cost = v[i].second;
        
        if (i + time <= n) {
            dp[i] = max(dp[i + 1], cost + dp[i + time]);
        } else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[0] << endl;
    return 0;
}