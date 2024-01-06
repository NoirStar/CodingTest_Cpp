#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;

	string sound[3] = { "pi","ka","chu" };

	while (true) {
		bool bFound = false;

		for (const auto& c : sound) {
			int idx = s.find(c);
			if (idx != string::npos) {
				string temp;
				for (int i = 0; i < c.size(); i++) temp += ".";
				s.replace(idx, c.size(), temp);
				bFound = true;
			}
		}

		if (!bFound) {
			for (const auto& c : s) {
				if (c != '.') {
					cout << "NO";
					return 0;
				}
			}
			cout << "YES";
			return 0;
		}
	}
}