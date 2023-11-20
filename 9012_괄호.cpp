#include <bits/stdc++.h>

using namespace std;

int main() {
	int nVPS;
	cin >> nVPS;

	vector<string> vVPS(nVPS);
	vector<string> vAnswer;

	for (int i = 0; i < nVPS; i++) {
		cin >> vVPS[i];
	}

	for (auto vps : vVPS) {
		int index;
		while (vps.find("()") != string::npos) {
			index = vps.find("()");
			vps.erase(index, 2);
		}
		vps.size() ? vAnswer.push_back("NO") : vAnswer.push_back("YES");
	}

	for (const auto& a : vAnswer) {
		cout << a << '\n';
	}

	return 0;
}