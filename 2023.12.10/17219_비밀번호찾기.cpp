#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nSite, nSearch;
	
	cin >> nSite >> nSearch;

	map<string, string> mSite;

	for (int i = 0; i < nSite; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mSite[s1] = s2;
	}

	for (int i = 0; i < nSearch; i++) {
		string s1;
		cin >> s1;
		cout << mSite[s1] << endl;
	}

	return 0;
}