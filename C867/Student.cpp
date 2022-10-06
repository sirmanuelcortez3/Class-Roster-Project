/*
 * Student.cpp
 *
 *  Created on: Jul 17, 2022
 *      Author: manuelcortez
 */

#include "Student.h"

/*Constructor is created  and is set to default*/
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	/*Sets the value to the default (0) for each day*/
	for (int i = 0; i < daysArray; i++) this->days[i] = 0;
	/*The default value is set to security*/
	this->degreeprogram = DegreeProgram::SECURITY;
}

/*Pointer is set*/
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeprogram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
	this->degreeprogram = degreeprogram;
}


/*Accessor/Getter for each instance for part D1*/
string Student::getstudentID() {
	return this->studentID; 
}
string Student::getfirstName() {
	return this->firstName; 
}
string Student::getlastName() { 
	return this->lastName;
}
string Student::getemailAddress() { 
	return this->emailAddress; 
}
int Student::getage() {
	return this->age; 
}
int* Student::getdays() {
	return this->days;
}
DegreeProgram Student::getdegreeprogram() {
	return this->degreeprogram;
}

/*Mutator/Setter for each instance for part D1*/
void Student::setstudentID(string studentID) { 
	this->studentID = studentID; 
}
void Student::setfirstName(string firstName) { 
	this->firstName = firstName; 
}
void Student::setlastName(string lastName) { 
	this->lastName = lastName;
}
void Student::setemailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setage(int age) {
	this->age = age;
}
void Student::setdays(int days[]) {
	for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
}
void Student::setdegreeprogram(DegreeProgram dp) {
	this->degreeprogram = dp; 
}


/*Print Defined*/
void Student::print() {
	/*Tabs each string*/
	cout << this->getstudentID() << '\t';
	cout << this->getfirstName() << '\t';
	cout << this->getlastName() << '\t';
	cout << this->getemailAddress() << '\t';
	cout << this->getage() << '\t';
	cout << this->getdays()[0] << ',';
	cout << this->getdays()[1] << ',';
	cout << this->getdays()[2] << '\t';
	cout << DegreeProgramStrings[this->getdegreeprogram()] << '\n';

}

/*(Part D.2) created all functions for the Student class: accessor, mutator, constructor, and print()*/