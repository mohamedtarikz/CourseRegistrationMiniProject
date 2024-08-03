//
// Created by moham on 8/3/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_USER_H
#define COURSEREGISTRATIONMINIPROJECT_USER_H

#include "bits/stdc++.h"
#include "CourseMain.h"
using namespace std;

namespace course {

    class User {
    public:
        virtual void welcome(){
            cout<<"Hello User!"<<endl;
        }

        void signout(){
            cout<<"Shutting Down..."<<endl<<endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    };

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_USER_H
