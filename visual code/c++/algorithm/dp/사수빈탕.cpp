#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int dp[301][301];
int grid[301][301];

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = m;
    }
    
    for (int x = 0; x <= 300; x++) {
        for (int y = 0; y <= 300; y++) {
            if (x == 0 && y == 0) continue;
            
            int right = (x > 0) ? dp[x-1][y] : 0;
            int up = (y > 0) ? dp[x][y-1] : 0;
            
            dp[x][y] = max(right, up);
            
            if (grid[x][y] > 0) {
                int timeElapsed = x + y;
                int remainingCandy = max(0, grid[x][y] - timeElapsed);
                dp[x][y] += remainingCandy;
            }
        }
    }
    
    cout << dp[300][300] << endl;
    return 0;
}