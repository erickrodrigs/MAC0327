from typing import List

MAX = 101

class Graph:
    def __init__(self) -> None:
        self.graph = dict()

    def add_vertex(self, v):
        if v not in self.graph:
            self.graph[v] = []

    def add_edge(self, u, v):
        self.add_vertex(u)
        self.add_vertex(v)
        self.graph[u].append(v)
        self.graph[v].append(u)

    def vertices(self):
        return list(self.graph.keys())

    def get_neighbors(self, v):
        if v in self.graph:
            return self.graph[v]
        
        return []

def dfs(graph: Graph, vertex: int, visited: List[bool]):
    visited[vertex] = True

    for neighbor in graph.get_neighbors(vertex):
        if not visited[neighbor]:
            dfs(graph, neighbor, visited)

def isGraphCthulhu(n: int, m: int, graph: Graph):
    vertices = graph.vertices()
    visited = [False] * (MAX + 1)

    if len(vertices) > 0:
        dfs(graph, vertices[0], visited)
    
    count_visited = 0
    for was_visited in visited:
        if was_visited:
            count_visited += 1
    
    if count_visited == n and n == m:
        return "FHTAGN!"
    
    return "NO"

def main():
    graph = Graph()
    n, m = map(int, input().split())

    for _ in range(m):
        u, v = map(int, input().split())
        graph.add_edge(u, v)

    print(isGraphCthulhu(n, m, graph))
    
main()
