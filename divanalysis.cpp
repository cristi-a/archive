// https://cses.fi/problemset/task/2182/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll modulo = 1e9 + 7;

    auto Pow = [](ll base, ll exp, ll mod) {
        ll temp = 1;
        base %= mod;
        while(exp) {
            if(exp&1) temp = temp * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return temp;
    };

    int n; cin >> n;
    ll ct = 1, s = 1, p = 1, exp = 1 ;
    for(int i=1; i<=n; i++) {
        ll x, k; cin >> x >> k;
        ct = ct * (k+1) % modulo;
        s = s * (Pow(x, k+1, modulo) - 1) % modulo * Pow(x-1, modulo-2, modulo) % modulo;
        p = Pow(p, k+1, modulo) * Pow(Pow(x, k*(k+1)/2, modulo), exp, modulo) % modulo;
        exp = exp * (k+1) % (modulo-1);
    }
    cout << ct << " " << s << " " << p;
    return 0;
}
