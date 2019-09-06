#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int divisible(int x, int y, int n){
    if (n == 1)
        return 0;
    return divisible(pow(x, n-1), pow(y, n-1), n-1);
}


int main(){
    assert(divisible(100, 333, 10) == 0);
}