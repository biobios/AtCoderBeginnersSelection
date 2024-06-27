#include <iostream>

using namespace std;

int main()
{
	uint64_t N, A, B;
	cin >> N >> A >> B;

	uint64_t sum = 0;

	for (uint64_t i = 1; i <= N; i++)
	{
		uint64_t num = i;
		uint64_t digit_sum = 0;

		while (num > 0)
		{
			digit_sum += num % 10;
			num /= 10;
		}

		if (A <= digit_sum && digit_sum <= B)
		{
			sum += i;
		}
	}

	cout << sum << endl;
	return 0;
}