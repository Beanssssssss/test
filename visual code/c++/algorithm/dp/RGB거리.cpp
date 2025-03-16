#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int dp[MAX][3];
int cost[MAX][3];
int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
