#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Use a priority queue to store {cost, {current node, stops}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Create an adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Start with the source node
        pq.push({0, {src, 0}});

        // Vector to store the minimum cost to reach a node with at most k stops
        vector<vector<int>> costs(n, vector<int>(k + 2, INT_MAX));
        costs[src][0] = 0;

        while (!pq.empty()) {
            auto [current_cost, info] = pq.top();
            auto [current_node, stops] = info;
            pq.pop();

            // If we've reached the destination node within the allowed stops, return the cost
            if (current_node == dst && stops <= k + 1) return current_cost;

            // If the number of stops is within the limit, explore the neighbors
            if (stops <= k) {
                for (const auto& neighbor : adj[current_node]) {
                    auto [next_node, price] = neighbor;
                    int new_cost = current_cost + price;

                    // Only push to the queue if this path offers a cheaper cost for the next node within the allowed stops
                    if (new_cost < costs[next_node][stops + 1]) {
                        costs[next_node][stops + 1] = new_cost;
                        pq.push({new_cost, {next_node, stops + 1}});
                    }
                }
            }
        }

        // If we never reach the destination node within the allowed stops, return -1
        int min_cost = INT_MAX;
        for (int i = 0; i <= k + 1; ++i) {
            min_cost = min(min_cost, costs[dst][i]);
        }
        return min_cost == INT_MAX ? -1 : min_cost;
    }
};
