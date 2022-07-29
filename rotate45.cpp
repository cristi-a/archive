// rotate matrix by 45 degrees
#include <bits/stdc++.h>
using namespace std;
const int nmax = 400;

int a[2*nmax+5][2*nmax+5], sp[2*nmax+5][2*nmax+5];

int main() {
    ifstream f("lazy.in");
    ofstream g("lazy.out");

    int n, k; f >> n >> k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) 
            f >> a[i+j-1][n-i+j];
    for(int i=1; i<=2*n-1; i++)
        for(int j=1; j<=2*n-1; j++) 
            sp[i][j] = a[i][j] + sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1];
    int mx = 0;
    for(int i=1; i<=2*n-1; i++)
        for(int j=1; j<=2*n+1; j++) {
            int s = sp[i][j];
            if(i>=2*k+1) s = s - sp[i-(2*k+1)][j];
            if(j>=2*k+1) s = s - sp[i][j-(2*k+1)];
            if(i>=2*k+1 and j>=2*k+1) s = s + sp[i-(2*k+1)][j-(2*k+1)];
            mx = max(mx, s);
        }
    g << mx;
    return 0;
}
