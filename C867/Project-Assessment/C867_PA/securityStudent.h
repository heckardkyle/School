#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"
#include <string>
using namespace std;

class SecurityStudent : public Student {
	public:
		// Constructors
		SecurityStudent(); // Subclass Default Constructor
		SecurityStudent(string studentID, string firstName, string lastName, // Subclass Overload Constructor
			string emailAddress, int age, int daysToComplete[], Degree degreeType);
		~SecurityStudent(); // Subclass Destructor
		// Subclass Getters
		Degree getDegreeProgram();
		// Subclass Print
		void print();
};

#endif