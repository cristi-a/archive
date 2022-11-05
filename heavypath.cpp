#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1e5;
const int lgmax = 16;

vector<vector<int>> dx(nmax+5);
int v[nmax+5], niv[nmax+5], under[nmax+5];

int cnt = 0, where[nmax+5], above[nmax+5], len[nmax+5], pos[nmax+5];
vector<vector<int>> path;
vector<vector<int>> aint;

void dfs(int node, int father) {
    under[node] = 1;
    niv[node] = niv[father] + 1;
    int w = -1, mx = 0;
    for(auto i : dx[node])
        if(i != father) {
            dfs(i, node);
            if(under[i] > mx) {
                mx = under[i];
                w = i;
            }
            under[node] += under[i];
        }
    if(w == -1) {
        path.emplace_back(vector<int>{node});
        where[node] = cnt;
        cnt++;
    }
    else {
        path[where[w]].emplace_back(node);
        where[node] = where[w];
        for(auto i : dx[node])
            if(i != father and i != w)
                above[where[i]] = node;
    }
}

bool comp(int a, int b) {
    return (niv[a] < niv[b]);
}

void build(int node, int left, int right, int w) {
    if(left == right) {
        aint[w][node] = v[path[w][left]];
        return;
    }
    int mid = (left + right) / 2;
    build(node*2, left, mid, w);
    build(node*2+1, mid+1, right, w);
    aint[w][node] = max(aint[w][node*2], aint[w][node*2+1]);
}

void update(int node, int left, int right, int ind, int val, int w) {
    if(left == right) {
        aint[w][node] = val;
        return;
    }
    int mid = (left + right) / 2;
    if(mid >= ind) update(node*2, left, mid, ind, val, w);
    if(mid < ind) update(node*2+1, mid+1, right, ind, val, w);
    aint[w][node] = max(aint[w][node*2], aint[w][node*2+1]);
}

int query(int node, int left, int right, int st, int dr, int w) {
    if(st <= left and right <= dr) return aint[w][node];
    int mid = (left + right) / 2, ans = 0;
    if(mid >= st) ans = max(ans, query(node*2, left, mid, st, dr, w));
    if(mid < dr) ans = max(ans, query(node*2+1, mid+1, right, st, dr, w));
    return ans;
}

int main() {
    ifstream f("heavypath.in");
    ofstream g("heavypath.out");

    int n, q; f >> n >> q;
    for(int i=1; i<=n; i++) f >> v[i];
    for(int i=1; i<=n-1; i++) {
        int x, y; f >> x >> y;
        dx[x].emplace_back(y);
        dx[y].emplace_back(x);
    }

    dfs(1, 0);
    for(int i=0; i<cnt; i++) {
        sort(path[i].begin(), path[i].end(), comp);
        len[i] = path[i].size();
        for(int j=0; j<len[i]; j++) pos[path[i][j]] = j;
        aint.emplace_back(vector<int>{});
        aint[i].resize(4*len[i]+5, 0);
        build(1, 0, len[i]-1, i);
    }

    for(int i=1; i<=q; i++) {
        int type, x, y; f >> type >> x >> y;
        if(type == 0) {
            int path_id = where[x];
            update(1, 0, len[path_id]-1, pos[x], y, path_id);
        }
        else {
            int ans = 0;
            while(where[x] != where[y]) {
                if(niv[above[where[x]]] < niv[above[where[y]]]) swap(x, y);
                ans = max(ans, query(1, 0, len[where[x]]-1, 0, pos[x], where[x]));
                x = above[where[x]];
            }
            int L = min(pos[x], pos[y]);
            int R = max(pos[x], pos[y]);
            ans = max(ans, query(1, 0, len[where[x]]-1, L, R, where[x]));
            g << ans << "\n";
        }
    }
    return 0;
}
