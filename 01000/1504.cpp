#include <iostream>
#include <vector>
#include <queue>
#define MAX 801
#define INF 1e7
using namespace std;

vector<pair<int, int>> adj[MAX];
int dist[MAX];

int V, E;

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

int dijkstra(int node, int end){
    for(int i = 1; i <= V; i++) dist[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    dist[node] = 0;
    pq.push(make_pair(node, 0));

    while(!pq.empty()){
        int now = pq.top().first;
        int cost = pq.top().second;

        pq.pop();

        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            int nextCost = adj[now][i].second;

            if(cost + nextCost < dist[next]){
                dist[next] = cost + nextCost;
                pq.push(make_pair(next, dist[next]));
            }
        }
    }
    return dist[end];
}

int main(){
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int a, b; cin >> a >> b;

    int dist1 = dijkstra(1, a) + dijkstra(a, b) + dijkstra(b, V);
    int dist2 = dijkstra(1, b) + dijkstra(b, a) + dijkstra(a, V);

    int result = min(dist1, dist2);
    result = (result < INF) ? result : -1;
    cout << result;

    return 0;
}