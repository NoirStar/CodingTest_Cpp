#include <bits/stdc++.h>

using namespace std;
int k;

vector<string> vRet;
vector<int> vVisited;
vector<char> vCompare;

bool Compare(char c1, char c2, char oper) {
	if (c1 > c2 && oper == '>') return true;
	else if (c1 < c2 && oper == '<') return true;
	return false;
}

void dfs(string ret) {

	int nSize = ret.size();
	if (nSize == k + 1) {
		vRet.push_back(ret);
		return;
	}

	for (int i = 0; i < 10; i++) {
		
		if (vVisited[i]) continue;
		if (nSize == 0 || Compare(ret[nSize - 1], i + '0', vCompare[nSize - 1])) {
			vVisited[i] = 1;
			dfs(ret+to_string(i));
			vVisited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> k;

	vCompare.assign(k, 0);
	vVisited.assign(10, 0);
	for (int i = 0; i < k; i++) {
		cin >> vCompare[i];
	}
		
	dfs("");

	sort(vRet.begin(), vRet.end());
	
	cout << vRet.back() << '\n';
	cout << vRet.front() << '\n';

	return 0;
}