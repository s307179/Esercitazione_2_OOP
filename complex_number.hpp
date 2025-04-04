#pragma once
#include <concepts>
#include <cmath>
using namespace std;

// definiamo la classe dei numeri complessi, definizione e operazioni base

template<typename T> requires floating_point<T> // gestiamo i valori di input imponendo che siano di tipo float o double
class complex_number {
	T real, imaginary;   // prende in input due valori che rappresentanto parte reale e parte immaginaria
public :
	complex_number()
		: real(0), imaginary(0)  //costruttore di default nel caso non venga passato nessun valore
	{}
		
	explicit complex_number(T r)
        : real(r), imaginary(0) // nel caso venga passato un unico valore si suppone sia un numero reale,
    {}	                        // non consideriamo il caso di un numero con sola componente immaginaria appartenendo
								// comunque quest'ultimo al campo dei nuemeri complessi
	complex_number(T r, T i)
		: real(r),imaginary(i)  // caso generale
	{}
	
	T parte_reale(void) const{
		return real;			// restituisce la parte reale del numero
	}
	
	T parte_immaginaria(void) const{
		return imaginary;		// restituisce la parte immaginaria 
	}
	complex_number <T> coniugato(void) const{
		return complex_number<T>(real, -imaginary);	//restituisce il coniugato del numero passato in input
	}
	
	T modulo(void) const {
		return sqrt(real*real + imaginary*imaginary);			// restituisce il modulo del numero complesso
	}
	complex_number <T> inverso(void)    {       // restituisce l'inverso (z -> z^-1)
		if (modulo()== 0)
		{cerr <<"non puoi fare la divisione per 0:"<<endl;}
		return complex_number<T>(real/(modulo()*modulo()), -imaginary/(modulo()*modulo()));
		//else 
		//{ cerr << "non puoi calcolare l'inverso di 0!";}
		//return 1;
	}
	
	
	
	
	complex_number& operator+=(const complex_number& other) { // somma al numero complesso in oggetto
        T x = real;											// le componenti dell' "altro" complesso , quindi
        T y = imaginary;									// esegue la somma modificando il valore passato
        T a = other.real;
        T b = other.imaginary;
        real = x+a;
        imaginary = y+b;
        return *this;
	}
	complex_number operator+(const complex_number& other) const { // esegue la somma creando una nuova variabile sum
        complex_number sum = *this;
        sum += other;
        return sum;
    }
	complex_number& operator+=(const T& other) { // somma al numero complesso passato il numero reale other, modificandone
        real += other;								// quindi solo la parte reale
        return *this;
	}
	
	complex_number operator+(const T& other) const { // esegue la somma creando una nuova variabile sum
        complex_number sum = *this;
        sum += other;
        return sum;
	}
		
	complex_number operator-() const { // restituisce l'opposto modificando ambo le componenti
        return complex_number(-real, -imaginary);
    }
	
	complex_number& operator*=(const complex_number& other) { // esegue il prodotto tra due complessi
        T x = real;											// modificando il complesso in input
        T y = imaginary;
        T a = other.real;
        T b = other.imaginary;
        real = x*a-y*b;
        imaginary = x*b+a*y;
        return *this;
	}
	complex_number operator*(const complex_number& other) const { // esegue il prodotto tra complessi creando 
        complex_number prod = *this;								// la variabile prod
        prod *= other;
        return prod;
    }
	complex_number& operator*=(const T& other) {		// esegue il prodotto tra un complesso e uno scalare (reale)
        real *=other;
		imaginary *= other;
        return *this;
	}
	
	complex_number operator*(const T& other) const { // esegue il prodotto complesso-scalare creando una nuova variabile prod
        complex_number prod = *this;
        prod *= other;
        return prod;
	}
};



template<typename T>  //rifacendosi all'operatore di somma precedentemente definito permette la commutatività dell'operazione
complex_number<T>		
operator+(const T r, const complex_number<T>& c)
{
    return c + r;
}


template<typename T>  //rifacendosi all'operatore di prodotto precedentemente definito permette la commutatività dell'operazione
complex_number<T>
operator*(const T r, const complex_number<T>& c)
{
    return c *r;
}



template<typename T> // consente l'output del numero complesso differenziando a seconda del valore della parte immaginaria
	ostream& operator<<(std::ostream& os,const complex_number<T>& c) {
		T image = c.parte_immaginaria();
		T real = c.parte_reale();
		if (real == 0 & image ==0) { os << 0;} // tratto il caso di vettore nullo
		else if (real==0 && image!=0){ // tratto il caso di numero immaginario
			if (image<0){
				if (image==-1) {os<<"-i";}
				else {os <<"-" << abs(image) << "i";} 
			}
			else{
				if (image==1) {os<<"i";}
				else {os << image << "i";}
				}
		}
		else if (real!=0 && image==0){os << real ;} // tratto il caso di numero reale
		else{
			if (image<0) {os << real << " - "<<abs(image) << "i";}
			else {os << real << " + " << image << "i";}
				
		}
		return os;
	}
