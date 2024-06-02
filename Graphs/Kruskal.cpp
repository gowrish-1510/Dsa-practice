#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Kruskal Algorithm to find Minimum spanning tree
// Time complexity- O(Elog(E) + Elog(v)) where E-no. of edges and V-no of vertices
//Elog(E) for sorting and Elog(v) for cycle detection using Union-Find algorithm by path compression
class Edge {
public:
    int source;
    int destination;
    int weight;

    Edge(int source, int destination, int weight) {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

int findParent(int u, int *parent) {
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u], parent);
}

bool unionFind(int u, int v, int *parent, int *sizes) {
    int a = findParent(u, parent);
    int b = findParent(v, parent);

    if (a == b)
        return true; //both verices have same parent and hence form a cycle

    if (sizes[a] > sizes[b])  //if parent of u has more children vertices than parent of v, then make b(parent of v) as child of a(parent of u)
    {
        parent[b] = a;
        sizes[a] += sizes[b];
    } else {
        parent[a] = b;
        sizes[b] += sizes[a];
    }

    return false;
}

vector<Edge> Kruskal(int e, int n, Edge **inp) {
    int parent[n], sizes[n], count = 0, i = 0;
    bool cycle = false;
    vector<Edge> MST;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sizes[i] = 1;
    }

    while (count < n - 1 && i < e) {
        cycle = unionFind(inp[i]->source, inp[i]->destination, parent, sizes);
        if (cycle) {   // if cycle detected, don't include that edge in MST
            i++;
            continue;
        }

        MST.push_back(*inp[i]); // if no cycle, include that edge in MST
        count++;
        i++;
    }

    return MST;
}

bool compare( Edge* u, Edge* v) { //function pointer is passed as a 3rd parameter to the sort() function
    return u->weight< v->weight;
}

int main() {
    int e, n, source, dest, weight;
    cout <<"Enter the number of edges and vertices in the graph respectively: ";
    cin >>e>>n;

    Edge **inp = new Edge*[e];
    cout <<"Enter source, destination, and weight for each edge:" << endl;
    for (int i = 0; i < e; i++) {
        cin >>source>>dest>>weight;
        inp[i] = new Edge(source, dest, weight);
    }

    // Sort the edges based on their weight
    sort(inp, inp + e, compare);

    vector<Edge> MST = Kruskal(e, n, inp);
    cout <<"Resultant MST is:" << endl;
    cout <<"Source Destination Weight" << endl;
    for ( auto& edge : MST) {
        cout <<edge.source << " " << edge.destination << " " <<edge.weight<< endl;
    }

    for (int i = 0; i < e; i++) {
        delete inp[i];
    }
    delete[] inp;

    return 0;
}
