#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
using namespace std;

class Student {
	public:
		// Constructors
		Student(); // Default Constructor
		Student(string studentID, string firstName, string lastName, // Overload constructor
			string emailAddress, int age, int daysToCompleteCourse[]);
		~Student(); // Destructor
		// Getters
		string		   getStudentID();
		string		   getFirstName();
		string		   getLastName();
		string		   getEmailAddress();
		int			   getAge();
		int*		   getDaysToCompleteCourse();
		virtual Degree getDegreeProgram() = 0;
		// Setters
		void setStudentID(int studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setDaysToCompleteCourse(int daysToCompleteCourse[]);
		// Print
		virtual void print() = 0;
		// Array const
		const static int daysCompleteArraySize = 3;
	protected:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int    age;
		int    daysToCompleteCourse[daysCompleteArraySize];
		Degree degreeType;
};

#endif
