#include <iostream>
using namespace std;

struct vector3d { double x,y,z ;};

ostream& operator<< (
      ostream& out, vector3d& v
                     )
{
    out<< "("<<v.x<<","<<v.y<<","<<v.z<<")";
    return out;
}
istream& operator>>(
        istream& in, vector3d& v
        )

{   in >>v.x>>v.y>>v.z;
    return in;
}
vector3d operator+ (
                    vector3d& v1,vector3d& v2)
{
    vector3d sum;
    sum.x= v1.x+v2.x;
    sum.y=v1.y+v2.y;
    sum.z=v1.z+v2.z;
    return sum;
}
int main()
{
vector3d v1, v2, v3;
cout << "input v1: ";
cin >> v1;
cout << "input v2: ";
cin >> v2;
v3= v1+v2;
cout << v1<<"+"<<v2<< "="<<v3;
}
