#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, M;
vector<pair<int, int>> adj[MAX];
int dist[MAX];

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

void dijkstra(int node, int end){
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    dist[node] = 0;
    pq.push(make_pair(node, 0));
    
    while(!pq.empty()){
        int now = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (now == end) return;

        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            int nextCost = adj[now][i].second;
            if(cost + nextCost < dist[next]){
                dist[next] = cost + nextCost;
                pq.push(make_pair(next, dist[next]));
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back(make_pair(b, d));
    }

    int a, b; cin >> a >> b;
    dijkstra(a, b);
    cout << dist[b];

    return 0;
}