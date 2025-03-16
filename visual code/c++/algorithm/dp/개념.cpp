//피보나치 dp
#include <iostream>

using namespace std;

int d[100];

int fibonacci(int x){
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(d[x] != 0) return d[x];
    return d[x] = fibonacci(x - 1) + fibonacci(x - 2);
}
int main(void){
    cout << fibonacci(30) << endl;
}