from collections import defaultdict
from queue import PriorityQueue


class Graph:

    def add_edge(self, u, v, weight):

        value = (weight, v)
        self.graph[u].append(value)
        value = (weight, u)
        self.graph[v].append(value)

    def ucs(self, current_node, goal_node):
        visited = []
        queue = PriorityQueue()
        queue.put((0, current_node))

        while not queue.empty():
            item = queue.get() # remove and returns a item in queue
            current_node = item[1]

            if current_node == goal_node:
                print(current_node, end=" ")
                queue.queue.clear()
            else:
                if current_node in visited:
                    continue

                print(current_node, end=" ")
                visited.append(current_node) # added the visited current item by using .append()

                for neighbour in self.graph[current_node]:
                    queue.put((neighbour[0], neighbour[1]))


g = Graph()
g.graph = defaultdict(list)
g.add_edge('A', 'B', 1)
g.add_edge('A', 'C', 3)
g.add_edge('B', 'G', 2)
g.add_edge('B', 'F', 3)
g.add_edge('C', 'G', 2)

g.graph
g.ucs('A', 'G')
