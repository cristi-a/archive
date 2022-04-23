//Query returns frequence of a given word
#include <bits/stdc++.h>
using namespace std;
const int SIGMA = 26;	
 
struct trie {
	trie *adj[SIGMA];
	int frq, dp;
	trie() {
		frq = 0, dp = 0;
		for(int i=0; i<SIGMA; i++) adj[i] = NULL;
	}
};
trie *start = new trie;	

void add(trie *node, char *w) {
	if(*w=='\0') {
		node -> frq ++;
		return;
	}
	if(node -> adj[*w-'a'] == NULL) {
		node -> adj[*w-'a'] = new trie;
		node -> dp ++;
	}
	add(node -> adj[*w-'a'], w+1);	
}	
 
bool erase(trie *node, char *w) {
	if(*w=='\0') node -> frq --;
	else if(node -> adj[*w-'a'] != NULL and erase(node -> adj[*w-'a'], w+1)) {
		node -> adj[*w-'a'] = NULL;
		node -> dp --;
	}
	if(node -> frq == 0 and node -> dp == 0 and node!=start) {
		delete node;
		return 1;
	}
	return 0;	
}	
 
int query(trie *node, char *w) {
	if(*w=='\0') return node -> frq;
	else if(node -> adj[*w-'a'] != NULL) return query(node -> adj[*w-'a'], w+1);
	return 0;	
}
