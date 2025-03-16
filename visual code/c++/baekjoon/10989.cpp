//매우빠르게 정렬
#include <iostream>

using namespace std;

int a[10001];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 0; i < 10001; i++) {
        while(a[i] != 0) {
            cout << i << '\n';
            a[i]--;
        }
    }
    return 0;
}