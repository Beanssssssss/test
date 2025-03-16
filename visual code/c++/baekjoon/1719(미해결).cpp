//택배
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 1001;
vector<pair<int, int>> *v1;

void dijkstra(int start, int n){
    int d[n + 1];
    int v2[n + 1];
    fill(v2, v2 + n + 1, INF);
    fill(d, d + n + 1, INF);
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));
    int cnt = 0;
    while(!pq.empty()){
        cnt++;
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i < v1[current].size(); i++){
            int next = v1[current][i].first;
            int nextDistance = distance + v1[current][i].second;
            if(nextDistance < d[next]){
                if(cnt == 1){
                    v2[next] = next;
                } else{
                    v2[next] = v2[current];
                }
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(i == start or v2[i] == INF){
            cout << "-" << " ";
        }
        else{
            cout << v2[i] << " ";
        }
    }
    cout << endl;
}
int main(){
    int n, m;
    cin >> n >> m;
    v1 = new vector<pair<int, int>>[n + 1];
    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v1[from].push_back(make_pair(to, cost));
        v1[to].push_back(make_pair(from, cost));
    }
    for(int i = 1; i <= n; i++){
        dijkstra(i, n);
    }
    delete[] v1;
    return 0;
}