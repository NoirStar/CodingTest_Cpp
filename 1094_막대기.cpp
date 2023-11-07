#include <bits/stdc++.h>

using namespace std;

int main() {
	int nStickX;
	int nCount = 0;
	vector<int> vSticks(1, 64); 

	cin >> nStickX;

	while (true) {
		int nStick = 0;
		for (int stick : vSticks) {
			nStick += stick;
		}
		
		if (nStick > nStickX) {
			int nShortestStick = vSticks.back() / 2;
			vSticks.pop_back();
			nStick -= nShortestStick;

			if (nStick >= nStickX) {
				vSticks.push_back(nShortestStick);
			}
			else {
				vSticks.push_back(nShortestStick);
				vSticks.push_back(nShortestStick);
			}
		}
		else {
			break;
		}
	}

	cout << vSticks.size();

	return 0;
}