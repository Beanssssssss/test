#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> dfsvisited;
vector<bool> bfsvisited;

void dfs(int x) {
    dfsvisited[x] = true;
    cout << x << " ";
    for(int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if(!dfsvisited[y]) dfs(y);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    bfsvisited[start] = true;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        
        for(int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if(!bfsvisited[y]) {
                q.push(y);
                bfsvisited[y] = true;
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;
    
    vector<bool> dfsvisited(N + 1, false);
    vector<bool> bfsvisited(N + 1, false);
    vector<vector<int>> graph(N + 1);
    
    // 그래프 입력받기
    for(int i = 0; i < M; i++) {
        int m1, m2;
        cin >> m1 >> m2;
        graph[m1].push_back(m2);
        graph[m2].push_back(m1);
    }
    
    // 각 리스트 오름차순으로 정렬
    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    // DFS, BFS 실행
    dfs(V);
    cout << endl;
    bfs(V);
    
    return 0;
}