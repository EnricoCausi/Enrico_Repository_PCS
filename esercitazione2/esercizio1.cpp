
#include <iostream>

int main()
{
double ad[4] = {0.0, 1.1, 2.2, 3.3};
float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
int ai[3] = {0, 1, 2};
int x = 1;
float y = 1.1;

std::cout <<"indirizzo di x "<<&x << "\n";
std::cout << "indirizzo di y "<<&y << "\n";
(&y)[1] = 0;
std::cout << x << "\n";

// stampo gli indirizzi dei vari elementi dei vari vettori 
// std::cout << "Indirizzi elem. ad: " << &ad[0] << " " << &ad[1] << " "<< &ad[2] << " "<< &ad[3] <<"\n";
// std::cout << "Indirizzi elem. af: ";
// for (int i = 0; i <= 7; i++) {std::cout << &af[i] << " ";}
// std::cout << "\n";
// std::cout <<"Indirizzi elem. ai: " << &ai[0] << " " <<  &ai[1] << " " << &ai[2] << "\n";

// quando tratto y (float) come se fosse un array facendo (&y)[1] = 0, sto calcolando un indirizzo di memoria spostandomi in avanti di 
// 4 byte (dimensione di y). Poiché lo stack cresce verso il basso, la variabile x (che ho dichiarato prima) si trova  a un indirizzo 
// di 4 byte maggiore rispetto a y. Cercando di modificare l'elemento in posizione (&y)[1], vado in realtà a modificare
// l'int x sovrascrivendolo a 0.

// MI FUNZIONA SOLO CON CLANG
return 0;
}