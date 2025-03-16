#include <iostream>

using namespace std;
int main(){
    long long N;
    cin >> N;
    bool dp1 = true;
    bool dp2 = false;
    bool dp3 = true;
    bool dp4 = true;
    bool dp5 = true;
    bool dp6 = true;
    bool dp7 = false;
    N = N % 7;
    if(N == 2 || N == 0) cout << "CY" << endl;
    else cout << "SK" << endl;
    
    return 0;
}