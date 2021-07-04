// 9093 단어 뒤집기
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i <= t; i++) {
		stack<char> s1;
		string temp;
		getline(cin, temp);
		if (i == 0) continue;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == ' ') {
				while (!s1.empty()) {
					cout << s1.top();
					s1.pop();
				}
				cout << temp[j];
				continue;
			}
			s1.push(temp[j]);
		}
		while (!s1.empty()) {
			cout << s1.top();
			s1.pop();
		}
		cout << "\n";
	}
}
