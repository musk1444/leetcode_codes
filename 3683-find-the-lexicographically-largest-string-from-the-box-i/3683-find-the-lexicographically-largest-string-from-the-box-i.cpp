class Solution {
public:
    string answerString(string word, int numFriends) {

        int n = word.size();
        int num = numFriends;

        string ans = "";
        if(n == num)
        {
            ans+= word[0];
        }
        if(num == 1) return word;

        for(int i =0, len = n - (num - 1); i<n; i++)
        {
            string t = word.substr(i,(n - i) < len ? n-i : len);
            if(ans.compare(t) < 0)
            ans = t;
        }



        return ans;
        
    }
};