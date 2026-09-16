class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char c: tasks)
            freq[c-'A']++;


        int maxFreq = *max_element(freq.begin(),freq.end()); // find max frequency
        int maxCount = count(freq.begin(), freq.end(), maxFreq); // find count of tasks with max freq

        return max((int)tasks.size(), (maxFreq-1) * (n+1) + maxCount);
    }
};