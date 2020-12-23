/**********************************************************************
Matr.-Nr:                      3077415
Nachname/Surname:              Hoque
Vorname/Given name:            A K M Rezaul
Uni-Email:                     a.hoque@stud.uni-due.de
Studiengang/Course of studis:  Software Engineering (ISE)
**********************************************************************/
#include<iostream>
#include<iomanip> // for setw() method
using namespace std;

struct point{
    double x,y,z;
};

struct sphere{
    point *center;
    double radius;
};

void print(sphere *spr){
    cout<<fixed<<setprecision(2); // for 2 digit decimal points
    cout<<setw(11)<<spr->center->x<<setw(11)<<spr->center->y<<setw(11)<<spr->center->z<<setw(11)<<spr->radius<<endl;
}

void print(sphere *arr[], int elem){
    for(int i=0; i<elem; i++){
        print(arr[i]);
    }
}

int main(void){
    int space = 5;
    struct sphere *c[space];

    for (int j = 0; j<space; j++){
        c[j] = new sphere;
        c[j]->center = new point;

        c[j]->radius = j+1;

        cout<<"input center sphere: "<<c[j]->radius<<endl;
        cout<<"input center x coordinate: ";
        cin>>c[j]->center->x;
        cout<<"input center y coordinate: ";
        cin>>c[j]->center->y;
        cout<<"input center z coordinate: ";
        cin>>c[j]->center->z;
    }

    print(c, space);

    for(int z = 0; z<space; z++){
        delete c[z]->center;
        delete c[z];
    }
    return 0;
}
