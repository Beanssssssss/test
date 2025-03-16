#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;
int d[MAX];
int dp(int x){
    if(x == 1) return 1; //홀수 상근 짐 짝수 상근 이김
    if(x == 2) return 0;
    if(x == 3) return 1;
    if(x == 4) return 0;
    if(d[x] != -1) return d[x];
    int x1, x3, x4;
    x1 = (dp(x - 1) + 1) % 2;
    x3 = (dp(x - 3) + 1) % 2;
    x4 = (dp(x - 4) + 1) % 2;
    if(x1 == 0 || x3 == 0 || x4 == 0){
        return d[x] = 0;
    }
    return d[x] = 1;
}
int main(){
    int N;
    cin >> N;
    memset(d, -1, sizeof(d));
    if(dp(N) == 0){
        cout << "SK" << endl;
    } else{
        cout << "CY" << endl;
    }
    return 0;
}
