#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/*
    vector path represents the bucket of vertexes that are adjacent to each other, it stores the graph indexes
*/
bool is_safe(int vertex, vector<vector<bool> > &graph, vector<int> &path, unordered_set<int> &visited, int pos){

    // vertex already in path
    if( visited.count(vertex) > 0 )
        return false;

    int previous_node = path[pos-1];
    // check if exists edge between vertex and previous vertex
    if (graph[previous_node][vertex] == 0)
        return false;

    return true;
}

/* A recursive utility function  
to solve hamiltonian cycle problem */
bool hamCycleUtil( vector<vector<bool> >&graph,  
                  vector<int> &path, unordered_set<int> &visited, int pos)  
{  
    /* base case: If all vertices are  
    included in Hamiltonian Cycle */
    if (pos == graph[0].size())  
    {
        int previous = path[pos-1];
        int first = path[0];
        // And if there is an edge from the  
        // last included vertex to the first vertex  
        if (graph[previous][first] == 1)  
            return true;  
        else
            return false;  
    }  
  
    // Try different vertices as a next candidate  
    // in Hamiltonian Cycle. We don't try for 0 as  
    // we included 0 as starting point in hamCycle()  
    for (int v = 1; v < graph[0].size(); v++)
    {  
        /* Check if this vertex can be added  
        // to Hamiltonian Cycle */
        if (is_safe(v, graph, path, visited, pos))  
        {  
            path[pos] = v;  
            visited.insert(v);
            /* recur to construct rest of the path */
            if (hamCycleUtil (graph, path, visited, pos + 1) == true)  
                return true;  


        // And if there is an edge from the  
        // last included vertex to the first vertex
        int previous = path[pos-1];
        int first = path[0];  
        if (graph[previous][first] == 1)  
  
            /* If adding vertex v doesn't lead to a solution,  
            then remove it */
            path[pos] = -1;  
        }  
    }
    /* If no vertex can be added to  
    Hamiltonian Cycle constructed so far,  
    then return false */
    return false;  
}

/* A utility function to print solution */
void printSolution(vector<int> &path)  
{  
    cout << "Solution Exists:"
            " Following is one Hamiltonian Cycle \n";  
    for(int &num : path)
        cout << num << " ";  
  
    // Let us print the first vertex again 
    // to show the complete cycle  
    cout << path[0] << " ";  
    cout << endl; 
}  

bool hamCycle(vector<vector<bool> > graph)  
{  
    vector<int> path(graph[0].size());
    unordered_set<int> visited;
    /* Let us put vertex 0 as the first vertex in the path. 
    If there is a Hamiltonian Cycle, then the path can be  
    started from any point of the cycle as the graph is undirected */
    path[0] = 0;
    visited.insert(0);

    if (hamCycleUtil(graph, path, visited, 1) == false )  
    {  
        cout << "\nSolution does not exist";  
        return false;  
    }  
  
    printSolution(path);  
    return true;  
}  

vector<vector<bool>> init_graph(int r, int c){
    vector<vector<bool>> g;
    for(int i = 0; i < r; i++){
        g.push_back(vector<bool>(c));
    }
    return g;
}


int main(int argc, char const *argv[])
{
    vector<vector<bool>> graph1 = init_graph(5, 5);
    graph1[0][0] = 0; graph1[0][1] = 1; graph1[0][2]= 0; graph1[0][3] = 1; graph1[0][4] = 0;

    graph1[1][0] = 1; graph1[1][1] = 0; graph1[1][2]= 1; graph1[1][3] = 1; graph1[1][4] = 1;

    graph1[2][0] = 0; graph1[2][1] = 1; graph1[2][2]= 0; graph1[2][3] = 0; graph1[2][4] = 1;

    graph1[3][0] = 1; graph1[3][1] = 1; graph1[3][2]= 0; graph1[3][3] = 0; graph1[3][4] = 1;

    graph1[4][0] = 0; graph1[4][1] = 1; graph1[4][2]= 1; graph1[4][3] = 1; graph1[4][4] = 0; 
      
    // Print the solution  
    hamCycle(graph1);
  
    return 0;
}
