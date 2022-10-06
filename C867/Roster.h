/*
 * Roster.h
 *
 *  Created on: Jul 17, 2022
 *      Author: manuelcortez
 */

#ifndef ROSTER_H_
#define ROSTER_H_

#pragma once
#include <stdio.h>

#include "Student.h"

class Roster {
public:
	int Index = -1;
	const static int DataTable = 5;
	Student* classRosterArray[DataTable];
	/*Parsing each set of data*/
	void parse(string row);
	/*Sets instance and updates roster*/
	void add(string sstudentID,
		string sfirstName,
		string slastName,
		string semailAddress,
		int sage,
		int sdaysInCourse1,
		int sdaysInCourse2,
		int sdaysInCourse3,
		DegreeProgram dp);
	/*Prints all students with tab separation*/
	void printAll();
	/*Print by degree program*/
	void printByDegreeProgram(DegreeProgram dp);
	/*Print by email*/
	void printInvalidEmails();
	/*Prints average day in completed course*/
	void printAverageDaysInCourse(string studentID);
	/*removes student by ID and creates error if not there*/
	void remove(string studentID);
	/*Destructor*/
	~Roster();
};


#endif /* ROSTER_H_ */

/*(Part E) is started in this file*/