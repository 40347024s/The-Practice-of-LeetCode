#include <cstdio>
#include <vector> 
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* GenerateGraph(vector<vector<int>> &adjList) {
    if (adjList.size()==0) {
        return nullptr;
    }
    Node *node = new Node [adjList.size()];
    for (int i=0; i<adjList.size(); i++) {
        node[i].val = i + 1;
        for (int j=0; j<adjList[i].size(); j++) {
            node[i].neighbors.push_back(&node[adjList[i][j]-1]);
        }
    }
    for (int i=0; i<adjList.size(); i++) {
        printf("node[%d] neighbors: [", node[i].val);
        for (int j=0; j<node[i].neighbors.size(); j++) {
            printf("%d, ", node[i].neighbors[j]->val);
        }
        printf("]\n");
    }
    return node;
}

Node* cloneGraph1(Node* node) {
    if (node==nullptr) {
        return node;
    }
    unordered_map <int, Node*> graph;
    vector <Node *> unseen;
    unseen.push_back(node);
    while (unseen.size()) {
        Node *cur = unseen.back();
        unseen.pop_back();
        if (graph.find(cur->val)!=graph.end()) {
            continue;
        }
        graph[cur->val] = new Node(cur->val, cur->neighbors);
        for (int i=0; i<cur->neighbors.size(); i++) {
            unseen.push_back(cur->neighbors[i]);
        }
    }
    
    for (int i=0; i<graph.size(); i++) {
        vector <Node *> new_neighbors;
        while (graph[i+1]->neighbors.size()) {
            int idx = graph[i+1]->neighbors.back()->val;
            new_neighbors.push_back(graph[idx]);
            graph[i+1]->neighbors.pop_back();
        }
        graph[i+1]->neighbors = new_neighbors;
    }
    return graph[1];
}

Node* cloneGraph2(Node* node) {
    if (node==nullptr) {
        return node;
    }
    unordered_map <int, Node*> graph;
    vector <Node *> unseen;
    unseen.push_back(node);
    while (unseen.size()) {
        Node *cur = unseen.back();
        unseen.pop_back();
        if (graph.find(cur->val)!=graph.end()) {
            if (graph[cur->val]->val == cur->val) {
                continue;
            }
            else {
                graph[cur->val]->val = cur->val;
            }
        }
        else {
            graph[cur->val] = new Node(cur->val);
        }
        for (int i=0; i<cur->neighbors.size(); i++) {
            unseen.push_back(cur->neighbors[i]);
            if (graph.find(cur->neighbors[i]->val)==graph.end()) {
                graph[cur->neighbors[i]->val] = new Node(0);
            }
            graph[cur->val]->neighbors.push_back(graph[cur->neighbors[i]->val]);
        }
    }
    return graph[1];
}

int main () {
    // vector <vector <int>> testcase_adjList = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
    // vector <vector <int>> testcase_adjList = {{}};
    // vector <vector <int>> testcase_adjList = {};
    vector <vector <vector <int>>> testcase_adjLists = {{{2, 4}, {1, 3}, {2, 4}, {1, 3}}, {{}}, {}};
    
    for (int i=0; i<testcase_adjLists.size(); i++) {
        printf("====== Testcase %d ======\n", i);
        // Method 1
        printf("Method 1:\n");
        cloneGraph1(GenerateGraph(testcase_adjLists[i]));

        // Method 2: Modified from Method 1
        printf("Method 2:\n");
        cloneGraph2(GenerateGraph(testcase_adjLists[i]));
    }
    return 0;
}