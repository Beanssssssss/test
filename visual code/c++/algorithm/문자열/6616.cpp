#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    string ans;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        cin.ignore();
        string message;
        getline(cin, message);

        message.erase(remove(message.begin(), message.end(), ' '), message.end());
        transform(message.begin(), message.end(), message.begin(), ::toupper);

        int len = message.size();
        int row = ceil((double)len / N);
        vector <char> vec(len);
        vector <bool> visited(len, false);
        string s;
        int j = 0;
        int cnt = 0;
        for(int i = 0; i < len; i++){
            int index = i;
            
            while(index < len){
                if(!visited[j])
                    vec[index] = message[j];
                index += N;
                j++;
                cnt++;
            }
            if(cnt == len) break;
        }  
        for(char c : vec){
            s += c;
        }
        ans += s + "\n";
    }
    cout << ans;


    return 0;
}