#include <iostream>
#include <algorithm>

using namespace std;
string makestring(string s){
    string news = s;
    reverse(news.begin(), news.end());
    int max_idx = 0;
    int max_cnt = 0;
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        int cnt = 0;
        j = 0;
        while(i + j < s.size()){
            if(s[i + j] == news[j]){
                cnt++;
            }
            j++;
        }
        if(cnt == s.size() - i){
            max_idx = --j;
            max_cnt = cnt;
            break;
        }
    }
    s += news.substr(max_cnt);
    return s;


}
int main(){
    int n; 
    string total_s;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        total_s += makestring(s) + "\n";
    }
    cout << total_s;
    return 0;
}