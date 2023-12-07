#include <bits/stdc++.h>

using namespace std;

struct Msg {
	int nMsg;
	int nCount;
	int nIdx;
};

int main() {
	int nMsg, nC;
	cin >> nMsg >> nC;

	map<int, pair<int,int>> mMsg;
	vector<Msg> vMsg;
	for (int i = 0; i < nMsg; i++) {
		int nTemp;
		cin >> nTemp;
		if (mMsg[nTemp].first == 0) {
			mMsg[nTemp] = {1, i};
		}
		else {
			mMsg[nTemp].first++;
		}
	}


	for (const auto& m : mMsg) {
		Msg msg;
		msg.nMsg = m.first;
		msg.nCount = m.second.first;
		msg.nIdx = m.second.second;
		vMsg.push_back(msg);
	}

	sort(vMsg.begin(), vMsg.end(), [](const Msg& m1, const Msg& m2) -> auto{
		if (m1.nCount == m2.nCount) {
			return m1.nIdx < m2.nIdx;
		}
		return m1.nCount > m2.nCount;
	});

	for (const auto& m : vMsg) {
		for (int i = 0; i < m.nCount; i++) {
			cout << m.nMsg << ' ';
		}
	}


	return 0;
}