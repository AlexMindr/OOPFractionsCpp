#include <iostream>

using namespace std;


class C{
static int x;
public:
C(){C::x++;}
~C(){C::x--;}
static int get_x(){return C::x;}
};

int C::x;
C c;
int main()
{cout<<C::get_x();
C d;
cout<<C::get_x();


{C c;
cout<<C::get_x();
}


cout<<C::get_x();
}


