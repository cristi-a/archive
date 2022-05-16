#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5;

int v[nmax+5];

void MergeSort(int left, int right) {
  if(left == right) return;
  int mid = (left + right) / 2;
  MergeSort(left, mid);
  MergeSort(mid+1, right);
  int i = left, j = mid + 1;
  vector<int> temp;
  while(i <= mid and j <= right) 
    if(v[i] < v[j]) temp.emplace_back(v[i++]);
    else temp.emplace_back(v[j++]);
  while(i <= mid) temp.emplace_back(v[i++]);
  while(j <= mid) temp.emplace_back(v[j++]);
  for(i=0; i<int(temp.size()); i++) v[left + i] = temp[i];
}

int main() {
  int n; cin >> n;
  for(int i=1; i<=n; i++) cin >> v[i];
  MergeSort(1, n);
  for(int i=1; i<=n; i++) cout << v[i] << " ";
  return 0;
}
