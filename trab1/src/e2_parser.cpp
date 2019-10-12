#include "parser.h"

vector<int> parse_e2(string test_name){
    string path = GetCurrentWorkingDir() + "/e2_testfiles/" + test_name;
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

    fp.close();
    return res;
}

void write_results(vector<int> v, string test_name){
    string path = GetCurrentWorkingDir() + "/e2_results/" + "RES_" + test_name;
    ofstream test_out(path, fstream::out);
    test_out << v.size() << endl;
    for(int &num : v){
        test_out << num << endl;
    }
    test_out.close();
}