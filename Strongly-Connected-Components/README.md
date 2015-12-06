## Strongly Connected Components

### Cycle Detect Problem
problem is we would like to detect a cycle in a directed graph. This can be done using a modified DFS traversal. I use a grey stack to keep track of nodes that are being currently traversed. If the node points to any of the nodes in the grey set, a back-edge has been detected i.e. a cycle is present. Its complexity is linear time.