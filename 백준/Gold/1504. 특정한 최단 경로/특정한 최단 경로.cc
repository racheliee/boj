#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct Vertex{
    int name;
    long long int distance;
    bool included;
    Vertex* parent;
};

struct CompareVertices{
    bool operator()(const Vertex& a, const Vertex& b) const {
        return a.distance > b.distance;
    }
};

// dijkstra's algorithm
long long int get_shortest_path(vector<vector<pair<int, int>>> adj_list, int S, int T){
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
    
    return vertices[T].distance;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E; //각각 num of vertices, num of edges
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj_list(V); //pair = col, weight

    for(int i= 0; i < E; i++){
        int row, col, weight;
        cin >> row >> col >> weight;
        row--; col--; //index와 통일 시키기 위해

        adj_list[row].emplace_back(col, weight);
        adj_list[col].emplace_back(row, weight); //since its undirected
    }

    int v1, v2;
    cin >> v1 >> v2;
    v1--; v2--;

    long long int path1 = get_shortest_path(adj_list, 0, v1) + get_shortest_path(adj_list, v1, v2) + get_shortest_path(adj_list, v2, V-1);
    long long int path2 = get_shortest_path(adj_list, 0, v2) + get_shortest_path(adj_list, v2, v1) + get_shortest_path(adj_list, v1, V-1);

    if((path1 >= INT_MAX && path2 >= INT_MAX)) cout << -1;
    else cout << min(path1, path2);
}