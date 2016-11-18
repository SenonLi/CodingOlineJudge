#pragma once

#ifndef __Employee__
#define __Employee__

#include "Person.h"
#include <map>

//typedef bool Employee::*

class Employee :public Person
{
public:
	Employee(); 
	Employee(const Employee  &obj); 
	explicit Employee(const std::string &name)	{ SetName(name); }

	virtual ~Employee();

private:
	//std::map<std::string, >


};


#endif // __Employee__

