class Solution {
public:

bool ispossible(vector<int>& tasks, vector<int>& workers, int& pills, int& strength, int& mid)
{
    int pillsused = 0;
    multiset<int> st(begin(workers), begin(workers) + mid); // we keep this to find out the 
    // lower bound to select whom to give the pills

    for(int i = mid-1; i>= 0;i--)
    {
        int required = tasks[i];

        // this gives the last value in our multiset
         
        auto it = prev(st.end());

        if(*it >= required)
        {
            st.erase(it);
        }
        else if(pillsused >= pills)
        {
            return false;
        }
        else
        {
            // we will find the lower bound for our pills to be used
            auto weakestworkerit = st.lower_bound(required-strength);
            if(weakestworkerit == st.end())
            {
                // koi worker aisa mila hi nai
                return false;
            }
            st.erase(weakestworkerit);
            pillsused++;
        }
    }
    return true;
}
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        
        int m = tasks.size();
        int n = workers.size();

        int l = 0;
        int r = min(m,n);

        sort(begin(tasks),end(tasks));
        sort(begin(workers),end(workers), greater<int>());

        int result = 0;

        while(l <= r)
        {
            int mid = l+(r-l)/2;
            if(ispossible(tasks,workers,pills,strength,mid))
            {
                result = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
    return result;
    }
};