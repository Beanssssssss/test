#include <iostream>
using namespace std;
#define MAX 1001
long d[MAX][MAX];
long dp(int x, int y){
    if(x == 1 || y == 1) return 1;
    if(d[x][y] != 0) return d[x][y];
    return d[x][y] = (dp(x - 1, y) + dp(x, y - 1) + dp(x - 1, y - 1)) % 1000000007;
}
int main(){
    int n, m;
    cin >> n >> m;
    cout << dp(n, m)<< endl;
}