class Solution {
public:

int sumdigit(int num)
{
    int sum = 0;
    while(num != 0)
    {
        sum += num%10;
        num = num/10;
    }

    return sum;
}
    int countLargestGroup(int n) {

        unordered_map<int,int> mpp;
        int maxsize = 0;
        int count = 0;

        for(int i = 1; i<=n; i++)
        {
            int digitsum = sumdigit(i);
            mpp[digitsum]++;

            if(mpp[digitsum] == maxsize)
            {
                count++;
            }
            else if(mpp[digitsum] > maxsize)
            {
                maxsize = mpp[digitsum];
                count = 1;
            }
        }

        return count;
        
    }
};