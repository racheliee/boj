#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;

struct Vertex{
    int name;
    int distance;
    bool included;
    Vertex* parent;
};

struct CompareVertices{
    bool operator()(const Vertex& a, const Vertex& b) const {
        return a.distance > b.distance;
    }
};

// S = starting vertex, T = ending vertex
// dijkstra's algorithm
void get_shortest_path(vector<vector<pair<int, int>>> adj_list, int S){
    int V = adj_list.size();

    vector<Vertex> vertices(V);
    for (int i = 0; i < V; i++) {
        vertices[i].name = i;
        vertices[i].distance = INT_MAX;
        vertices[i].included = false;
    }
    vertices[S].distance = 0;

    priority_queue<Vertex, vector<Vertex>, CompareVertices> pq;
    pq.push(vertices[S]);

    while(!pq.empty()){
        Vertex u = pq.top();
        pq.pop();
        
        if(u.included) continue;

        u.included = true;

        for(const auto& neighbour: adj_list[u.name]){
            int v = neighbour.first;
            int weight = neighbour.second;

            if(!vertices[v].included && u.distance + weight < vertices[v].distance){
                vertices[v].distance = u.distance + weight;
                pq.push(vertices[v]);
            }
        }
    }

    for(int i = 0; i < V; i++){
        if(i == S) cout << 0 << "\n";
        else if(vertices[i].distance == INT_MAX) cout << "INF" << "\n";
        else cout << vertices[i].distance << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, S; //각각 num of vertices, num of edges, and starting vertex
    cin >> V >> E >> S;

    vector<vector<pair<int, int>>> adj_list(V); //pair = col, weight

    S--; //index와 통일 시키기 위해
    for(int i= 0; i < E; i++){
        int row, col, weight;
        cin >> row >> col >> weight;
        row--; col--; //index와 통일 시키기 위해

        adj_list[row].emplace_back(col, weight);
    }

    get_shortest_path(adj_list, S);
}