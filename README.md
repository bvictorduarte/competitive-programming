# Programação Competitiva

Minhas soluções de problemas de programação competitiva e a biblioteca de algoritmos que fui montando ao longo da preparação para a **OBI** (Olimpíada Brasileira de Informática) e a **Maratona de Programação da SBC**.

Tudo em **C++17**.

## Números

| Fonte | Soluções |
| --- | ---: |
| [OBI](problems/obi) (2007–2023, fases 1, 2 e 3) | 138 |
| [Codeforces](problems/codeforces) | 128 |
| [CSES Problem Set](problems/cses) | 119 |
| [AtCoder Beginner Contest](problems/atcoder) | 49 |
| [Beecrowd](problems/beecrowd) | 41 |
| [Maratona SBC](problems/maratona-sbc) (2006–2024) | 40 |
| [UVa Online Judge](problems/uva) | 25 |
| [Contests de treino](problems/contests) (Unicamp, Bits) | 21 |
| [Kattis](problems/kattis) | 14 |
| [Seletiva para a Maratona](problems/seletiva) | 12 |
| [SPOJ](problems/spoj), [LeetCode](problems/leetcode), [CodeChef](problems/codechef), [USACO](problems/usaco), [outros](problems/misc) | 13 |
| **Total** | **600** |

## Estrutura

```
.
├── library/        # implementações reutilizáveis (o "caderno" de maratona)
│   ├── graphs/
│   ├── data-structures/
│   └── math/
├── study/          # estudos por tópico
└── problems/       # soluções, organizadas por plataforma/competição
    ├── cses/       #   por seção do problem set
    ├── codeforces/ #   por contest
    ├── atcoder/    #   por ABC
    ├── obi/        #   por ano → fase
    ├── maratona-sbc/
    └── ...
```

## Biblioteca

Implementações que eu reaproveito em competição:

**Grafos**
- [BFS](library/graphs/bfs.cpp)
- [Dijkstra](library/graphs/dijkstra.cpp)
- [Kosaraju](library/graphs/kosaraju.cpp): componentes fortemente conexas
- [Pontes](library/graphs/bridges.cpp)
- [LCA](library/graphs/lca.cpp): menor ancestral comum (binary lifting)
- [Dominator Tree](library/graphs/dominator-tree.cpp)
- [Dinic](library/graphs/dinic.cpp): fluxo máximo
- [Emparelhamento bipartido máximo](library/graphs/bipartite-matching.cpp)

**Estruturas de dados**
- [DSU / Union-Find](library/data-structures/dsu.cpp): união por tamanho

**Matemática** (fórmulas prontas, os "bizus")
- [Geometria](library/math/geometry.h)
- [Trigonometria](library/math/trigonometry.h)
- [Somas e séries](library/math/sums-series.h)
- [Derivadas e integrais](library/math/derivatives-integrals.h)

Em [`study/`](study) ficam estudos de tópicos como programação dinâmica, Convex Hull Trick, algoritmos em grafos, Prim (MST), crivo de Eratóstenes e algoritmo de Euclides estendido.

## Como compilar

```bash
g++ -std=c++17 -O2 -Wall solucao.cpp -o solucao
./solucao < entrada.txt
```

A maioria das soluções usa `#include <bits/stdc++.h>`, então precisa do GCC. No macOS, instale com `brew install gcc` e use o `g++-<versão>` que ele instalar.
