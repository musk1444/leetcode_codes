class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mpp;
        for(auto word: strs)
        {
            string sword = word;
            sort(sword.begin(), sword.end());
            mpp[sword].push_back(word);
        }

        //now that we have all teh pairs together
        vector<vector<string>> res;
        for(auto it: mpp)
        {
            res.push_back(it.second);
        }

        return res;
        
    }
};