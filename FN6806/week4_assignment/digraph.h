#pragma once
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Digraph
{
  int n; // number of vertices
         // vertices are 1,...,n
  int m; // number of edges

  // adjacency matrix; A[i][j]=true if and only if
  // (i,j) is an edge. Note that each A and each
  // sub-array A[i] must have length n+1, since
  // vertices are 1,...,n (not 0,...,n-1)
  vector<vector<bool>> A;

  // out_neighbors[i] contains
  // exactly the vertices j  for which (i,j) is an edge
  vector<vector<int>> out_neighbors;

  // ImNeighbors[i] contains
  // exactly the vertices j  for which (j,i) is an edge
  vector<vector<int>> in_neighbors;

public:
  Digraph() : n(0), m(0) {}; // Default constructor
  Digraph(int n) : n{n}, m{0}, A(n + 1, vector<bool>(n + 1, false)),
                   out_neighbors(n + 1), in_neighbors(n + 1) {} // Constructor: set n to n, m to 0,
                                                                // A an (n+1)x(n+1) array and
  // resize out_neighbors, in_neighbors to length n+1.
  // Initialize all entries of A to 0
  ~Digraph() = default; // Destructor: delete A and its sub-arrays

  void add_edge(int v, int w)
  {
    A[v][w] = true;
    in_neighbors[w].push_back(v);
    out_neighbors[v].push_back(w);
    ++m;
  } // add edge (v,w): update A, out_neighbors,
    // and in_neighbors accordingly
  void read(const string file)
  {
    ifstream infile(file);
    string label;
    infile >> label >> n;
    A.resize(n + 1, vector<bool>(n + 1, false));
    out_neighbors.resize(n + 1);
    in_neighbors.resize(n + 1);

    int v, w;
    while (infile >> v >> w) {
        add_edge(v, w);
    }

  } // initialize all data members from the
                                // graph data contained in "file"
  int vertices() const
  {return n;}
  int edges() const
  {return m;}

  void print() const
  {
    for (auto v = 1; v <= n; ++v)
    {
      for (auto w : out_neighbors[v])
      {
        cout << "(" << v << ", " << w << ")" << endl;
      }
    }
  } // print all edges to the screen
  void BFS(int s0,vector<int>& parent)const;
  void DFS_A(int s0,vector<int>& parent)const;
  vector<int> path(int v, int w) const
  {
    vector<int> parent(n + 1, -1);
    vector<int> shortest_path;

    BFS(v, parent);

    if (parent[w] == -1) {
        return shortest_path;
    }

    for (int current = w; current != -1; current = parent[current]) {
        shortest_path.push_back(current);
    }

    reverse(shortest_path.begin(), shortest_path.end());

    return shortest_path;
  }
  // return shortest directed path from v to w (if existent);
  // return empty vector if no such path exists

  vector<int> path_dfs(int v, int w) const
  {
    vector<int> parent(n + 1, -1);
    vector<int> shortest_path;

    DFS_A(v, parent);

    if (parent[w] == -1) {
        return shortest_path;
    }

    for (int current = w; current != -1; current = parent[current]) {
        shortest_path.push_back(current);
    }

    reverse(shortest_path.begin(), shortest_path.end());

    return shortest_path;
  }

};
