#include <iostream>
#include <string>
using namespace std;

int main(){
    int L, R;
    cin >> L >> R;
    string sL = to_string(L);
    string sR = to_string(R);
    if(sL.size() != sR.size()){
        cout << 0 << endl;
        return 0;
    }
    int min8 = 0;
    for(int i = 0; i < sL.size(); i++){
        if(sL[i] != sR[i]) break;
        if(sL[i] == '8') min8++;
    }
    cout << min8 << endl;
}