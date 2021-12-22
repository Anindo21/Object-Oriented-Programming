#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

class DayOfYear{
private:
    short unsigned dayOfYear;
    short unsigned year;
    static const int days[12];
public:
    // standard constructor
    DayOfYear(short unsigned d=1, short unsigned y=2021):
        dayOfYear(d),
        year(y)
    {}
    // overloaded constructor
    DayOfYear(int day, int month, int years):
        year(years)
    {
        switch (month)
        {
            case 1:
                dayOfYear = day;
                break;
            case 2:
                dayOfYear = days[0]+day;
                break;
            case 3:
                dayOfYear = days[1]+day;
                break;
            case 4:
                dayOfYear = days[2]+day;
                break;
            case 5:
                dayOfYear = days[3]+day;
                break;
            case 6:
                dayOfYear = days[4]+day;
                break;
            case 7:
                dayOfYear = days[5]+day;
                break;
            case 8:
                dayOfYear = days[6]+day;
                break;
            case 9:
                dayOfYear = days[7]+day;
                break;
            case 10:
                dayOfYear = days[8]+day;
                break;
            case 11:
                dayOfYear = days[9]+day;
                break;
            case 12:
                dayOfYear = days[10]+day;
                break;
        }
    }

    int get_dayOfYear(){
        return dayOfYear;
    }

    friend DayOfYear& operator++(DayOfYear& dy){
        if (dy.get_dayOfYear()==days[11]){
            dy.dayOfYear = 1;
            dy.year += 1;
        }else{
            dy.dayOfYear += 1;
        }
        return dy;
    }


    friend istream& operator>>(istream& in, DayOfYear& dy){
        int y, m, d;
        char ch;
        in>>y>>ch>>m>>ch>>d; // insert as 2021-1-2
        DayOfYear *ddyy = new DayOfYear(d, m, y);
        dy = *ddyy; // copy the pointer
        delete ddyy;
        return in;
    }
    friend ostream& operator<<(ostream& out, DayOfYear& dy){

        if (dy.get_dayOfYear()<=days[0]){
            return out<<dy.year<<"-"<<"1"<<"-"<<dy.get_dayOfYear();
        }
        else if (days[0]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[1]){
            return out<<dy.year<<"-"<<"2"<<"-"<<dy.get_dayOfYear()-days[0];
        }
        else if (days[1]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[2]){
            return out<<dy.year<<"-"<<"3"<<"-"<<dy.get_dayOfYear()-days[1];
        }
        else if (days[2]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[3]){
            return out<<dy.year<<"-"<<"4"<<"-"<<dy.get_dayOfYear()-days[2];
        }
        else if (days[3]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[4]){
            return out<<dy.year<<"-"<<"5"<<"-"<<dy.get_dayOfYear()-days[3];
        }
        else if (days[4]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[5]){
            return out<<dy.year<<"-"<<"6"<<"-"<<dy.get_dayOfYear()-days[4];
        }
        else if (days[5]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[6]){
            return out<<dy.year<<"-"<<"7"<<"-"<<dy.get_dayOfYear()-days[5];
        }
        else if (days[6]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[7]){
            return out<<dy.year<<"-"<<"8"<<"-"<<dy.get_dayOfYear()-days[6];
        }
        else if (days[7]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[8]){
            return out<<dy.year<<"-"<<"9"<<"-"<<dy.get_dayOfYear()-days[7];
        }
        else if (days[8]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[9]){
            return out<<dy.year<<"-"<<"10"<<"-"<<dy.get_dayOfYear()-days[8];
        }
        else if (days[9]<dy.get_dayOfYear() && dy.get_dayOfYear()<=days[10]){
            return out<<dy.year<<"-"<<"11"<<"-"<<dy.get_dayOfYear()-days[9];
        }
        else{
            return out<<dy.year<<"-"<<"12"<<"-"<<dy.get_dayOfYear()-days[10];
        }
    }
};

const int DayOfYear::days[] = {31,59,90,120,151,181,212,243,273,304,334,365};

class Vehicle{
private:
    const int no;
    string model;
    float price24h;
public:
    Vehicle(int n, string m, float p):
        no(n),
        model(m),
        price24h(p)
    {}

    virtual ~Vehicle(){
        cout<<"need to know what to do with this"<<endl;
    }

    int get_no(){
        return no;
    }

    string get_model(){
        return model;
    }

    float get_price(int rentDays){
        return rentDays*price24h;
    }

    virtual void print()=0; // pure virtual method
};

class Bike:public Vehicle{
public:
    Bike(int n, string m):
        Vehicle(n, m, 9.99)
    {}

    virtual void print(){
        cout<<get_no()<<": "<<get_model()<<" (Bike)"<<endl;
    }
};

class EMotorVehicle:public Vehicle{
public:
    EMotorVehicle(int n, string m, float p):
        Vehicle(n, m, p)
    {}

    virtual bool is_streetLegal()=0; //pure virtual method

    virtual void print(){
        if (is_streetLegal()==true){
            cout<<get_no()<<": "<<get_model();
        }else{
            cout<<get_no()<<": "<<get_model()<<" (not street legal)";
        }
    }
};

class EBike:public EMotorVehicle{
public:
    EBike(int n, string m, float p=29.99):
        EMotorVehicle(n, m, p)
    {}

    virtual bool is_streetLegal(){
        return true;
    }

    virtual void print(){
        EMotorVehicle::print();
        cout<<" (EBike)"<<endl;
    }
};

class EScooter:public EMotorVehicle{
private:
    bool streetLegal;
public:
    EScooter(int n, string m, float p=19.99, bool s=false):
        EMotorVehicle(n, m, p),
        streetLegal(s)
    {}

    virtual bool is_streetLegal(){
        return streetLegal;
    }

    virtual void print(){
        EMotorVehicle::print();
        cout<<" (EScooter)"<<endl;
    }
};

class Rental{
private:
    const int no;
    DayOfYear from;
    int days;
    string customer;
    static int last_no;
public:
    Rental(string c, DayOfYear f, int d=1):
        customer(c),
        from(f),
        days(d),
        no(last_no)
    {
        last_no += 1;
    }

    int get_days(){
        return days;
    }

    DayOfYear get_from(){
        return from;
    }

    DayOfYear get_until(){
        DayOfYear to = get_from();
        for(int d=0; d<get_days(); d++){
            ++to;
        }
        return to;
    }

    void print(){
        DayOfYear d = get_until();
        cout<<from<<" to "<<d<<", rental no. "<<no<<" for "<<customer<<" ";
    }
};

int Rental::last_no=1; // initialized the static variable

class Schedule{
private:
    Vehicle *vehicle;
    Rental *year[365];
    Schedule *next;

public:
    Schedule(Vehicle *v):
        vehicle(v),
        year{nullptr},
        next(nullptr)
    {}

    Vehicle* get_vehicle(){
        return vehicle;
    }

    Schedule* get_next(){
        return next;
    }

    void set_next(Schedule* n){
        next = n;
    }

    bool isFree(DayOfYear dy, int days){
        int r;
        while(days){
            r = dy.get_dayOfYear();
            if(year[r]==nullptr)
                return true;
            else
                days-=1;
        }
        return false;
    }

    float book(string personName, DayOfYear date, int days){
        if(isFree(date, days)==true){
            Rental *rents = new Rental(personName, date, days);
            int r;
            for(int d=0; d<days; d++){
                r = date.get_dayOfYear();
                year[r]=rents;
                ++date;
            }
            return vehicle->get_price(days);
        }else{
            return 0.00;
        }
    }

    void print(DayOfYear date1){
        vehicle->print();
        int d = date1.get_dayOfYear();
        for(int r=0; r<365; r++){
            if(year[d] != nullptr){
                year[d]->print();
                d += year[d]->get_days();
            }
        }
    }

    void print(){
        cout<<"SCHEDULE FOR ";
        vehicle->print();
        for(int r=0; r<365; r++){
            if(year[r] != nullptr){
                year[r]->print();
                cout<<", total: "<<vehicle->get_price(year[r]->get_days())<<" EUR"<<endl;
                r += year[r]->get_days();
            }
        }
    }
};

class Agency{
private:
    float profitPercent;
    float profit;
    Schedule *head;
    Schedule *last;
    int counts = 0; // this variable for simulation task means to choose l

protected:
    Schedule* searchFor(int s){
        Schedule* ptr = head;
        while(ptr!=nullptr){
            if(ptr->get_vehicle()->get_no()==s){
                return ptr;
            }
            ptr= ptr->get_next();
        }
        return nullptr;
    }

public:
    Agency():
        profitPercent(20),
        profit(0.00),
        head(nullptr),
        last(nullptr)
    {}

    float get_profit(){
        return profit;
    }

    void set_profitPercentage(float pp){
        profitPercent=pp;
    }

    void add(Vehicle* v){
        Schedule *ptr = new Schedule(v);

        if(head==nullptr){
            head=ptr;
            last=head;
        }
        else{
            last->set_next(ptr);
            last = last->get_next();
        }
        counts++;
    }


    bool isFree(int vehicleNr, DayOfYear date, int days){
        Schedule* ptr;
        ptr=searchFor(vehicleNr);
        if(ptr != nullptr)
            return ptr->isFree(date, days);
        else
            return false;
    }

    float book(int vehicleNr, string customer, DayOfYear date, int days){
        Schedule* ptr;
        float books;
        ptr=searchFor(vehicleNr);
        if(ptr!=nullptr){
            books = ptr->book(customer, date, days);
            profit = profit+((profitPercent/100)*books);
            return books;
        }else{
            return 0.00;
        }
    }

    int chooseVehicle(){
        int no;
        Schedule* newPtr = head;
        while(newPtr!=nullptr){
            newPtr->get_vehicle()->print();
            newPtr=newPtr->get_next();
        }
        cout<<"choose vehicle no: ";
        cin>>no;
        return no;
    }

    void print(DayOfYear date1){
        cout<<"SCHEDULE FOR "<<date1<<endl;
        Schedule *newPtr = head;
        while(newPtr!=nullptr){
            newPtr->print(date1);
            newPtr=newPtr->get_next();
        }
    }

    void print(void){
        Schedule *newPtr = head;
        while(newPtr!=nullptr){
            newPtr->print();
            newPtr=newPtr->get_next();
        }

        cout<<fixed<<setprecision(2)<<"profit: "<<get_profit()<<" EUR"<<endl;
    }
    // this class for simulation task means to choose l
    int get_counts(){
        return counts;
    }
};

int main()
{
    // this static variable for city1, city2, trekky1,......
    static int var1=0;
    static int var2=0;
    static int var3=0;
    static int customer=0;
    char choose;
    static int carNo=1; // initializes the constant car model number

    DayOfYear today, tomorrow, initial;
    tomorrow=++initial;
    Agency agency;
    Vehicle *vehicle;

    cout<<"SIMPLIFIED SIMULATION OF A RENTAL AGENCY"<<endl;
    cout<<"============================================="<<endl;

    while(true){
        cout<<"----------------------------------------------"<<endl;
        cout<<"MENUE"<<endl;
        cout<<"A end of simulation"<<endl
            <<"B set new simulation date"<<endl
            <<"C new rental manually"<<endl
            <<"D print rental of today "<<today<<endl
            <<"E print rental of tomorrow "<<tomorrow<<endl
            <<"F print all rentals"<<endl
            <<"G print agency profit percent"<<endl
            <<"H set agency profit percent"<<endl
            <<"I add bikes"<<endl
            <<"J add E-bikes"<<endl
            <<"K add E-scooters"<<endl
            <<"L new rental simulation"<<endl;
        cout<<"your choice: ";
        cin>>choose;

        if(choose=='a')
            break;

        if(choose=='b'){
            DayOfYear date;
            cout<<"input date of today: ";
            cin>>date;
            today = date;
            tomorrow = ++date;
        }
        if(choose=='c'){
            int vehicleNr;
            DayOfYear date;
            int days;
            string name;
            float price;

            vehicleNr=agency.chooseVehicle();
            cout<<"day of rental: ";
            cin>>date;
            cout<<"number of days: " ;
            cin>>days;
            if(agency.isFree(vehicleNr, date, days)==true){
                cout<<"input data vehicle renter name: ";
                cin>>name;

                price=agency.book(vehicleNr, name, date, days);
                if(price>=0){
                    cout<<"booked, price for this rental: "<<price<<" EUR"<<endl;
                }
            }else{
                cout<<"sorry vehicle already booked"<<endl;
            }
        }
        if(choose=='d'){
            agency.print(today);
        }
        if(choose=='e'){
            agency.print(tomorrow);
        }
        if(choose=='f'){
            agency.print();
        }
        if(choose=='g'){
            cout<<"agency profit: "<<agency.get_profit()<<" EUR"<<endl;
        }
        if(choose=='h'){
            float ppercent;
            cout<<"agency profit percent: ";
            cin>>ppercent;
            agency.set_profitPercentage(ppercent);
        }
        if(choose=='i'){
            int bikes;
            string bikeName;

            cout<<"how many Bikes in this simulation? ";
            cin>>bikes;
            for(int i=0; i<bikes; i++){
                bikeName = "City" + to_string(++var1); // for making city1, city2, .....
                vehicle = new Bike(carNo, bikeName);
                agency.add(vehicle);
                carNo++;
            }
        }
        if(choose=='j'){
            int ebikes;
            string ebikeName;

            cout<<"how many EBikes in this simulation? ";
            cin>>ebikes;
            for(int i=0; i<ebikes; i++){
                ebikeName = "Trekky" + to_string(++var2); // for making trekky1, trekky2, .....
                vehicle = new EBike(carNo, ebikeName);
                agency.add(vehicle);
                carNo++;
            }
        }
        if(choose=='k'){
            int escooters;
            string  escooterName;

            cout<<"how many EScooters in this simulation? ";
            cin>>escooters;
            for(int i=0; i<escooters; i++){
                escooterName = "Scooty" + to_string(++var3); // for making Scooty1, Scooty2, .....
                vehicle = new EScooter(carNo, escooterName);
                agency.add(vehicle);
                carNo++;
            }
        }
        if(choose=='l'){
            int vehiceNr;
            int date;
            int days;
            string customerName;
            int reservation;

            cout<<"how many reservations to simulate? ";
            cin>>reservation;

            for(int s=0; s<reservation; s++){
                vehiceNr = 1+(rand()%agency.get_counts());
                date = 1+(rand()%365);
                days = 1+(rand()%7);
                DayOfYear d(date, 2021);
                customerName = "customer"+to_string(++customer);

                cout<<"rental vehicle "<<vehiceNr<<" from "<<d<<" for "<<days<<" days";
                if(agency.isFree(vehiceNr, d, days)==true){
                    cout<<"\n";
                    agency.book(vehiceNr, customerName, d, days);
                }else{
                cout<<" sorry vehicle already booked"<<endl;
                }
            }
        }
    }
    return 0;
}
