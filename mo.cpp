// base either sqrt(n) or power of 2 close to sqrt(n)
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;
const int base = 256;

int v[nmax+5];
int ans = 0;
int vf[2*nmax+10];

int vfAp[nmax+5];
int sol[nmax+5];

struct query {
	int st,dr,k,ind;
}ms[nmax+5];

bool comp(query a, query b) {
	int stba = a.st / base;
	int stbb = b.st / base;
	if(stba!=stbb) return(stba < stbb);
	return(a.dr < b.dr);
}

void add(int ind) {
	vfAp[vf[v[ind]]]--;
	vf[v[ind]]++;
	vfAp[vf[v[ind]]]++;
}

void rem(int ind) {
	vfAp[vf[v[ind]]]--;
	vf[v[ind]]--;
	vfAp[vf[v[ind]]]++;
}

int main () {
	ifstream f ("fsecv.in");
	ofstream g ("fsecv.out");

	int n,q; f >> n >> q;
	for(int i=1; i<=n; i++) {
		f >> v[i];
		v[i] += nmax + 1;
	}
	for(int i=1; i<=q; i++) {
		f >> ms[i].st >> ms[i].dr >> ms[i].k;
		ms[i].ind = i;
	}
	sort(ms+1,ms+q+1,comp);
	int l = 0 , r = 0;
	for(int i=1; i<=q; i++) {
		while(l>ms[i].st)
			add(--l);
		while(r<ms[i].dr)
			add(++r);
		while(l<ms[i].st)
			rem(l++);
		while(r>ms[i].dr)
			rem(r--);
		sol[ms[i].ind] = vfAp[ms[i].k];
	}
	for(int i=1; i<=q; i++) g << sol[i] << "\n";
	return 0;
}
