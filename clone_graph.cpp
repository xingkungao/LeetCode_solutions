/*************************************************************************
  > File Name: clone_graph.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 11 Jan 2015 04:59:03 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

/**
 *
 *  * Definition for undirected graph.
 */
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
	public:
		UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
			unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
			return cloneGraphRecursive(node, map); 
		};

		UndirectedGraphNode* cloneGraphRecursive(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &map) {
			if (!node)
				return node;
			if (!map[node]) {
				UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
				map[node] = newNode;

				for (int i = 0; i < node->neighbors.size(); i++) {
					newNode->neighbors.push_back(cloneGraphRecursive(node->neighbors[i], map)); 
				}
			}
			return map[node];
		}

		void test() {
		}
};

int main() {
	Solution s;
	s.test();
}
