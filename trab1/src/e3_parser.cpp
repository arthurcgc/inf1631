#include "parser.h"

vector<vector<bool> > parse_e3(string test_name){
    string path = GetCurrentWorkingDir() + "/e3_testfiles/" + test_name;
    ifstream fp(path, ifstream::in);
    if (!fp.good()){
        throw "Error: file not found";
    }
    string line;
    getline(fp, line);
    stringstream ss(line);
    string buffer;
    getline(ss, buffer, ' ');
    int cols = stoi(buffer);
    getline(ss, buffer);
    int lines = stoi(buffer);

    vector<vector<bool> > graph;
    for(int i = 0; i < cols; i++)
        graph.push_back(vector<bool>(cols));
    

    for(int i = 0; i < lines; i++){
        getline(fp, line);
        stringstream buffer2(line);
        string sv1; getline(buffer2, sv1, ' ');
        string sv2; getline(buffer2, sv2);
        int v1 = stoi(sv1);
        int v2 = stoi(sv2);

        if(v2 == 4)
            cout << endl;
        graph[v1-1][v2-1] = 1;
        graph[v2-1][v1-1] = 1;
    }

    return graph;
}

void write_failure(string test_name){
    string path = GetCurrentWorkingDir() + "/e3_results/" + "RES_" + test_name;
    ofstream test_out(path, fstream::out);

    test_out << "Solution not found!";
    test_out.close();
    return;
}

void write_results(vector<int> v, string test_name){
    string path = GetCurrentWorkingDir() + "/e3_results/" + "RES_" + test_name;
    ofstream test_out(path, fstream::out);
    for(int &num : v){
        test_out << num + 1 << " -> ";
    }
    test_out << v[0] + 1;
    test_out.close();
}