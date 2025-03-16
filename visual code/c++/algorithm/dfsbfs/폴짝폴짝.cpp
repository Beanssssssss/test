#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[10001];
vector<int> cnt(10001, -1);

void bfs(int a, int b) {
    queue<int> q;
    q.push(a);
    cnt[a] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : v[x]) {
            if (cnt[y] == -1) {
                cnt[y] = cnt[x] + 1;
                q.push(y);
            }
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;
    
    vector<int> stone(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> stone[i];
    }

    for (int i = 1; i <= n; i++) {
        int x = stone[i];
        for (int j = i + x; j <= n; j += x) {
            v[i].push_back(j);
        }
        for (int j = i - x; j >= 1; j -= x) {
            v[i].push_back(j);
        }
    }

    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return 0;
    }

    bfs(a, b);
    cout << (cnt[b] == -1 ? -1 : cnt[b]) << '\n';
    return 0;
}