#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	int num = 0;
	for (int i = 0; i < n; i++) {
		string s;
		int m;
		cin >> s;
		if (s != "empty" && s != "all") {
			cin >> m;
			if (s[0] == 'a' && s[1] == 'd') num |= (1 << m);
			else if (s[0] == 'r') num &= ~(1 << m);
			else if (s[0] == 'c') cout << ((num & (1 << m)) == 0 ? 0 : 1) << '\n';
			else if (s[0] == 't') num ^= (1 << m);
		}
		else if (s == "all") {
			num = (1 << 21) - 1;
		}
		else {
			num = 0;
		}
	}
	return 0;
}