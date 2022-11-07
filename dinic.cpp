struct Dinic {
    struct Edge {
        int x, y;
        ll cap = 0, flow = 0;
        Edge(int _x, int _y, ll _cap) : x(_x), y(_y), cap(_cap) {}
    };
    static const ll inf = 1e18;
    int n, start, fin;
    vector<vector<int>> dx;
    vector<Edge> e;
    vector<int> dist, ptr;
    queue<int> q;

    Dinic(int _n, int _start, int _fin) : n(_n), start(_start), fin(_fin) {
        dx.resize(n);
        dist.resize(n);
        ptr.resize(n);
    }

    void AddEdge(int x, int y, ll cap) {
        e.emplace_back(x, y, cap);
        dx[x].emplace_back(e.size() - 1);
        e.emplace_back(y, x, 0);
        dx[y].emplace_back(e.size() - 1);
    }

    bool bfs() {
        while(q.empty() == false) {
            int now = q.front(); q.pop();
            for(auto it : dx[now]) {
                if(e[it].cap - e[it].flow < 1) continue;
                if(dist[e[it].y] != -1) continue;
                dist[e[it].y] = dist[now] + 1;
                q.emplace(e[it].y);
            }
        }
        return (dist[fin] != -1);
    }
    ll dfs(int node, ll curr) {
        if(curr == 0) return 0;
        if(node == fin) return curr;
        for(int &it = ptr[node]; it<int(dx[node].size()); it++) {
            int pos = dx[node][it];
            int nxt = e[pos].y;
            if(dist[node] + 1 != dist[nxt] or e[pos].cap - e[pos].flow < 1) continue;
            ll fl = dfs(nxt, min(curr, e[pos].cap - e[pos].flow));
            if(fl == 0) continue;
            e[pos].flow += fl;
            e[pos^1].flow -= fl;
            return fl;
        }
        return 0;
    }
    ll flow() {
        ll ans = 0;
        while(1) {
            fill(dist.begin(), dist.end(), -1);
            dist[start] = 0;
            q.emplace(start);
            if(bfs() == false) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll add = dfs(start, inf)) ans += add;
        }
        return ans;
    }
};
