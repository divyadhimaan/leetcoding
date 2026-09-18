class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<char>> adjList;
        unordered_set<char> st;
        for(int i=0;i<words.size()-1;i++)
        {
            int len = min(words[i].size(), words[i+1].size());
            bool written = false;
            for(int j=0;j<len;j++)
            {
                if(words[i][j] != words[i+1][j])
                {
                adjList[words[i][j]].push_back(words[i+1][j]);
                written = true;
                break;
                }

            }
            if(!written && words[i].size() > words[i+1].size())
                return "";

        }


        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
                st.insert(words[i][j]);
        }

        vector<int> inDegree(26,0);
        int uniqueWords;
        for(auto x: adjList)
        {
            vector<char> temp = x.second;
            for(int i=0;i<temp.size();i++)
            {
                inDegree[temp[i]-'a']++;
            }
        }

        queue<char> q;
        for(int i=0;i<26;i++){
            if(st.contains(i+'a') && inDegree[i]==0)
                q.push(i+'a');
        }

        string resString = "";
        while(!q.empty())
        {
            char currNode= q.front();
            q.pop();

            resString += currNode;
            st.erase(currNode);

            for(int next: adjList[currNode]){
                inDegree[next-'a']--;
                if(inDegree[next-'a']==0)
                    q.push(next);
            }
        }

        return st.empty() ? resString: "";

    }
};