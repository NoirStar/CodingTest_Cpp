#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nPok, nAnswer;

	cin >> nPok >> nAnswer;

	map<string, int> mPok;
	vector<string> vPok;
	for (int i = 1; i <= nPok; i++) {
		string s;
		cin >> s;
		mPok.insert({s,i});
		vPok.push_back(s);
	}

	auto IsDigit = [](string s) {
		if (s[0] >= 'A' && s[0] <= 'Z') return false;
		return true;
	};

	for (int i = 0; i < nAnswer; i++) {
		string s;
		cin >> s;
		if (IsDigit(s)) {
			cout << vPok[stoi(s) - 1] << '\n';
		}
		else {
			cout << mPok[s] << '\n';
		}
	}

	return 0;
}