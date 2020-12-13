#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"
#include <string>
using namespace std;

class NetworkStudent : public Student {
	public:
		// Constructors
		NetworkStudent(); // Subclass Default Constructor
		NetworkStudent(string studentID, string firstName, string lastName, // Subclass Overload Constructor
			string emailAddress, int age, int daysToComplete[], Degree degreeType);
		~NetworkStudent(); // Subclass Destructor
		// Subclass Getters
		Degree getDegreeProgram();
		// Subclass Print
		void print();
};

#endif