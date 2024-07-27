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
    vector<Teacher> Teachers;
    vector<string> timings;
public:
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

    Course(string ID, string NAME, int init_Subs = 0){
        id = ID;
        name = NAME;
        num_subs = init_Subs;
    }
};

class Cart{
    vector<Course> courses;
    double total_price;
public:
    double getTOTAL(){return total_price;}

    void AddCourse(Course course){
        courses.emplace_back(course);
        total_price += course.getPRICE();
    }
    void RemCourse(string id){
        auto it = find_if(courses.begin(),courses.end(),[id](Course iter){return iter.getID() == id;});
        if(it != courses.end()){
            total_price -= it->getPRICE();
            courses.erase(it);
        }
    }

    Cart(double initTotal = 0){
        total_price = initTotal;
    }
};

int main() {
    ////////////     Teachers     //////////////////
    vector<Teacher> Teachers;
    Teachers.emplace_back("T12","Samah Abd-ElWahed",4.65,5);
    Teachers.emplace_back("T01","Adel Shakal",5.0,9);
    Teachers.emplace_back("T45","Samar Shakshouka",3.8,3);
    Teachers.emplace_back("T06","Amr Elsisi",2.7,6);
    ////////////     Courses     //////////////////
    vector<Course> Courses;
    return 0;
}
