#include <bits/stdc++.h>

using namespace std;

class CDeque {
public:
	void ExecuteCommand(string& strCommand);

private:
	void push_front(int n);
	void push_back(int n);
	int pop_front();
	int pop_back();
	int size();
	bool empty();
	int front();
	int back();

private:
	deque<int> m_dDeque;
};

void CDeque::push_front(int n) {
	m_dDeque.push_front(n);
}

void CDeque::push_back(int n) {
	m_dDeque.push_back(n);
}

int CDeque::pop_front() {
	if (m_dDeque.empty()) {
		return -1;
	}
	int nRet = m_dDeque.front();
	m_dDeque.pop_front();
	return nRet;
}

int CDeque::pop_back() {
	if (m_dDeque.empty()) {
		return -1;
	}
	int nRet = m_dDeque.back();
	m_dDeque.pop_back();
	return nRet;
}

int CDeque::size() {
	return m_dDeque.size();
}

bool CDeque::empty() {
	return m_dDeque.empty();
}
int CDeque::front() {
	if (m_dDeque.empty()) {
		return -1;
	}
	return m_dDeque.front();
}

int CDeque::back() {
	if (m_dDeque.empty()) {
		return -1;
	}
	return m_dDeque.back();
}


void CDeque::ExecuteCommand(string& strCommand) {
	if (strCommand.find("push_back") != string::npos) {
		push_back(stoi(strCommand.substr(10)));
	}
	else if (strCommand.find("push_front") != string::npos) {
		push_front(stoi(strCommand.substr(11)));
	}
	else if (strCommand == "front") {
		cout << front() << '\n';
	}
	else if (strCommand == "back") {
		int nBack = back();
		cout << nBack << '\n';
	}
	else if (strCommand == "pop_front") {
		cout << pop_front() << '\n';
	}
	else if (strCommand == "pop_back") {
		cout << pop_back() << '\n';
	}
	else if (strCommand == "size") {
		cout << size() << '\n';
	}
	else if (strCommand == "empty") {
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

	CDeque CDeque;
	for (auto& c : vCommand) {
		CDeque.ExecuteCommand(c);
	}
	return 0;
}