#include <bits/stdc++.h>
#include "Instructor.h"
#include "Course.h"
#include "Cart.h"
#include "System.h"
using namespace std;
using namespace course;


//initializing sample data for testing


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
