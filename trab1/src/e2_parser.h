#pragma once

#include <fstream>
#include <string>
#include <vector>
#include<iostream>
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif
using namespace std;

vector<int> parse(string test_name);
void write_results(vector<int> v, string test_name);