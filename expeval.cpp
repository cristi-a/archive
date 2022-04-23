#include <bits/stdc++.h>	
using namespace std;	

int nr();
int small();
int half();
int whole();	

string t; 
int poz = 0;	

int nr() {
	int temp = 0;
	while(t[poz]>='0' and t[poz]<='9') temp = temp * 10 + (t[poz++] - '0');
	return temp;	
}	

int small() {
	int temp = 0;
	if(t[poz]=='(') poz++, temp = whole(), poz++;
	else temp = nr();
	return temp;	
}	

int half() {
	int temp = small();
	while(t[poz]=='*' or t[poz]=='/') 
		t[poz++]=='*' ? temp *= small() : temp /= small();
	return temp;	
}	

int whole() {
	int temp = half();
	while(t[poz]=='+' or t[poz]=='-') 
		t[poz++]=='+' ? temp += half() : temp -= half();
	return temp;	
}	

int main() {
	cin >> t;
	cout << whole();
	return 0;	
}
