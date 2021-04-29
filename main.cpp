/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 * Disini ada contoh code, boleh dihapus.
 */

#include <iostream>
#include <vector>

#include "graph.hpp"

int main() {
    std::cout << "dapat menambah dan menghapus vertex [case_1]" << std::endl;
  strukdat::graph<int> g;
  g.add_vertex(1);
  g.add_vertex(2);
  if(g.order() == 2){
  	std::cout << "1.1 Berhasil" << std::endl;
  }

  g.add_vertex(2);
  if(g.order() == 2){
  	std::cout << "1.2 Berhasil" << std::endl;
  }

  g.add_vertex(3);
  if(g.order() == 3){
  	std::cout << "1.3 Berhasil" << std::endl;
  }

  g.remove_vertex(2);
  if(g.order() == 2){
  	std::cout << "1.4 Berhasil" << std::endl;
  }


  std::cout << "dapat menambah dan menghapus edge [case_2]" << std::endl;
  strukdat::graph<int> g2;

  g2.add_vertex(1);
  g2.add_vertex(2);
  g2.add_vertex(3);

  g2.add_edge(1, 2);
  if(!g2.is_edge(1, 3)){
  	std::cout << "2.1 Berhasil" << std::endl;
  }

  g2.add_edge(1, 3);
  if(g2.is_edge(1, 2)){
  	std::cout << "2.2 Berhasil" << std::endl;
  }
  if(g2.is_edge(1, 3)){
  	std::cout << "2.3 Berhasil" << std::endl;
  }
  if(g2.is_edge(2, 1)){
  	std::cout << "2.4 Berhasil" << std::endl;
  }
  if(!g2.is_edge(2, 3)){
  	std::cout << "2.5 Berhasil" << std::endl;
  }

    std::cout << "dapat melakukan bfs traversal [case_3]" << std::endl;
  strukdat::graph<int> g3;

  g3.add_vertex('a');
  g3.add_vertex('b');
  g3.add_vertex('c');
  g3.add_vertex('d');
  g3.add_vertex('e');

  g3.add_edge('a', 'b');
  g3.add_edge('a', 'c');
  g3.add_edge('b', 'd');
  g3.add_edge('c', 'e');

  std::vector<char> ans;
  const std::vector<char> sol1 = {'a', 'b', 'c', 'd', 'e'};
  const std::vector<char> sol2 = {'a', 'c', 'b', 'e', 'd'};

  g3.bfs('a', [&ans](char a) { ans.push_back(a); });
  if((std::equal(ans.begin(), ans.end(), sol1.begin(), sol1.end()) ||
           std::equal(ans.begin(), ans.end(), sol2.begin(), sol2.end()))){
  	std::cout << "3 Berhasil" << std::endl;
  }

  std::cout << "dapat melakukan dfs traversal [case_4]" << std::endl;
  strukdat::graph<int> g4;

  g4.add_vertex('a');
  g4.add_vertex('b');
  g4.add_vertex('c');
  g4.add_vertex('d');
  g4.add_vertex('e');

  g4.add_edge('a', 'b');
  g4.add_edge('a', 'c');
  g4.add_edge('b', 'd');
  g4.add_edge('c', 'e');

  std::vector<char> ans4;
  const std::vector<char> sol1_4 = {'a', 'b', 'd', 'c', 'e'};
  const std::vector<char> sol2_4 = {'a', 'c', 'e', 'b', 'd'};

  g4.dfs('a', [&ans4](char a) { ans4.push_back(a); });
  if((std::equal(ans4.begin(), ans4.end(), sol1_4.begin(), sol1_4.end()) ||
           std::equal(ans4.begin(), ans4.end(), sol2_4.begin(), sol2_4.end()))){
  	std::cout << "4 Berhasil" << std::endl;
  }

	return 0;
}
