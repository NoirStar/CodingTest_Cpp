#include <bits/stdc++.h>

using namespace std;

int main() {
	int nCable, nNeedCable;
	cin >> nCable >> nNeedCable;
	vector<long long> vCable(nCable);
	
	for (int i = 0; i < nCable; i++) {
		cin >> vCable[i];
	}

	long long nLowCable = 1;
	long long nMaxCable = *max_element(vCable.begin(), vCable.end());

	while (nLowCable <= nMaxCable) {
		long long nMakeCable = 0;
		long long nMidCable = (nLowCable + nMaxCable) / 2;

		for (const auto& cable : vCable) {
			nMakeCable += (cable / nMidCable);
		}
		if (nMakeCable < nNeedCable) {
			nMaxCable = nMidCable-1;
		}
		else {
			nLowCable = nMidCable+1;
		}
	}
	cout << nMaxCable;
	return 0;
}