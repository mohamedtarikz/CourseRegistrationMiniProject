//
// Created by moham on 8/3/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_USER_H
#define COURSEREGISTRATIONMINIPROJECT_USER_H

#include "bits/stdc++.h"
//#include "System.h"
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
            exit(0);
        }
    };

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_USER_H
