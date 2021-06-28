#include <iostream>
using namespace std;
long long int T, x = 0, y = 0, d = 0, i1 = 1, k = 1, index = 1;
int main(void) {

	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		i1 = 1, k = 1, index = 1;
		scanf("%d%d", &x, &y);

		for (;;)
		{
			i1 = i1 + index;
			if (y-x < i1)
				break;
			i1 = i1 + index;
			k++;
			if (y - x < i1)
				break;
			k++;
			index++;
		}
		printf("%d\n", k);
	}
}
