#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>  // std::gcd, std::lcm

using namespace std;

int find_min_x(double p) {
    for (int x = 1; x <= 100000; x++) {
        int s = round(p * x);
        double check = floor(((double)s / x) * 1000) / 1000;
        if (fabs(check - p) < 1e-9) return x;
    }
    return -1;
}
bool check_x(double p, int x){
    
    int s = round(p * x);
    double check = floor(((double)s / x) * 1000) / 1000;
    if (fabs(check - p) < 1e-9) return true;
    
    return false;
}
bool compare(pair<double, int> &a, pair<double, int> &b){
    return a.second < b.second;
}
int main() {
    int n;
    cin >> n;
    vector<pair<double, int>> x_values;
    for (int i = 0; i < n; i++) {
        double p;
        cin >> p;
        x_values.push_back(make_pair(p, find_min_x(p)));
    }

    sort(x_values.begin(), x_values.end(), compare);
    int maxp = x_values[n - 1].second;
    for(int i = 0; i < n; i++){
        check_x(x_values[i].first, maxp);
        if(check_x(x_values[i].first, maxp)){
            x_values[i].second = maxp;
        }
    }
    int result = x_values[0].second;
    for(int i = 1; i < n; i++){
        result = lcm(result, x_values[i].second);
    }

    cout << result << endl;
    return 0;
}