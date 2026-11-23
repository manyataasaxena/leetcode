#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Return existing clone if already visited to avoid cycles
        if (visited.count(node)) {
            return visited[node];
        }

        // Create clone and register it before traversing neighbors
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};