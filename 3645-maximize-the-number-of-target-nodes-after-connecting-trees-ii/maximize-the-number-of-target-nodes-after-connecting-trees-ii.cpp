class Solution {
public:
    int EvenLevelNodes(int nodeCount, vector<vector<int>>& adjacencyList) {
        vector<int> visited(nodeCount, 0);
        visited[0] = 1;
        int evenLevelCount = 0;
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({0, 0});

        while (!bfsQueue.empty()) {
            auto [currentNode, level] = bfsQueue.front();
            bfsQueue.pop();

            if (level % 2 == 0) evenLevelCount++;

            for (int& neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    bfsQueue.push({neighbor, level + 1});
                    visited[neighbor] = 1;
                }
            }
        }
        return evenLevelCount;
        
            
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edgesGraph1, vector<vector<int>>& edgesGraph2) {
        int nodesGraph1 = edgesGraph1.size() + 1;
        int nodesGraph2 = edgesGraph2.size() + 1;

        vector<vector<int>> adjacencyList1(nodesGraph1), adjacencyList2(nodesGraph2);

        for (auto& edge : edgesGraph1) {
            adjacencyList1[edge[0]].push_back(edge[1]);
            adjacencyList1[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edgesGraph2) {
            adjacencyList2[edge[0]].push_back(edge[1]);
            adjacencyList2[edge[1]].push_back(edge[0]);
        }

        int evenlevelNodesGraph1 = EvenLevelNodes(nodesGraph1, adjacencyList1);
        int maxReachableNodesGraph2= max(nodesGraph2-EvenLevelNodes(nodesGraph2, adjacencyList2),EvenLevelNodes(nodesGraph2, adjacencyList2));
        vector<int>reachableNodesGraph1(nodesGraph1,0);
        vector<int> visited(nodesGraph1, 0);
        visited[0] = 1;
        int evenLevelCount = 0;
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({0, 0});

        while (!bfsQueue.empty()) {
            auto [currentNode, level] = bfsQueue.front();
            bfsQueue.pop();

            if (level % 2 == 0){
                reachableNodesGraph1[currentNode] =evenlevelNodesGraph1;
            }
            else{
                reachableNodesGraph1[currentNode] =nodesGraph1-evenlevelNodesGraph1;
            } 

            for (int& neighbor : adjacencyList1[currentNode]) {
                if (!visited[neighbor]) {
                    bfsQueue.push({neighbor, level + 1});
                    visited[neighbor] = 1;
                }
            }
        }
        

        for (int i = 0; i < nodesGraph1; i++) {
            reachableNodesGraph1[i] += maxReachableNodesGraph2;
        }

        return reachableNodesGraph1;
    }
};
