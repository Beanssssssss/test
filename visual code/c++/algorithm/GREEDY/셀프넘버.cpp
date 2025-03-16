#include <iostream>
using namespace std;

bool v[10001];

int main(){
    for(int i = 1; i < 10; i++){
        v[i * 2] = true;
    }
    for(int i = 10; i < 100; i++){
        int a = i / 10;
        int b = i % 10;
        v[i + a + b] = true;
    }
    for(int i = 100; i < 1000; i++){
        int a = i / 100;
        int b = (i / 10) % 10;
        int c = i % 10;
        v[i + a + b + c] = true;
    }
    for(int i = 1000; i <= 10000; i++){
        int a = i / 1000;
        int b = (i / 100) % 10;
        int c = (i / 10) % 10;
        int d = i % 10;
        if(i + a + b + c + d > 10000) continue;
        v[i + a + b + c + d] = true;
    }
    for(int i = 1; i <= 10000; i++){
        if(!v[i]) cout << i << endl;
    }
}