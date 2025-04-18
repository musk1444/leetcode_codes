class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if(beginWord == endWord) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        wordset.erase(beginWord);

        while(!q.empty())
        {
            // jab tak queue khali nai hojata
            auto it = q.front();
            q.pop();

            string word = it.first;
            int steps = it.second;

            if(word == endWord)
            {
                return steps;
            }
            for(int i = 0; i<word.length(); i++)
            {
                char originalchar = word[i];
                for(char ch = 'a'; ch<='z';ch++)
                {
                    word[i] = ch;
                    if(wordset.find(word) != wordset.end())
                    {
                        // we have found the word in our set
                        wordset.erase(word);
                        q.push({word,steps+1});
                    }
                }

                word[i] = originalchar;
            }
        }
        return 0;
    }
};