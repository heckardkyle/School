#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <iostream>
#include <string>
using namespace std;

class Roster {
	public:
		// Constructors
		Roster();
		Roster(int capacity);
		~Roster();
		// Manipulators
		void parseThenAdd(string studentData);
		void add(string studentID, string firstName, string lastName, string emailAddress,
			int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
		void remove(string studentID);
		Student* getStudent(int index);
		// Prints
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(Degree degreeProgram);
	private:
		Student** classRosterArray;
		int capacity;
		int lastIndex;
};

#endif
