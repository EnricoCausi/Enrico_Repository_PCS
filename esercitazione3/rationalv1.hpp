#pragma once
#include <concepts>
#include <ostream>
#include <iostream>
#include <numeric>

template<typename I> requires std::integral<I>
class rational
{
I num_;
I den_;

void semplifica() {
	
	if (num_ == 0 && den_ == 0) {return;}
	
	if (den_ == 0) {
		if (num_ >0) {num_ = 1;}
		else if (num_<0) {num_ = -1;}
		return;
	}
	
	if (num_ == 0) {
		den_ = 1;
		return;
	}
	
	I mcd = std::gcd(std::abs(num_), std::abs(den_));

	num_ /= mcd;
	den_ /= mcd;


	if (den_ < 0) {
		num_ = -num_;
		den_ = -den_;
}

}

public:
    /* Costruttore di default */
    rational()
        : num_(I{0}), den_(I{1})
    {}	
    
    /* Costruttore user-defined */
    rational(const I& pnum, const I& pden)
        : num_(pnum), den_(pden)
    {
	semplifica();
	}
    
    /* Restituiscono i valori di num e dem */
    I num() const { return num_; }
    I den() const { return den_; }
	
    bool is_nan() const { return num_ == 0 && den_ == 0; }
    bool is_inf() const { return den_ == 0 && num_ != 0; }
	
/* Implementazione canonica dell'incremento */
    rational& operator+=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = 0; 
            den_ = 0;
            return *this;}

        if (is_inf() && other.is_inf()) {
            // Se hanno segno opposto, il risultato è NaN
            if ((num_ > 0 && other.num_ < 0) || (num_ < 0 && other.num_ > 0)) {
                num_ = 0; 
                den_ = 0;
            }
            return *this;
        }

        if (other.is_inf()) {
            num_ = other.num_;
            den_ = other.den_;
            return *this;
        }

        if (is_inf()) {
            return *this;
        }
        
        // Caso normale
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        semplifica();
        
        return *this;
    }	
	
    /* Implementazione canonica della somma */
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

	
    /* Implementazione canonica dell'incremento */
    rational& operator-=(const rational& other) {
        rational opposto(-other.num_, other.den_);
		*this += opposto;
		return *this;
    }	
	
    /* Implementazione canonica della somma */
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }


    /* Implementazione canonica di *= con un razionale */
    rational& operator*=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = 0; 
            den_ = 0;
            return *this;
        }

        num_ *= other.num_;
        den_ *= other.den_;
        semplifica();
        return *this;
    }
    
    /* Implementazione canonica del prodotto tra razionali */
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }
	
    rational& operator/=(const rational& other) {
		if (is_nan() || other.is_nan() || (is_inf() && other.is_inf())) {
				num_ = 0; 
				den_ = 0;
				return *this;}

        num_ *= other.den_;
        den_ *= other.num_;
        semplifica();
        return *this;
    }
    
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
	
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& rat)
{
    if (rat.is_nan()) {os << " Nan \n"; return os;}
	
	if (rat.is_inf()) {
        if (rat.num() > 0) { os << " +Inf \n"; }
        else { os << " -Inf \n"; }
        return os;
    }
	
	if (rat.den() == 1) {
		os << " " << rat.num() << " ";
		}
	else {
	os << " " << rat.num() << "/" << rat.den() << " ";
	}
    return os;
}

// NOTA: Per la gestione di Inf/NaN ho utilizzato un assistente 
// basato su Intelligenza Artificiale (Google Gemini) come supporto
// e per il debug degli errori di compilazione.
