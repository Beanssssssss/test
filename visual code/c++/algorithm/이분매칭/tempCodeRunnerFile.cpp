#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 10001; // 해시 테이블 최대 크기
vector<int> v[MAX_N];    // 해시 충돌을 처리하기 위한 그래프
int d[MAX_N];            // 매칭 정보
bool c[MAX_N];           // 방문 체크

// 깊이 우선 탐색 (DFS)로 매칭 시도
bool dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        int y = v[x][i]; // y는 해시 테이블의 위치
        if (c[y]) continue; // 이미 방문한 위치면 넘어감
        c[y] = true;

        // 아직 매칭되지 않았거나, 기존 매칭을 밀어내고 가능하면 갱신
        if (d[y] == -1 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int M, N;
        cin >> M >> N;

        // 초기화
        for (int i = 0; i < N; i++) v[i].clear();
        memset(d, -1, sizeof(d));

        // 입력 받기
        for (int i = 0; i < M; i++) {
            int h1, h2;
            cin >> h1 >> h2;
            v[i].push_back(h1);
            v[i].push_back(h2);
        }

        // 매칭 실행
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            memset(c, false, sizeof(c)); // 방문 배열 초기화
            if (dfs(i)) cnt++; // dfs 성공하면 매칭 증가
        }

        // 결과 출력
        cout << (cnt == M ? "successful hashing" : "rehash necessary") << endl;
    }

    return 0;
}