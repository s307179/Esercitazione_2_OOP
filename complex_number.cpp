#include <iostream>
#include "complex_number.hpp"
using namespace std;
// per eseguirlo g++ -std=c++20 -o complex_number complex_number.cpp
int main(void) {
    using com = complex_number<double>;
    // verifichiamo la stampa
    com c1(3.1415926535,2.99792365);
	com c2(3.0,-4.0);
	com c6(1.61); // reale
	com c7(0,7.574358029); //immaginario
	cout << c1 <<endl;
	cout <<c2 << endl;
	cout << c6<<endl;
	cout <<c7 << endl;
	// verifichiamo il corretto funzionamento dei costruttori di inizializzazione
	com c3; //nullo
	cout <<c3<<endl;
	com c4(6.0); //reale
	cout<<c4<<endl;
	cout << c3.inverso() <<endl;
	double d = 5.0;
	// verifichiamo i vari metodi
	cout<< "la parte reale del numero " << c1 << " è " << c1.parte_reale()<<endl;
	cout<< "la parte immaginaria del numero " << c2 << " è " << c2.parte_immaginaria()<<endl;
	cout<< "il coniugato del numero " << c2 << " è " << c2.coniugato()<<endl;
	cout << "l'inverso del numero "<< c1 << " è " << c1.inverso() <<endl;
	cout << "il modulo del numero " << c1 << " è " << c1.modulo()<<endl;
	// verifichiamo gli operatori 
	cout << "la somma dei numeri complessi " <<c1<< " e "<<c2<< " è " << c1+c2<<endl;
	cout << "il prodotto dei numeri complessi " <<c1<< " e "<<c2<< " è " << c1*c2<<endl;
	cout << "la somma tra il numero complesso " << c1<< " e il reale " << d << " è " << c1+d<<endl;
	cout << "il prodotto tra il numero complesso " << c1<< " e il reale " << d << " è " << c1*d<<endl;
	// verifichiamo la commutatività
	cout << d+c1<<endl;
	cout << d*c1<<endl;
    return 0;
}
