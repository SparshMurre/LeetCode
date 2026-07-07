class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int sum = 0;
        int place = 1;

        while (n > 0) {
            int digit = n % 10;
            sum += digit;

            if (digit != 0) {
                x += 1LL * digit * place;
                place *= 10;
            }

            n /= 10;
        }

        return x * sum;
    }
};