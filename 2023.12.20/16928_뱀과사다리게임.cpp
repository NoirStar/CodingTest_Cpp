#include <bits/stdc++.h>

using namespace std;

vector<int> vBoard;
vector<bool> vVisited;

void bfs(int here) {

	queue<pair<int,int>> q;
	q.push({ here, 0 });
	vVisited[1] = true;

	while (!q.empty()) {
		int pos, nDice;
		tie(pos, nDice) = q.front();
		q.pop();
		if (pos == 100) {
			cout << nDice;
			return;
		}

		for (int i = 1; i <= 6; i++) {

			int npos = pos + i;

			if (npos > 100 || vVisited[npos]) continue;
			
			if (vBoard[npos] > 0)
				npos = vBoard[npos];

			q.push({ npos, nDice+1 });
			vVisited[npos] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nLad, nSnake;
	cin >> nLad >> nSnake;

	vBoard.assign(101,0);
	vVisited.assign(101,0);
	
	for (int i = 0; i < nLad + nSnake; i++) {
		int x, y;
		cin >> x >> y;
		vBoard[x] = y;
	}

	bfs(1);

	return 0;
}