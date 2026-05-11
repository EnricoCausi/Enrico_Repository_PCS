#include <iostream>
#include <string>
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