/*
 * Student.h
 *
 *  Created on: Jul 17, 2022
 *      Author: manuelcortez
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "Degree.h"

using std::string;
using std::cout;

class Student {
public:
	const static int daysArray = 3;
	/*Constructor Function Set*/
	Student(); /*Parameterless*/
	/*Fully set*/
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeprogram);
	
	/*accessor/getter*/
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	int* getdays();
	DegreeProgram getdegreeprogram();

	/*mutator/setter*/
	void setstudentID(string ID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int age);
	void setdays(int days[]);
	void setdegreeprogram(DegreeProgram dp);

	/*Print function for specific data*/
	void print();


private:
	/*Makes it only accessible to the object*/
	string studentID, firstName, lastName, emailAddress;
	int age;
	int days[daysArray];
	DegreeProgram degreeprogram;

};


#endif /* STUDENT_H_ */

/*(Part D.1) creating a class called Student with all variables*/