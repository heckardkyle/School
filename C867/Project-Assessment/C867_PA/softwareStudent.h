#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"
#include <string>
using namespace std;

class SoftwareStudent : public Student {
	public:
		// Constructors
		SoftwareStudent(); // Subclass Default Constructor
		SoftwareStudent(string studentID, string firstName, string lastName, // Subclass Overload Constructor
			string emailAddress, int age, int daysToComplete[], Degree degreeType);
		~SoftwareStudent(); // Subclass Destructor
		// Subclass Getters
		Degree getDegreeProgram();
		// Subclass Print
		void print();
};

#endif