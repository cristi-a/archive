// using doubles
// possible without (see chtrick.cpp)
#include <bits/stdc++.h>
using namespace std;	

struct Point {
	double x, y;
	double operator*(const Point&other) {
		return x*other.y - other.x*y;
	}	
};	

bool comp(Point a, Point b) {
	if(a.x!=b.x) return a.x < b.x;
	return a.y < b.y;	
}	
 
bool crease(Point New, Point Origin, Point Old) {
	Old.x = Old.x - Origin.x; Old.y = Old.y - Origin.y;
	New.x = New.x - Origin.x; New.y = New.y - Origin.y;
	return (New*Old) < 0.00;	
}	
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	vector<Point> v(n);
	for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y;
	sort(v.begin(), v.end(), comp);
	vector<Point> lower, upper;
	for(int i=0; i<n; i++) {
		while(lower.size() >= 2 and crease(v[i], lower[lower.size()-1], lower[lower.size()-2])) lower.pop_back();
		lower.emplace_back(v[i]);
	}
	for(int i=n-1; i>=0; i--) {
		while(upper.size() >= 2 and crease(v[i], upper[upper.size()-1], upper[upper.size()-2])) upper.pop_back();
		upper.emplace_back(v[i]);
	}
	cout << lower.size() + upper.size() - 2 << "\n";
	for(int i=0; i<lower.size()-1; i++) cout << fixed << setprecision(12) << lower[i].x << " " << lower[i].y << "\n";
	for(int i=0; i<upper.size()-1; i++) cout << fixed << setprecision(12) << upper[i].x << " " << upper[i].y << "\n";
	return 0;	
}
