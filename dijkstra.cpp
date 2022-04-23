#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 2e5;
const ll inf = 1e18;
 
vector<vector<pair<ll,int>>> dx(nmax+5);
ll dp[nmax+5];
 
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
 
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int x,y; ll c; cin >> x >> y >> c;
        dx[x].emplace_back(c,y);
    }

    for(int i=1; i<=n; i++)
        dp[i] = inf;

    dp[1] = 0;
    pq.push({0,1});
    while(pq.size()) {
        pair<ll,int> now = pq.top(); pq.pop();
        if(now.first!=dp[now.second]) continue;
        for(auto i : dx[now.second]) {
            pair<ll,int> nxt = i;
            if(dp[nxt.second] > now.first + nxt.first) {
                dp[nxt.second] = now.first + nxt.first;
                pq.push({now.first+nxt.first,nxt.second});
            }
        }
    }

    for(int i=1; i<=n; i++) cout << dp[i] << " ";
    return 0;
}
