#include <iostream>

using namespace std;

int main()
{
	uint64_t N, Y;
	cin >> N >> Y;

	int64_t count10000, count5000, count1000;
	int64_t use10000, use5000, use1000;

	count10000 = Y / 10000;
	
	use10000 = count10000;
	for (; use10000 >= 0; use10000--) {
		count5000 = (Y % 10000) / 5000 + (count10000 - use10000) * 2;
		use5000 = count5000;
		for (; use5000 >= 0; use5000--) {
			use1000 = (Y % 5000) / 1000 + (count5000 - use5000) * 5;

			if (use10000 + use5000 + use1000 == N) {
				cout << use10000 << " " << use5000 << " " << use1000 << endl;
				return 0;
			}

			if (use10000 + use5000 + use1000 > N)
				break;
		}
	}

	cout << "-1 -1 -1" << endl;
	return 0;
}