#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int d[MAX];
bool dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 0;
    if(x == 3) return 1;
    if(x == 4) return 1;
    if(d[x] != 0) return d[x];
    int x1, x3, x4;
    x1 = (dp(x - 1) + 1) % 2;
    x3 = (dp(x - 3) + 1) % 2;
    x4 = (dp(x - 4) + 1) % 2;
    if(x1 == 1 || x3 == 1 || x4 == 1){
        return d[x] = 1;
    }
    return d[x] = 0;
        

}
int main(){
    int N;
    cin >> N;
    if(dp(N) % 2 == 0){
        cout << "CY" << endl;
    } else{
        cout << "SK" << endl;
    }
    return 0;
}