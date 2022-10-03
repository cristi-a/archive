#include <bits/stdc++.h>
using namespace std;
const int nmax = 100;

vector<vector<int>> dx(nmax+5);
int curr, idx[nmax+5], lowlink[nmax+5], nr;
bool onstack[nmax+5];
stack<int> s;

vector<vector<int>> comp;

void strongconnect(int node) {
    idx[node] = curr; lowlink[node] = curr;
    curr++;
    s.emplace(node); onstack[node] = true;

    for(auto next : dx[node]) {
        if(idx[next] == -1) {
            strongconnect(next);
            lowlink[node] = min(lowlink[node], lowlink[next]);
        }
        else if(onstack[next])
            lowlink[node] = min(lowlink[node], lowlink[next]);
    }

    if(idx[node] == lowlink[node]) {
        nr++;
        int currnode;
        vector<int> temp;
        do {
            currnode = s.top(); s.pop(); onstack[currnode] = false;
            temp.emplace_back(currnode);
        } while(currnode != node);
        comp.emplace_back(temp);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int x, y; cin >> x >> y;
        dx[x].emplace_back(y);
    }

    for(int i=1; i<=n; i++) 
        idx[i] = -1;

    for(int i=1; i<=n; i++)
        if(idx[i] == -1)
            strongconnect(i);

    cout << nr;
    return 0;
}
