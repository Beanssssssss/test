#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> *v;
int *d;
bool *c;

bool dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) { 
        int t = v[x][i];
        if (c[t]) continue;
        c[t] = true;
        if (d[t] == 0 || dfs(d[t])) {
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;
        
    
        v = new vector<int>[M + 1];
        d = new int[N + 1]();  // 0으로 초기화
        c = new bool[N + 1](); // false로 초기화

        for (int j = 1; j <= M; j++) {
            int a, b;
            cin >> a >> b;
            for (int k = a; k <= b; k++) {
                v[j].push_back(k);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= M; i++) {
            fill(c, c + N + 1, false);
            if (dfs(i)) cnt++;
        }

        cout << cnt << endl;

        delete[] v;
        delete[] d;
        delete[] c;
    }

    return 0;
}