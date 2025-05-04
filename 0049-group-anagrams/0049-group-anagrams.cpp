class Solution {
public:

string generate(string& word)
{
    int hash[26] = {0};

    for(auto &ch:word)
    {
        hash[ch-'a']++;
        // we keep addign the character frequency
    }

    string new_word = "";
    for(int i = 0; i<26; i++)
    {
        int freq = hash[i]; // take out the frequency of that character
        if(freq > 0)
        {
           new_word += string(freq, i-'a');
        }
    }

    return new_word;

}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        unordered_map<string, vector<string>> mpp;
        
        vector<vector<string>> result;

        for(int i = 0; i<n; i++)
        {
            string word = strs[i];
            string new_word = generate(word);

            mpp[new_word].push_back(word);
        }

        for(auto it:mpp)
        {
            result.push_back(it.second);
        }

        return result;
        
    }
};