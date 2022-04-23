#include <bits/stdc++.h>
using namespace std;	
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int rez = 0;
        for(int i=1; i<=n; i++) {
            int x; cin >> x;
            rez = rez ^ x;
        }
        cout << (rez ? "W\n" : "L\n");
    }
    return 0;	
}
