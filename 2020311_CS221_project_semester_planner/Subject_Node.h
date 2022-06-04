#pragma once

#include <iostream>
#include <fstream> // To Open and Manipulte Files
#include <string>
#include <sstream>  //to use String Stream (To split strings into words)
#include "SuperVector.h"

using namespace std;

class Subject_Node
{

protected:
    string CODE;
    int SEMESTER_NO;
    int CREDITS;

    int EASE;
    bool MODIFIABLE;
    int priority;
    ;

public:
    long double GP;

    SuperVector<string> CHILDREN;

    bool get_mod()
    {

        return MODIFIABLE;
    }

    int get_credit()
    {

        return CREDITS;
    }

    long double get_gp()
    {

        return GP;
    }

    int get_priority()
    {

        return priority;
    }

    string get_code()
    {

        return CODE;
    }

    int get_sem()
    {

        return SEMESTER_NO;
    }

    void set_gp()
    {

        cout << "Enter GP for " << get_code() << " Course : ";
        cin >> GP;
        MODIFIABLE = false;
    }

    Subject_Node()
    {

        CODE = "";
        SEMESTER_NO = 0;
        CREDITS = 0;
        GP = 0.00;
        EASE = 0;
        MODIFIABLE = false;
        priority = 0;
    }

    Subject_Node(SuperVector<string> V)
    {

        this->CODE = V[0];
        this->SEMESTER_NO = stoi(V[1]);
        this->CREDITS = stoi(V[2]);
        this->EASE = stoi(V[3]);
        GP = 1.00;
        priority = EASE + CREDITS;

        if (V[4] == "F")
        {

            this->MODIFIABLE = false;
        }
        else
        {

            this->MODIFIABLE = true;
        }

        for (int i = 5; i < V.size(); i++)
        {

            if (V[i] == "")
            {

                break;
            }

            CHILDREN.push_back(V[i]);
        }
    }

    void grade_inc()
    {

        if (MODIFIABLE == true)
        {

            if (GP >= 0.00 && GP <= 4.00)
            {

                GP = GP + 0.33;

                if (GP > 4.00)
                {
                    GP = 4.00;
                }
            }
        }
    }

    void print_node()
    {

        cout << "Course Code:\n"
             << CODE << endl;
        cout << "Course Semester:\n"
             << SEMESTER_NO << endl;
        cout << "Course Credits:\n"
             << CREDITS << endl;
        cout << "Course GP Obtained/Needed:\n"
             << GP << endl;

        cout << "Course is Pre/Co-Requisite for the Following Courses:\n";

        for (int i = 0; i < CHILDREN.size(); i++)
        {
            cout << CHILDREN[i] << " , ";
        }

        cout << endl
             << endl;
    }
};