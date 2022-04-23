#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	auto PowMod = [&](ll Base, int Exp, int Mod) {
		ll Temp = 1;
		Base %= Mod;
		while(Exp) {
			if(Exp & 1) Temp = Temp * Base % Mod;
			Base = Base * Base % Mod;
			Exp = Exp >> 1;
		}
		return Temp;
	};
	return 0;
}
