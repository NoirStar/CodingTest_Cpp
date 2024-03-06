#include <bits/stdc++.h>

using namespace std;

int main() {
	string s, b, ans;
	cin >> s >> b;
	
	for (auto& c : s) {
		ans += c;

		if (ans.size() >= b.size()
			&& ans.substr(ans.size() - b.size(), b.size()) == b) {
			ans.erase(ans.end() - b.size(), ans.end());
		}
	}

	if (ans.empty()) cout << "FRULA";
	else cout << ans;
	return 0;
}