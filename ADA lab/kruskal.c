
#include <stdio.h>
#include <limits.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to find the subset of an element i
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to do union of two subsets
void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Compare function for qsort
int compare(const void *a, const void *b) {
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight - b1->weight;
}

// Function to perform Kruskal's algorithm
void kruskalMST(int V, int E, struct Edge edges[]) {
    struct Edge result[MAX];  // This will store the resultant MST
    int e = 0;  // An index variable for result[]
    int i = 0;  // An index variable for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Allocate memory for creating V subsets
    int parent[MAX];

    // Initialize all subsets as single element sets
    for (int v = 0; v < V; v++)
        parent[v] = -1;

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < E) {
        // Step 2: Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If not, include it in the result.
        struct Edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        // If including this edge does not cause a cycle, include it in the result and increment the index of result for the next edge
        if (x != y) {
            result[e++] = next_edge;
            unionSet(parent, x, y);
        }
    }

    // Print the resultant MST
    printf("Edges in the Minimum Cost Spanning Tree:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d \tWeight: %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V, E;
    struct Edge edges[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges with their weights (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(V, E, edges);

    return 0;
}
