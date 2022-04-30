// https://cses.fi/problemset/result/3887671/
// https://cp-algorithms.com/graph/bridge-searching.html
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;

vector<vector<int>> dx(nmax+5);
vector<bool> viz(nmax+5);
vector<int> tin(nmax+5), low(nmax+5);
vector<pair<int,int>> bridge;
int idx;

void dfs(int node, int ant) {
    viz[node] = true; 
    tin[node] = idx; low[node] = idx; idx++;
    for(auto i : dx[node]) {
        if(i == ant) continue;
        if(viz[i]) low[node] = min(low[node], tin[i]);
        else {
            dfs(i, node);
            low[node] = min(low[node], low[i]);
            if(low[i] > tin[node]) bridge.emplace_back(node, i);                
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) tin[i] = -1, low[i] = -1;
    for(int i=1; i<=m; i++) {
        int x, y; cin >> x >> y;
        dx[x].emplace_back(y);
        dx[y].emplace_back(x);
    }
    for(int i=1; i<=n; i++)
        if(!viz[i])
            dfs(i, -1);
    cout << bridge.size() << "\n";
    for(auto i : bridge) cout << i.first << " " << i.second << "\n";
    return 0;
}
