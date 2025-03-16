#include <iostream>
#include <vector>
#include <cstring> // memset 사용
using namespace std;

vector<int> v[10];  // 그래프 인접 리스트
bool visited[10];    // 방문 여부
int d[10][2];        // 매칭 결과 (각 노드당 2개 매칭 가능)

bool dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        int t = v[x][i];
        if (visited[t]) continue;
        visited[t] = true;
        // t가 첫 번째 또는 두 번째 자리 비어 있으면 매칭
        if (d[t][0] == -1) {
            d[t][0] = x;
            return true;
        } else if (d[t][1] == -1) {
            d[t][1] = x;
            return true;
        }
        // 자리 차 있으면 기존 매칭된 노드와 재배치 시도
        if (dfs(d[t][0])) {
            d[t][0] = x;
            return true;
        } else if (dfs(d[t][1])) {
            d[t][1] = x;
            return true;
        }
    }
    return false;
}

int main() {
    // 그래프 연결 정보 추가
    v[1].push_back(2);
    v[1].push_back(3);
    v[2].push_back(2);
    v[2].push_back(1);
    v[3].push_back(1);
    
    memset(d, -1, sizeof(d));  // -1로 초기화 (매칭 없는 상태)

    for (int i = 1; i < 4; i++) {
        memset(visited, false, sizeof(visited));  // 모든 노드 방문 초기화
        dfs(i);
    }

    for (int i = 1; i < 4; i++) {
        cout << i << " -> ";
        if (d[i][0] != -1) cout << d[i][0] << " ";
        if (d[i][1] != -1) cout << d[i][1];
        cout << endl;
    }

    return 0;
}