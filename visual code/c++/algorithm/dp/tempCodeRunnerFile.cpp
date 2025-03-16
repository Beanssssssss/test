#include <iostream>
#include <vector>
using namespace std;
vector<int> v(1001);

int main(){
    int n;
    cin >> n;
    for(int i=1; i <= n; i++){
        cin >> v[i];
    }
    int max = 0;
    for(int i = 1; i <= n - 1; i++){
        int copy = i;
        int j = i + 1;
        int cnt = 1;
        while(j <= n){
            if(v[copy] < v[j]){
                cnt++;
                copy = j;
                j++;
            } else{
                j++;
                continue;
            }
            
        }
        if(max < cnt){
            max = cnt;
        }
    }
    cout << max << '\n';
    return 0;
}