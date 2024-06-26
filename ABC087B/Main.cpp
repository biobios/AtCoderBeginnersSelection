#include <iostream>

using namespace std;

int main() {
	int A, B, C, X;
	cin >> A >> B >> C >> X;



	unsigned int result = 0;
	unsigned int count500, count100, count50;

	count500 = X / 500;
	
	int64_t use500, use100, use50;

	if (count500 >= A) {
		use500 = A;
	}
	else {
		use500 = count500;
	}

	for (; use500 >= 0; use500--) {
		count100 = ((X % 500) + 500 * (count500 - use500)) / 100;
		if (count100 >= B) {
			use100 = B;
		}
		else {
			use100 = count100;
		}

		for (; use100 >= 0; use100--) {
			count50 = ((X % 100) + 100 * (count100 - use100)) / 50;
			
			if (count50 > C)
				break;

			result++;

		}
	}

	cout << result << endl;

	return 0;

	//size_t i;
	//if (count500 > A) {
	//	i = count500 - A;
	//}
	//else {
	//	i = 0;
	//}

	//for (; i <= count500; i++) {
	//	unsigned int count500_dash = count500 - i;
	//	unsigned int count100_dash = count100 + 5 * i;

	//	size_t j;
	//	if (count100_dash > B) {
	//		j = count100_dash - B;
	//	}
	//	else {
	//		j = 0;
	//	}

	//	for (; j <= count100_dash; j++) {
	//		unsigned int count100_dash_dash = count100_dash - j;
	//		unsigned int count50_dash = count50 + 2 * j;

	//		if (count50_dash > C)break;
	//		if (count100_dash_dash <= B && count500_dash <= A) {
	//			result++;
	//		}
	//	}
	//}

}