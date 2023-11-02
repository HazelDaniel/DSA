#!/usr/bin/env python3
from collections import defaultdict
import math

[WHITE, GREY, BLACK] = [0, 1, 2]
time = 0
color_map = dict([(0, "WHITE"), (1, "GREY"), (2, "BLACK")])


class Vertex:
    def __init__(self, value):
        self.discovery_time = math.inf
        self.finish_time = math.inf
        self.value = value
        self.color = WHITE
        self.pi = None

    # def __str__(self):
    #     return f"VERTEX=>[\n\tdiscovery time:{self.discovery_time}\n"\
    #             f"\tfinish time:{self.finish_time} \n"\
    #             f"\tvalue:{self.value} \n]"\
    def __str__(self):
        return f"VERTEX({self.value})"

    def __repr__(self):
        return f"VERTEX({self.value})"

    def __hash__(self):
        return hash(self.value)

    def __eq__(self, other):
        if isinstance(other, Vertex):
            return self.value == other.value
        return False


vertex_map = {
    1: Vertex(1),
    2: Vertex(2),
    3: Vertex(3),
    4: Vertex(4),
    5: Vertex(5),
    6: Vertex(6),
    8: Vertex(8),
}


class DiGraph:
    def __init__(self):
        self.adj = defaultdict(list[Vertex])
        self.vertices = []

    def add_edge(self, a, b):
        u = vertex_map.get(a, None)
        v = vertex_map.get(b, None)
        if not u or not v:
            print("cannot add an edge between non-existent vertices")
            return
        # print(f"adding edge : {a} => {b}")
        if (v not in self.adj[u] and v):
            self.adj[u].append(v)

    def add_vertices(self, vertex_set):
        self.vertices = vertex_set
        for v in vertex_set:
            self.adj.__setitem__(v, [])

    def has_vertex(self, G, v):
        if (G.adj[v]):
            return True
        return False

    def has_edge(self, G, u, v):
        if v in G.adj[u]:
            return True
        return False


def dfs(G):
    stack = []
    for v in G.adj.keys():
        if v.color == WHITE:
            dfs_visit(G, v, stack)
    return stack


def dfs_visit(G, u, stack):
    u.color = GREY
    global time
    time += 1
    u.discovery_time = time
    for v in G.adj[u]:
        if v.color == WHITE:
            v.pi = u
            dfs_visit(G, v, stack)

    time += 1
    u.finish_time = time
    u.color = BLACK
    stack.append(u)


def dfs_single_visit(G, u, stack):
    u.color = BLACK
    for v in G.adj[u]:
        if v.color == WHITE:
            dfs_single_visit(G, v, stack)
    stack.append(u)


def reverse_adj_list(G):
    transpose = DiGraph()
    for a in G.adj.keys():
        for b in G.adj[a]:
            transpose.add_edge(b.value, a.value)
    return transpose


def kosaraju(G: DiGraph):
    stack = dfs(G)
    components = []
    # print("adjacency list")
    # print("-------------------")
    # for item in G.adj.items():
    #     print(item)
    # print("-------------------")

    components.append([])
    i = 0
    for v in G.vertices:
        v.color = WHITE

    transpose = reverse_adj_list(G)
    while (stack):
        u = stack.pop()
        if (u.color == WHITE):
            components.append([])
            dfs_single_visit(transpose, u, components[i])
            i += 1

    global time
    print("STRONGLY CONNECTED COMPONENTS :")
    components = [c for c in components if c]
    for c in components:
        print(c)
    time = 0


graph = DiGraph()
vertex_list = vertex_map.values()
graph.add_vertices(vertex_list)
graph.add_edge(1, 2)
graph.add_edge(2, 3)
graph.add_edge(3, 1)
graph.add_edge(2, 4)
graph.add_edge(4, 5)
graph.add_edge(5, 6)
graph.add_edge(6, 4)
graph.add_edge(6, 8)

kosaraju(graph)
