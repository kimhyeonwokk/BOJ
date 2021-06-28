#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int> > vec(N);
    vector<int> answer(N);

    for (int i = 0; i < N; ++i) {
        cin >> vec[i].first;
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    int ct = 0;
    for (int i = 0; i < N; ++i) {
        int idx = vec[i].second;
        int temp = ct;

        answer[idx] = temp;
        ct++;

        while (i < N && vec[i].first == vec[i + 1].first) {
            ++i;
            idx = vec[i].second;
            answer[idx] = temp;
        }
    }

    for (auto a : answer)
        cout << a << " ";

}
