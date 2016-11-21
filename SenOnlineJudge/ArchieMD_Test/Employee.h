#pragma once

#ifndef __Employee__
#define __Employee__

#include "ArchieMD_Test/Person.h"

#include <map>
#include <iostream>
#include <boost/function.hpp>

//typedef bool (*ptrFuncCheckNum)(const int &invokeFuncNum);
typedef boost::function<bool (const int &invokeFuncNum)> Callback;

class Employee : public Person
{
public:
	Employee(); 
	Employee(const Employee  &other); // Copy Constructor
	explicit Employee(const std::string &name);

	virtual ~Employee();

	Employee & operator = (const Employee &other); // Assignment Operator

	void SetAge(const int iAge);
	bool InvokeJob(const std::string &jobName, int invokeFuncNum);
	void RemoveJob(const std::string &jobName);

	void AddJob(const std::string &jobName, const Callback &noIdeaFunc);


protected:
	std::map<std::string, Callback > *jobsFuncMap;


};


#endif // __Employee__

