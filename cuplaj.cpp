#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e4;

vector<vector<int>> dx(nmax+5);
bool viz[nmax+5];
int st[nmax+5], dr[nmax+5];

bool couple(int node) {
    if(viz[node]) return false; 
    viz[node] = true;
    for(auto next : dx[node]) 
        if(dr[next] == 0) {
            st[node] = next;
            dr[next] = node;
            return true;
        }
    for(auto next : dx[node])
        if(couple(dr[next])) {
            st[node] = next;
            dr[next] = node;
            return true;
        }
    return false;
}

int main() {
    ifstream f("cuplaj.in");
    ofstream g("cuplaj.out");

    int n, m, e; f >> n >> m >> e;
    for(int i=1; i<=e; i++) {
        int x, y; f >> x >> y;
        dx[x].emplace_back(y);
    }
    int ans = 0;
    bool ok = false;
    while(ok == false) {
        ok = true;
        for(int i=1; i<=n; i++) viz[i] = false;
        for(int i=1; i<=n; i++)
            if(st[i] == 0 and couple(i)) {
                ans++;
                ok = false;
            }
    }
    g << ans << "\n";
    for(int i=1; i<=n; i++)
        if(st[i]) g << i << " " << st[i] << "\n";
    return 0;
}
