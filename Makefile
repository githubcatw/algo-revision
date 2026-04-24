help:
	echo "Please select a folder to build"

bst_demo:
	gcc bst/*.c -o bst_demo --debug

stack_demo:
	gcc stack/*.c -o stack_demo --debug

heap_demo:
	gcc heap/*.c -o heap_demo --debug

dsu_demo:
	gcc dsu/*.c -o dsu_demo --debug

pq_demo:
	gcc pq/*.c -o pq_demo --debug

searching_demo:
	gcc searching/*.c -o searching_demo --debug

dfs_and_bfs_demo:
	gcc graph/graph.c queue/queue.c stack/stack.c dfs_and_bfs/*.c -o dfs_and_bfs_demo --debug

clean:
	rm *_demo
