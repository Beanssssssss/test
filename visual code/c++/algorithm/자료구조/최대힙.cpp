#include <iostream>
#include <queue>

using namespace std;
string s;
int main(){
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num == 0){
            if(pq.empty()){
                s += "0\n";
            }else{  
                s += to_string(pq.top()) + '\n';
                pq.pop();
            }
        } else{
            pq.push(num);
        }
    }
    cout << s;
    return 0;
}