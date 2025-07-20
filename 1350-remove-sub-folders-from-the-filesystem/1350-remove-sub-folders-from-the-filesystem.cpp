class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        int n = folder.size();
        unordered_set<string> st(begin(folder), end(folder));

        vector<string> result;
        for(auto currfolder:folder)
        {
            bool issubfolder = false;
            string tempfolder = currfolder;

            while(!currfolder.empty())
            {
                auto position = currfolder.find_last_of('/');
                currfolder = currfolder.substr(0,position);

                if(st.find(currfolder) != st.end())
                {
                    // it means currfolder is a subfolder
                    issubfolder = true;
                    break;
                }
            }
            if(!issubfolder)
            {
                result.push_back(tempfolder);
            }
        }

        return result;
        
    }
};