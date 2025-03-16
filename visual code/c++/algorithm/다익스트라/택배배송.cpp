#include <iostream>
#include <vector>
#include <queue>
#define MAX 50001
#define INF 500000001
using namespace std;
vector<pair<int, int>> v[MAX];
int d[MAX];
void dijkstra(int x){
    d[x] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(x, 0));
    while(!pq.empty()){
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i < v[current].size(); i++){
            int y = v[current][i].first;
            int ydistance = v[current][i].second + distance;
            if(ydistance < d[y]){
                d[y] = ydistance;
                pq.push(make_pair(y, -ydistance));
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    fill(d, d + n + 1, INF);
    dijkstra(1);
    cout << d[n] << endl;
    return 0;
}