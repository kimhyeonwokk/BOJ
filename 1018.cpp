#include <iostream>
using namespace std;

char arr[51][51];
char correct1[9][9];
char correct2[9][9];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (i % 2 == 1 && j % 2 == 1)
			{
				correct1[i][j] = 'W';
				correct2[i][j] = 'B';
			}
			else if (i % 2 == 0 && j % 2 == 0)
			{
				correct1[i][j] = 'W';
				correct2[i][j] = 'B';
			}
			else
			{
				correct1[i][j] = 'B';
				correct2[i][j] = 'W';
			}
		}
	}
	int N, M, index1 = 0, index2 = 0 , min = 0;
	char c;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> c;
			arr[i][j] = c;
		}
	}

	for (int i = 1; i <= N - 7; i++)
	{
		index1 = 0;
		index2 = 0;
		for (int j = 1; j <= M - 7; j++)
		{
			index1 = 0;
			index2 = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (arr[i + k][j + l] != correct1[k + 1][l + 1])
						index1++;

					if (arr[i + k][j + l] != correct2[k + 1][l + 1])
						index2++;
				}
			}
			if (index1 < index2)
			{
				if (i == 1 && j == 1)
					min = index1;
				else if (index1 < min)
					min = index1;
			}
			else
			{
				if (i == 1 && j == 1)
					min = index2;
				else if (index2 < min)
					min = index2;
			}
		}

	}
	cout << min;
}
