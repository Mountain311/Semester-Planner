#pragma once

#include "File_I_O.h"

using namespace std;

class graph: public File_I_O {

protected:

	SuperVector<Subject_Node> subjects;

public:

	void graph_gen() { //generates a graph  from the selected file


		cout << "Enter File name for Your Faculty and Batch (in the Form \"FacultyBatch\") :" << endl;
		cin >> file_name;

        file_name = file_name + ".csv";

        read_file.open(file_name, ios::in);

		SuperVector<string> column;
		string row, word, line;

		while (!read_file.eof())
		{
			column.clear();   //Clears every entry currently in the vector 

			getline(read_file, line); // Gets a single line from the File and assigns it to the string

			istringstream s(line); // Assigns the String to the string stream so that it can be manipulated

			while (getline(s, word, ','))  // Takes the string stream and breaks it into smaller strings deliminated by the ',' special Character and assigns these to another
			{
				column.push_back(word);  // Enters the smaller strings into a new index of the vector
			}

			if (column[0] == "END")
			{

				break;
				
			}

			Subject_Node sub(column);

			subjects.push_back(sub);

		}
		read_file.close();

	}

	void print_graph() {

		for (int i = 1; i < subjects.size(); i++) {

			subjects[i].print_node();

		}

	}

};