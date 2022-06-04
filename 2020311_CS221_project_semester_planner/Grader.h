#pragma once

#include "graph.h"

using namespace std;

class Grader : public graph{

protected:
	long double goal_cgpa=0;
	long double current_cgpa=0;
	long double max_cgpa=0;
	long double cgpa = 1.00;
	int total_credits=0;
	int current_credits = 0;

public:
	void get_goal()
	{

		cout << "What is Your Desired CGPA by the time you Graduate:\n";
		cin >> goal_cgpa;
	}

	int get_total_credits(){

		for (int i = 1; i < subjects.size(); i++)
		{

			total_credits += subjects[i].get_credit();

		}

		return total_credits;
	}


	long double calc_cgpa()
	{

		for (int i = 1; i < subjects.size(); i++)
		{


			cgpa += (subjects[i].get_gp() * static_cast<long double>(subjects[i].get_credit()));

		}


		cgpa = cgpa / static_cast<long double>(total_credits);

		return cgpa;
	}


	long double calc_max()
	{

		for (int i = 1; i < subjects.size(); i++)
		{
			if(subjects[i].get_mod()==false){

				max_cgpa += (subjects[i].get_gp() * static_cast<long double>(subjects[i].get_credit()));

			}
			else
			{

				max_cgpa += (static_cast<long double>(4.00) * static_cast<long double>(subjects[i].get_credit()));
			}
		}

		max_cgpa = max_cgpa / static_cast<long double>(total_credits);


		return max_cgpa;
	}

	
	void get_current(){

		int current_sem;

		cout << "How many semesters have you passed Completely?\n";
		cin >> current_sem;

		for (int i = 1; i < subjects.size();i++){

			if(subjects[i].get_sem()<=current_sem){

				subjects[i].set_gp();

			}

		}

	}
	

	void grader()
	{
		get_goal();

		get_current();

		get_total_credits();

		calc_max();

		cout << endl
			 << endl
			 << max_cgpa << endl;

		if(goal_cgpa>max_cgpa){

			cout << "\n\nThis CGPA is not acheivable (Maximum acheivable CGPA is : " << max_cgpa<<endl;

			exit(0);
		}

		calc_cgpa();

		do{

			for (int i = 6; i > 0;i--){ //loop to select priority of subjects

				for (int j = 1; j < subjects.size(); j++){ //loop to iterate through the subjects

					int p = subjects[j].get_priority();

					if (p == i)
					{

						for (int k = 0; k < p;k++){ //loop to ensure subjects are graded accoring to priority

							subjects[j].grade_inc();

							calc_cgpa();


							if (cgpa >= goal_cgpa)
							{

								break;
							}
						}
					}

					if (cgpa >= goal_cgpa){

						break;

					}
					

				}
				if (cgpa >= goal_cgpa)
				{

					break;
				}
			}

		} while (cgpa < goal_cgpa);

		cout << endl
			 << endl
			 << "CGPA at Gradguation : "<<calc_cgpa()<<endl<<endl;
	}

};