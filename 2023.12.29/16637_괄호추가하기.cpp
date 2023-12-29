#include <bits/stdc++.h>

using namespace std;
// DAG 
// 숫자와 기호를 나눠야함

// 3 8 5 2
// * +   
// idx = 0 일때 
// num[0] num[1] oper[0]  한다음, num[이전+1], oper[이전+1]  경우의수, 
// num[1] num[2] oper[1]  한다음, num[0] 랑 더하는 경우의수?

int nRet = numeric_limits<int>::min();
vector<int> vNum;
vector<char> vOper;

int Calc(int a, int b, int c) {
	if (a == '+') return b + c;
	else if (a == '-') return b - c;
	else if (a == '*') return b * c;
}

void Calculator(int here, int n) {
	// 재귀는 기저사례부터 생각하고 정의한다.
	if (here == vNum.size() - 1) {
		nRet = max(nRet, n);
		return;
	}

	// num[0] num[1] oper[0]  한다음, num[이전+1], oper[이전+1]  경우의수, 
	Calculator(here + 1, Calc(vOper[here], n, vNum[here + 1]));

	// 이 경우의 수도 있으므로 고려한다.
	if (here + 2 <= vNum.size() - 1) {
		// num[1] num[2] oper[1]  한다음, num[0] 랑 더하는 경우의수 더하고, num[이전+2] 부터 계속진행
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

	// 누적합 처음부터시작
	Calculator(0, vNum[0]);
	cout << nRet;

	return 0;
}