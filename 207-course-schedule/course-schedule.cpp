enum cellState { UNVISITED, VISITING, VISITED };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (auto pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }

        vector<int> coursesState(numCourses, UNVISITED);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, coursesState, i))
                return false;
        }

        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& graph, vector<int>& coursesState,
             int course) {
        if (coursesState[course] == VISITING)
            return false;
        if (coursesState[course] == VISITED)
            return true;

        coursesState[course] = VISITING;

        for (auto neighbor : graph[course]) {
            if (!dfs(graph, coursesState, neighbor))
                return false;
        }

        coursesState[course] = VISITED;
        return true;
    }
};