//
// Created by moham on 8/1/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_INSTRUCTOR_H
#define COURSEREGISTRATIONMINIPROJECT_INSTRUCTOR_H

#include "bits/stdc++.h"
#include "User.h"
using namespace std;

namespace course{
    class Instructor: public User{
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

        void welcome() override{
            cout<<"Hello...You are signed in as Instructor!"<<endl;
        }

        virtual void resign(string id) = 0;
        virtual void AskForRaise() = 0;
        //class constructor
        Instructor(string ID, string NAME, double RATE, int EXP){
            id = ID;
            name = NAME;
            rating = RATE;
            experience = EXP;
        }
    };

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_INSTRUCTOR_H
