#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<pair<int, int>> segTree;
int n;
string s;

pair<int, int> init(int start, int end, int node) {
    if (start == end) return segTree[node] = {v[start], start + 1};
    int mid = (start + end) / 2;
    return segTree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

void update(int start, int end, int node, int idx, int val) {
    if (idx < start || idx > end) return; 

    if (start == end) {
        segTree[node] = {val, idx + 1};
        v[idx] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid)
        update(start, mid, node * 2, idx, val);
    else
        update(mid + 1, end, node * 2 + 1, idx, val);

    pair<int, int> leftChild = segTree[node * 2];
    pair<int, int> rightChild = segTree[node * 2 + 1];

    if (leftChild.first < rightChild.first) {
        segTree[node] = leftChild;
    } else if (leftChild.first > rightChild.first) {
        segTree[node] = rightChild;
    } else {
        segTree[node] = (leftChild.second < rightChild.second) ? leftChild : rightChild;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n;
    v.resize(n);
    segTree.resize(4 * n, make_pair(0, 0));

    for (int i = 0; i < n; i++) cin >> v[i];

    init(0, n - 1, 1);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int y, z;
            cin >> y >> z;
            update(0, n - 1, 1, y - 1, z);
        } else { 
            s += to_string(segTree[1].second) + '\n';
        }
    }
    cout << s << endl;

    return 0;
}