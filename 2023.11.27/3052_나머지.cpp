#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int> sInt;
	for (int i = 0; i < 10; i++) {
		int nTemp;
		cin >> nTemp;
		sInt.insert(nTemp % 42);
	}
	cout << sInt.size();
	
	return 0;
}