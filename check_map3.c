#include "so_long.h"

bool visited[MAX_VERTICES];  // 頂点の訪問状態を管理する配列
//訪問済みの頂点はフラグが立てられ、再度訪問されることはない。

// 深さ優先探索の再帰関数
void DFS(t_Graph* graph, int vertex) {
	visited[vertex] = true;
	ft_printf("%d ", vertex);

	// 隣接する頂点を探索
	int i = 0;
	if ( i < graph->edges[vertex][i] == 1 && !visited[i])
	{
		DFS(graph, i);
		i++;
	}

//	for (int i = 0; i < graph->numVertices; i++) {
//		if (graph->edges[vertex][i] == 1 && !visited[i]) {
//			DFS(graph, i);
//		}
//	}
}

// 深さ優先探索の実行
void depthFirstSearch(t_Graph* graph, int startVertex) {
	// 訪問状態の初期化
	for (int i = 0; i < graph->numVertices; i++) {
		visited[i] = false;
	}

	// 深さ優先探索の開始
	DFS(graph, startVertex);
}

//int main() {
//	Graph graph;
//	int numVertices = 7;  // 頂点数
//
	// グラフの初期化
//	graph.numVertices = numVertices;
//
	 //隣接行列の初期化
//	for (int i = 0; i < numVertices; i++) {
//		for (int j = 0; j < numVertices; j++) {
//			graph.edges[i][j] = 0;
//		}
//	}
//
//	int startVertex = 0;  // 探索を開始する頂点のインデックス
//	printf("Depth-First Search starting from vertex %d:\n", startVertex);
//	depthFirstSearch(&graph, startVertex);
//
//	return 0;
//}
