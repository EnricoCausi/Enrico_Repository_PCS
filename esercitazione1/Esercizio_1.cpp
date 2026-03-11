#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
	
	
if (argc != 2){ cout<<"Devi inserire 2 parametri, ne hai inseriti " << argc << "\n";
return 1;}
ifstream ifs(argv[1]);
if (ifs.is_open()) {
for (int i = 0; i <=2; i++) {
	string citta;
	double temp0;
	double temp6;
	double temp12;
	double temp18;
	ifs >> citta >> temp0 >> temp6 >> temp12 >> temp18;
	double temp_media = (temp0 + temp6 + temp12 + temp18)/4.0;
	cout <<"Temperature at " << citta << " "<< temp_media << "\n"; 
}
return 0;}
else cout << "Ricontrolla il nome del file \n";
return 1;

}

