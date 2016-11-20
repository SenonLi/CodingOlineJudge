#pragma once

#ifndef __Employee__
#define __Employee__

#include "ArchieMD_Test/Person.h"
#include <map>
#include <iostream>

typedef bool (*ptrFuncCheckNum)(const int &invokeFuncNum);

class Employee : public Person
{
public:
	Employee(); 
	Employee(const Employee  &other); // Copy Constructor
	explicit Employee(const std::string &name);

	//typedef bool (Employee::*ptrInnerFunc)();

	virtual ~Employee();

	Employee & operator = (const Employee &other); // Assignment Operator

	void SetAge(const int iAge);
	bool InvokeJob(const std::string &jobName, int invokeFuncNum);
	//void AddJob(const std::string &jobName, const ptrFuncCheckNum &noIdeaFunc);

	void AddJob(const std::string &jobName, ptrFuncCheckNum noIdeaFunc);

	void RemoveJob(const std::string &jobName);

protected:
	std::map<std::string, ptrFuncCheckNum> *jobsFuncMap;


};


#endif // __Employee__

