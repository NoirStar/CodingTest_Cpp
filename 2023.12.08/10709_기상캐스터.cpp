#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> vSky(h, vector<char>(w, 0));
	vector<vector<int>> vRet(h, vector<int>(w, -1));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> vSky[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			for (int k = j; k >= 0; k--) {
				if (vSky[i][k] == 'c') {
					vRet[i][j] = j - k;
					break;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << vRet[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}