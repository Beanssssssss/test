#include <iostream>
#include <vector>
using namespace std;
vector<int> makeTable(vector<int> &pattern){
    int pattern_size = pattern.size();
    vector<int> table(pattern_size, 0);
    int j = 0;
    for(int i = 1; i < pattern_size; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j - 1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}
// 자 비교하다가 불일치가 나면 불일치 난 위치에서 테이블값 만큼 앞으로 이동해서 비교
void KMP(vector<int> &parent, vector<int> &pattern){
    vector<int> table = makeTable(pattern);
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int j = 0;
    for(int i = 0; i < parent_size; i++){
        while(j > 0 && parent[i] != pattern[j]){
            j = table[j - 1];
        }
        if(parent[i] == pattern[j]){
            if(j == pattern_size - 1){
                cout << "YES" << endl;
                return;
            }
            else{
                j++;
            }
        }
    }
    cout << "NO" << endl;
}
int main(){
    int n;
    cin >> n;
    vector<int> check;
    vector<int> v1(n + n);
    
    for(int i = 0; i < n; i++){
        cin >> v1[i];
        v1[n + i] = v1[i];
    }
    vector<int> v2(n);
    for(int i = 0; i < n; i++){
        cin >> v2[i];
    }
    KMP(v1, v2);
    return 0;
}