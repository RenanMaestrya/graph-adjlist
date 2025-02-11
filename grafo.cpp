#include <iostream>

using namespace std;

class Node {
public:
    int vertex;
    Node* next;
    Node(int v) : vertex(v), next(nullptr) {}
};

class AdjList {
public:
    Node* head;
    AdjList() : head(nullptr) {}
    
    void addNode(int v) {
        Node* newNode = new Node(v);
        newNode->next = head;
        head = newNode;
    }
};

class Graph {
private:
    int numVertices;
    AdjList* adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList = new AdjList[numVertices];
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            Node* current = adjList[i].head;
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList;
    }

    void addEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
            adjList[v1].addNode(v2);
            adjList[v2].addNode(v1);
            cout << "Edge added between " << v1 << " and " << v2 << "\n";
        } else {
            cout << "Invalid vertices!\n";
        }
    }

    void displayGraph() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            Node* current = adjList[i].head;
            while (current) {
                cout << current->vertex << " ";
                current = current->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    
    g.displayGraph();
    
    return 0;
}
