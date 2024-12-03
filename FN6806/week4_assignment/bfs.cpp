// Purpose: Breadth First Search (BFS) for a directed graph
#include <iostream>
#include <list>
#include <vector>
#include "digraph.h"

using std::cout;
using std::list;
using std::vector;

// class DiGraph;

void Digraph::BFS(int s0,vector<int>& parent) const {
  vector<bool> visited;
  // Use n+1 to accommodate node number from 1 to n
  visited.resize(n + 1, false);

  // Create a queue for BFS
  list<int> queue;
  queue.push_back(s0);

  // Mark the current node as visited and enqueue i
  visited[s0] = true;

  parent[s0] = -1;  // Starting vertex has no parent


  while (!queue.empty()) {
    // Dequeue a vertex from queue and print it
    int s;
    s = queue.front();
    // cout << s << " ";
    queue.pop_front();

    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    for (auto adjacent : out_neighbors[s]) {
      if (!visited[adjacent]) {
        visited[adjacent] = true;
        queue.push_back(adjacent);
        parent[adjacent] = s;
      }
    }
  }
}
