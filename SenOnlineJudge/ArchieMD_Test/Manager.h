#pragma once

#ifndef __Manager__
#define __Manager__

#include "ArchieMD_Test/Employee.h"

#include <vector>

class Manager : public Employee
{
public:
	virtual ~Manager();

	static Manager* GetInstance();

	void Add(Employee* newEmployee);
	void Remove(Employee* badEmployee);

	Employee* Find(const std::string &employName) const;
	std::vector<Employee> FindAll(const std::string &jobName) const;
	void RemoveAll(const std::string &jobName);

	void Assign(const std::string &employeeName, const std::string &jobName, const Callback &ptrFunc);

	void inline SetManagerName(const std::string strName)	{ SetName(strName); }
	std::string inline GetManagerName() const { return GetName(); }
	void inline SetManagerAge(const int iAge)	{ SetAge(iAge); }
	int inline GetManagerAge() const { GetAge(); }

	bool InvokeManagerJob(const std::string &jobName, int invokeFuncNum)	{
		InvokeJob(jobName, invokeFuncNum);
	}
	void AddManagerJob(const std::string &jobName, const Callback &noIdeaFunc)	{
		AddJob(jobName, noIdeaFunc);
	}
	void RemoveManagerJob(const std::string &jobName)	{
		RemoveJob(jobName);
	}

private:
	Manager();
	Manager(const Manager &);// Prevent from being copied or reassigned
	Manager& operator = (const Manager&);

	static Manager* managerInstance;

	std::vector<Employee*> ptrEmployeeVector;
};




#endif // __Manager__