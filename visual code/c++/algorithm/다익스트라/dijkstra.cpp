#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int>> a[7];
int d[7];

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));
    while(!pq.empty()){
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i < a[current].size(); i++){
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}
int main(void){
    for(int i = 1; i <= number; i++){
        d[i] = INF;
    }
    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    /*
    간선추가...
    */
   dijkstra(1);
   // 1이든 뭐든 원하는 값 start
   for(int i = 1; i <= number; i++){
    cout << i << " ";
   }
   return 0;
}