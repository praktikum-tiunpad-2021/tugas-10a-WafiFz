#pragma once

#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>

namespace strukdat {

template <typename VertexType>
class graph {
  /**
   * @brief Tipe data dari adjacency list. (BOLEH DIUBAH)
   *
   * @note
   * Misal:
   *
   * adj_list_type adj_list =
   *
   * | map key  |             list_type
   * | - - - -  | - - - - - - - - - - - - - - - - -
   * | vertex_1 | vertex_2, vertex_5, vertex_4, ...
   * | vertex_2 | vertex_1, vertex_3
   * |   ...    |           ...
   *
   * maka,
   *
   * adj_list[vertex_2]; // { vertex_1, vertex_3 }
   */
  using list_type = std::unordered_set<VertexType>;
  using adj_list_type = std::unordered_map<VertexType, list_type>;

 public:
  /**
   * @brief Default constructor.
   *
   * @constructor
   */
  graph() {}

  /**
   * @brief Menambahkan vertex baru pada graph
   *
   * @param val nilai dari vertex yang akan ditambahkan
   */
  void add_vertex(const VertexType &val) {
    // Contoh implementasi. (BOLEH DIUBAH)
    // inisialisasi _adj_list[val] dengan list kosong
    _adj_list.insert(std::make_pair(val, list_type()));
  }

  void remove_vertex(const VertexType &val) {
    _adj_list.erase(val);
  }

  /**
   * @brief Menambahkan edge baru dari 2 vertex
   *
   * @param val1 nilai vertex 1
   * @param val2 nilai vertex 2
   */
  void add_edge(const VertexType &val1, const VertexType val2) {
  	auto it = _adj_list[val1].find(val2);

  	if(it == _adj_list[val1].end()){
  		_adj_list[val1].insert(val2);
  	}

  	it = _adj_list[val2].find(val1);

   	if(it == _adj_list[val2].end()){
  		_adj_list[val2].insert(val1);
  	}
  }

  /**
   * @brief Menghapus vertex baru pada graph
   *
   * @param val nilai dari vertex yang akan dihapus
   */
  void remove_edge(const VertexType &val1, const VertexType &val2) {
  	auto it = _adj_list[val1].find(val2);

  	if(it != _adj_list[val1].end()){
  		_adj_list[val1].erase(val2);
  	}

  	it = _adj_list[val2].find(val1);

   	if(it != _adj_list[val2].end()){
  		_adj_list[val2].erase(val1);
  	} 
  }

  /**
   * @brief Mengembalikan ordo dari graph.
   *
   * @note
   * Ordo graph adalah jumlah node pada graph
   *
   * @return jumlah node pada graph
   */
  size_t order() const {
    return _adj_list.size();
  }

  /**
   * @brief Cek apakah 2 vertex bertetangga satu sama lain.
   *
   * @param val1 nilai vertex 1
   * @param val2 nilai vertex 2
   *
   * @return vertex-vertex saling bertetangga
   */
  bool is_edge(const VertexType &val1, const VertexType &val2) const {
    adj_list_type _adj_list_check = _adj_list;
      
      auto it1  = _adj_list_check[val1].find(val2);
      auto it2 = _adj_list_check[val2].find(val1);

      if(it1 != _adj_list_check[val1].end() && it2 != _adj_list_check[val2].end()){
        return true;
      }else{
        return false;
      }
  }

  /**
   * @brief Melakukan BFS traversal pada graph
   *
   * @param root vertex awal
   * @param func fungsi yang akan dieksekusi pada setiap vertex
   */
  void bfs(const VertexType &root,
           std::function<void(const VertexType &)> func) const {
    bool *visited = new bool[root];
    for(int i = 0; i < root; i++) visited[i] = false;
    
    std::list<VertexType> queue;
    VertexType vertexHelp = root;
    adj_list_type _adj_list_check = _adj_list;

    queue.push_back(vertexHelp);
    visited[vertexHelp] = true;

    while (!queue.empty()){
    	vertexHelp = queue.front();
    	queue.pop_front();
    	func(vertexHelp);

    	for(auto i = _adj_list_check[vertexHelp].begin();
    		i != _adj_list_check[vertexHelp].end();
    		++i){
    			if(!visited[*i]){
    				visited[*i] = true;
    				queue.push_back(*i);
    			}
    	}

    }
  }

  /**
   * @brief Melakukan BFS traversal pada graph
   *
   * @param root vertex awal
   * @param func fungsi yang akan dieksekusi pada setiap vertex
   */
  void dfs(const VertexType &root,
           std::function<void(const VertexType &)> func) const {
    bool *visited = new bool[root];
    for(int i = 0; i < root; i++) visited[i] = false;
    
    list_type stack;
    VertexType vertexHelp = root;
    adj_list_type _adj_list_check = _adj_list;

    stack.insert(vertexHelp);
    visited[vertexHelp] = true;

    while (!stack.empty()){
      vertexHelp = *stack.begin();
      stack.erase(stack.begin());
      func(vertexHelp);

      for(auto i = _adj_list_check[vertexHelp].begin();
        i != _adj_list_check[vertexHelp].end();
        ++i){
          if(!visited[*i]){
            visited[*i] = true;
            stack.insert(*i);
          }
      }

    }
  }

 private:
  /**
   * @brief Adjacency list dari graph
   *
   * @private
   */
  adj_list_type _adj_list;
};

}  // namespace strukdat