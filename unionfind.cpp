/*
	disjoint set union
	small-to-large merging
	at first: comp[i] = i, dim[i] = 1 for every i
*/
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;

int comp[nmax+5], dim[nmax+5];

int Find(int node) {
	if(comp[node] == node) return node;
	comp[node] = Find(comp[node]);
	return comp[node];
}

void Union(int a, int b) {
	int ra = Find(a), rb = Find(b);
	if(ra == rb) return;
	if(dim[ra] > dim[rb]) swap(ra, rb);
	dim[rb] += dim[ra];
	comp[ra] = comp[rb];
}
