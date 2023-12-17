#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0
#define INF 1000000

int found[MAX_VERTICES];
int distance[MAX_VERTICES];

typedef struct GraphNode {
    int vertex;
    int weight;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;


int choose(int distance[], int n, int found[]) {
    int i, min, minpos;
    min = INF;
    minpos = -1;
    for (i = 0; i < n; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}  // 집합 S에 포함되지 않는 정점 중 distance가 가장 작은 정점 return

void print_status(GraphType* g) {
    static int step = 1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (int i = 0; i < g->n; i++) {
        if (distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf("found: ");
    for (int i = 0; i < g->n; i++) {
        printf("%2d ", found[i]);
    }
    printf("\n\n");
}

GraphNode* create_node(int vertex, int weight) {
    GraphNode* new_node = (GraphNode*)malloc(sizeof(GraphNode));
    if (new_node == NULL) {
        fprintf(stderr, "노드 생성 오류");
        exit(1);
    }
    new_node->vertex = vertex;
    new_node->weight = weight;
    new_node->link = NULL; 
    return new_node;
}

void insert_edge(GraphType* g, int u, int v, int weight) {
    GraphNode* new_node = create_node(v, weight);
    new_node->link = g->adj_list[u];
    g->adj_list[u] = new_node;
}

void shortest_path(GraphType* g, int start) {
    int i, u, w;
	GraphNode *node;
    for (i = 0; i < g->n; i++) {
		distance[i] = INF;
        found[i] = FALSE;
    }
	for(node=g->adj_list[start];node;node=node->link){
		int x = node->vertex;
		distance[x] = node->weight;
	} // distance[i] = INF 인채로 두면 안되지.. 리스트 받아서 초기화해줌.
	
    found[start] = TRUE;
    distance[start] = 0;

    for (i = 0; i < g->n; i++) {
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = TRUE;

        GraphNode* node = g->adj_list[u];
        while (node != NULL) {
            w = node->vertex;
            if (!found[w]) {
                if (distance[u] + node->weight < distance[w]) {
                    distance[w] = distance[u] + node->weight;
                }
            }
            node = node->link;
        }
    }
}

void print_list(GraphType *g,int v){
	GraphNode *w;
	found[v] = TRUE;
	printf("정점 %d -> ",v);
	for(w=g->adj_list[v];w;w=w->link){
		printf("%d-> ",w->vertex);
	}
	printf("\n");
}

void cleanup(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        GraphNode* current = g->adj_list[i];
        while (current != NULL) {
            GraphNode* temp = current;
            current = current->link;
            free(temp);
        }
    }
}

int main() {
    GraphType g = {7, {NULL}};

    insert_edge(&g, 0, 1, 7);
    insert_edge(&g, 0, 4, 3);
    insert_edge(&g, 0, 5, 10);
    insert_edge(&g, 1, 0, 7);
    insert_edge(&g, 1, 2, 4);
    insert_edge(&g, 1, 3, 10);
    insert_edge(&g, 1, 4, 2);
    insert_edge(&g, 1, 5, 6);
    insert_edge(&g, 2, 1, 4);
    insert_edge(&g, 2, 3, 2);
    insert_edge(&g, 3, 1, 10);
    insert_edge(&g, 3, 2, 10);
    insert_edge(&g, 3, 4, 11);
    insert_edge(&g, 3, 5, 9);
    insert_edge(&g, 3, 6, 4);
    insert_edge(&g, 4, 0, 3);
    insert_edge(&g, 4, 1, 2);
    insert_edge(&g, 4, 3, 11);
    insert_edge(&g, 4, 6, 5);
    insert_edge(&g, 5, 0, 10);
    insert_edge(&g, 5, 1, 6);
    insert_edge(&g, 5, 3, 9);
    insert_edge(&g, 6, 3, 4);
    insert_edge(&g, 6, 4, 5);

	
	for(int i=0;i<7;i++){
		print_list(&g,i);
	}
	
    shortest_path(&g, 0);

    cleanup(&g);

    return 0;
}
