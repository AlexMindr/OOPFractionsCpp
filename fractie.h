#ifndef FRACTIE_H_INCLUDED
#define FRACTIE_H_INCLUDED
#include <iostream>
using namespace std;
class fractie{
int nrt,nmt;

public:
//setat
void set_nrt(int nrt){this->nrt=nrt;}
void set_nmt(int nmt){this->nmt=nmt;}
//furnizat
int get_nrt(){return nrt;}
int get_nmt(){return nmt;}
//constructor
fractie(){nrt=0;nmt=1;
}
fractie(int x){
this->nrt=x;
this->nmt=1;
}
fractie(int x,int y)
{this->nrt=x;
this->nmt=y;
}
//copy constructor
fractie (const fractie &ob)
{nrt=ob.nrt;
nmt=ob.nmt;
}
//simplificare fractie
void simplificare();
//citire cin>>/operator>>
friend istream& operator >>(istream&,fractie&);
//afisare cout<</operator<<
friend ostream& operator <<(ostream&, const fractie&);
//operator =
fractie& operator =(const fractie&);
//destructor
~fractie(){}//cout<<endl<<"Destructor"<<endl;}
//adunare +
friend fractie operator +(const fractie&,const fractie&);
//scadere -
friend fractie operator -(const fractie&,const fractie&);
//inmultire *
friend fractie operator *(const fractie&,const fractie&);
//impartire /
friend fractie operator /(const fractie&,const fractie&);
//inmultire cu intreg*
friend fractie operator *(const fractie&,int);
//pentru citirea,memorarea si afisarea a n obiecte
friend class citire;

};
class citire {
int n;
fractie *v;
public:
fractie get_v(int i){return v[i];}
void citiren();
void afisaren();
};

#endif // FRACTIE_H_INCLUDED
