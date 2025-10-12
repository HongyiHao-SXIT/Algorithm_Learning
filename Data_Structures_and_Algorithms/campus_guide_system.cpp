#include <iostream>
#include <vector>
#include <limits>
#include <string>

constexpr int MAX_VERTEX = 100;
constexpr int MAX_COST = 9999;

struct Graph {
    std::vector<std::string> vertices;
    std::vector<std::vector<int>> edges;
    int vertexCount = 0;
    int edgeCount = 0;
};

// 函数声明
void showMenu();
void floydAlgorithm(const Graph& graph, std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& next);
void showShortestPath(const Graph& graph, const std::vector<std::vector<int>>& dist, const std::vector<std::vector<int>>& next);
void traverseAllScenicSpots(const Graph& graph);
void createGraph(Graph& graph);
void displayMap();
void viewScenicSpot();

// ---------------------- 主函数 ----------------------
int main() {
    Graph campusGraph;
    std::vector<std::vector<int>> dist(MAX_VERTEX, std::vector<int>(MAX_VERTEX, MAX_COST));
    std::vector<std::vector<int>> next(MAX_VERTEX, std::vector<int>(MAX_VERTEX, -1));

    createGraph(campusGraph);

    while (true) {
        showMenu();
        int choice = 0;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                floydAlgorithm(campusGraph, dist, next);
                showShortestPath(campusGraph, dist, next);
                break;
            case 2:
                traverseAllScenicSpots(campusGraph);
                break;
            case 3:
                displayMap();
                break;
            case 4:
                viewScenicSpot();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid input, please try again.\n";
                break;
        }
    }
    return 0;
}

// ---------------------- 函数定义 ----------------------
void showMenu() {
    std::cout << "---------------- Campus Guide System ----------------\n";
    std::cout << "1: Shortest path between two scenic spots\n";
    std::cout << "2: Traverse all scenic spots\n";
    std::cout << "3: Display campus map\n";
    std::cout << "4: View scenic spot introduction\n";
    std::cout << "0: Exit\n";
    std::cout << "-----------------------------------------------------\n";
}

void floydAlgorithm(const Graph& graph, std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& next) {
    int n = graph.vertexCount;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = graph.edges[i][j];
            if (graph.edges[i][j] != MAX_COST && i != j) {
                next[i][j] = j;
            } else {
                next[i][j] = -1;
            }
        }
        dist[i][i] = 0;
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
}

void showShortestPath(const Graph& graph, const std::vector<std::vector<int>>& dist, const std::vector<std::vector<int>>& next) {
    int start, end;
    std::cout << "Enter start and destination (0-indexed): ";
    std::cin >> start >> end;

    if (start < 0 || start >= graph.vertexCount || end < 0 || end >= graph.vertexCount) {
        std::cout << "Invalid vertices.\n";
        return;
    }

    std::cout << "Shortest path: ";
    int current = start;
    while (current != end && current != -1) {
        std::cout << current << " -> ";
        current = next[current][end];
    }
    std::cout << end << "\nDistance: " << dist[start][end] << "\n";
}

void traverseAllScenicSpots(const Graph& graph) {
    std::cout << "Traversing all scenic spots:\n";
    for (int i = 0; i < graph.vertexCount; ++i) {
        std::cout << i << ": " << graph.vertices[i] << "\n";
    }
}

void createGraph(Graph& graph) {
    std::cout << "Enter number of vertices and edges: ";
    std::cin >> graph.vertexCount >> graph.edgeCount;
    graph.vertices.resize(graph.vertexCount);
    graph.edges.assign(graph.vertexCount, std::vector<int>(graph.vertexCount, MAX_COST));

    std::cout << "Enter vertex names:\n";
    for (int i = 0; i < graph.vertexCount; ++i) {
        std::cin >> graph.vertices[i];
    }

    std::cout << "Enter edges (format: i j weight, 0-indexed):\n";
    for (int i = 0; i < graph.edgeCount; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph.edges[u][v] = w;
    }
}

void displayMap() {
    std::cout << "Campus Map:\n";
    std::cout << "[0]---[1]\n";
    std::cout << " |     |\n";
    std::cout << "[2]---[3]\n";
}

void viewScenicSpot() {
    int choice;
    std::cout << "Enter scenic spot number to view description: ";
    std::cin >> choice;
    switch (choice) {
        case 0: std::cout << "Spot 0: Main Gate\n"; break;
        case 1: std::cout << "Spot 1: Library\n"; break;
        case 2: std::cout << "Spot 2: Sports Field\n"; break;
        case 3: std::cout << "Spot 3: Lecture Hall\n"; break;
        default: std::cout << "Invalid spot number\n"; break;
    }
}
