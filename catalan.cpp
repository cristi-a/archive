// https://en.wikipedia.org/wiki/Catalan_number
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll modulo = 1e9 + 7;
const int nmax = 1e6;

ll fact[2*nmax+5];

ll lgput(ll base, ll exp) {
    ll temp = 1;
    while(exp) {
        if(exp&1) temp = temp * base % modulo;
        base = base * base % modulo;
        exp = exp >> 1;
    }
    return temp;
}

ll comb(int N, int K) {
    return fact[N] * lgput(fact[K], modulo-2) % modulo * lgput(fact[N-K], modulo-2) % modulo; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if(n%2==1) {
        cout << 0;
        return 0;
    }
    n /= 2;
    fact[0] = 1;
    for(int i=1; i<=2*n; i++) fact[i] = 1LL * fact[i-1] * i % modulo;
    cout << lgput(n+1, modulo-2) * comb(2*n, n) % modulo;
    return 0;
}
