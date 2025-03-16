//백준 시리얼번호
#include <iostream>
#include <algorithm>
using namespace std;

int getSum(string a){
    int n = a.length();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] - '0' <= 9 && a[i] - '0' >= 0) {
            sum += a[i] - '0';
        }
    }
    return sum;
}
bool compare(string a, string b) {
    if(a.length() == b.length()) {
        int aSum = getSum(a);
        int bSum = getSum(b);
        if(aSum == bSum) {
            return a < b;
        } else {
            return aSum < bSum;
        }
    } else {
        return a.length() < b.length();
    }
}
int main(){
    int n;
    cin >> n;
    string arr[51];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, compare);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}