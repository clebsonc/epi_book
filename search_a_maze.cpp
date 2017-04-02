#include <utility>
#include <limits>
#include <iostream>
#include <vector>
#include <exception>
#include <queue>

enum class NodeColor : char {
  kgray,
  kwhite
};

class Node{
  private:
    int x, y;  // coordinate of the node
    NodeColor color;  // color of the node
    int x_pred, y_pred;  // coordinate of predecessor node

  public:
    Node(){}

    Node(int x, int y){
      this->x = x;
      this->y = y;
      this->color = NodeColor::kwhite;
      this->x_pred = -1;
      this->y_pred = -1;
    }
    
    std::pair<int, int> getCoordinate() const{
      return std::pair<int, int>(x, y);
    }

    void setPredecessor(int x, int y){
      this->x_pred = x;
      this->y_pred = y;
    }

    std::pair<int, int> getPredecessor() const{
      return std::pair<int, int>(x_pred, y_pred);
    }

    void setColor(NodeColor c){
      this->color = c;
    }

    NodeColor getColor(){
      return this->color;
    }
    
    void printNode(){
      std::cout << "Coordinate: " << x << ", " << y << std::endl;
      std::cout << "Color: " << (this->color == NodeColor::kwhite ? "WHITE" : "GRAY") << std::endl;
      std::cout << "Predecessor: " << this->x_pred << ", " << y_pred << std::endl;
    }
};

class Maze{
  private:
    std::vector<std::vector<Node>> maze;
    int x_s, y_s;  // start coordinate of the maze;
    int x_e, y_e;  // exit coordinate of the maze;

  public:
    Maze(){}

    Maze(int l, int c){
      for (int i = 0; i < l; i++){
        std::vector<Node> line_vector;
        for (int j = 0; j < c; j++){
          line_vector.emplace_back(Node(i, j));
        }
        maze.emplace_back(line_vector);
      }
    }

    void setWalls(const std::vector<std::pair<int, int>> & walls){
      for (auto & x : walls){
        maze.at(x.first).at(x.second).setColor(NodeColor::kgray);
      }
    }

    void setEntrance(int x, int y){
      this->x_s = x;
      this->y_s = y;
    }

    void setExit(int x, int y){
      this->x_e = x;
      this->y_e = y;
    }

    std::vector<std::pair<int, int>> getNeighboors(int x, int y){
      std::vector<std::pair<int, int>> neighbors;
      if (x < 0 || y < 0 || x >= maze.size() || y >= maze.at(0).size()){
        std::cerr << "Invalid Index" << std::endl;
      }
      else if (x > 0 && x < maze.size()-1 && y > 0 && y < maze.at(0).size()-1){
        if (maze.at(x-1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x-1, y));
        if (maze.at(x+1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x+1, y));
        if (maze.at(x).at(y-1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y-1));
        if (maze.at(x).at(y+1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y+1));
      }
      else if (x==0 && y == 0){
        if (maze.at(x).at(y+1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y+1));
        if (maze.at(x+1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x+1, y));
      }
      else if (x==maze.size()-1 && y == 0){
        if (maze.at(x).at(y+1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y+1));
        if (maze.at(x-1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x-1, y));
      }
      else if (x==0 && y == maze.at(0).size()-1){
        if (maze.at(x).at(y-1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y-1));
        if (maze.at(x+1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x+1, y));
      }
      else if (x==maze.size()-1 && y == maze.at(0).size()-1){
        if (maze.at(x).at(y-1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y-1));
        if (maze.at(x-1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x-1, y));
      }
      else if (x == 0){
        if (maze.at(x+1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x+1, y));
        if (maze.at(x).at(y+1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y+1));
        if (maze.at(x).at(y-1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y-1));
      }
      else if (x == maze.size()-1){
        if (maze.at(x-1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x-1, y));
        if (maze.at(x).at(y+1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y+1));
        if (maze.at(x).at(y-1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y-1));
      }
      else if (y == 0){
        if (maze.at(x).at(y+1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y+1));
        if (maze.at(x-1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x-1, y));
        if (maze.at(x+1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x+1, y));
      }
      else if (y = maze.at(0).size()-1){
        if (maze.at(x).at(y-1).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x, y-1));
        if (maze.at(x-1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x-1, y));
        if (maze.at(x+1).at(y).getColor() == NodeColor::kwhite)
          neighbors.emplace_back(std::pair<int, int>(x+1, y));
      }
      return neighbors;
    }

    void computeBFS(){
      std::queue<std::pair<int, int>> q;
      q.emplace(std::pair<int, int>(x_s, y_s));
      while (!q.empty()){
        std::pair<int, int> u = q.front();
        q.pop();
        maze.at(u.first).at(u.second).setColor(NodeColor::kgray);
        std::vector<std::pair<int, int>> neighbors = 
                              this->getNeighboors(u.first, u.second);
        for (auto v : neighbors){
          if (maze.at(v.first).at(v.second).getColor() == NodeColor::kwhite){
            maze.at(v.first).at(v.second).setPredecessor(u.first, u.second);
            q.emplace(v);
          }
        }
      }
    }
    
    void print_source_to_destine(int x, int y){
      std::pair<int, int> pred = maze.at(x).at(y).getPredecessor();
      if (pred.first == -1 && pred.second == -1){
        maze.at(x).at(y).printNode();
        std::cout << "|" << std::endl;
        std::cout << "V" << std::endl;
        return;
      }
      print_source_to_destine(pred.first, pred.second);
      maze.at(x).at(y).printNode();
      std::cout << "|" << std::endl;
      std::cout << "V" << std::endl;
    }

    void print_maze() const {
      for (auto line : maze){
        for (auto column : line){
          column.printNode();
          std::cout << std::endl;
        }
        std::cout << "-------------" << std::endl;
      }
    }
};


int main(){
  Maze m(10, 10);
  std::vector<std::pair<int, int>> walls;
  walls.emplace_back(std::pair<int, int>(0, 0));
  walls.emplace_back(std::pair<int, int>(0, 6));
  walls.emplace_back(std::pair<int, int>(0, 7));
  walls.emplace_back(std::pair<int, int>(1, 2));
  walls.emplace_back(std::pair<int, int>(2, 2));
  walls.emplace_back(std::pair<int, int>(2, 5));
  walls.emplace_back(std::pair<int, int>(2, 6));
  walls.emplace_back(std::pair<int, int>(2, 8));
  walls.emplace_back(std::pair<int, int>(2, 9));
  walls.emplace_back(std::pair<int, int>(3, 3));
  walls.emplace_back(std::pair<int, int>(3, 4));
  walls.emplace_back(std::pair<int, int>(3, 5));
  walls.emplace_back(std::pair<int, int>(3, 8));
  walls.emplace_back(std::pair<int, int>(4, 1));
  walls.emplace_back(std::pair<int, int>(4, 2));
  walls.emplace_back(std::pair<int, int>(5, 1));
  walls.emplace_back(std::pair<int, int>(5, 2));
  walls.emplace_back(std::pair<int, int>(5, 5));
  walls.emplace_back(std::pair<int, int>(5, 6));
  walls.emplace_back(std::pair<int, int>(5, 7));
  walls.emplace_back(std::pair<int, int>(5, 8));
  walls.emplace_back(std::pair<int, int>(6, 4));
  walls.emplace_back(std::pair<int, int>(7, 0));
  walls.emplace_back(std::pair<int, int>(7, 2));
  walls.emplace_back(std::pair<int, int>(7, 4));
  walls.emplace_back(std::pair<int, int>(7, 6));
  walls.emplace_back(std::pair<int, int>(8, 0));
  walls.emplace_back(std::pair<int, int>(8, 2));
  walls.emplace_back(std::pair<int, int>(8, 3));
  walls.emplace_back(std::pair<int, int>(8, 7));
  walls.emplace_back(std::pair<int, int>(8, 8));
  walls.emplace_back(std::pair<int, int>(8, 9));
  walls.emplace_back(std::pair<int, int>(9, 7));
  walls.emplace_back(std::pair<int, int>(9, 8));
  m.setWalls(walls);
  m.setEntrance(9, 0);
  m.setExit(0, 9);
  m.computeBFS();
  m.print_source_to_destine(0, 9);
  

  return 0;
}

