class Solution {
public:
    string fractionAddition(string exp) {

        int n = exp.length();
        int nume = 0;
        int deno = 1;

        int i = 0;
        while(i < n)
        {
            int currnume = 0;
            int currdeno = 0;

            bool isneg = (exp[i] == '-');
            if(exp[i] == '+' || exp[i] == '-')
            {
                // jab tak ye expressions h to aag ebdho
                i++;
            }

            while(i<n && (isdigit(exp[i])))
            {
                int val = exp[i] - '0';
                currnume = currnume*10 + val;
                i++;
            }
            i++; // this is done to skip the divisor character '/'

            if(isneg == true)
            {
                currnume *= -1;
            }

            while(i < n && (isdigit(exp[i])))
            {
                // build the currdenominator
                int val = exp[i] - '0';
                currdeno = currdeno*10 + val;
                i++;
            }
            // ab result nikaal lo
            nume = nume*currdeno + deno*currnume;
            deno = deno*currdeno;
        }

        int gcd = abs(__gcd(nume,deno));
        // jais eki -3,6 ka gcd 3 hona chhaiye but isme dikat aajati h corner case me

        nume = nume/gcd;
        deno = deno/gcd;

        return to_string(nume) + '/' + to_string(deno);
        
    }
};