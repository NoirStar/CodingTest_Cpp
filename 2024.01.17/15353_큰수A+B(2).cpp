#include <bits/stdc++.h>

using namespace std;

string AddString(string a, string b) {
	int sum = 0;
	string strRet;

	while (a.size() || b.size() || sum) {
		if (a.size()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		strRet += (sum % 10) + '0';
		// Ä³¸®
		sum /= 10;
	}
	reverse(strRet.begin(), strRet.end());
	return strRet;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a,b;
	cin >> a >> b;

	cout << AddString(a, b);

	return 0;
}