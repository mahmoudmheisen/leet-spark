class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int minTime = INT_MIN;
        set<int> processedNodes;
        unordered_map<int, vector<vector<int>>> graph;
        unordered_map<int, int> minCost;
        priority_queue<vector<int>, vector<vector<int>>,
                       decltype([](vector<int>& a, vector<int>& b) {
                           return a[1] > b[1];
                       })>
            minHeap;

        for (auto time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }

        minHeap.push({k, 0});
        minCost[k] = 0;
        while (!minHeap.empty()) {
            vector<int> node = minHeap.top();
            minHeap.pop();

            int nodeId = node[0];
            int nodeCost = node[1];

            if (processedNodes.count(nodeId))
                continue;
            
            processedNodes.insert(nodeId);

            vector<vector<int>> nodeNeighbors = graph[nodeId];

            for (auto neighbor : nodeNeighbors) {
                int neighborId = neighbor[0];
                int neighborCost = neighbor[1];

                int newCost = nodeCost + neighborCost;
                if (!minCost.count(neighborId) || minCost[neighborId] > newCost) {
                    minCost[neighborId] = newCost;
                    minHeap.push({neighborId, newCost});
                }
            }
        }

        for (auto [_, cost] : minCost) {
            cout << _ << " " << cost << endl;
            minTime = max(cost, minTime);
        }

        return minCost.size() == n ? minTime : -1;
    }
};