#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    long long N;
    cin >> N;
    if(N % 2 == 0)
        cout << "CY" << endl;
    else
        cout << "SK" << endl;
    return 0;
}