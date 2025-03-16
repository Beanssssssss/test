#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long> v(N);
    vector<pair<long, long>> vec;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    long vmin = 10000000000;
    int i = 0;
    int j = N - 1;
    while(i < j){
        long sum = v[i] + v[j];
        if(abs(sum) < vmin){
            vec.clear();
            vec.push_back(make_pair(v[i], v[j]));
            vmin = abs(sum);
        }
        if(sum < 0){
            i++;
        } else if(sum > 0){
            j--;
        } else{
            break;
        }
        
    }
    cout << vec[0].first << " " << vec[0].second << endl;
    return 0;
}