#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;
class Point{
    public:
    int node;
    int cost;
    Point(int node, int cost){
        this->node = node;
        this->cost = cost;
    }
};
int n, start, finish;
vector<int> degree(MAX);
vector<int> result(MAX);
vector<int> c(MAX);
vector<Point> a[MAX];
vector<Point> b[MAX];

void tpsort(){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < a[x].size(); i++){
            Point y = Point(a[x][i].node, a[x][i].cost);
            if(result[y.node] <= y.cost + result[x])
                result[y.node] = y.cost + result[x];
            if(--degree[y.node] == 0)
                q.push(y.node);
        }
    }
    int count = 0;
    q.push(finish);
    while(!q.empty()){
        int y = q.front();
        q.pop();
        for(int i = 0; i < b[y].size(); i++){
            Point x = Point(b[y][i].node, b[y][i].cost);
            if(result[y] - result[x.node] == x.cost){
                count++;
                if(c[x.node] == 0){
                    q.push(x.node);
                    c[x.node] = 1;
                }
            }
        }
    }
    cout << result[finish] << "\n" << count << endl;
}
int main(){
    int m;
    cin >> n;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        int s, end, cost;
        cin >> s >> end >> cost;
        a[s].push_back(Point(end, cost));
        b[end].push_back(Point(s, cost));
        degree[end]++;
    }
    cin >> start >> finish;
    tpsort();
    return 0;
}