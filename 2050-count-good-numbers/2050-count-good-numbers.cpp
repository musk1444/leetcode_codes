class Solution {
public:

const int MOD = 1e9+7;

int power(long long base, long long exp)
{
    if(exp == 0)
    {
        return 1;
    }
    long long halfvalue = power(base, exp/2);
    long long result = (halfvalue * halfvalue) % MOD;
    // ahgar humara exponent odd value h to

    if(exp % 2 == 1)
    {
        result = (result * base) % MOD;
    }

    return result;

}

    int countGoodNumbers(long long n) {
        
        long long evenplaces = (n+1)/2 ;
        long long oddplaces = n/2;

        return (long long)power(5, evenplaces) * power(4, oddplaces) % MOD;
    }
};