#include <iostream>
#include <math.h>

using namespace std;

int quocient(long x, long y, int n){
    if (n == 1)
        return ( (x - y) % (x - y) ) == 0;
    return long(pow(x, n-1)) + (y * quocient(x, y, n - 1));
}

int main(){
    cout << quocient(75, 43, 4) << endl;
}