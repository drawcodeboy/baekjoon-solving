#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e8
using namespace std;

int N, M, X;
vector<pair<int, int>> adj[MAX];
int dist[MAX];

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

void dijkstra(int node){
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
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        int a, b, t; cin >> a >> b >> t;
        adj[a].push_back(make_pair(b, t));
    }

    dijkstra(X);
    int result[MAX];

    // 돌아오는 길
    for(int i = 1; i <= N; i++){
        result[i] = 0;
        result[i] += dist[i];
    }

    // 가는 길
    int maxValue = 0;
    for(int i = 1; i <= N; i++){
        if(i == X) continue;
        dijkstra(i);
        result[i] += dist[X];
        maxValue = max(maxValue, result[i]);
    }

    cout << maxValue;
}