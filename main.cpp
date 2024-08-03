#include <bits/stdc++.h>
#include "System.h"
#include "Cart.h"
#include "Manager.h"
using namespace std;
using namespace course;

void ManagerFunction(Manager manager, System sys){
    int idI = 1;
    int idC = 1;
    while(true){
        cout<<"1- Add an Instructor"<<endl;
        cout<<"2- Add a new Course"<<endl;
        cout<<"3- Print ALL Courses Info"<<endl;
        cout<<"4- Sign out"<<endl;
        cout<<"Enter (1,2,3,4): ";
        string choice;
        getline(cin,choice,'\n');
        if(choice.size() > 1 || choice[0] < '1' || choice[0] > '6'){
            cout<<"INVALID INPUT!!\n";
            continue;
        }
        if(choice == "1"){
            string ID = to_string(idI),name;
            double rating;
            int exp;
            cout<<"Name: ";
            getline(cin,name,'\n');
            cout<<"Rating: ";
            cin>>rating;
            cout<<"Experience: ";
            cin>>exp;
            manager.AddInstructor(ID,name,rating,exp);
            idI++;
            cin.ignore();
        }
        else if(choice == "2"){
            string ID = to_string(idC),name;
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
            idC++;
        }
        else if(choice == "3"){
            sys.ViewCourses();
        }
        else{
            manager.signout();
            break;
        }
    }
}

int main() {
    Init_Days();
    Manager manager;
    System sys;
    ManagerFunction(manager, sys);
    return 0;
}
