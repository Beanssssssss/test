#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    sort(arr, arr + n);

    int mincnt = 5;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = arr[i]; j < arr[i] + 5; j++) {
            if (s.find(j) == s.end()) {
                cnt++;
            }
        }
        if (cnt == 0) {
            cout << 0 << endl;
            return 0;
        }
        if(cnt > 0 && mincnt > cnt){
            mincnt = cnt;
        }
    }

    cout << mincnt << endl;
    return 0;
}