#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool d[51][51];
int c[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int, int>> pq;
int bfs(int m, int n) {
    int cnt = 0;
    
    while (!pq.empty()) {
        pair<int, int> x = pq.front();
        pq.pop();

        if (!d[x.first][x.second]) continue;
        d[x.first][x.second] = false;

        queue<pair<int, int>> q;
        q.push(x);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + c[i][0];
                int ny = cur.second + c[i][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (d[nx][ny]) {
                    d[nx][ny] = false;
                    q.push({nx, ny});
                }
            }
        }
        cnt++;
    }
    return cnt;
}
int main(){
    int t;
    cin >> t;
    string s;
    for(int i = 0; i < t; i++){
        int m, n, k;
        cin >> m >> n >> k;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = false;
            }
        }
        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            d[x][y] = true;
            pq.push(make_pair(x, y));
        }
        s += to_string(bfs(m, n)) + "\n";
    }
    cout << s << endl;
    return 0;
}