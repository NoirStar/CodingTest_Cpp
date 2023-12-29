#include <bits/stdc++.h>

using namespace std;
// DAG 
// ���ڿ� ��ȣ�� ��������

// 3 8 5 2
// * +   
// idx = 0 �϶� 
// num[0] num[1] oper[0]  �Ѵ���, num[����+1], oper[����+1]  ����Ǽ�, 
// num[1] num[2] oper[1]  �Ѵ���, num[0] �� ���ϴ� ����Ǽ�?

int nRet = numeric_limits<int>::min();
vector<int> vNum;
vector<char> vOper;

int Calc(int a, int b, int c) {
	if (a == '+') return b + c;
	else if (a == '-') return b - c;
	else if (a == '*') return b * c;
}

void Calculator(int here, int n) {
	// ��ʹ� ������ʺ��� �����ϰ� �����Ѵ�.
	if (here == vNum.size() - 1) {
		nRet = max(nRet, n);
		return;
	}

	// num[0] num[1] oper[0]  �Ѵ���, num[����+1], oper[����+1]  ����Ǽ�, 
	Calculator(here + 1, Calc(vOper[here], n, vNum[here + 1]));

	// �� ����� ���� �����Ƿ� ����Ѵ�.
	if (here + 2 <= vNum.size() - 1) {
		// num[1] num[2] oper[1]  �Ѵ���, num[0] �� ���ϴ� ����Ǽ� ���ϰ�, num[����+2] ���� �������
		Calculator(here + 2, Calc(vOper[here], n, Calc(vOper[here + 1], vNum[here + 1], vNum[here + 2])));
	}
	return;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int nLen;
	string strInput;
	cin >> nLen;
	cin >> strInput;

	for (int i = 0; i < nLen; i++) {
		if (i % 2 == 0) vNum.push_back(strInput[i] - '0');
		else vOper.push_back(strInput[i]);
	}

	// ������ ó�����ͽ���
	Calculator(0, vNum[0]);
	cout << nRet;

	return 0;
}