#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
bool visited[101][101];
char d[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
vector<int> ans;
int bfs(int x, int y, char s){
    queue<pair<int, int>> q;
    visited[x][y] = true;
    int cnt = 1;
    q.push(make_pair(x, y));
    while(!q.empty()){
        int kx = q.front().first;
        int ky = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = kx + dx[i];
            int ny = ky + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                if(!visited[nx][ny] && d[nx][ny] == s){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            d[i][j] = s[j];
        }
    }
    int w = 0;
    int b = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                int ans = 0;
                if(d[i][j] == 'W'){
                    ans = bfs(i, j, d[i][j]);
                    w += ans * ans;
                } else{
                    ans = bfs(i, j, d[i][j]);
                    b += ans * ans;
                }
            }
        }
    }
    cout << w << " " << b << endl;
    return 0;
}