#include <bits/stdc++.h>
using namespace std;

string day[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

class Teacher{
    string id;
    string name;
    double rating;
    int experience;
public:
    void setID(string ID){id = ID;}
    string getID(){return id;}

    void setNAME(string NAME){name = NAME;}
    string getNAME(){return name;}

    void setRATE(double RATE){rating = RATE;}
    double getRATE(){return rating;}

    void setEXP(int EXP){experience = EXP;}
    int getEXP(){return experience;}

    Teacher(string ID, string NAME, double RATE, int EXP){
        id = ID;
        name = NAME;
        rating = RATE;
        experience = EXP;
    }
};

class Course{
    string id;
    string name;
    int num_subs;
    double price;
public:
    vector<Teacher> Teachers;
    vector<string> timings;

    void setID(string ID){id = ID;}
    string getID(){return id;}

    void setNAME(string NAME){name = NAME;}
    string getNAME(){return name;}

    void setNUMSUBS(int NUMSUBS){num_subs = NUMSUBS;}
    int getNUMSUBS(){return num_subs;}

    void setPRICE(double PRICE){price = PRICE;}
    double getPRICE(){return price;}

    void AddTeacher(Teacher teacher){Teachers.emplace_back(teacher);}

    void AddDays(string day){timings.emplace_back(day);}

    Course(string ID, string NAME, double PRICE, int init_Subs = 0){
        id = ID;
        name = NAME;
        price = PRICE;
        num_subs = init_Subs;
    }
};

vector<Teacher> Teachers;
vector<Course> Courses;

map<string,bool> taken;

class Cart{
    vector<Course> courses;
    double total_price;
public:
    double getTOTAL(){return total_price;}

    void AddCourse(string id){
        auto crs = find_if(Courses.begin(),Courses.end(),[id](Course iter){return iter.getID() == id;});
        courses.emplace_back(*crs);
        total_price += crs->getPRICE();
    }
    void RemCourse(string id){
        auto it = find_if(courses.begin(),courses.end(),[id](Course iter){return iter.getID() == id;});
        if(it != courses.end()){
            total_price -= it->getPRICE();
            courses.erase(it);
        }
    }

    bool isValidInput(string id){
        auto itr = find_if(courses.begin(),courses.end(),[id](Course course){return course.getID() == id;});
        return (itr != courses.end());
    }

    void ViewCart(){
        for (auto course:courses) {
            cout<<endl<<"("<<course.getID()<<")"<<course.getNAME()<<" ";
            for (int i = 0; i < 80 - course.getNAME().size() - course.getID().size(); ++i) {
                cout<<"-";
            }
            cout<<" "<<course.getPRICE()<<endl;
        }
        cout<<endl<<"Total: ";
        for (int i = 0; i < 77; ++i) {
            cout<<" ";
        }
        cout<<total_price<<endl<<endl;
        cout<<"[(C)heckout]                 [(R)emove item]              [(B)ack]\n(C/R/B)\n\n";
    }

    Cart(double initTotal = 0){
        total_price = initTotal;
    }
};

class System{
public:
    void ViewCourses(){
        cout<<"Courses:"<<endl;
        for(auto itr:Courses){
            if(taken[itr.getID()])
                continue;
            cout<<"    ID: "<<itr.getID()<<endl;
            cout<<"    Name: "<<itr.getNAME()<<endl;
            cout<<"    Price: "<<itr.getPRICE()<<endl;
            cout<<"    Days: (";
            for(int i = 0; i < itr.timings.size() - 1; i++){
                cout<<itr.timings[i]<<", ";
            }
            cout<<itr.timings[itr.timings.size()-1]<<")"<<endl;
            cout<<"    Teachers: (";
            for(int i = 0; i < itr.Teachers.size() - 1; i++){
                cout<<itr.Teachers[i].getNAME()<<", ";
            }
            cout<<itr.Teachers[itr.Teachers.size()-1].getNAME()<<")"<<endl;
            cout<<"---------------------------------------------------------\n";
        }
    }
    bool isValidInput(string id){
        auto itr = find_if(Courses.begin(),Courses.end(),[id](Course course){return course.getID() == id;});
        return (itr != Courses.end());
    }
    void ViewCertianCourse(string id){
        auto crs = find_if(Courses.begin(),Courses.end(),[id](Course course){return course.getID() == id;});
        cout<<"NAME: "<< crs->getNAME()<<endl;
        cout<<"PRICE: "<<crs->getPRICE()<<endl;
        cout<<"Days: (";
        for(int i = 0; i < crs->timings.size() - 1; i++){
            cout<<crs->timings[i]<<", ";
        }
        cout<<crs->timings[crs->timings.size()-1]<<")"<<endl;
        cout<<"Teachers: (";
        for(int i = 0; i < crs->Teachers.size() - 1; i++){
            cout<<crs->Teachers[i].getNAME()<<", ";
        }
        cout<<crs->Teachers[crs->Teachers.size()-1].getNAME()<<")"<<endl<<endl;
        for(auto teach:crs->Teachers){
            cout<<"Name: "<<teach.getNAME()<<endl;
            cout<<"Experience: "<<teach.getEXP()<<endl;
            cout<<"Rating: "<<teach.getRATE()<<endl;
            cout<<endl;
        }
        cout<<"[(P)urchase]                        [(C)ancel]"<<endl;
    }
};

void Init_Teachers(){
    Teachers.emplace_back("T12","Samah Abd-ElWahed",4.65,5);
    Teachers.emplace_back("T01","Adel Shakal",5.0,9);
    Teachers.emplace_back("T45","Samar Shakshouka",3.8,3);
    Teachers.emplace_back("T06","Amr Elsisi",2.9,6);
    Teachers.emplace_back("T10","Alaa Mubarak",4.5,10);
}
void Init_Courses(){
    Courses.emplace_back("CS101","Introduction to Computer Science",249.99);
    Courses[0].AddTeacher(Teachers[0]);
    Courses[0].AddTeacher(Teachers[2]);
    Courses[0].AddDays(day[0]);
    Courses[0].AddDays(day[4]);
    Courses.emplace_back("IT101","Introduction to Networks",549.99);
    Courses[1].AddTeacher(Teachers[1]);
    Courses[1].AddTeacher(Teachers[2]);
    Courses[1].AddDays(day[1]);
    Courses[1].AddDays(day[3]);
    Courses.emplace_back("AI201","Learning about Neural Networks",999.99);
    Courses[2].AddTeacher(Teachers[3]);
    Courses[2].AddTeacher(Teachers[4]);
    Courses[2].AddTeacher(Teachers[0]);
    Courses[2].AddDays(day[5]);
    Courses[2].AddDays(day[6]);
    Courses.emplace_back("MA121","Partial Differential Equation",749.99);
    Courses[3].AddTeacher(Teachers[1]);
    Courses[3].AddTeacher(Teachers[4]);
    Courses[3].AddDays(day[0]);
    Courses[3].AddDays(day[2]);
}

int main() {
    ////////////     Teachers     //////////////////
    Init_Teachers();
    ////////////     Courses     //////////////////
    Init_Courses();
    ////////////     Beginning     ////////////////
    System sys;
    Cart cart;
    string input;
    while(true){
        sys.ViewCourses();
        cout << "Enter CourseID to Get More Info or enter 'cart' to go to checkout: ";
        cin >> input;
        transform(input.begin(),input.end(),input.begin(),::toupper);
        while(input != "CART" && !sys.isValidInput(input)){
            cout<<"INVALID INPUT!! Please enter a valid ID: ";
            cin>>input;
            transform(input.begin(),input.end(),input.begin(),::toupper);
        }
        if(input == "CART"){
            if(cart.getTOTAL() == 0){
                cout<<"You didn't purchase anything, are you sure you want to leave?(Y/N): ";
                cin>>input;
                transform(input.begin(),input.end(),input.begin(),::tolower);
                while(input != "y" && input != "n"){
                    cout<<"INVALID INPUT!! Please enter (Y/N): ";
                    cin>>input;
                    transform(input.begin(),input.end(),input.begin(),::tolower);
                }
                if(input == "y"){
                    cout<<"Good Bye!"<<endl;
                    break;
                }
                else{
                    cout<<"Welcome back!"<<endl;
                    continue;
                }
            }
            else{
                cart.ViewCart();
                cin>>input;
                transform(input.begin(),input.end(),input.begin(),::tolower);
                while(input != "c" && input != "r" && input != "b"){
                    cout<<"INVALID INPUT!! Please enter (C/R/B): ";
                    cin>>input;
                    transform(input.begin(),input.end(),input.begin(),::tolower);
                }
                if(input == "b"){
                    continue;
                }
                else if(input == "r"){
                    cout<<"Enter ID of the course you want to remove: ";
                    cin>>input;
                    transform(input.begin(),input.end(),input.begin(),::toupper);
                    while(!cart.isValidInput(input)){
                        cout<<"INVALID INPUT!! Please enter the CourseID that you want to remove: ";
                        cin>>input;
                        transform(input.begin(),input.end(),input.begin(),::toupper);
                    }
                    cart.RemCourse(input);
                    taken[input] = 0;
                    cout<<"Opertaion Complete!!"<<endl;
                }
                else{
                    cout<<"Operation Complete!!\nHave a nice day!"<<endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    break;
                }
            }
        }
        else if(sys.isValidInput(input)){
            if(taken[input]){
                cout<<"You have already purchased this course."<<endl<<endl;
                continue;
            }
            cout<<"\n//////////////////////////////////////////////////\n"<<endl;
            sys.ViewCertianCourse(input);
            cout<<"(P/C)\n";
            string cnfirm;
            cin>>cnfirm;
            transform(cnfirm.begin(),cnfirm.end(),cnfirm.begin(),::tolower);
            while(cnfirm != "p" && cnfirm != "c"){
                cout<<"INVALID INPUT!! Please enter (P/C): ";
                cin>>cnfirm;
                transform(cnfirm.begin(),cnfirm.end(),cnfirm.begin(),::tolower);
            }
            if(cnfirm == "p"){
                cart.AddCourse(input);
                taken[input] = 1;
                cout<<"Operation Complete!!"<<endl<<endl;
            }
        }
    }
    return 0;
}
