#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nLen;
	cin >> nLen;
	string strInput;
	cin >> strInput;

	vector<long long> vPow(51);
	vPow[0] = 1;

	for (int i = 1; i <= 50; i++) {
		vPow[i] = (vPow[i - 1] * 31) % 1234567891;
	}

	long long llSum = 0;
	for (int i = 0; i < nLen; i++) {
		llSum += ((static_cast<long long>(strInput[i]) - 'a' + 1) * vPow[i]) % 1234567891;
	}
	llSum %= 1234567891;

	cout << llSum;

	return 0;
}