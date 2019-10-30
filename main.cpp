#include <iostream>
#include <bits/stdc++.h>
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

void citire::citiren()
{cout<<"Introduceti n: "<<endl;
    cin>>n;
    this->v=new fractie[n];
    for(int i=0;i<n;i++)
        {cout<<"Introduceti fractia "<<i+1<<": "<<endl;
        cin>>this->v[i];
        }
}
void citire::afisaren()
{cout<<"Sunt "<<n<<" fractii:"<<endl;
for(int i=0;i<n;i++)
    cout<<"Fractia "<<i+1<<" este: "<<v[i]<<endl;


}
istream& operator >>(istream& in,fractie& fr)
{   cout << "Introduceti numaratorul:";
    in >> fr.nrt;
    cout << "Introduceti numitorul: ";
    in >> fr.nmt;
    if(fr.nmt==0){cout<<"Numitorul nu poate fi 0, reintroduceti alta valoare:"; in>>fr.nmt;}

    //if(fr.nmt<0){fr.nmt=-fr.nmt;fr.nrt=-fr.nrt;}////?
    //fr.simplificare();////?
    return in;
}
ostream& operator <<(ostream &out, const fractie &fr)
{
    if(fr.nmt==1)out<<fr.nrt;
    else out<<fr.nrt<<"/"<<fr.nmt;
    return out;
}
int cmmd(int x,int y){
int z;
if (x==0 || y==1) return 1;
if (x<0) x=-x;
if (y<0) y=-y;

    while (x!=0){
    if (y>x) {z=x;
              x=y;
              y=z;}
    x%=y;
    }
return y;
}

void fractie::simplificare(){
int x;
if (nmt<0) {nrt=-nrt;
            nmt=-nmt;
           }
if(nmt>1){x=cmmd(this->nmt,this->nrt);
          if (x>1){nrt/=x;nmt/=x;}
         }
}
fractie& fractie::operator =(const fractie& ob)
{if(this==&ob)
return *this;
else {nrt=ob.nrt;
      nmt=ob.nmt;
}
    return *this;
}


fractie operator +(const fractie& f1,const fractie& f2)
{fractie f;
if (f1.nmt==f2.nmt){f.nrt=f1.nrt+f2.nrt; f.nmt=f1.nmt;}
else {
int cmmmc,cmmdc=cmmd(f1.nmt,f2.nmt);
cmmmc=f1.nmt*f2.nmt/cmmdc;
f.nrt=f1.nrt*(cmmmc/f1.nmt)+f2.nrt*(cmmmc/f2.nmt);
f.nmt=cmmmc;
}
f.simplificare();
    return f;
}
fractie operator -(const fractie& f1,const fractie& f2)
{fractie f;
if (f1.nmt==f2.nmt){if (f1.nrt==f2.nrt)f.nrt=0;
        else {f.nrt=f1.nrt-f2.nrt; f.nmt=f1.nmt;}
                    }
else {
int cmmmc,cmmdc=cmmd(f1.nmt,f2.nmt);
cmmmc=f1.nmt*f2.nmt/cmmdc;
f.nrt=f1.nrt*(cmmmc/f1.nmt)-f2.nrt*(cmmmc/f2.nmt);
f.nmt=cmmmc;
}
f.simplificare();
    return f;
}

fractie operator *(const fractie& f1,const fractie& f2)
{fractie f;
    f.nmt=f1.nmt*f2.nmt;
    f.nrt=f1.nrt*f2.nrt;
    f.simplificare();
    return f;
}
fractie operator /(const fractie& f1,const fractie& f2)
{fractie f;
    f.nmt=f1.nmt*f2.nrt;
    f.nrt=f1.nrt*f2.nmt;
    f.simplificare();
    return f;
}

fractie operator *(const fractie& f1,int a)
{fractie f;
    f.nmt=f1.nmt;
    f.nrt=f1.nrt*a;
    f.simplificare();
    return f;
}
void Rezolvaresis(fractie &solx,fractie &soly){
fractie a1,b1,c1,a2,b2,c2,x,y,ds,dx,dy;
cout<<"Introduceti coeficientii sistemului de forma a1*x+b1*y=c1 si a2*x+b2*y=f"<<endl;
cout<<"a1: ";
cin>>a1;
cout<<"b1: ";
cin>>b1;
cout<<"c1: ";
cin>>c1;
cout<<"a2: ";
cin>>a2;
cout<<"b2: ";
cin>>b2;
cout<<"c2: ";
cin>>c2;
ds=(a1*b2)-(a2*b1);
dx=(b2*c1)-(b1*c2);
dy=(a1*c2)-(a2*c1);
if (ds.get_nrt()==0) {if (dx.get_nrt()==0)cout<<"Sistem nedeterminat";
                     else cout<<"Sistem incompatibil";
                     }
else{
     x=dx/ds;
     y=dy/ds;
     cout<<"Perechea de solutii (x,y) este: "<<x<<" "<<y<<endl;
     solx=x;
     soly=y;
    }
}

int main()
{cout<<"Constructor fara parametru, fractia a este initializata cu 0:"<<endl;
fractie a;
cout<<a<<endl;
cout<<"Constructor cu un parametru, fractia b este un numar intreg (de exemplu 3):"<<endl;
fractie b(3);
cout<<b<<endl;
cout<<"Constructor cu 2 parametri, fractia c este initializata cu un numarator si un numitor (de exemplu 3/5):"<<endl;
fractie c(3,5);
cout<<c<<endl;
cout<<"Apelare constructorul de copiere(de exemplu d va copia valoarea fractiei c):"<<endl;
fractie d(c);
cout<<d<<endl;
cout<<"Vrem sa vedem ce valoare are fractia c printr-un furnizor:"<<endl;
cout<<"-numaratorul:";
cout<<c.get_nrt()<<endl;
cout<<"-numitorul:";
cout<<c.get_nmt()<<endl;
cout<<"Vrem sa setam valoarea fractiei c:"<<endl;
cout<<"-numaratorul sa fie 2: ";
c.set_nrt(2);
cout<<c<<endl;
cout<<"-numitorul sa fie 12: ";
c.set_nmt(12);
cout<<c<<endl;
cout<<"Vremm sa simplificam fractia c:"<<endl;
c.simplificare();
cout<<c<<endl;
cout<<"Citirea si afisarea unei fracti (fr vor fi afisate exact cum au fost citite):"<<endl;
fractie e1,e2,e3;
cout<<"Introduceti o fractie de forma x/1: "<<endl;
cin>>e1;
cout<<e1<<endl;
cout<<"Introduceti o fractie de forma x/y: "<<endl;
cin>>e2;
cout<<e2<<endl;
cout<<"Introduceti o fractie de forma -x/y: "<<endl;
cin>>e3;
cout<<e3<<endl;
cout<<"Suma/diferenta/produsul/impartirea a doua fractii introduse de noi (rezultatul va fi o fractie ireductibila):"<<endl;
cout<<"Citire prima fractie:"<<endl;
fractie fs,fd,fin,fim,f1,f2;
cin>>f1;
cout<<"Citire a doua fractie:"<<endl;
cin>>f2;
fs=f1+f2;
fd=f1-f2;
fin=f1*f2;
fim=f1/f2;
cout<<"Suma: "<<fs<<endl;
cout<<"Diferenta: "<<fd<<endl;
cout<<"Inmultirea: "<<fin<<endl;
cout<<"Impartirea: "<<fim<<endl;
cout<<"Inmultirea unei fracti introduse de la tastatura cu un numar intreg x:"<<endl;
int x;
fractie g;
cout<<"Citire fractie: "<<endl;
cin>>g;
cout<<"Citire x: ";
cin>>x;
g=g*x;
cout<<"Rezultat: "<<g<<endl;
cout<<"Citirea, memorarea si afisarea a n obiecte de tip fractie,cu n introdus de la tastatura: "<<endl;
citire A;
A.citiren();
A.afisaren();
//cout<<a.get_v(1);

fractie solx,soly;
Rezolvaresis(solx,soly);


    return 0;
}
