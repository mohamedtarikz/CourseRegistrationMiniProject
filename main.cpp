#include <bits/stdc++.h>
using namespace std;

string day[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

class Instructor{
    //info about instructor
    string id;
    string name;
    double rating;
    int experience;
public:
    //getters and setters
    void setID(string ID){id = ID;}
    string getID(){return id;}

    void setNAME(string NAME){name = NAME;}
    string getNAME(){return name;}

    void setRATE(double RATE){rating = RATE;}
    double getRATE(){return rating;}

    void setEXP(int EXP){experience = EXP;}
    int getEXP(){return experience;}

    //class constructor
    Instructor(string ID, string NAME, double RATE, int EXP){
        id = ID;
        name = NAME;
        rating = RATE;
        experience = EXP;
    }
};
class Course{
    //info about course
    string id;
    string name;
    int num_subs;
    double price;
public:
    //vector of Instructors
    vector<Instructor> Instructors;
    //vector of timings of the course
    vector<string> timings;

    //getters and setters
    void setID(string ID){id = ID;}
    string getID(){return id;}

    void setNAME(string NAME){name = NAME;}
    string getNAME(){return name;}

    void setNUMSUBS(int NUMSUBS){num_subs = NUMSUBS;}
    int getNUMSUBS(){return num_subs;}

    void setPRICE(double PRICE){price = PRICE;}
    double getPRICE(){return price;}

    //method to add instructor
    void AddInstructor(Instructor teacher){Instructors.emplace_back(teacher);}
    //method to add a day for the course
    void AddDays(string day){timings.emplace_back(day);}

    //class constructor
    Course(string ID, string NAME, double PRICE, int init_Subs = 0){
        id = ID;
        name = NAME;
        price = PRICE;
        num_subs = init_Subs;
    }
};

//vectors for all the instructors and the courses
vector<Instructor> Instructors;
vector<Course> Courses;

//map to indicate whether a course has been bought or not
map<string,bool> taken;

class Cart{
    //vector for the courses bought
    vector<Course> courses;
    //total price for the items in the cart
    double total_price;
public:
    //method to get total
    double getTOTAL(){return total_price;}

    void AddCourse(string id){
        //check for the course in the Courses vector
        auto crs = find_if(Courses.begin(),Courses.end(),[id](Course iter){return iter.getID() == id;});
        //add the course to the cart
        courses.emplace_back(*crs);
        //add the price to the total price
        total_price += crs->getPRICE();
    }
    void RemCourse(string id){
        //check if the id given is in the cart
        auto it = find_if(courses.begin(),courses.end(),[id](Course iter){return iter.getID() == id;});
        if(it != courses.end()){//if present in the cart
            //subtract the price from the total price
            total_price -= it->getPRICE();
            //remove the course from the cart
            courses.erase(it);
        }
    }

    bool isValidInput(string id){
        //check if the given id is present in cart
        auto itr = find_if(courses.begin(),courses.end(),[id](Course course){return course.getID() == id;});
        return (itr != courses.end());
    }

    void ViewCart(){
        //view every course in the cart in the following format
        //(ID)NAME-----------------PRICE
        for (auto course:courses) {
            cout<<endl<<"("<<course.getID()<<")"<<course.getNAME()<<" ";
            for (int i = 0; i < 80 - course.getNAME().size() - course.getID().size(); ++i) {
                cout<<"-";
            }
            cout<<" "<<course.getPRICE()<<endl;
        }
        //view total price below all items
        cout<<endl<<"Total: ";
        for (int i = 0; i < 77; ++i) {
            cout<<" ";
        }
        cout<<total_price<<endl<<endl;
        cout<<"[(C)heckout]                 [(R)emove item]              [(B)ack]\n(C/R/B)\n\n";
    }

    //class constructor
    Cart(double initTotal = 0){
        total_price = initTotal;
    }
};
class System{
public:
    void ViewCourses(){//view all the courses not yet bought
        cout<<"Courses:"<<endl;
        for(auto itr:Courses){
            if(taken[itr.getID()])
                continue;
            //print info about the course
            cout<<"    ID: "<<itr.getID()<<endl;
            cout<<"    Name: "<<itr.getNAME()<<endl;
            cout<<"    Price: "<<itr.getPRICE()<<endl;
            //print the days the course is active in
            cout<<"    Days: (";
            for(int i = 0; i < itr.timings.size() - 1; i++){
                cout<<itr.timings[i]<<", ";
            }
            cout<<itr.timings[itr.timings.size()-1]<<")"<<endl;
            //print the instructors' names
            cout<<"    Instructors: (";
            for(int i = 0; i < itr.Instructors.size() - 1; i++){
                cout<<itr.Instructors[i].getNAME()<<", ";
            }
            cout<<itr.Instructors[itr.Instructors.size()-1].getNAME()<<")"<<endl;
            cout<<"---------------------------------------------------------\n";
        }
    }
    bool isValidInput(string id){
        //check if the given id is present in the courses
        auto itr = find_if(Courses.begin(),Courses.end(),[id](Course course){return course.getID() == id;});
        return (itr != Courses.end());
    }
    void ViewCertianCourse(string id){
        //find the position of the course with the given id
        auto crs = find_if(Courses.begin(),Courses.end(),[id](Course course){return course.getID() == id;});
        //print important info about it
        cout<<"NAME: "<< crs->getNAME()<<endl;
        cout<<"PRICE: "<<crs->getPRICE()<<endl;
        //print the days the course is active in
        cout<<"Days: (";
        for(int i = 0; i < crs->timings.size() - 1; i++){
            cout<<crs->timings[i]<<", ";
        }
        cout<<crs->timings[crs->timings.size()-1]<<")"<<endl;
        //print instructors' names
        cout<<"Instructors: (";
        for(int i = 0; i < crs->Instructors.size() - 1; i++){
            cout<<crs->Instructors[i].getNAME()<<", ";
        }
        cout<<crs->Instructors[crs->Instructors.size()-1].getNAME()<<")"<<endl<<endl;
        //print info about every instructor (name, experience, rating)
        for(auto teach:crs->Instructors){
            cout<<"Name: "<<teach.getNAME()<<endl;
            cout<<"Experience: "<<teach.getEXP()<<endl;
            cout<<"Rating: "<<teach.getRATE()<<endl;
            cout<<endl;
        }
        cout<<"[(P)urchase]                        [(C)ancel]"<<endl;
    }
};

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
