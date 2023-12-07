#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> vMovie;

// �Ű������� ����Ǹ鼭 �Ȱ��� ����
string quard(int y, int x, int size) {
	if (size == 1) return string(1, vMovie[y][x]);
	char b = vMovie[y][x];
	string ret;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			// ���� �����ϴ� ��ġ�� ���� �ٸ��� ���� ��ȣ�� �����Ѵ�.
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
	// ��ΰ� �������
	return string(1, vMovie[y][x]);
}

// divide and conquer => ��� �Ǵ� ����
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