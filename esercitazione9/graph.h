#include <iostream>
#include <optional>
#include <string>
#include <map>
#include <set>
using namespace std;

class unidirected_edge {
    
private:
    int source;
    int target;

public: 

    unidirected_edge(int s, int t) {
		if (s<t){
			source = s;
			target = t;
		}
        else {
			source = t;
			target = s;
		}
    }

    int from() const{
        return source;
    }
	
    int to() const{
        return target;
    }
		
	bool operator<(const unidirected_edge& other) const {
        if (source != other.source) {
            return source < other.source;
        }
		else{
			return target< other.target;
		}
    }
	
	bool operator==(const unidirected_edge& other) const {
		bool stesso_verso = (source == other.source && target == other.target);
		bool verso_opposto = (source == other.target && target == other.source);
		
		return (stesso_verso || verso_opposto); 
	}	
		
};


ostream& operator<<(ostream& os, const unidirected_edge& edge){
	os<<"(" << edge.from() << " - " << edge.to() << ")";
	return os;
}








class unidirected_graph {
    
private:
    map<int, set<int>> lista_adiacenza;
	
	map<unidirected_edge, int> edge_to_int;
	map<int, unidirected_edge> int_to_edge;
	
	int counter = 0;

public: 

	unidirected_graph() {};
	unidirected_graph(const unidirected_graph& other);

	void add_edge(int s, int t){
		unidirected_edge nuovo_arco(s,t);
		
		if (edge_to_int.find(nuovo_arco) != edge_to_int.end()) {
        return; 
    }
		
		lista_adiacenza[s].insert(t);
		lista_adiacenza[t].insert(s);
		
		edge_to_int.insert({nuovo_arco, counter});
		int_to_edge.insert({counter, nuovo_arco});
		
		counter++;
	}
	
	const set<int>& neighbours(int s) const{
		return lista_adiacenza.at(s);
	}
	
	set<unidirected_edge> all_edges() const {
		set<unidirected_edge> insieme_archi;
		for (const auto& coppia : edge_to_int){
			insieme_archi.insert(coppia.first);
		}
		return insieme_archi;
	}
	
	set<int> all_nodes() const{
		set<int> insieme_nodi;
		for (const auto& coppia : lista_adiacenza){
			insieme_nodi.insert(coppia.first);
		}
		return insieme_nodi;
	}

	int edge_number(unidirected_edge edge) const{
		return edge_to_int.at(edge);
	}

	std::optional<unidirected_edge> edge_at(int indice) const{
		if (indice >= counter) {
			cout<< "Arco inesistente\n";
			return std::nullopt;}
		
		else {return int_to_edge.at(indice);}
	}

	// unidirected_graph operator-(const unidirected_graph& other) const;

};

unidirected_graph::unidirected_graph(const unidirected_graph& other){
	lista_adiacenza = other.lista_adiacenza;
	counter = other.counter;
	edge_to_int = other.edge_to_int;
	int_to_edge = other.int_to_edge;
}

// unidirected_graph unidirected_graph::operator-(const unidirected_graph& other) const {
	// unidirected_graph ris;
	// set<unidirected_edge> insieme_archi1= all_edges();
	// set<unidirected_edge> insieme_archi2= other.all_edges();
	
	// for (const unidirected_edge& arco : insieme_archi1) {
        
        // if (insieme_archi2.find(arco) == insieme_archi2.end()) {
			// ris.add_edge(arco.from(), arco.to());
        // }
    // }

    // return ris;
// }


// int main(){
	
// cout << "\n";

    // unidirected_graph mio_grafo;

    // mio_grafo.add_edge(1, 2);
    // mio_grafo.add_edge(2, 5);
    // mio_grafo.add_edge(2, 4);
	// mio_grafo.add_edge(3, 5);
	// mio_grafo.add_edge(3, 6);
	
	// unidirected_graph grafo_sottrazione;

    // grafo_sottrazione.add_edge(1, 2);
    // grafo_sottrazione.add_edge(3, 5);
    // grafo_sottrazione.add_edge(3, 4);

	// unidirected_graph grafo_risultato = mio_grafo - grafo_sottrazione;
	
	// cout<< "insieme archi rimasti: ";
	// set<unidirected_edge> archi_grafo_sottrazione= grafo_risultato.all_edges();
	// for (unidirected_edge edge : archi_grafo_sottrazione) {
		// cout << edge << " ";
    // }
    // cout << "\n\n";
	
	// cout<< "Nodi rimasti: ";
	// set<int> nodi_grafo_risultato = grafo_risultato.all_nodes();
	// for (int nodo : nodi_grafo_risultato){
		// cout<< nodo << " ";
	// }
	// cout<< "\n\n";
	
	// unidirected_graph grafo2 = mio_grafo;

    // cout << "Cerco i vicini del nodo 1: \n";
        
    // const set<int>& vicini_di_1 = mio_grafo.neighbours(1);
        
    // cout << "Il nodo 1 e' collegato a: ";   
    // for (int nodo_vicino : vicini_di_1) {
        // cout << nodo_vicino << " ";
    // }
    // cout << "\n\n";

	// cout<< "Insieme Archi: ";
	// set<unidirected_edge> insieme_archi= mio_grafo.all_edges();
	// for (unidirected_edge edge : insieme_archi) {
		// cout << edge << " ";
    // }
    // cout << "\n\n";
	
	// cout<< "Insieme Nodi: ";
	// set<int> insieme_nodi = mio_grafo.all_nodes();
	// for (int nodo : insieme_nodi){
		// cout<< nodo << " ";
	// }
	// cout<< "\n\n";
	
	// unidirected_edge edge(2,1);
	// cout<< "L'arco: "<< edge << " è il numero: " <<mio_grafo.edge_number(edge) << "\n";
	
	// int index = 2;
	// std::optional<unidirected_edge> risultato = mio_grafo.edge_at(index);
    
    // if (risultato) {
        // cout << "edge_at " << index << ": " << risultato.value() << "\n";
    // }	
	// return 0;
// }