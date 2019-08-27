/*
    Given a directed graph design an algorithm to find out whether there is a route between 2 nodes
*/

#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

class Node{
    public: Node* adj;
    public: bool marked;
    public: int size_adj;
    public: int nodeNum;
    public: Node(){}
    public: Node(int numOfAdj, int nodeNum){
        adj = new Node[numOfAdj];
        size_adj = numOfAdj;
        this->nodeNum = nodeNum;
        marked = false;
    }
};

class Graph {
    public: Node* nodes;
    
    public: Graph(int numOfNodes){
        nodes = new Node[numOfNodes];
    }

    /* Execute a bfs and stop if it finds the destination node */
    public: bool isRouteBetween(int s, int d){
        queue<Node> q;
        q.push(nodes[s]);
        nodes[s].marked = true;
        while(!q.empty()){ // sort of bfs 
            Node curr = q.front();
            q.pop();
            for(int i = 0; i < curr.size_adj; i++){
                //cout << "Compare " << d << " with " << i << " ";
                if(curr.adj[i].nodeNum == nodes[d].nodeNum) return true; // if node found return true
                if(!curr.adj[i].marked){ 
                    //cout << " Mark " << i << " ";
                    curr.adj[i].marked = true;
                    q.push(curr.adj[i]);
                }
                //cout << endl;
            }
        }
        return false;
    }
};

int main(){
    Graph g = Graph(5);
    for(int i = 0; i < 5; i++){
        g.nodes[i] = Node(5, i);
    }

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            g.nodes[i].adj[j] = g.nodes[j];
        
    cout << g.isRouteBetween(1, 4) << endl;  
}