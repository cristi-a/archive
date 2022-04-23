#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll modulo = 1e9 + 7;
 
ll M[2][2] = {{0, 1},
              {1, 1}};
			
ll R[2][2] = {{0, 1},
              {1, 1}};
				
void Multiply(ll A[][2], ll B[][2]) {
	ll temp[2][2] = {{0,0},{0,0}};
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				temp[i][j] = (temp[i][j] + A[i][k] * B[k][j] % modulo) % modulo;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			A[i][j] = temp[i][j];
}		
 
void Raise(ll exp) {
	while(exp) {
		if(exp&1) Multiply(R, M);
		Multiply(M, M);
		exp = exp >> 1;
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
				  
	ll n; cin >> n;
	if(n==0) {
		cout << 0;
		return 0;
	}
	if(n==1) {
		cout << 1;
		return 0;
	}
	Raise(n-2);
	cout << R[1][1];
	return 0;
}
