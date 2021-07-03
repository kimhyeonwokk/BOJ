// 1759 암호 만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> choose;
vector<char> all;
int L, C;
void find(int index, int cnt) {
	if (cnt == L) {
		int count1 = 0;
		int count2 = 0;
		for (auto i : choose) {
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
				count1++;
			}
			else
				count2++;
		}
		if (count1 < 1 || count2 < 2)
			return;
		for (auto i : choose)
			cout << i;
		cout << "\n";
		return;
	}
	if (index >= C) return;
	choose.push_back(all[index]);
	find(index + 1, cnt + 1);
	choose.pop_back();
	find(index + 1, cnt);

}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char temp;
		cin >> temp;
		all.push_back(temp);
	}
	sort(all.begin(), all.end());
	find(0, 0);
}
