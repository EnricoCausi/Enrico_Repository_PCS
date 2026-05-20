#include <iostream>
#include <queue>
#include <stack>
#include <optional>


using namespace std;

template<typename T>
class fifo {
	private: 
		queue<T> q;
		
	public:
		void put(const T& el){
			q.push(el);
		}
		
		optional<T> get(){
			if (q.empty()) {return nullopt;}
			T testa = q.front();
			q.pop();
			return testa;
		}
		
		bool empty(){
			return q.empty();
		}

};


template<typename T>
class lifo {
	private: 
		stack<T> s;
		
	public:
		void put(const T& el){
			s.push(el);
		}
		
		optional<T> get(){
			if (s.empty()) {return nullopt;}
			T testa = s.top();
			s.pop();
			return testa;
		}
		
		bool empty(){
			return s.empty();
		}

};

