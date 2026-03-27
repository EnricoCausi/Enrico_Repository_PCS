#include <concepts>
#include "rationalv1.hpp"
#include <iostream>
using namespace std;

int main(void)
{
rational<int> a(2,0);
rational<int> b(2,4);

rational<int> c = a+b;
rational<int> d = b-a;
rational<int> e = a*b;
rational<int> f = b/a;
cout << "a: " << a << "\n";
cout << "b: " << b << "\n";
cout << "Somma "<< c << "\n";
cout << "Differenza "<< d << "\n";
cout << "Prodotto "<< e << "\n";
cout << "Rapporto "<< f << "\n";
return 0;

}

// NOTA: Per la gestione di Inf/NaN ho utilizzato un assistente 
// basato su Intelligenza Artificiale (Google Gemini) come supporto
// e per il debug degli errori di compilazione.

