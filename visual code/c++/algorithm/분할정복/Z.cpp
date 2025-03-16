#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N, r, c;
    cin >> N >> r >> c;
    int ans = 0;
    for(int i = N; i > 1; i--){
        int mid = (1 << (i - 1));
        int idx = 1 << (2 * (i - 1));
        if(r >= mid){
            if(c >= mid){
                ans += idx * 3;
                r -= mid;
                c -= mid;
            } else{
                ans += idx * 2;
                r -= mid;     
            }
        }
        else{
            if(c >= mid){
                ans += idx * 1;
                c -= mid;
            } 
        }
    }
    ans += 2 * r + c;
    cout << ans << endl;
}