// 1159
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool Alphabet[26] = { 0 };
int main() {
	int Number;
	cin >> Number;
	vector<string> name;
	for (int i = 0; i < Number; i++) {
		string n;
		cin >> n;
		name.push_back(n);
		Alphabet[n[0] - 97] = true;
	}
	for (int i = 0; i < 26; i++) {
		if (Alphabet[i] == false) continue;
		int index = 0;
		for (int j = 0; j < Number; j++) {
			if (char(i + 97) == name[j][0])
				index++;
		}
		if (index < 5) {
			Alphabet[i] = false;
		}
	}
	int index = 0;
	for (int i = 0; i < 26; i++) {
		if (Alphabet[i] == true) {
			cout << char(i + 97);
		}
		else {
			index++;
		}
	}
	if (index == 26) {
		cout << "PREDAJA" << endl;
	}
}
