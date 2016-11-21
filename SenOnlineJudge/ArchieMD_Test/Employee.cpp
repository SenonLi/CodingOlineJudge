#include "Employee.h"


Employee::Employee()
{
	jobsFuncMap = new std::map<std::string, Callback>;
}

// Copy Constructor
Employee::Employee(const Employee  &other)	{
	jobsFuncMap = new std::map<std::string, Callback>;

	if (this != &other)  // protect against invalid self-assignment
	{
		SetName(other.GetName());
		SetAge(other.GetAge());
		
		std::map<std::string, Callback>::const_iterator it = other.jobsFuncMap->begin();
		while (it != other.jobsFuncMap->end())
		{
			jobsFuncMap->insert(std::map<std::string, Callback>::value_type(it->first, it->second));

			//jobsFuncMap->at(it->first) = Callback(it->second);
			++it;
		}
	}
}

Employee::Employee(const std::string &name)	{
	SetName(name); 

	jobsFuncMap = new std::map<std::string, Callback>;
}

Employee::~Employee()
{
	delete jobsFuncMap;
}


// Assignment Operator
// In general, any time you need to write your own custom copy constructor,
// you also need to write a custom assignment operator.
// The C++ standard forbids the compiler to pass a temporary object (an object that does not have a variable name)
// through a non-const reference parameter.

Employee & Employee::operator = (const Employee &other)	{
	
	if (jobsFuncMap) delete jobsFuncMap;
	
	jobsFuncMap = new std::map<std::string, Callback>;

	if (this != &other)  // protect against invalid self-assignment
	{
		SetName(other.GetName());
		SetAge(other.GetAge());

		std::map<std::string, Callback>::const_iterator it = other.jobsFuncMap->begin();
		while (it != other.jobsFuncMap->end())
		{
			jobsFuncMap->at(it->first) = it->second;
			++it;
		}
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

			Callback ptrFuncCheck = jobsFuncMap->at(jobName);

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

void Employee::AddJob(const std::string &jobName, const Callback &noIdeaFunc)	{

	//jobsFuncMap->insert(std::pair<std::string, Callback>(jobName, noIdeaFunc));

	jobsFuncMap->insert(std::map<std::string, Callback>::value_type(jobName, noIdeaFunc));
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