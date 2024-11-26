#include "digraph.h"
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

int main() {
  Digraph G1(5);
  G1.add_edge(1, 2);
  G1.add_edge(2, 3);
  G1.add_edge(3, 4);
  cout << "Edges of digraph G1: "
       << "\n";
  G1.print();

  Digraph G;
  G.read("digraph2.txt");
  cout << "\n";
  cout << "Shortest directed paths from 1 to 91,...,100 in G2:"
       << "\n";

  for (int w = 91; w <= 100; w++) {
    vector<int> path = G.path(1, w);
    if (path.size() == 0)
      cout << "No directed path from 1 to " << w << " exists.";
    for (size_t i = 0; i < path.size(); i++)
      cout << path[i] << " ";
    cout << "\n";
  }
  // G.BFS(22);

  return 0;
}
