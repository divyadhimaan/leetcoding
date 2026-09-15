class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freqMap;
        for(char c: s)
            freqMap[c]++;


        priority_queue<pair<int, char>> pq;
        for(auto x: freqMap){
            pq.push({x.second, x.first});
        }

        string temp = "";
        while(!pq.empty()){
            auto [freq, c] = pq.top();
            pq.pop();

            for(int i=0;i<freq;i++){
                temp += c;
            }
        }
        
        return temp;

        
    }
};