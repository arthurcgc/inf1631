#include "e2_parser.h"

std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

vector<int> parse(string test_name){
    string path = GetCurrentWorkingDir() + "/testfiles/" + test_name;
    vector<int> res;
    ifstream fp(path, ifstream::in);
    if (!fp.good()){
        throw "Error: file not found";
    }
    string line;
    getline(fp, line);
    int size = stoi(line);
    for(int i = 0; i < size; i++){
        getline(fp, line);
        int num = stoi(line, nullptr, 10);
        res.push_back(num);
    }

    return res;
}