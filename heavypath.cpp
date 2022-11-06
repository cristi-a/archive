// https://codeforces.com/blog/entry/53170
#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5;

vector<vector<int>> dx(nmax+5);
int init[nmax+5], dim[nmax+5], par[nmax+5], nxt[nmax+5], niv[nmax+5];

int in[nmax+5], out[nmax+5], timer = 1, v[nmax+5];
int aint[4*nmax+5];

void dfs_dim(int node) {
    dim[node] = 1;
    for(auto &i : dx[node]) {
        dx[i].erase(find(dx[i].begin(), dx[i].end(), node));
        par[i] = node;
        niv[i] = niv[node] + 1;
        dfs_dim(i);
        dim[node] += dim[i];
        if(dim[i] > dim[dx[node][0]]) swap(i, dx[node][0]);
    }
}

void dfs_hld(int node) {
    in[node] = timer++;
    for(auto i : dx[node]) {
        nxt[i] = (i == dx[node][0] ? nxt[node] : i);
        dfs_hld(i);
    }
    out[node] = timer - 1;
}

void build(int node, int left, int right) {
    if(left == right) {
        aint[node] = v[left];
        return;
    }
    int mid = (left + right) / 2;
    build(node*2, left, mid);
    build(node*2+1, mid+1, right);
    aint[node] = max(aint[node*2], aint[node*2+1]);
}

void update(int node, int left, int right, int pos, int val) {
    if(left == right) {
        aint[node] = val;
        return;
    }
    int mid = (left + right) / 2;
    if(mid >= pos) update(node*2, left, mid, pos, val);
    if(mid < pos) update(node*2+1, mid+1, right, pos, val);
    aint[node] = max(aint[node*2], aint[node*2+1]);
}

int query(int node, int left, int right, int st, int dr) {
    if(st <= left and right <= dr) return aint[node];
    int mid = (left + right) / 2, ans = 0;
    if(mid >= st) ans = max(ans, query(node*2, left, mid, st, dr));
    if(mid < dr) ans = max(ans, query(node*2+1, mid+1, right, st, dr));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> init[i];
    for(int i=1; i<=n-1; i++) {
        int x, y; cin >> x >> y;
        dx[x].emplace_back(y);
        dx[y].emplace_back(x);
    }
    nxt[1] = 1;
    dfs_dim(1);
    dfs_hld(1);
    for(int i=1; i<=n; i++) v[in[i]] = init[i];
    build(1, 1, n);
    for(int i=1; i<=q; i++) {
        int type, a, b; cin >> type >> a >> b;
        if(type == 1) update(1, 1, n, in[a], b);
        else {
            int ans = 0;
            while(nxt[a] != nxt[b]) {
                if(niv[nxt[a]] < niv[nxt[b]]) swap(a, b);
                ans = max(ans, query(1, 1, n, in[nxt[a]], in[a]));
                a = par[nxt[a]];
            }
            if(in[a] > in[b]) swap(a, b);
            ans = max(ans, query(1, 1, n, in[a], in[b]));
            cout << ans << "\n";
        }
    }
    return 0;
}
