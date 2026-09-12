class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];

            adjList[bi].push_back(ai);
        }

        vector<int> inDegree(numCourses, 0);
        for(int i=0;i<adjList.size();i++){
            for(int j=0;j<adjList[i].size();j++){
                inDegree[adjList[i][j]]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0)
                q.push(i);
        }

        int coursesDone = 0;
        while(!q.empty()){
            int currCourse = q.front();
            q.pop();

            coursesDone++;

            for(int nextCourse: adjList[currCourse]){
                inDegree[nextCourse]--;
                if(inDegree[nextCourse]==0)
                    q.push(nextCourse);
            }
        }

        return coursesDone == numCourses;
    }
};