#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    set<int, greater<int>> v;
    string hh;
    int h;
    cin >> hh >> h;

    for(int i = 1; i < n; i++){
        string a;
        int b;
        cin >> a >> b;
        if(a.substr(0, 4) == "2024"){
            int fs = max(0, y - (x - b));
            v.insert(b + fs);
        }
    }
    auto it = next(v.begin(), m - 1);
    if(*it - h <= y){
        cout << "YES\n" << *it - h << endl;
    } else{
        cout << "NO\n";
    }
    return 0;
}
