#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF = 300001;
vector<pair<int, int>> *v;
int *d;
void dijkstra(int X, int N, int K){
    d[X] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(X, 0));
    while(!pq.empty()){
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i < v[current].size(); i++){
            int next = v[current][i].first;
            int nextDistance = distance + v[current][i].second;
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        if(i == X) continue;
        if(d[i] == K){
            cout << i << endl;
            cnt++;
        }
    }
    if(cnt == 0) cout << -1 << endl;
}
int main(){
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    v = new vector<pair<int, int>>[N + 1];
    d = new int[N + 1];
    fill(d, d + N + 1, INF);
    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        v[start].push_back(make_pair(end, 1));
    }
    dijkstra(X, N, K);
    return 0;
}