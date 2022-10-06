/*
 * Roster.cpp
 *
 *  Created on: Jul 17, 2022
 *      Author: manuelcortez
 */

#include <string>

#include "Roster.h"

 /*Parses through each row*/
void Roster::parse(string studentdata) {
	/*extracts substring after each delimiter which is the comma*/
	int x = studentdata.find(",");
	string sstudentID = studentdata.substr(0, x);
	/*moves forward*/
	int y = x + 1;
	x = studentdata.find(",", y);
	string sfirstName = studentdata.substr(y, x - y);
	/*moves forward*/
	y = x + 1;
	x = studentdata.find(",", y);
	string slastName = studentdata.substr(y, x - y);
	/*moves forward*/
	y = x + 1;
	x = studentdata.find(",", y);
	string semailAddress = studentdata.substr(y, x - y);
	/*moves forward*/
	y = x + 1;
	x = studentdata.find(",", y);
	int sage = stoi(studentdata.substr(y, x - y));
	/*moves forward*/
	y = x + 1;
	x = studentdata.find(",", y);
	int sdaysInCourse1 = stoi(studentdata.substr(y, x - y));
	/*moves forward*/
	y = x + 1;
	x = studentdata.find(",", y);
	int sdaysInCourse2 = stoi(studentdata.substr(y, x - y));
	/*moves forward*/
	y = x + 1;
	x = studentdata.find(",", y);
	int sdaysInCourse3 = stoi(studentdata.substr(y, x - y));
	/*moves forward*/
	y = x + 1;
	x = studentdata.find(",", y);
	DegreeProgram dp = DegreeProgram::SECURITY;
	if (studentdata.at(y) == 'S' && studentdata.at(y + 1) == 'E') {
		dp = DegreeProgram::SECURITY;
	}
	else if (studentdata.at(y) == 'S' && studentdata.at(y + 1) == 'O') {
		dp = DegreeProgram::SOFTWARE;
	}
	else if (studentdata.at(y) == 'N') {
		dp = DegreeProgram::NETWORK;
	}
	
	add(sstudentID, sfirstName, slastName, semailAddress, sage, sdaysInCourse1, sdaysInCourse2, sdaysInCourse3, dp);
}


/*combines strings and creates object*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourses2, int daysInCourses3, DegreeProgram dp) {
	int DaysInCourse[3] = { daysInCourse1,daysInCourses2,daysInCourses3 };

	classRosterArray[++Index] = new Student(studentID, firstName, lastName, emailAddress, age, DaysInCourse, dp);

}


/*displays all students and adds a header*/
void Roster::printAll() {
	/*Header for each student*/
	cout << "Student ID|First Name|Last Name|Email Address|Age|Days in Courses|Degree Program\n";
	for (int i = 0; i <= Roster::Index; i++) {
		cout << classRosterArray[i]->getstudentID(); cout << '\t';
		cout << classRosterArray[i]->getfirstName(); cout << '\t';
		cout << classRosterArray[i]->getlastName(); cout << '\t';
		cout << classRosterArray[i]->getemailAddress(); cout << '\t';
		cout << classRosterArray[i]->getage(); cout << '\t';
		cout << classRosterArray[i]->getdays()[0]; cout << '\t';
		cout << classRosterArray[i]->getdays()[1]; cout << '\t';
		cout << classRosterArray[i]->getdays()[2]; cout << '\t';
		cout << DegreeProgramStrings[classRosterArray[i]->getdegreeprogram()] << std::endl;
	}
}


/*displays student with their degree program with header*/
void Roster::printByDegreeProgram(DegreeProgram dp) {
	/*Header for each student*/
	cout << "Student ID|First Name|Last Name|Email Address|Age|Days in Courses|Degree Program\n";
	for (int i = 0; i <= Roster::Index; i++) {
		if (Roster::classRosterArray[i]->getdegreeprogram() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}


/*prints invalid emails*/
void Roster::printInvalidEmails() {
	/*sets ALL emails to false*/
	bool ALL = false;
	/*checks each email against '@',' ','.'*/
	for (int i = 0; i <= Roster::Index; i++) {
		string semailAddress = (classRosterArray[i]->getemailAddress());
		if (semailAddress.find('@') == string::npos || (semailAddress.find(' ') == string::npos && semailAddress.find('.') == string::npos)) {
			/*sets each email address to true that passes against 'test'*/
			ALL = true;
			/*prints each email*/
			cout << semailAddress << std::endl;
		}
	}
}


/*it averages the amount of days spent within the course*/
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::Index; i++) {
		/*Identified by student paramter*/
		if (classRosterArray[i]->getstudentID() == studentID) {
			cout << studentID << ":";
			cout << (classRosterArray[i]->getdays()[0]
				+ classRosterArray[i]->getdays()[1]
				/*divides by 3*/
				+ classRosterArray[i]->getdays()[2]) / 3.0 << std::endl;
		}
	}
}

/*removes student by given ID*/
void Roster::remove(string studentID) {
	bool REMOVE = false;
	for (int i = 0; i <= Roster::Index; i++) {
		if (classRosterArray[i]->getstudentID() == studentID) {
			REMOVE = true;
			if (i < DataTable - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[DataTable - 1];
				classRosterArray[DataTable - 1] = temp;
			}
			Roster::Index--;
		}

	}
	if (REMOVE) {
		cout << studentID << " removed." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " not found in roster." << std::endl << std::endl;
}

/*Destructor being initiated and memory is releasing from Roster.*/
Roster::~Roster() {
	cout << "Destructor: Memory Releasing..." << std::endl << std::endl;
	for (int i = 0; i < DataTable; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

/*Creates Roster class (Part E) as well as each function and object*/