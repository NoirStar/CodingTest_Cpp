#include <bits/stdc++.h>

using namespace std;
/*

�����̴� ���̰� 64cm�� ���븦 ������ �ִ�. ��� ��, �״� ���̰� Xcm�� ���밡 ������ �;�����. �����̴� ���� ������ �ִ� ���븦 �� ���� ����� �ڸ�������, Ǯ�� �ٿ��� ���̰� Xcm�� ���븦 ������� �Ѵ�.

���븦 �ڸ��� ���� ���� ����� �������� �ڸ��� ���̴�. �����̴� �Ʒ��� ���� ������ ���ļ� ���븦 �ڸ����� �Ѵ�.

�����̰� ������ �ִ� ������ ���̸� ��� ���Ѵ�. ó������ 64cm ���� �ϳ��� ������ �ִ�. �̶�, ���� X���� ũ�ٸ�, �Ʒ��� ���� ������ �ݺ��Ѵ�.
������ �ִ� ���� �� ���̰� ���� ª�� ���� �������� �ڸ���.
����, ������ �ڸ� ������ ���� �� �ϳ��� ������ �����ִ� ������ ������ ���� X���� ũ�ų� ���ٸ�, ������ �ڸ� ������ ���� �� �ϳ��� ������.
����, �����ִ� ��� ���븦 Ǯ�� �ٿ��� Xcm�� �����.
X�� �־����� ��, ���� ������ ��ģ�ٸ�, �� ���� ���븦 Ǯ�� �ٿ��� Xcm�� ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/


// ó������ 64cm  ��� ������ ���� x ���� Ŭ��
// ���� ª�� �� �������� �ڸ���
// �����ִ� ������ ������ ���� x���� ũ�ų� ���ٸ� ������ �ڸ��� ������
// x�� ��������� ��� ����� ������°�
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