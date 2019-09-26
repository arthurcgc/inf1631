#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <map>
#include <array>

using namespace std;

/* 
    counting sort is a subroutine of radix sort that sorts
    the digits in each place value

    i.e: if we're evaluating a 3-digit number in base 10, counting sort will be called
    to sort the 1's place, then it will be called to sort the 10's place, then it will be called to sort
    the 100's place
*/
vector<int> countingSort(vector<int> &v,int digit, int base){
    int n = v.size();
    vector<int> res(n);
    // map that counts number of occurrences of the digits in v
    map<int,int> occur;

    // counts the number of occurences of each digit in A
    for (int i = 0; i < v.size(); i++){
        int digit_of_v_i=  int( v[i] / pow(base, digit) )  % base;
        occur[digit_of_v_i++];
    }

    /*
        change occur to show the cumulative number of digits up to index 
    */
    for(int i = 1; i < base; i++)
        occur[i] += occur[i-1];
    
    for(int i = v.size()-1; i >= 0; i--){
        int digit_of_v_i=  int( v[i] / pow(base, digit) )  % base;
        occur[digit_of_v_i]--;
        res[ occur[digit_of_v_i] ] = v[i];        
    }

    return res;
}

void radixSort(vector<int> &v, int base){
    // high is the largest number in the vector
    int high = *max_element(v.begin(), v.end()-1);

    // compute the number of digits needed to represent the highest number in v
    int max_digits = floor( ( log(high)/log(base) ) + 1);

    for(int i = 0; i < max_digits; i++)
        v = countingSort(v, i, base);
}


void print_vector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
        cout << "v[" << i << "] = "  << v[i] << endl;;
}

int main(){
    array<int, 9> arr = {1, 2, 3, 4, 5, 9, 8, 7, 6};
    vector<int> v;v.push_back(0);v.push_back(1);
    cout << v[8] << endl;
    radixSort(v, 10);
    print_vector(v);
    return 0;
}