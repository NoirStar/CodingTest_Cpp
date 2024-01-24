#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;

	cin >> n;
	int a, b;
	a = n * (0.78);
	b = n * 0.8 + (n * 0.2 * 0.78);
	cout << a << ' ' << b;

	return 0;
}