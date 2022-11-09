#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;
const int logmax = 17;

vector<vector<int>> dx(nmax+5);
int frst[nmax+5], timer = 0, niv[nmax+5];
int eul[2*nmax+5], rmq[2*nmax+5][logmax+5], Log2[2*nmax+5];

void dfs(int node, int father, int idx) {
    frst[node] = ++timer;
    eul[timer] = node;
    niv[node] = idx;
    for(auto i : dx[node]) {
        if(i == father) continue;

        dfs(i, node, idx+1);
        eul[++timer] = node; 
    }
}

int merge(int a, int b) {
    return (niv[a] < niv[b] ? a : b);
}

int query(int st, int dr) {
    int p2 = Log2[dr - st + 1];
    return merge(rmq[st][p2], rmq[dr-(1<<p2)+1][p2]);
}

int main() {
    ifstream f("lca.in");
    ofstream g("lca.out");

    int n, q; f >> n >> q;
    for(int x=2; x<=n; x++) {
        int y; f >> y;
        dx[x].emplace_back(y);
        dx[y].emplace_back(x);
    }

    dfs(1, 0, 1);
    for(int i=2; i<=timer; i++) Log2[i] = Log2[i/2] + 1;
    for(int i=1; i<=timer; i++) rmq[i][0] = eul[i];
    for(int j=1; (1<<j)<=timer; j++)
        for(int i=1; i+(1<<j)-1<=timer; i++)
            rmq[i][j] = merge(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);

    for(int i=1; i<=q; i++) {
        int a, b; f >> a >> b;
        if(frst[a] > frst[b]) swap(a, b);
        g << query(frst[a], frst[b]) << "\n";
    }
    return 0;
}
