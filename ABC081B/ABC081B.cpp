#include <iostream>

using namespace std;

unsigned int getLSB(unsigned int num) {
    if (num == 0) return ~(0);

    unsigned int ret;
    for (ret = 0; ret < sizeof(unsigned int) * 8; ret++) {
        if (((num >> ret) & 1) != 0) break;
    }

    return ret;
}

int main()
{
    unsigned int N;
    cin >> N;
    unsigned int result = ~(0);

    for (size_t i = 0; i < N; i++) {
        unsigned int input;
        cin >> input;
        unsigned int lsb = getLSB(input);
        if (result > lsb) {
            result = lsb;
        }
    }

    cout << result << endl;
    return 0;

}