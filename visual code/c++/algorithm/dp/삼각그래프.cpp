#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    int N, test_case = 1;
    string s;
    
    while (true) {
        cin >> N;
        if (N == 0) {
            cout << s;
            break;
        }
        vector<vector<int>> graph(N, vector<int>(3));
        vector<vector<int>> dp(N, vector<int>(3));

        for (int i = 0; i < N; i++) {
            cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        }

        dp[0][0] = 1e9;
        dp[0][1] = graph[0][1]; 
        dp[0][2] = dp[0][1] + graph[0][2]; 

        for (int i = 1; i < N; i++) {
            dp[i][0] = graph[i][0] + min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = graph[i][1] + min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]});
            dp[i][2] = graph[i][2] + min({dp[i-1][1], dp[i-1][2], dp[i][1]});
        }

        ostringstream result;
        result << test_case++ << ". " << min(dp[N-1][1], dp[N-1][0] + graph[N-1][1]) << '\n';
        s += result.str();
    }

    return 0;
}