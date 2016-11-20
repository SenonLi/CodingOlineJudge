#include "Employee.h"


Employee::Employee()
{
}

// Copy Constructor
Employee::Employee(const Employee  &other)	{
	;
}

Employee::Employee(const std::string &name)	{
	SetName(name); 
}

Employee::~Employee()
{

}


// Assignment Operator
// In general, any time you need to write your own custom copy constructor,
// you also need to write a custom assignment operator.
// The C++ standard forbids the compiler to pass a temporary object (an object that does not have a variable name)
// through a non-const reference parameter.

Employee & Employee::operator = (const Employee &other)	{
	if (this != &other)  // protect against invalid self-assignment
	{
		SetName(other.GetName());
		SetAge(other.GetAge());
		;
	}

	return *this;
}

void Employee::SetAge(const int iAge)	{ 
	assignAge(iAge);
	std::cout << "Employee's Age is Set" << std::endl;
}

bool Employee::InvokeJob(const std::string &jobName, int invokeFuncNum)	{
	//try	{
		if (jobsFuncMap->find(jobName) != jobsFuncMap->end())	{
			ptrFuncCheckNum ptrFuncCheck = jobsFuncMap->at(jobName);
			return ptrFuncCheck(invokeFuncNum);
		}
		else
		{
			throw "no jobName exists to InvokeJob !";
		}
	//}
	//catch (const char* e)	{
	//	std::cerr << "Invalid InvokeJob : " << e << std::endl;
	//}
}

//void Employee::AddJob(const std::string &jobName, const ptrFuncCheckNum &noIdeaFunc)	{
void Employee::AddJob(const std::string &jobName, ptrFuncCheckNum noIdeaFunc)	{

	jobsFuncMap->insert(std::pair<std::string, ptrFuncCheckNum>(jobName, noIdeaFunc));

	//jobsFuncMap->insert(std::map<std::string, ptrFuncCheckNum>::value_type(jobName, noIdeaFunc));

}

void Employee::RemoveJob(const std::string &jobName)	{
	//try{
		if (jobsFuncMap->find(jobName) != jobsFuncMap->end())	{
			jobsFuncMap->erase(jobName);
		}
		else
		{
			throw "no jobName exists to RemoveJob !";
		}
	//}
	//catch (const std::invalid_argument& e)	{
	//	std::cerr << "Invalid RemoveJob :" << e.what() << std::endl;
	//}

}	