class Solution {
public:

string generate(string& word)
{
    vector<int> hash(26,0);
    string newword = "";

    for(auto &ch:word)
    {
        hash[ch-'a']++;
    }
    for(int i = 0; i<26; i++)
    {
        int freq = hash[i];
        if(freq > 0)
        {
            newword += string(freq,i-'a');
        }
    }

    return newword;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        unordered_map<string, vector<string>> mpp;

        for(auto word:strs)
        {
            string newword = generate(word);
            mpp[newword].push_back(word);
        }
        vector<vector<string>> ans;
        for(auto it:mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};