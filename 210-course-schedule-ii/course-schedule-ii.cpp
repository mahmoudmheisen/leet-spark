enum nodeState {
    UNVISITED,
    VISITING,
    VISITED
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        unordered_map<int, vector<int>> graph;
        vector<nodeState> states(numCourses, UNVISITED);

        for (auto pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, states, order, i))
                return {};
        }

        return order;
    }

    bool dfs(unordered_map<int, vector<int>>& graph, vector<nodeState>& states,
             vector<int>& order, int course) {
        if (states[course] == VISITING)
            return false;
        if (states[course] == VISITED)
            return true;

        states[course] = VISITING;

        for (auto neighbor : graph[course]) {
            if (!dfs(graph, states, order, neighbor))
                return false;
        }

        states[course] = VISITED;
        order.push_back(course);
        return true;
    }
};