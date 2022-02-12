#include "FInt.hpp"

Fint::Fint(int i): m_data(i){
    
}

Fint::Fint(Fint &fint): m_data(fint.m_data){
    
}

Fint::~Fint(){
    
}

Fint & Fint::operator +=(Fint fint){
    m_data += fint.m_data;
    return *this;
}

Fint & Fint::operator -=(Fint fint){
    m_data -= fint.m_data;
    return *this;
}

Fint & Fint::operator *=(Fint fint){
    m_data *= fint.m_data;
    return *this;
}

Fint & Fint::operator /=(Fint fint){
    m_data /= fint.m_data;
    return *this;
}

Fint & Fint::operator %=(Fint fint){
    m_data %= fint.m_data;
    return *this;
}

Fint Fint::operator ++(){
    Fint temp(m_data);
    m_data++;
    return temp;
}

Fint & Fint::operator ++(int){
    m_data++;
    return *this;
}

Fint Fint::operator --(){
    Fint temp(m_data);
    m_data--;
    return temp;
}

Fint & Fint::operator --(int){
    m_data++;
    return *this;
}

Fint Fint::operator +(Fint fint){
    Fint temp(m_data);
    temp += fint;
    return fint;
}

Fint Fint::operator -(Fint fint){
    Fint temp(m_data);
    temp -= fint;
    return fint;
}

Fint Fint::operator *(Fint fint){
    Fint temp(m_data);
    temp *= fint;
    return fint;
}

Fint Fint::operator /(Fint fint){
    Fint temp(m_data);
    temp /= fint;
    return fint;
}

Fint Fint::operator %(Fint fint){
    Fint temp(m_data);
    temp %= fint;
    return fint;
}

bool Fint::operator ==(Fint fint){
    return m_data == fint.m_data;
}

bool Fint::operator !=(Fint fint){
    return m_data != fint.m_data;
}

bool Fint::operator >(Fint fint){
    return m_data > fint.m_data;
}

bool Fint::operator >=(Fint fint){
    return m_data >= fint.m_data;
}

bool Fint::operator <(Fint fint){
    return m_data < fint.m_data;
}

bool Fint::operator <=(Fint fint){
    return m_data <= fint.m_data;
}
