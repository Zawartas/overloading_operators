#include <iostream>
#include <stdio.h>

using namespace std;

class Vector {
private:
    int x, y, z;

public:
    Vector(int a = 0, int b = 0, int c = 0): x(a), y(b), z(c){cout << "Default constructor\n";};
    Vector(const Vector &w): x(w.x), y(w.y), z(w.z){cout << "Copy constructor\n";};
    void show (){printf("%d %d %d\n",x, y, z);}
    /*-----------OVERLOADING OPERATORS-----------*/

//friend
public:
    //Vector operator+ (const Vector &a, const Vector &b){return Vector(a.x+b.x, a.y+b.y, a.z+b.z);}
    //above can not exist as we would have to do: wiktor.operator+(sth, sth), doesn't make sense
    friend Vector operator+ (const Vector &a, const Vector &b){return Vector(a.x+b.x, a.y+b.y, a.z+b.z);}
    //defined as a separate method
    Vector operator* (const Vector &b){return Vector(this->y*b.z-this->z*b.y, -(this->x*b.z-this->z*b.x), this->x*b.y-this->y*b.x);}
    friend Vector operator* (const int a, const Vector &b){return Vector(b.x*a, b.y*a, b.z*a);}
    friend ostream &operator << (ostream &stream, const Vector &b)
        {return stream << b.x << " " << b.y << " " << b.z;};
    //why reference ? cause we dont want to return a copy ? a copy of what ? we work on real data
    friend istream &operator >> (istream &stream, Vector &b)
        {return stream >> b.x >> b.y >> b.z;};
public:
    //why reference ? cause we dont want to return a copy ? a copy of what ? we work on real data
    Vector &operator += (const Vector &b){x += b.x; y += b.y; z += b.z; return *this;}
    //assignement
    Vector &operator= (const Vector &b){x = b.x; y = b.y; z = b.z; return *this;}
    //()
    Vector operator() (){cout << "operator()\n";}
};

int main (){

Vector wiktor1;
wiktor1.show();
Vector wiktor2(2, 5, -1);
wiktor2.show();
Vector wiktor3(-2, 4, -6);
wiktor3.show();
Vector wiktor4(wiktor3);
wiktor4.show();
wiktor1 = wiktor2 * wiktor3;
wiktor1.show();
wiktor1 = 3 * wiktor2;
wiktor1.show();
wiktor1 = wiktor2 * 2;
wiktor1.show();
wiktor1 = wiktor2 + wiktor3;
wiktor1.show();
wiktor1 += Vector(1, 1, 1);
wiktor1.show();
wiktor1 = wiktor2 = wiktor3;
wiktor1.show();
wiktor1();
cout << wiktor1 << endl;
cin >> wiktor1;
wiktor1.show();

return 0;
}
