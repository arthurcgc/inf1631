#pragma once

#include <sstream>
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

vector<int> parse_e2(string test_name);
vector<vector<bool> > parse_e3(string test_name);
void write_results(vector<int> v, string test_name);
void write_failure(string test_name);

static string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}