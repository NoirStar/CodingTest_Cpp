#include <bits/stdc++.h>

using namespace std;

class CStack {
public:
	void ExecuteCommand(string& strCommand);

private:
	void push(int n);
	int pop();
	int size();
	int empty();
	int top();

private:
	vector<int> m_vStack;
};

void CStack::push(int n) {
	m_vStack.push_back(n);
}

int CStack::pop() {
	if (m_vStack.empty()) {
		return -1;
	}
	int nRet = m_vStack.back();
	m_vStack.pop_back();
	return nRet;
}

int CStack::size() {
	return m_vStack.size();
}

int CStack::empty() {
	return m_vStack.empty();
}

int CStack::top() {
	if (m_vStack.empty()) {
		return -1;
	}
	return m_vStack.back();
}

void CStack::ExecuteCommand(string& strCommand) {
	if (strCommand.find("push") != string::npos) {
		push(stoi(strCommand.substr(5)));
	}
	else if (strCommand.find("pop") != string::npos) {
		cout << pop() << '\n';
	}
	else if (strCommand.find("empty") != string::npos) {
		cout << empty() << '\n';
	}
	else if (strCommand.find("size") != string::npos) {
		cout << size() << '\n';
	}
	else if (strCommand.find("top") != string::npos) {
		cout << top() << '\n';
	}
}

int main() {
	int nSize;
	cin >> nSize;
	cin.ignore();

	vector<string> vCommand;
	string input;
	for (int i = 0; i < nSize; i++) {
		getline(cin, input);
		vCommand.push_back(input);
	}

	CStack cStack;
	for (auto& c : vCommand) {
		cStack.ExecuteCommand(c);
	}
	return 0;
}