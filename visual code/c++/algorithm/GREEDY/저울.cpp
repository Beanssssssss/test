#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
// 5까지 만들어졌다는 것은 
int main(){
    int n;
    cin >> n;
    int target = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(target < a[i]) break;
        target += a[i];
    }
    cout << target << endl;
    return 0;
}