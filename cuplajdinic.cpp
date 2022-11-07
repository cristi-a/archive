#include <bits/stdc++.h>
using namespace std;

ifstream f("cuplaj.in");
ofstream g("cuplaj.out");

struct Dinic {
    struct Edge {
        int x, y;
        int cap = 0, flow = 0;
        Edge(int _x, int _y, int _cap) : x(_x), y(_y), cap(_cap) {}
    };
    static const int inf = 2e9;
    vector<Edge> edges;
    vector<vector<int>> dx;
    vector<int> ptr, dist;
    queue<int> q;
    int n, s, t;
    Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        dx.resize(n);
        ptr.resize(n);
        dist.resize(n);
    }
    void add_edge(int x, int y, int cap) {
        edges.emplace_back(x, y, cap);
        dx[x].emplace_back(edges.size() - 1);
        edges.emplace_back(y, x, 0);
        dx[y].emplace_back(edges.size() - 1);
    }
    bool bfs() {
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        q.emplace(s);
        while(q.empty() == false) {
            int now = q.front(); q.pop();
            for(auto it : dx[now]) {
                if(edges[it].cap - edges[it].flow < 1) continue;
                if(dist[edges[it].y] != -1) continue;
                dist[edges[it].y] = dist[now] + 1;
                q.emplace(edges[it].y);
            }
        }
        return (dist[t] != -1);
    }
    int dfs(int node, int curr) {
        if(curr == 0) return 0;
        if(node == t) return curr;
        for(auto &it = ptr[node]; it < int(dx[node].size()); it++) {
            int id = dx[node][it];
            int v = edges[id].y;
            if(edges[id].cap - edges[id].flow < 1 or dist[node] + 1 != dist[v]) continue;
            int fl = dfs(v, min(curr, edges[id].cap - edges[id].flow));
            if(fl == 0) continue;
            edges[id].flow += fl;
            edges[id ^ 1].flow -= fl;
            return fl;
        }
        return 0;
    }
    void matching(int l) {
        int ans = 0;
        while(bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while(int add = dfs(s, inf)) ans += add;
        }
        g << ans << "\n";
        for(int i=1; i<=l; i++)
            for(auto it : dx[i])
                if(edges[it].flow > 0) g << i << " " << edges[it].y - l << "\n";
    }
};

int main() {
    int n, m, e; f >> n >> m >> e;
    Dinic G(n+m+2, 0, n+m+1);
    for(int i=1; i<=n; i++) G.add_edge(0, i, 1);
    for(int i=n+1; i<=n+m; i++) G.add_edge(i, n+m+1, 1);
    for(int i=1; i<=e; i++) {
        int x, y; f >> x >> y;
        G.add_edge(x, y+n, 1);
    }
    G.matching(n);
    return 0;
}
