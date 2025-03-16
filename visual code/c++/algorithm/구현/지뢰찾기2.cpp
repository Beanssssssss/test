#include <iostream>
#include <string>
using namespace std;

char d[101][101];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
int n;
void countbomb(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isdigit(d[i][j])){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >=0 && ny < n && !isdigit(d[nx][ny])){
                        if(d[nx][ny] == '*') cnt++;
                        if(d[i][j] == '0'){
                            d[nx][ny] = 'X';
                        }
                    }
                }
                if(d[i][j] - '0' > cnt) {
                    for(int k = 0; k < 8; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx >= 0 && nx < n && ny >=0 && ny < n && !isdigit(d[nx][ny])){
                            if(d[nx][ny] != 'X')
                                d[nx][ny] = '*';
                                cnt++;
                        }
                        if(d[i][j] - '0' == cnt) break;
                    }
                }
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> d[i][j];
        }
    }
    countbomb();
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(d[i][j] == '*' || d[i][j] == '#')
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}