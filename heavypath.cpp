// https://codeforces.com/blog/entry/53170 - flattening tree
// https://codeforces.com/blog/entry/18051 - segtree with 2 * n memory
#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5;

vector<vector<int>> dx(nmax+5);
int init[nmax+5], dim[nmax+5], par[nmax+5], nxt[nmax+5], niv[nmax+5];

int in[nmax+5], out[nmax+5], timer = 1, v[nmax+5];
int aint[2*nmax+5];

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

void build(int n) {
    for(int i=1; i<=n; i++) aint[i+n] = v[i];
    for(int i=n-1; i>=1; i--) aint[i] = max(aint[2*i], aint[2*i+1]);
}

void update(int n, int pos, int val) {
    for(aint[pos+=n]=val; pos>1; pos/=2) aint[pos/2] = max(aint[pos], aint[pos^1]);
}

int query(int n, int st, int dr) {
    int temp = 0;
    for(st += n, dr += n; st < dr; st/=2, dr/=2) {
        if(st&1) temp = max(temp, aint[st++]);
        if(dr&1) temp = max(temp, aint[--dr]);
    }
    return temp;
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
    build(n);
    for(int i=1; i<=q; i++) {
        int type, a, b; cin >> type >> a >> b;
        if(type == 1) update(n, in[a], b);
        else {
            int ans = 0;
            while(nxt[a] != nxt[b]) {
                if(niv[nxt[a]] < niv[nxt[b]]) swap(a, b);
                ans = max(ans, query(n, in[nxt[a]], in[a]+1));
                a = par[nxt[a]];
            }
            if(in[a] > in[b]) swap(a, b);
            ans = max(ans, query(n, in[a], in[b]+1));
            cout << ans << "\n";
        }
    }
    return 0;
}

