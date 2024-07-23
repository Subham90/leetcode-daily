class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;  // Use long long to handle large negative exponents
        if (m < 0) {
            m = -m;  // Convert to positive for calculation
            x = 1 / x;  // Invert x for negative exponent
        }
        double ans = 1.0;
        while (m > 0) {
            if (m & 1) {
                ans *= x;
                m--;
            }
            else
            {
            x *= x;
            m >>= 1;
            }// Equivalent to m = m / 2
        }
        return ans;
    }
};
