#include <iostream>
#include <algorithm>
using namespace std;
string arr[20001];
bool compare(string a, string b) {
    if(a.length() == b.length()) {
        return a < b;
    } else {
        return a.length() < b.length();
    }
}
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++)
    {
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        cout << arr[i] << '\n';
    }

    return 0;
}