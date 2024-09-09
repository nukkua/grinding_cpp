#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <vector>

#pragma GCC optimize("03")

#define INF std::numeric_limits<int>::max()
#define endl '\n'

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

auto bfs(std::vector<std::vector<int>> &list,
         int initialNode) -> std::vector<int> {
  int n = list.size();

  std::queue<int> q;
  std::vector<int> d(n, INF);
  q.push(initialNode);
  d[initialNode] = 0;

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    for (auto &y : list[x]) {
      if (d[y] == INF) {
        d[y] = d[x] + 1;
        q.push(y);
      }
      if (x == y) {
        return d;
      }
    }
  }

  return d;
}

signed main() {
  fastio();
  int r, c;
  std::cin >> r >> c;
  char forest[r][c];
  std::vector<std::vector<int>> list(r *
                                     c); // Lista de adyacencia para r*c nodos
  int initialNode = 0;
  int finalNode = 0;

  // Leer el bosque
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      std::cin >> forest[i][j];
    }
  }

  // Generar el grafo
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int node = i * c + j; // Índice del nodo en la lista de adyacencia

      if (forest[i][j] != 'T') {
        // Conectar con el nodo a la izquierda
        if (j - 1 >= 0 && forest[i][j - 1] != 'T') {
          list[node].push_back(i * c + (j - 1));
        }

        // Conectar con el nodo a la derecha
        if (j + 1 < c && forest[i][j + 1] != 'T') {
          list[node].push_back(i * c + (j + 1));
        }

        // Conectar con el nodo de arriba
        if (i - 1 >= 0 && forest[i - 1][j] != 'T') {
          list[node].push_back((i - 1) * c + j);
        }

        // Conectar con el nodo de abajo
        if (i + 1 < r && forest[i + 1][j] != 'T') {
          list[node].push_back((i + 1) * c + j);
        }
      }
      if (forest[i][j] == 'S') {
        initialNode = node;
      }
      if (forest[i][j] == 'E') {
        finalNode = node;
      }
    }
  }

  auto d = bfs(list, initialNode);

  std::cout << "From " << initialNode << " to " << finalNode << " is -> "
            << d[finalNode] << endl;

  return 0;
}
