// You are given a graph of an airline network connecting cities as an adjacency list.
// Given any two cities (vertices) find the number of hops needed to reach from the first city to the second.
// Note: If two cities are directly connected by an edge, the number of hops is 1
//by Luis Umana
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int numHops(unordered_map<string, vector<string>>& aList, string v1, string v2);

int main() {
	unordered_map<string, vector<string>> adjList{ {"A", {"C", "E"}},
	   											{"C", {"A", "I"}}, 
												{"I", {"C", "H", "D"}},
												{"H", {"I"}},
												{"D", {"I", "B", "G"}},
												{"B", {"E", "F", "G", "D", "I"}},
												{"G", {"B", "D"}},
												{"F", {"B"}},
												{"E", {"A", "B"}}
												};
	cout << "Number of hops between cities D and A is " << numHops(adjList, "D", "A") << endl; // Should be 3

	cout << "Number of hops between cities A and B is " << numHops(adjList, "A", "B") << endl; // Should be 2

	return 0;
}

// Returns the number of hops between vertices v1 and v2
int numHops(unordered_map<string, vector<string>>& aList, string v1, string v2) {
	unordered_map<string, bool> visited;
    unordered_map<string, int> hopDist;

	// Initialize visited to false, and hopDist to zero
	for (auto& ele: aList) {
		visited[ele.first] = false;
		hopDist[ele.first] = 0;
	}

 // Your code here......
    // Include any STL libraries you need
    queue <string> Search;
    Search.push(v1);
    visited[v1] = true;
    while (!Search.empty()){
        string City = Search.front();
        Search.pop();
        for (int k = 0; k < aList[City].size(); k++){
            if (visited[aList[City][k]]){
                continue;
            }
            hopDist[aList[City][k]] = hopDist[City] + 1;
            Search.push(aList[City][k]);
            visited[aList[City][k]] = 1;
        }
    }
	return hopDist[v2] - hopDist[v1];
}
