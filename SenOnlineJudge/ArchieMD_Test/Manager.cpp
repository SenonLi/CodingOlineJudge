#include "Manager.h"

Manager* Manager::managerInstance = NULL;

Manager::Manager()
{
}

Manager::~Manager()
{
	if (NULL != managerInstance)	{
		delete managerInstance;
		managerInstance = NULL;
	}
}

Manager* Manager::GetInstance()	{
	if (NULL == managerInstance)	{
		managerInstance = new Manager();
	}

	return managerInstance;
}


void Manager::Add(Employee* newEmployee)	{
	
	if (ptrEmployeeVector.size() == 0)	ptrEmployeeVector.push_back(newEmployee);
	else
	{
		int i = 0;
		for (std::vector<Employee*>::iterator it = ptrEmployeeVector.begin();
			it < ptrEmployeeVector.end(); it++, i++)	{
			if (newEmployee->GetAge() <= ptrEmployeeVector.at(i)->GetAge())	{
				ptrEmployeeVector.insert(it, newEmployee);
				break;
			}
		}
	}
}


void Manager::Remove(Employee* badEmployee)	{
	//try	{
		bool found = false;
		for (int i = 0; i < ptrEmployeeVector.size(); i++)	{
			if (badEmployee == ptrEmployeeVector.at(i))	{
				delete badEmployee;

				// vector.erase automatically trim the size of the vector
				ptrEmployeeVector.erase(ptrEmployeeVector.begin() + i);
				found = true;
				break;
			}				
		}

		if (! found)	throw "no badEmployee exists to Remove !";

	//}
	//catch (const char* e)	{
	//	std::cerr << "Invalid Remove : " << e << std::endl;
	//}
}

Employee* Manager::Find(const std::string &employName) const{
	for (int i = 0; i < ptrEmployeeVector.size(); i++)	{
		if (employName == ptrEmployeeVector.at(i)->GetName())	{
			return ptrEmployeeVector.at(i);
		}
	}

	return NULL;
}

std::vector<Employee>& Manager::FindAll(const std::string &jobName) const	{
	std::vector<Employee> employeeVector;

	//try{
		if (jobsFuncMap->find(jobName) != jobsFuncMap->end())	{
			//jobsFuncMap->at(jobName)
			ptrFuncCheckNum func = jobsFuncMap->at(jobName);
			for (int i = 0; i < ptrEmployeeVector.size(); i++)	{
				// predicate by jobFunc
				if ((*func)(ptrEmployeeVector.at(i)->GetAge()))
					employeeVector.push_back(*(ptrEmployeeVector.at(i)));
			}

			return employeeVector;
		}
		else
		{
			throw "no jobName exists to FindAll !";
		}
	//}
	//catch (const char* e)	{
	//	std::cerr << "Invalid FindAll :" << e << std::endl;
	//}
}

void Manager::RemoveAll(const std::string &jobName)	{

	if (jobsFuncMap->find(jobName) != jobsFuncMap->end())	{

		ptrFuncCheckNum func = jobsFuncMap->at(jobName);
		for (int i = 0; i < ptrEmployeeVector.size(); i++)	{
			// predicate by jobFunc
			if ((*func)(ptrEmployeeVector.at(i)->GetAge()))	{

				delete ptrEmployeeVector.at(i);
				ptrEmployeeVector.erase(ptrEmployeeVector.begin() + i);
				// vector.erase automatically trim the size of the vector
			}
		}
	}
	else
	{
		throw "no jobName exists to RemoveAll !";
	}
}

void Manager::Assign(const std::string &employeeName, const std::string &jobName
	, const ptrFuncCheckNum &ptrFunc)	{

	bool found = false;
	for (int i = 0; i < ptrEmployeeVector.size(); i++)	{
		if (employeeName == ptrEmployeeVector.at(i)->GetName())	{

			ptrEmployeeVector.at(i)->AddJob(jobName, ptrFunc);

			found = true;
			break;
		}
	}

	if (!found)	throw "no employeeName exists to Assign !";

}
