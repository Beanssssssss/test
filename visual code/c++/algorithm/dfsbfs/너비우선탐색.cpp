#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;
vector<int> vec[MAX];
bool visited[MAX];
int idx = 1;
int order[MAX];
void bfs(int start){
    visited[start] = true;
    queue<int> pq;
    pq.push(start);
    while(!pq.empty()){
        int x = pq.front();
        pq.pop();
        order[x] = idx++;
        for(int n : vec[x]){
            if(!visited[n]){
                visited[n] = true;
                pq.push(n);
            }
        }
    }
}
int main(){
    int n, m ,r;
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(vec[i].begin(), vec[i].end());
    }
    bfs(r);
    for(int i = 1; i <= n; i++){
        cout << (order[i] == 0 ? 0 : order[i]) << '\n';
    }
    return 0;
}