#include <iostream>
#include <math.h>

using namespace std;

long quocient(long x, long y, int n){
    if (n == 1)
        return ( (x - y) % (x - y) ) == 0;
    return long(pow(x, n-1)) + (y * quocient(x, y, n - 1));
}

int main(){
    cout << endl << "---EXERCISE 1 OUTPUT---" << endl << endl;
    cout << "(75^4-43^4)/(75-43) = " << quocient(75, 43, 4) << endl;
    cout << "(732^7-433^7)/(732-433) = " << quocient(732, 433, 7) << endl;
    cout << "(193^9-147^9)/(193-147) = " << quocient(193, 147, 9) << endl;
    cout << "(341^5-251^5)/(341-251) = " << quocient(341, 251, 5) << endl;
    cout << "(270^17-85^17)/(270-85) = " << quocient(341, 251, 17) << endl;
    cout << endl << "---END OF EXERCISE 1 TESTS---" << endl << endl;
}