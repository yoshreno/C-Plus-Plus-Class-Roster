#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;


class Student {
	public:
		Student();
		Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[3], DegreeProgram degreeProgram);

		void SetStudentID(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmail(string email);
		void SetAge(int age);
		void SetDaysInCourse(int  daysInCourse1, int  daysInCourse2, int  daysInCourse3);
		void SetDegreeProgram(DegreeProgram degreeProgram);

		string GetStudentID() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmail() const;
		int GetAge() const;
		int GetDaysInCourse1() const;
		int GetDaysInCourse2() const;
		int GetDaysInCourse3() const;
		DegreeProgram GetDegreeProgram() const;

		void Print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int daysInCourse[3];
		DegreeProgram degreeProgram;

		string PrintDegreeValue(DegreeProgram degreeProgram);
};

#endif