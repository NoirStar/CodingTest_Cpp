#include <bits/stdc++.h>

using namespace std;

struct StStringAscSortor {
	bool operator()(const string& str1, const string& str2) const {
		if (str1.size() == str2.size()) {
			return str1 < str2;
		}
		return str1.size() < str2.size();
	}
};

int main() {

	int nWord;
	set<string, StStringAscSortor> sStrList;
	cin >> nWord;

	for (int i = 0; i < nWord; i++) {
		string strTemp;
		cin >> strTemp;
		sStrList.insert(strTemp);
	}
	
	for (const auto& str : sStrList) {
		cout << str << '\n';
	}
	return 0;
}