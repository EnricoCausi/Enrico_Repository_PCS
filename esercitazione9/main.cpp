#include <iostream>
#include <vector>
#include "fifo_lifo.h"
#include "graph.h"

template <typename T>
unidirected_graph graph_visit(const unidirected_graph& mio_grafo, int nodo_sorgente, T& c){
	unidirected_graph albero_risultato;
	int N = mio_grafo.all_nodes().size();
	vector<bool> visitati(N, false);
	
	c.put(nodo_sorgente);
    visitati[nodo_sorgente-1] = true;

    while (!c.empty()) {
        int nodo_corrente = c.get().value();

		for (int vicino : mio_grafo.neighbours(nodo_corrente)) {           

			if (!visitati[vicino-1]){
				visitati[vicino-1] = true;
				albero_risultato.add_edge(nodo_corrente,vicino);
				c.put(vicino);
			}
		}
    }
    return albero_risultato;
}


void dfs_helper(const unidirected_graph& mio_grafo, int nodo_corrente, vector<bool>& visitati, unidirected_graph& albero_risultato) {

    for (int vicino : mio_grafo.neighbours(nodo_corrente)) {
        
        if (!visitati[vicino - 1]) {
            visitati[vicino - 1] = true;  
            albero_risultato.add_edge(nodo_corrente, vicino);          
            dfs_helper(mio_grafo, vicino, visitati, albero_risultato);
        }
    }
}

unidirected_graph recursive_dfs(const unidirected_graph& mio_grafo, int nodo_sorgente) {
    unidirected_graph albero_risultato;
    int N = mio_grafo.all_nodes().size();   
    vector<bool> visitati(N, false); 
    visitati[nodo_sorgente - 1] = true;
    
    dfs_helper(mio_grafo, nodo_sorgente, visitati, albero_risultato);
    
    return albero_risultato;
}

unidirected_graph dijkstra(const unidirected_graph& mio_grafo, vector<vector<int>>& matrice_pesi, int nodo_sorgente) {
    unidirected_graph albero_risultato;
	
	priority_queue<
		pair<int, int>, 
		vector<pair<int, int>>, 
		greater<pair<int, int>>> 
	PQ; // top() mi restituisce la distanza minima
	
    int N = mio_grafo.all_nodes().size();   
	int Infinito = 1e7;
	vector<int> pred(N, -1);
	vector<int> dist(N, Infinito);
	
	pred[nodo_sorgente-1] = nodo_sorgente;
	dist[nodo_sorgente-1] = 0;
	//PQ.push({0, nodo_sorgente});
	
	for(int i =1; i<=N; i++)
		PQ.push({dist[i-1], i});
	
	while (!PQ.empty()){
		auto [p,u] = PQ.top();
		PQ.pop();
		for (int vicino : mio_grafo.neighbours(u))
			if (dist[vicino-1] > dist[u-1] + matrice_pesi[u-1][vicino-1]){
				dist[vicino-1] = dist[u-1] + matrice_pesi[u-1][vicino-1];
				pred[vicino-1] = u;
				PQ.push({dist[vicino-1], vicino});
			}
	}
	for (int i = 1; i <= N; ++i) {
        if (pred[i-1] != -1 && i != nodo_sorgente) {
            albero_risultato.add_edge(pred[i-1], i);
        }
    }
	
    return albero_risultato;
}




int main(){
		
	fifo<int> q;
	lifo<int> s;
	
	cout << "\n";

    unidirected_graph mio_grafo;

    mio_grafo.add_edge(1, 2);
    mio_grafo.add_edge(1, 4);
    mio_grafo.add_edge(1, 3);
	mio_grafo.add_edge(1, 6);
	mio_grafo.add_edge(2, 4);
	mio_grafo.add_edge(2, 5);
	mio_grafo.add_edge(2, 7);
	mio_grafo.add_edge(3, 6);
	mio_grafo.add_edge(4, 6);
	mio_grafo.add_edge(4, 7);
	mio_grafo.add_edge(5, 7);
	mio_grafo.add_edge(6, 7);
	mio_grafo.add_edge(6, 8);
	mio_grafo.add_edge(7, 9);
	mio_grafo.add_edge(8, 9);
	
	
	cout << "Inserito mio_grafo: ";
	set<unidirected_edge> insieme_archi_mio_grafo= mio_grafo.all_edges();
	for (unidirected_edge edge : insieme_archi_mio_grafo) {
		cout << edge << " ";
    }
    cout << "\n\n";
	

	int nodo_sorgente =  1;
	unidirected_graph albero_risultato = graph_visit(mio_grafo, nodo_sorgente, q);
	cout<< "Albero risultante: ";
	set<unidirected_edge> insieme_archi_albero_risultato= albero_risultato.all_edges();	
	for (unidirected_edge edge : insieme_archi_albero_risultato) {
		cout << edge << " ";
    }
    cout << "\n\n";
	
	
	unidirected_graph albero_risultato_recursive_dfs = recursive_dfs(mio_grafo, nodo_sorgente);
	cout<< "Albero risultante recursive_dfs: ";
	set<unidirected_edge> insieme_archi_albero_risultato_recursive_dfs= albero_risultato_recursive_dfs.all_edges();	
	for (unidirected_edge edge : insieme_archi_albero_risultato_recursive_dfs) {
		cout << edge << " ";
    }
    cout << "\n\n";
	
	
	int N = mio_grafo.all_nodes().size();
    
    // Matrice N*N per i pesi inizializzata tutta a 1
    vector<vector<int>> matrice_pesi(N, vector<int>(N, 1));
    
    // Allontano il nodo 4 dal nodo 1
    // matrice_pesi[1][4] = 10;
    // matrice_pesi[4][1] = 10;
    
    unidirected_graph albero_dijkstra = dijkstra(mio_grafo, matrice_pesi, nodo_sorgente);
    
    cout << "Albero risultante Dijkstra: ";
    set<unidirected_edge> insieme_archi_dijkstra = albero_dijkstra.all_edges();  
    for (unidirected_edge edge : insieme_archi_dijkstra) {
        cout << edge << " ";
    }
    cout << "\n\n";
	
	
	
	return 0;
}

