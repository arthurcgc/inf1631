#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool divisible(long x, long y, int n){
    if (n == 1)
        return ( (x - y) % (x - y) ) == 0;
    return divisible(long(pow(x, n-1)), long(pow(y, n-1)), n-1);
}

int main(){
    cout << divisible(75, 43, 4) << endl;
}