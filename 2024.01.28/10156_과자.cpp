#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c,d;
	cin >> a >> b >> c;

	d = a * b - c;
	if (d < 0) d = 0;
	cout << d;
	return 0;
}