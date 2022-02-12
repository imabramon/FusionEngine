//
//  FInt.hpp
//  Fusion Engine
//
//  Created by Влад Шелопугин on 11.02.2022.
//  Copyright © 2022 Влад Шелопугин. All rights reserved.
//

#ifndef FInt_hpp
#define FInt_hpp

/*!
 *\brief Int class-wraper
 *\author imabramon
 *\version 0.1
 */

class Fint{
public:
    Fint(int i = 0);
    Fint(Fint &fint);
    ~Fint();
    
    Fint & operator +=(Fint fint);
    Fint & operator -=(Fint fint);
    Fint & operator *=(Fint fint);
    Fint & operator /=(Fint fint);
    Fint & operator %=(Fint fint);
    
    Fint operator ++();
    Fint & operator ++(int);
    Fint operator --();
    Fint & operator --(int);
    
    Fint operator +(Fint fint);
    Fint operator -(Fint fint);
    Fint operator *(Fint fint);
    Fint operator /(Fint fint);
    Fint operator %(Fint fint);
    
    bool operator ==(Fint fint);
    bool operator !=(Fint fint);
    bool operator >(Fint fint);
    bool operator >=(Fint fint);
    bool operator <(Fint fint);
    bool operator <=(Fint fint);
private:
    int m_data;
};

#endif /* FInt_hpp */
