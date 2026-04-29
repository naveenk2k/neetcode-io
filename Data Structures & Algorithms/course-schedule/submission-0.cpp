class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (vector<int> x : prerequisites) {
            graph[x[1]].push_back(x[0]);
            ++inDegrees[x[0]];
        }

        stack<int> courses;
        for (int i = 0; i < inDegrees.size(); ++i) {
            if (inDegrees[i] == 0) courses.push(i);
        }

        vector<int> ans;
        while (!courses.empty()) {
            int x = courses.top();
            courses.pop();
            ans.push_back(x);

            for (int y : graph[x]) {
                --inDegrees[y];
                if (inDegrees[y] == 0) courses.push(y);
            }
        }

        return ans.size() == numCourses;
    }
};
