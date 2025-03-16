#include <iostream>
#include <queue>
#define MAX 2222
#define INF 10000000
using namespace std;
int d[MAX][MAX];
long long dist[MAX][MAX];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int n;
int dijkstra(){
    queue<pair<int, int>> pq;
    pq.push({0, 0});
    dist[0][0] = 0;
    while(!pq.empty()){
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();
        int distance = dist[x][y];
        if(x == n - 1 && y == n - 1) return dist[x][y];
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int next_distance = (d[nx][ny] >= d[x][y]) ? (d[nx][ny] - d[x][y] + 1) : 0;
                if (next_distance + distance < dist[nx][ny]) {
                    dist[nx][ny] = next_distance + distance;
                    pq.push({nx, ny});
                }
            }
        }
    }
    return INF;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> d[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = INF;
        }
    }
    cout << dijkstra() << endl;
}