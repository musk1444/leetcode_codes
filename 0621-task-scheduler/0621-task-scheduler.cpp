class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> mpp(26,0);

        for(auto &task:tasks)
        {
            mpp[task - 'A']++;
        }

        int time = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i<26; i++)
        {
            if(mpp[i] > 0)
            {
                pq.push(mpp[i]);
            }
        }

        // we push all the frequency into our pq
        
        while(!pq.empty())
        {
            vector<int> temp;

            for(int i = 1; i<= n+1; i++)
            {
                if(!pq.empty())
                {
                    auto freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(auto freq: temp)
            {
                if(freq > 0)
                {
                    pq.push(freq);
                }
            }
            if(pq.empty())
            {
                //a agr pq khali hogya poora to add krdo size of the temp
                time += temp.size();
            }
            else
            {
                time += n+1;
            }
        }

        return time;
        
    }
};