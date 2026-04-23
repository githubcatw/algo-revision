# algorithmiques revision

revision and implementation of all algorithms and data structures that will be on the practical exam.

note that these are **my implementations**, not class notes. the code is sometimes based on the book Introduction to Algorithms.

## structure
this repository roughly follows our syllabus.

- data structures:
  - [heap](heap/) _(min-heap and max-heap)_
  - [stack](stack/)
  - [disjoint set](dsu/)
  - [queue](queue/)
  - [binary search tree](bst/) _(includes all 3 types of traversal: preorder, postorder, inorder)_
  - [graph](graph/) _(using adjacency matrix. **NOTE: no demo program is available**)_
- graph algorithms:
  - [BFS and DFS of a graph](dfs_and_bfs/)

incomplete:
- [_(min-)_priority queue](pq/)

## building and testing
this repo uses make for building demo programs. detailed instructions are in the folders' readme files, but the general instruction is to run:
```
make (folder name)_demo
```
for example, to build a demo program for BSTs, run:
```
make bst_demo
```

do note that sometimes a folder cannot be built using make. incomplete implementations cannot be built using make by design. however, if an implementation that isn't marked as incomplete cannot be built, please let me know on tg or by opening an issue.

to rebuild a demo program (e.g. after editing the source), first delete its built executable or run:
```
make clean
```
to delete all demo program builds. then, build again with the appropriate command.

----

_no ai generated code is present in this repository. this is not homework._
