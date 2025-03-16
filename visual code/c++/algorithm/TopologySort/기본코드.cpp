#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(int N, vector<vector<int>>& adj) {
    vector<int> indegree(N, 0);  // 각 노드의 진입 차수
    queue<int> q;
    
    // 진입 차수 계산
    for (int u = 0; u < N; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }
    
    // 진입 차수가 0인 노드를 큐에 넣기
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;  // 위상 정렬 결과 저장

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // 인접 노드들의 진입 차수 감소
        for (int v : adj[node]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 위상 정렬이 가능하다면 결과 출력
    if (topoOrder.size() == N) {
        for (int node : topoOrder) {
            cout << node + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "Cycle detected! Topological Sort not possible." << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;  // N: 노드 수, M: 간선 수
    
    vector<vector<int>> adj(N);

    // 간선 입력 받기
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);  // u -> v로 간선 추가
    }

    topologicalSort(N, adj);

    return 0;
}