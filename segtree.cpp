/*
	Update - add X to values in range [a, b]
	Query - sum of range [a, b]
	
	w/ lazy update
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 2e5;
const int lgmax = 18;

int v[nmax+5];
ll aint[4*nmax+5]; 
ll lazy[4*nmax+5]; // 4 * array length for worst case

void Push(int node, int left, int right) {
	aint[node] += 1L * lazy[node] * (right - left + 1);
	for(int i=0; left!=right and i<2; i++) {
		int son = node * 2 + i;
		lazy[son] += lazy[node];
	}
	lazy[node] = 0;
}

void Build(int node, int left, int right) {
	if(left == right) {
		aint[node] = v[left];
		return;
	}
	int mid = (left + right) / 2;
	Build(node*2, left, mid);
	Build(node*2+1, mid+1, right);
	aint[node] = aint[node*2] + aint[node*2+1];
}

void Update(int node, int left, int right, int st, int dr, ll val) {
	if(st<=left and right<=dr) {
		lazy[node] += val;
		return;
	}
	Push(node, left, right);
	int mid = (left + right) / 2;
	if(mid>=st) Update(node*2, left, mid, st, dr, val);
	if(mid<dr) Update(node*2+1, mid+1, right, st, dr, val);
	aint[node] = aint[node*2] + aint[node*2+1];
}

ll Query(int node, int left, int right, int st, int dr) {
	Push(node, left, right);
	if(st<=left and right<=dr) return aint[node];
	ll rez = 0;
	int mid = (left + right) / 2;
	if(mid>=st) rez += Query(node*2, left, mid, st, dr);
	if(mid<dr) rez += Query(node*2+1, mid+1, right, st, dr);
	return rez;
}
