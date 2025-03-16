#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 10001;
int N, D;
vector<pair<int, int>> shortcuts[10001];
int dist[10001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));
    dist[0] = 0;

    while (!pq.empty()) {
        int curPos = pq.top().first;
        int curDist = -pq.top().second;
        pq.pop();

        if (dist[curPos] < curDist) continue;

        if (curPos + 1 <= D && dist[curPos + 1] > curDist + 1) {
            dist[curPos + 1] = curDist + 1;
            pq.push(make_pair( curPos + 1, -dist[curPos + 1]));
        }

        for (int i = 0; i < shortcuts[curPos].size(); i++) {
            int nextPos = shortcuts[curPos][i].first;
            int cost = shortcuts[curPos][i].second;

            if (nextPos <= D && dist[nextPos] > curDist + cost) {
                dist[nextPos] = curDist + cost;
                pq.push(make_pair(nextPos, -dist[nextPos]));
            }
        }
    }
}

int main() {
    cin >> N >> D;
    
    fill(dist, dist + 10001, INF);

    for (int i = 0; i < N; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        if (end > D || start > D) continue;
        shortcuts[start].push_back(make_pair(end, cost));
    }

    dijkstra(0);

    cout << dist[D] << "\n";
    return 0;
}