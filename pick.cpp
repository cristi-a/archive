#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1e5;

struct Point {
    ll x = 0;
    ll y = 0;
    ll operator*(const Point &other) {
        return x*other.y - y*other.x;
    }
};

int main() {
    ifstream f("copaci.in");
    ofstream g("copaci.out");

    int n; f >> n;
    vector<Point> v(n);
    for(int i=0; i<n; i++) f >> v[i].x >> v[i].y;
    v.emplace_back(v[0]);
    ll B = 0;
    ll A = 0;
    for(int i=1; i<=n; i++) {
        ll X = abs(v[i].x - v[i-1].x);
        ll Y = abs(v[i].y - v[i-1].y);
        A = A + v[i]*v[i-1];
        B += (!X or !Y ? X+Y : __gcd(X, Y)); 
    }
    g << abs(A)/2 + 1 - B/2;
    return 0;
}
