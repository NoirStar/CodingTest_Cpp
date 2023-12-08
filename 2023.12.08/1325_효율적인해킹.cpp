#include <bits/stdc++.h>

using namespace std;

void dfs(int there) {
	
}

int main() {
	int nCom, nCase;
	cin >> nCom >> nCase;

	vector<vector<int>> vRelative(nCom+1);

	for (int i = 0; i < nCase; i++) {
		int a, b;
		cin >> a >> b;
		vRelative[a].push_back(b);
	}

	sort(vRelative.begin(), vRelative.end(), [](auto v1, auto v2) {
		return v1.size() > v2.size();
	});

	sort(vRelative[0].begin(), vRelative[0].end());

	for (const auto& v : vRelative[0]) cout << v << ' ';

	return 0;
}