class Solution {
public:
int n;
vector<string> result;

bool isvalid(string str)
{
    if(str[0] == '0') return false;

    int val = stoi(str);
    
    if(val > 255) return false;

    return true;
}
void solve(string& s, int index, int parts, string curr)
{
    if(index == n && parts == 4)
    {
        curr.pop_back(); // decimal wala dot pop out krenge bus
        result.push_back(curr);
        return;
    }

    if(index+1 <= n)
    solve(s, index+1, parts+1,curr+ s.substr(index,1) + '.');

    if(index+2 <= n && isvalid(s.substr(index,2)))
    solve(s, index+2, parts+1,curr+ s.substr(index,2) + '.');

    if(index+3 <= n && isvalid( s.substr(index,3)))
    solve(s, index+3, parts+1,curr+ s.substr(index,3) + '.');

}

    vector<string> restoreIpAddresses(string s) {
        
        n = s.length();
        if(n>12)
        {
            return {};
        }

        result.clear();
        int parts = 0;
        string curr = "";

        solve(s,0,parts,curr);

        return result;        
    }
};