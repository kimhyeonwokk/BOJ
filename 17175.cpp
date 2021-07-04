// 17175 피보나치는 지겨웡~
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long int fibo[51] = { 0 };
    fibo[0] = 1;
    fibo[1] = 1;
    fibo[2] = 3;
    fibo[3] = 5;
    for (int i = 4; i <= 50; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2] + 1;
    cout << fibo[n] % 1000000007;
}
