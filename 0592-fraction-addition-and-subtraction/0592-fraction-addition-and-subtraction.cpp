class Solution {
public:
    string fractionAddition(string exp) {

        int n = exp.length();
        int i = 0;
        bool isneg = false;

        int num = 0;
        int den = 1;

        while(i<n)
        {
            int currnum = 0;
            int currden = 0;
            
            isneg = (exp[i] == '-');

            while(exp[i] == '+' || exp[i] == '-')
            {
                i++;
            }
            // now we will find out the numerator
            while(i<n && (isdigit(exp[i])))
            {
                int val = exp[i] - '0';
                currnum = currnum*10 + val;
                i++;
            }
            i++; // this is to skip the '/' divisor operator
            if(isneg)
            {
                currnum = currnum*-1;
            }

            while(i<n && (isdigit(exp[i])))
            {
                int val = exp[i] - '0';
                currden = currden*10 + val;
                i++;
            }

            num = den*currnum + num*currden;
            den = den*currden;

            int gcd = abs(__gcd(num,den));

            num = num/gcd;
            den = den/gcd;
        }

        return to_string(num) + '/' + to_string(den);

                                              
        
    }
};