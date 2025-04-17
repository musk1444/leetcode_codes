class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // set<string> myset(wordList.begin(), wordList.end());
        unordered_set<string> myset(wordList.begin(), wordList.end());
        if(myset.find(endWord) == myset.end()) return 0;
        if(beginWord == endWord)
        {
            return 0;
        }

        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        myset.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(int i = 0; i<word.length(); i++)
            {
                char originalchar = word[i];
                for(char ch = 'a';  ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(myset.count(word))
                    {
                        myset.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = originalchar;

            }

        }

        return 0;
        
    }
};