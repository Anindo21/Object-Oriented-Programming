/**********************************************************************
Matr.-Nr:                     ... 3077415
Nachname/Surname:             ... Hoque
Vorname/Given name:           ... A K M Rezaul
Uni-Email:                    ... a.hoque@stud.uni-due.de
Studiengang/Course of studis: ... Software Engineering(ISE)
**********************************************************************/

#include <iostream>
#include<cmath>
using namespace std;

const double PI=3.141592653589793238463;

class Circle{

private:
    double x,y,radius;

public:
    void set_radius (double rd);
    double get_radius ();
    void set_center (double a,double b);
    void print();
    double get_area();
    double get_diameter();
    void set_diameter(double d);
    bool isAUnitCircle();

};

void Circle::set_radius (double rd){
        radius=rd;
    }
double Circle::get_radius (){
        return radius;
    }
void Circle::set_center (double a,double b){
        x=a;
        y=b;
    }

void Circle::print(){

    cout<<"center=("<<x<<","<<y<<"), radius="<<get_radius()<<" diameter="<<get_diameter()
    <<" area="<<get_area()<<endl;
}
double Circle::get_area(){
    double res;
    res = get_radius();
    return PI*pow(res,2);
}
double Circle::get_diameter(){
    return (2*get_radius());
}
void Circle::set_diameter(double d){
    radius=d/2;
}
bool Circle::isAUnitCircle(){
    return get_radius()==1;
}

int main (void)
{

    Circle c1 ,*c2;
    c1.set_center(2.1,0.5);
    c1.set_radius(1.3);


    c2=new Circle;
    c2->set_center(-3.5,1.8);
    c2->set_radius(3.7);

    cout<<"circle data c1:";
    c1.print();
    cout<<"circle data c2:";
    c2->print();

    c1.set_diameter(c2->get_radius());

    c2->set_diameter(c1.get_radius());

    cout<<"modified circle data c1:";
    c1.print();
    cout<<"modified circle data c2:";
    c2->print();
    if (c1.isAUnitCircle()==true)
        cout<<"c1 is a unit circle"<<endl;

    else
        cout<<"c1 is not a unit circle"<<endl;

    if (c2->isAUnitCircle()==true)
        cout<<"c2 is a unit circle"<<endl;
    else
        cout<<"c2 is not a unit circle"<<endl;
    return 0;
}
