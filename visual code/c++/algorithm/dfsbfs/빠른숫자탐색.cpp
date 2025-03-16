#include <iostream>
#include <queue>
using namespace std;

int d[5][5]; 
bool visited[5][5];
int dist[5][5];
int dx[4] = {1, -1, 0, 0};  
int dy[4] = {0, 0, 1, -1};

int bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    dist[sr][sc] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (d[x][y] == 1) return dist[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) { 
                if (!visited[nx][ny] && d[nx][ny] != -1) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> d[i][j];
        }
    }
    
    int sr, sc;
    cin >> sr >> sc;

    cout << bfs(sr, sc) << endl;
    return 0;
}