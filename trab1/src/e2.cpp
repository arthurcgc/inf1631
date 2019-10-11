#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <map>
#include <array>
#include "e2_parser.h"

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
    vector<int> occur(base);

    // counts the number of occurences of each digit in A
    for (int i = 0; i < v.size(); i++){
        int digit_of_v_i=  int( v[i] / pow(base, digit) )  % base;
        occur[digit_of_v_i]++;
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
        cout << "v[" << i << "] = "  << v[i] << endl;
    cout << "-----------------" << endl;
}


map<string, int> tests(){
    map<string, int> name_base;
    name_base["Integers_50_3.txt"]    = 10;
    name_base["Integers_1000_1.txt"]  = 10;
    name_base["Integers_1000_2.txt"]  = 10;
    name_base["Integers_1000_3.txt"]  = 10;
    name_base["Integers_5000_1.txt"]  = 10;
    name_base["Integers_5000_2.txt"]  = 10;
    name_base["Integers_5000_3.txt"]  = 10;
    name_base["Integers_10000_1.txt"] = 10;
    name_base["Integers_10000_2.txt"] = 10;
    name_base["Integers_10000_3.txt"] = 10;
    name_base["Integers_50000_1.txt"] = 10;
    name_base["Integers_50000_2.txt"] = 10;
    name_base["Integers_50000_3.txt"] = 10;
    name_base["Integers_10000_1.txt"] = 10;
    name_base["Integers_10000_2.txt"] = 10;
    name_base["Integers_10000_3.txt"] = 10;

    return name_base;
}

int main(){
    // vector<pair<vector<int>, int > > vectors;
    // array<int, 9> arr1 = {111, 222, 3333, 444444, 1, 9, 8, 7, 6};
    // vector<int> v1(arr1.begin(), arr1.end());
    // vectors.push_back(make_pair(v1, 10));


    // array<int, 6> arr2 = {0b0111, 0b1001, 0b0001, 0b0011, 0b1011, 0b1111};
    // vector<int> v2(arr2.begin(), arr2.end());
    // vectors.push_back(make_pair(v2, 2));


    // array<int, 6> arr3 = {0xa2, 0xa1, 0xa, 0xbf, 0xc43, 0x01};
    // vector<int> v3(arr3.begin(), arr3.end());
    // vectors.push_back(make_pair(v3, 16));

    // for(int i = 0; i < vectors.size(); i++){
    //     vector<int> vit = vectors[i].first;
    //     int base = vectors[i].second;
    //     radixSort(vit, base);
    //     print_vector(vit);
    // }

    map<string, int> test_case = tests();
    vector< vector<int> > intvecs;
    int base = 10;

    for(map<string, int>::iterator it = test_case.begin(); it != test_case.end(); it++){
        cout << it->first << endl;
        vector<int> v = parse(it->first);
        radixSort(v, base);
        cout << "---TEST NAME: " + it->first + "---\n" << endl;
        print_vector(v);
    }

    return 0;
}