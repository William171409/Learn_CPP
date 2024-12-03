// Purpose: Depth First Search-A (DFS) for a directed graph
#include <iostream>
#include <list>
#include <vector>
#include "digraph.h"
#include "q4_3_template.hpp"

using std::cout;
using std::list;
using std::vector;

// class DiGraph;

void Digraph::DFS_A(int s0,vector<int>& parent) const {
    vector<bool> visited;
    // Use n+1 to accommodate node number from 1 to n
    visited.resize(n + 1, false);
    parent[s0]=-1;

    Stack<int> stack{};
    stack.push(s0);
    while(!stack.is_empty())
    {
        int u{stack.top()};
        stack.pop();
        if (!visited[u])
        {
            visited[u]=true;
            for(auto w:out_neighbors[u])
            {
                if(!visited[w])
                {   
                    stack.push(w);
                    parent[w]=u;
                }
            }
        }
    }


}

