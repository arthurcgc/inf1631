#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

typedef struct node Node;
typedef struct graph Graph;

struct node{
    int val;
    vector<Node*> adj;
};

struct graph{
    vector<Node*> nodes;
};



void visit(Node *n){
    cout << "Node: " << n->val << endl;
}

void DFS(graph &g){
    stack<Node*> s;
    unordered_set<Node*> visited;
    s.push(g.nodes[0]);

    while(!s.empty()){
        Node *curr = s.top();
        s.pop();
        if(visited.count(curr) <= 0){
            visit(curr);
            visited.insert(curr);
            for(Node *to_visit : curr->adj)
                s.push(to_visit);
        }
    }
}

int main(){
    Node *n1, *n2, *n3, *n4, *n5, *n6;
    n1 = new Node(); n2 = new Node(); n3 = new Node();
    n4 = new Node(); n5 = new Node(); n6 = new Node();
    n1->val = 0; n2->val = 1; n3->val = 2;
    n4->val = 3; n5->val = 4; n6->val = 5;

    n1->adj.push_back(n2); n1->adj.push_back(n5);
    n2->adj.push_back(n3); n2->adj.push_back(n4); n2->adj.push_back(n1);
    n3->adj.push_back(n2); n3->adj.push_back(n4); 
    n4->adj.push_back(n3); n4->adj.push_back(n6); 
    n5->adj.push_back(n1); n5->adj.push_back(n6); 
    n6->adj.push_back(n4); n6->adj.push_back(n5); 

    Graph g; 
    g.nodes.push_back(n1);g.nodes.push_back(n2);g.nodes.push_back(n3);
    g.nodes.push_back(n4);g.nodes.push_back(n5);g.nodes.push_back(n6);

    DFS(g);
}