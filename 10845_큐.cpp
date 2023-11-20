#include <bits/stdc++.h>

using namespace std;

class CQueue {
public:
	void ExecuteCommand(string& strCommand);

private:
	void push(int n);
	int pop();
	int size();
	bool empty();
	int front();
	int back();

private:
	vector<int> m_vQueue;
};

void CQueue::push(int n) {
	m_vQueue.push_back(n);
}

int CQueue::pop() {
	if (m_vQueue.empty()) {
		return -1;
	}
	int nRet = m_vQueue.front();
	m_vQueue.erase(m_vQueue.begin());
	return nRet;
}
int CQueue::size() {
	return m_vQueue.size();
}

bool CQueue::empty() {
	return m_vQueue.empty();
}
int CQueue::front() {
	if (m_vQueue.empty()) {
		return -1;
	}
	return m_vQueue.front();
}

int CQueue::back() {
	if (m_vQueue.empty()) {
		return -1;
	}
	return m_vQueue.back();
}


void CQueue::ExecuteCommand(string& strCommand) {	
	if (strCommand.find("push") != string::npos) {
		push(stoi(strCommand.substr(5)));
	}
	else if (strCommand.find("pop") != string::npos) {
		cout << pop() << '\n';
	}
	else if ((strCommand.find("front") != string::npos)) {
		cout << front() << '\n';
	}
	else if ((strCommand.find("back") != string::npos)) {
		cout << back() << '\n';
	}
	else if ((strCommand.find("size") != string::npos)) {
		cout << size() << '\n';
	}	
	else if ((strCommand.find("empty") != string::npos)) {
		cout << empty() << '\n';
	}
}

int main() {
	int nCommand;
	cin >> nCommand;
	cin.ignore();
	
	string strInput;
	vector<string> vCommand(nCommand);
	for (int i = 0; i < nCommand; i++) {
		getline(cin, strInput);
		vCommand[i] = strInput;
	}

	CQueue cQueue;
	for (auto& c : vCommand) {
		cQueue.ExecuteCommand(c);
	}
	return 0;
}