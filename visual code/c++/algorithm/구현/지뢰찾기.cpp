#include <iostream>
#include <string>
#define MAX 101
using namespace std;

char d[MAX][MAX];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
string s;
void checkbomb(int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int cnt = 0;
            if(d[i][j] == '*'){
                s += '*';

            } else{
                for(int k = 0; k < 8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                        if(d[nx][ny] == '*') cnt++;
                    }
                }
                s += to_string(cnt);
            }
        }
        s += "\n";
    }
}
int main(){
    while(true){
        int r, c;
        cin >> r >> c;
        if(r == 0 && c == 0) break;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> d[i][j];
            }
        }
        checkbomb(r, c);
    }
    cout << s;
    return 0;
}