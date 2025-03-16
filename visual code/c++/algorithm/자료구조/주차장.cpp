#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> park;
vector<int> parkfull;
vector<int> car;
int main(){
    int n, m;
    cin >> n >> m;
    park.resize(n + 1);
    parkfull.resize(n + 1, 0);
    car.resize(m + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> park[i].first;
    }

    for(int i = 1; i <= m; i++){
        cin >> car[i];
    }

    queue<int> carwait;
    int cost = 0;
    for(int i = 0 ; i < 2 * m; i++){
        int carnum;
        cin >> carnum;
        if(carnum > 0){
            if(carwait.empty()){
                bool carpark = false;
                for(int j = 1; j <= n; j++){
                    if(parkfull[j] == 0){
                        parkfull[j] = carnum;
                        park[j].second = car[carnum] * park[j].first;
                        carpark = true;
                        break;
                    }
                }
                if(!carpark){
                    carwait.push(carnum);
                }
            } else{
                carwait.push(carnum);
            }
        }
        else{
            int caroutnum = -carnum;
            for(int j = 1; j <= n; j++){
                if(parkfull[j] == caroutnum){
                    cost += park[j].second;
                    parkfull[j] = 0;
                    park[j].second = 0;
                    break;
                }
            }
            if (!carwait.empty()){
                int carinnum = carwait.front();
                carwait.pop();
                for (int j = 1; j <= n; j++){
                    if (parkfull[j] == 0){
                        parkfull[j] = carinnum;
                        park[j].second = car[carinnum] * park[j].first;
                        break;
                    }
                }
            }
        }
    }
    cout << cost << endl;
    return 0;
}

