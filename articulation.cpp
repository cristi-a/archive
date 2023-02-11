#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;

vector<vector<int>> dx(nmax+5);
int tin[nmax+5], low[nmax+5], timer = 0;
bool viz[nmax+5];

vector<int> spetzial;

void dfs(int node, int father) {
    viz[node] = true;
    tin[node] = timer; low[node] = timer; timer++;
    int nr = 0;
    for(auto i : dx[node]) {
        if(i == father) continue;
        if(viz[i] == true) low[node] = min(low[node], tin[i]);
        else {
            nr++;
            dfs(i, node);
            low[node] = min(low[node], low[i]);
            if(low[i] >= tin[node] and father != -1) spetzial.emplace_back(node);
        }
    }
    if(father == -1 and nr > 1) spetzial.emplace_back(node);
}

int main() {
    ifstream f("pamant.in");
    ofstream g("pamant.out");

    int n, m; f >> n >> m;
    for(int i=1; i<=m; i++) {
        int x, y; f >> x >> y;
        dx[x].emplace_back(y);
        dx[y].emplace_back(x);
    }
    vector<int> teams;
    for(int i=1; i<=n; i++)
        if(viz[i] == false) {
            dfs(i, -1);
            teams.emplace_back(i);
        }
    g << teams.size() << "\n";
    for(auto i : teams) g << i << " ";
    sort(spetzial.begin(), spetzial.end());
    spetzial.erase(unique(spetzial.begin(), spetzial.end()), spetzial.end());
    g << "\n" << spetzial.size() << "\n";
    for(auto i : spetzial) g << i << " ";
    return 0;
}
