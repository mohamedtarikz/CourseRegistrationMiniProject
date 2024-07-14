#include <bits/stdc++.h>
using namespace std;

enum Days{
    Sat,
    Sun,
    Mon,
    Tue,
    Wed,
    Thur,
    Fri
};

class Teacher{
    double rate;
    string name;
    int experience;
    Days timing;
public:
    double getRate(){
        return rate;
    }
    void setRate(double rating){
        rate = rating;
    }

    string getName(){
        return name;
    }
    void setName(string naming){
        name = naming;
    }

    int getExp(){
        return experience;
    }
    void setExp(int exp){
        experience = exp;
    }

    Days getTiming(){
        return timing;
    }
    void setTiming(Days time){
        timing = time;
    }
};

class Course{
    int price;
    vector<Teacher> teachers;
    pair<Days,Days> timing;
public:
    int getPrice(){
        return price;
    }
    void setPrice(int pricing){
        price = pricing;
    }

    void addTeacher(Teacher t){
        teachers.emplace_back(t);
    }
    void removeTeacher(string nameRem){
        auto it = remove_if(teachers.begin(),teachers.end(),[&](Teacher& teach){return teach.getName() == nameRem;});
        if(it != teachers.end())
            teachers.erase(it);
    }
    Teacher getTeacher(int idx){
        return teachers[idx];
    }

    void SetFirstDay(Days day){
        timing.first = day;
    }
    void SetSecondDay(Days day){
        timing.second = day;
    }
    Days getFirstDay(){
        return timing.first;
    }
    Days getSecondDay(){
        return timing.second;
    }
};

int main() {

    return 0;
}
