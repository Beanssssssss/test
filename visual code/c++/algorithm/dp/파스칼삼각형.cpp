#include <iostream>
#include <vector>
using namespace std;
int d[31][31];
int dp(int r, int c){
    if(r == 1) return 1;
    if(r == 2) return 1;
    if(d[r][c] != 0) return d[r][c];
    int result = 0;
    if(c <= 1) result = 1;
    else if(c >= r) result = 1;
    else result = dp(r - 1, c - 1) + dp(r - 1, c);

    return d[r][c] = result;


}
int main(){
    int r, c, w;
    cin >> r >> c >> w;
    d[1][1] = 1;
    d[2][1] = 1;
    d[2][2] = 1;
    int sum = 0;
    int rr = r;
    int j = r;
    for(int i = c; i <= c + w - 1; i++){
        for(j = rr; j <= r + w - 1; j++){
            sum += dp(j, i);
            
        }
        rr++;
    }
    cout << sum << endl;
}