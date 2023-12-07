#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> vMovie;

// 매개변수가 변경되면서 똑같은 로직
string quard(int y, int x, int size) {
	if (size == 1) return string(1, vMovie[y][x]);
	char b = vMovie[y][x];
	string ret;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			// 현재 시작하는 위치의 값과 다르면 새로 괄호를 생성한다.
			if (b != vMovie[i][j]) {
				ret += '(';
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}
	// 모두가 같을경우
	return string(1, vMovie[y][x]);
}

// divide and conquer => 재귀 또는 스택
int main() {
	int nSize;
	cin >> nSize;
	string strInput;

	vMovie.assign(nSize, vector<char>(nSize, 0));

	for (int i = 0; i < nSize; i++) {
		cin >> strInput;
		for (int j = 0; j < nSize; j++) {
			vMovie[i][j] = strInput[j];
		}
	}

	cout << quard(0, 0, nSize);

	return 0;
}