#include <bits/stdc++.h>
#include "System.h"
#include "Cart.h"
#include "Manager.h"
using namespace std;
using namespace course;

void ManagerUI(Manager& manager, System& sys){
    while(true){
        cout<<endl;
        cout<<"1- Add an Instructor"<<endl;
        cout<<"2- Add a new Course"<<endl;
        cout<<"3- Add Instructor to Course"<<endl;
        cout<<"4- Print ALL Courses Info"<<endl;
        cout<<"5- Sign out"<<endl;
        cout<<"Enter (1,2,3,4,5): ";
        string choice;
        getline(cin,choice,'\n');
        if(choice.size() > 1 || choice[0] < '1' || choice[0] > '5'){
            cout<<"INVALID INPUT!!\n";
            continue;
        }
        if(choice == "1"){
            string ID = to_string(++numInstructor),name;
            double rating;
            int exp;
            cout<<"Name: ";
            getline(cin,name,'\n');
            cout<<"Rating: ";
            cin>>rating;
            cout<<"Experience: ";
            cin>>exp;
            manager.AddInstructor(ID,name,rating,exp);
            cin.ignore();
        }
        else if(choice == "2"){
            string ID = to_string(++numCourses),name;
            double price;
            cout<<"Name: ";
            getline(cin,name,'\n');
            cout<<"Price: ";
            cin>>price;
            manager.AddCourse(ID,name,price);
            cout<<endl;
            int numIns;
            cout<<"Number of Instructors: ";
            cin>>numIns;
            string ins;
            cin.ignore();
            for (int i = 0; i < numIns; ++i) {
                cout<<"Enter InstructorID: ";
                getline(cin,ins,'\n');
                if(!manager.AddInstructorToCourse(ins,ID))
                    i--;
            }
            int numDays;
            cout<<"Number of Days: ";
            cin>>numDays;
            string day;
            cin.ignore();
            for (int i = 0; i < numDays; ++i) {
                cout<<"Enter Day for the Course: ";
                getline(cin,day,'\n');
                if(!manager.AddDayToCourse(ID,day))
                    i--;
            }
        }
        else if(choice == "3"){
            cout<<"Enter InstructorID: ";
            string IID;
            getline(cin,IID);
            if(!sys.CheckForInstructor(IID)){
                cout<<"INVALID InstructorID!!"<<endl<<endl;
                continue;
            }
            cout<<"Enter CourseID: ";
            string CID;
            getline(cin,CID);
            if(!sys.CheckForCourse(CID)){
                cout<<"INVALID CourseID!!"<<endl<<endl;
            }
            manager.AddInstructorToCourse(IID,CID);
            cout<<"Operation Complete!"<<endl<<endl;
        }
        else if(choice == "4"){
            sys.ViewCourses();
        }
        else{
            manager.signout();
            break;
        }
    }
}
void NormalUI(User& user, System& sys, Cart& cart){
    user.welcome();
    while(true){
        sys.ViewCourses();
        cout<<"Enter CourseID to show more info or 'cart' to go check the cart: ";
        string choice;
        getline(cin,choice);
        transform(choice.begin(),choice.end(),choice.begin(),::tolower);
        if(choice != "cart" && !sys.CheckForCourse(choice)){
            cout<<"INVALID INPUT!!"<<endl;
            continue;
        }
        if(sys.CheckForCourse(choice)){
            sys.ViewCertianCourse(choice);
            string isPurchace;
            getline(cin,isPurchace);
            transform(isPurchace.begin(),isPurchace.end(),isPurchace.begin(),::tolower);
            while(isPurchace != "p" && isPurchace != "c"){
                cout<<"INVALID INPUT!! Please enter (P/C): ";
                getline(cin,isPurchace);
                transform(isPurchace.begin(),isPurchace.end(),isPurchace.begin(),::tolower);
            }
            if(isPurchace == "p"){
                cart.AddCourse(choice);
                taken[choice] = true;
                cout<<"Operation Complete!"<<endl<<endl;
            }
        }
        else{
            cart.ViewCart();
            getline(cin,choice);
            transform(choice.begin(),choice.end(),choice.begin(),::tolower);
            while(choice != "c" && choice != "r" && choice != "b"){
                cout<<"INVALID INPUT!! Please enter(C/R/B): ";
                getline(cin,choice);
                transform(choice.begin(),choice.end(),choice.begin(),::tolower);
            }
            if(choice == "r"){
                cout<<"Enter ID of the course you want to remove: ";
                getline(cin,choice);
                while(!cart.isValidInput(choice)){
                    cout<<"INVALID INPUT!! Please enter a valid CourseID: ";
                    getline(cin,choice);
                }
                cart.RemCourse(choice);
                taken[choice] = false;
            }
            else if(choice == "c"){
                cout<<"Operation Complete!!\n";
                cout<<"Have a nice Day!!\n\n";
                user.signout();
                break;
            }
        }
    }
}
void InstructorUI(Instructor*& instructor, System& sys){
    instructor->welcome();
    cout<<"Please Enter your ID: ";
    string ID;
    getline(cin,ID);
    while(!sys.CheckForInstructor(ID)){
        cout<<"No Such InstructorID in System!! Please enter valid ID: ";
        getline(cin,ID);
    }
    cout<<"1- Request Resignation."<<endl;
    cout<<"2- Request Raise."<<endl;
    cout<<"3- Sign out."<<endl;
    cout<<"Enter(1,2,3): ";
    string choice;
    getline(cin,choice);
    while(choice.size() > 1 || choice[0] < '1' || choice[0] > '3'){
        cout<<"INVALID INPUT!! Please Enter(1,2,3): ";
        getline(cin,choice);
    }
    if(choice == "1"){
        instructor->resign();
    }
    else if(choice == "2"){
        instructor->AskForRaise();
    }
    else{
        instructor->signout();
    }
}

int main() {
    System sys;
    sys.InitInstructors();
    sys.InitCourses();
    while(true) {
        cout << "Are you a:\n";
        cout << "1- Manager." << endl;
        cout << "2- Normal User." << endl;
        cout << "3- Instructor." << endl;
        cout << "4- Shut Down." << endl;
        cout<<"Enter(1,2,3,4): ";
        string choice;
        getline(cin,choice);

        if(choice == "1"){
            Manager manager;
            ManagerUI(manager,sys);
        }
        else if(choice == "2"){
            User user;
            Cart* cart = new Cart();
            taken.clear();
            NormalUI(user,sys,*cart);
            delete cart;
        }
        else if(choice == "3"){
            Instructor* instructor;
            InstructorUI(instructor,sys);
        }
        else if(choice == "4"){
            cout<<"Good Bye!"<<endl;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }
        else{
            cout<<"INVALID INPUT!!\n\n";
        }
    }
    return 0;
}
