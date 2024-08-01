#include <bits/stdc++.h>
#include "Instructor.h"
#include "Course.h"
#include "Cart.h"
#include "System.h"
using namespace std;
using namespace course;

string day[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

//initializing sample data for testing
void Init_Instructors(){
    //initialize instructors
    Instructors.emplace_back("T12","Samah Abd-ElWahed",4.65,5);
    Instructors.emplace_back("T01","Adel Shakal",5.0,9);
    Instructors.emplace_back("T45","Samar Shakshouka",3.8,3);
    Instructors.emplace_back("T06","Amr Elsisi",2.9,6);
    Instructors.emplace_back("T10","Alaa Mubarak",4.5,10);
}
void Init_Courses(){
    //initialize courses
    Courses.emplace_back("CS101","Introduction to Computer Science",249.99);
    Courses[0].AddInstructor(Instructors[0]);
    Courses[0].AddInstructor(Instructors[2]);
    Courses[0].AddDays(day[0]);
    Courses[0].AddDays(day[4]);
    Courses.emplace_back("IT101","Introduction to Networks",549.99);
    Courses[1].AddInstructor(Instructors[1]);
    Courses[1].AddInstructor(Instructors[2]);
    Courses[1].AddDays(day[1]);
    Courses[1].AddDays(day[3]);
    Courses.emplace_back("AI201","Learning about Neural Networks",999.99);
    Courses[2].AddInstructor(Instructors[3]);
    Courses[2].AddInstructor(Instructors[4]);
    Courses[2].AddInstructor(Instructors[0]);
    Courses[2].AddDays(day[5]);
    Courses[2].AddDays(day[6]);
    Courses.emplace_back("MA121","Partial Differential Equation",749.99);
    Courses[3].AddInstructor(Instructors[1]);
    Courses[3].AddInstructor(Instructors[4]);
    Courses[3].AddDays(day[0]);
    Courses[3].AddDays(day[2]);
}

int main() {
    ////////////     Instructors     //////////////////
    Init_Instructors();
    ////////////     Courses     //////////////////
    Init_Courses();
    ////////////     Beginning     ////////////////
    System sys;//system instance
    Cart cart;//cart instance
    string input;
    while(true){//run until checkout
        sys.ViewCourses();//view available courses
        cout << "Enter CourseID to Get More Info or enter 'cart' to go to checkout: ";
        cin >> input;
        transform(input.begin(),input.end(),input.begin(),::toupper);
        //input validation
        while(input != "CART" && !sys.isValidInput(input)){
            cout<<"INVALID INPUT!! Please enter a valid ID: ";
            cin>>input;
            transform(input.begin(),input.end(),input.begin(),::toupper);
        }
        if(input == "CART"){//to check the cart
            if(cart.getTOTAL() == 0){//if the cart is empty check if the user wants to leave or not
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
                cart.ViewCart();//view cart
                cin>>input;
                transform(input.begin(),input.end(),input.begin(),::tolower);
                //inpt validation
                while(input != "c" && input != "r" && input != "b"){
                    cout<<"INVALID INPUT!! Please enter (C/R/B): ";
                    cin>>input;
                    transform(input.begin(),input.end(),input.begin(),::tolower);
                }
                if(input == "b"){
                    continue;
                    //to cancel checkout
                }
                else if(input == "r"){//to remove an item from the cart
                    cout<<"Enter ID of the course you want to remove: ";
                    cin>>input;
                    transform(input.begin(),input.end(),input.begin(),::toupper);
                    //inpt validation
                    while(!cart.isValidInput(input)){
                        cout<<"INVALID INPUT!! Please enter the CourseID that you want to remove: ";
                        cin>>input;
                        transform(input.begin(),input.end(),input.begin(),::toupper);
                    }
                    //remove course
                    cart.RemCourse(input);
                    //declare as not bought
                    taken[input] = 0;
                    cout<<"Opertaion Complete!!"<<endl;
                }
                else{//to pay and checkout
                    cout<<"Operation Complete!!\nHave a nice day!"<<endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    break;
                }
            }
        }
        else if(sys.isValidInput(input)){
            if(taken[input]){
                //to check if the user wants to buy a course already bought
                cout<<"You have already purchased this course."<<endl<<endl;
                continue;
            }
            cout<<"\n//////////////////////////////////////////////////\n"<<endl;
            sys.ViewCertianCourse(input);//view info about a certain course
            cout<<"(P/C)\n";
            string cnfirm;
            cin>>cnfirm;
            transform(cnfirm.begin(),cnfirm.end(),cnfirm.begin(),::tolower);
            //input validation
            while(cnfirm != "p" && cnfirm != "c"){
                cout<<"INVALID INPUT!! Please enter (P/C): ";
                cin>>cnfirm;
                transform(cnfirm.begin(),cnfirm.end(),cnfirm.begin(),::tolower);
            }
            if(cnfirm == "p"){//if the user wants to purchace course
                //add course to cart
                cart.AddCourse(input);
                //declare as already bought
                taken[input] = 1;
                cout<<"Operation Complete!!"<<endl<<endl;
            }
        }
    }
    return 0;
}
