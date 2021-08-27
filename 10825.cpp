#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
struct Name {
	string name;
	int korean;
	int english;
	int math;
};
bool cmp(const Name& a, const Name& b) {
	if (a.korean == b.korean) {
		if (a.english == b.english) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.english < b.english;
	}
	return a.korean > b.korean;
}
vector<Name> list;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string n; int k, e, m;
		cin >> n >> k >> e >> m;
		list.push_back({ n,k,e,m });
	}
	sort(list.begin(), list.end(), cmp);
	for (auto i : list) {
		cout << i.name << "\n";
	}
}
