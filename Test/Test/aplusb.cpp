#include <iostream>

using namespace std;

int main()
{
	int N, i, j, k, num, count = 0;
	int a[50001] = { 0 };
	int b[50001] = { 0 };
	cin >> N;
	for(i = 0; i < N; i++)
	{
		cin >> num;
		if (num < 0)
			b[abs(num)]++;
		else
			a[num]++;
	}
	for (i = 0; i <= 50000; i++)
	{
		if (a[i] != 0)
		{
			for (j = 0; j <= 50000; j++)
			{
				if (j == i)
				{
					if (a[i] > 1)
					{
						k = abs(i + j);
						if (k > 50000)
							break;
						if (a[k] != 0)
							count += a[i] * (a[i] - 1);
					}
					continue;
				}
				if (a[j] != 0)
				{
					k = abs (i + j);
					if (k > 50000)
						break;
					if (a[k] != 0)
					{
						count += a[i] * a[j] * a[k];
					}
				}
				if (b[j] != 0)
				{
					k = i + j;
					if (k > 50000 || k < -50000)
						break;
					if (k < 0)
					{
						if (b[abs(k)] != 0)
						{
							count += b[i] * b[j] * b[k];
						}
					}
					else
					{
						if (a[k] != 0)
						{
							count += b[i] * b[j] * a[k];
						}
					}
				}

			}
		}
		if (b[i] != 0)
		{
			for (j = 0; j < 50000; j++)
			{
				if (j == i)
				{
					if (b[i] > 1)
					{
						k = abs(i + j);
						if (k > 50000)
							break;
						if (b[k] != 0)
							count += b[i] * (b[i] - 1);
					}
					continue;
				}
				if (a[j] != 0)
				{
					k = i + j;
					if (k > 50000 || k < -50000)
						break;
					if (k < 0)
					{
						if (b[abs(k)] != 0)
						{
							count += b[i] * b[j] * b[k];
						}
					}
					else
					{
						if (a[k] != 0)
						{
							count += b[i] * b[j] * a[k];
						}
					}
				}
				if (b[j] != 0)
				{
					k = abs(i + j);
					if (k > 50000)
						break;
					if (b[k] != 0)
					{
						count += b[i] * b[j] * b[k];
					}
				}

			}
		}
	}
	cout << count << endl;
	return 0;
}