#include <bits/stdc++.h>

using namespace std;

int main() {
	int nNumX;
	cin >> nNumX;
	
	int nHansu = 0;
	for (int i = 1; i <= nNumX; i++) {
		if (i < 10) {
			nHansu++;
		}
		else {
			string strTemp = to_string(i);
			bool bIsHansu = true;
			int nGap = stoi(strTemp.substr(0, 1)) - stoi(strTemp.substr(1, 1));
			for (int j = 0; j < strTemp.length()-1; j++) {
				if (stoi(strTemp.substr(j, 1)) - stoi(strTemp.substr(j + 1, 1)) != nGap) {
					bIsHansu = false;
				}
			}
			bIsHansu ? nHansu++ : nHansu;
		}
	}
	cout << nHansu;
	return 0;
}