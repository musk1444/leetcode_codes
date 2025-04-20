class Solution {
public:

bool is_symmetric(string& str)
{
    int len = str.length();
    if(len % 2 != 0)
    {
        return false;
    }
    int lefthalfsum = 0;
    int righthalfsum = 0;
    for(int i = 0; i<len/2; i++)
    {
        lefthalfsum += str[i] - '0';
    }
    for(int i = len/2; i<len; i++)
    {
        righthalfsum += str[i] - '0';
    }

    return (lefthalfsum == righthalfsum);
    
}
    int countSymmetricIntegers(int low, int high) {

        int count = 0;
        for(int num = low; num<=high; num++)
        {
            string str = to_string(num);
            if(is_symmetric(str))
            {
                count++;
            }
        }
        return count;
        
    }
};