#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int getMax(vector<int> &v){
    int max = *v.begin();
    for (vector<int>::iterator it = v.begin()+1; it != v.end(); it++){
        if (*it > max)
            max = *it;
    }
    return max;
}

void countSort(vector<int> &v, int base){
    int n = v.size();
    vector<int> res(n);
    
}

void radixSort(vector<int> &v){
    int n = v.size();
    int lead = getMax(v);

    for(int base = 1; lead / base > 0; base *= 10){
        countSort(v, base);
    }
}


int main(){
    vector<int> v{1, 2, 3, 4, 5, 9, 8, 7, 6};
    cout << getMax(v) << endl;
}