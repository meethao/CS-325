#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Point{
      private:
            int x;
            int y;
      public:
            Point();
            Point(int x, int y);
            void set_x(int x);
            void set_y(int y);
            int get_x();
            int get_y();

};

Point::Point(): x(-1), y(-1) {}

Point::Point(int x, int y): x(x), y(y) {}

void Point::set_x(int x){
      this->x = x;
}

void Point::set_y(int y){
      this->y = y;
}

int Point::get_x(){
      return x;
}

int Point::get_y(){
      return y;
}


class Edge{
public:
      int src;
      int dest;
      int weight;
};

class Graph{
public:
      int V;
      int E;
      Edge* edge;
};

Graph* createGraph(int V, int E){
      Graph* graph = new Graph;
      graph->V = V;
      graph->E = E;
      graph->edge = new Edge[E];

      return graph;
}

class subset{
public:
      int parent;
      int rank;
};

int find(subset subsets[], int i){
      if(subsets[i].parent != i){
            subsets[i].parent = find(subsets, subsets[i].parent);
      }
      return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
      int xroot = find(subsets, x);
      int yroot = find(subsets, y);

      if(subsets[xroot].rank < subsets[yroot].rank){
            subsets[xroot].parent = yroot;
      }
      else if(subsets[xroot].rank > subsets[yroot].rank){
            subsets[yroot].parent = xroot;
      }
      else{
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
      }
}

int myComp(const void* a, const void*b){
      Edge* a1 = (Edge*)a;
      Edge* b1 = (Edge*)b;

      return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph, Point** p){
      int V = graph->V;
      Edge result[V];
      int e = 0;
      int i = 0;
      qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

      subset* subsets = new subset[(V * sizeof(subset))];

      for(int v = 0; v < V; v++){
            subsets[v].parent = v;
            subsets[v].rank = 0;
      }

      while(e < V - 1 && i < graph->E){
            Edge next_edge = graph->edge[i++];

            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);

            if(x != y){
                  result[e++] = next_edge;
                  Union(subsets, x, y);
            }
      }

      int total = 0;
      cout << "Edges in MST" << endl;
      cout << "Point (x,y)";
      cout << setw(35) << "Distance" << endl;
      for(int i = 0; i < e; i++){
            cout << setw(5) << "(" << p[result[i].src]->get_x() << ", " << p[result[i].src]->get_y() << ")" << "  -   ";
            cout << "(" << p[result[i].dest]->get_x() << ", " << p[result[i].dest]->get_y() << ")";
            cout <<setw(20)<<result[i].weight << endl;
            total = total + result[i].weight;
      }
      cout << setw(30) << "Total distance " << total << endl;
      return;
}



int get_distance(Point *a, Point *b){
      double dis = sqrt(pow(a->get_x() - b->get_x(), 2) + pow(a->get_y() - b->get_y(), 2));

      int dis_1=(int)dis;
      double r = dis - dis_1;

      if(r >= 0.5){
            return dis_1 + 1;
      }
      else{
            return dis_1;
      }
}

int get_edge(int V){
      int edge = 0;
      for(int i = V - 1; i > 0; i--){
            edge = edge + i;
      }
      return edge;
}

int main(int argc, char** argv){
      int V = 0, E = 0;
      int x = 0, y = 0;

      ifstream infile;
      infile.open(argv[1]);

      if(infile.fail()){
            cout << "Failed to read " << argv[1] << endl;
      }

      infile >> V;
      E = get_edge(V);

      Graph* graph = createGraph(V, E);
      Point **p;
      p = new Point* [V];

      for(int i = 0; i < V; i++){
            infile >> x >> y;
            p[i] = new Point(x, y);
      }

      infile.close();

      int m = 0;
      for(int i = 0; i < V; i++){
            for(int j = i + 1; j < V; j++){
                  graph->edge[m].src = i;
                  graph->edge[m].dest = j;
                  graph->edge[m].weight = get_distance(p[i], p[j]);
                  m++;
            }
      }

      KruskalMST(graph, p);
}
