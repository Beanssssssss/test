#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    vector<int> x = {x1, x2, x3};
    vector<int> y = {y1, y2, y3};
    vector<long double> v;
    set<pair<int, int>> s1;
    set<long double> s2;
    for(int i = 0; i < 3; i++){
        s1.insert({x[i], y[i]});
    }
    for(int i = 1; i < 3; i++){
        int dy = y[i] - y[i- 1];
        int dx = x[i] - x[i-1];
        if(dx == 0){
            if(x1 == x2 && x2 == x3){
                cout << -1.0 << endl;
                return 0;
            }
        }
        long double dydx = (double)dy / dx;
        s2.insert(dydx);
    }
    if(s1.size() != 3){
        cout << -1.0 << endl;
        return 0;
    }
    if(s2.size() == 1){
        cout << -1.0 << endl;
        return 0;
    }

    for(int i = 0; i < 3; i++){
        long double length = sqrt(pow(x[(i+1)%3]-x[i%3], 2) + pow(y[(i+1)%3]-y[i%3], 2));
        long double length2 = sqrt(pow(x[(i+2)%3]-x[i%3], 2) + pow(y[(i+2)%3]-y[i%3], 2));
        long double length3 = sqrt(pow(x[(i+2)%3]-x[(i+1)%3], 2) + pow(y[(i+2)%3]-y[(i+1)%3], 2));
        v.push_back((length + length2) * 2);
        v.push_back((length + length3) * 2);
    }
    long double max_value = *max_element(v.begin(), v.end());
    long double min_value = *min_element(v.begin(), v.end());
    cout << fixed << setprecision(20); 
    cout << max_value - min_value << endl;
    return 0;
}