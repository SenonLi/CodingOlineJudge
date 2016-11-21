#include "Manager.h"

Manager* Manager::managerInstance = NULL;

Manager::Manager() : Employee()
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
		std::vector<Employee*>::iterator it = ptrEmployeeVector.begin();
		bool inserted = false;
		for ( ;	it < ptrEmployeeVector.end(); it++, i++)	{

			if (newEmployee->GetAge() <= ptrEmployeeVector.at(i)->GetAge())	{
				ptrEmployeeVector.insert(it, newEmployee);
				inserted = true;
				break;
			}
		}

		if (!inserted)		ptrEmployeeVector.insert(it, newEmployee);
	}
}


void Manager::Remove(Employee* badEmployee)	{
	//try	{
		bool found = false;
		for (int i = 0; i < ptrEmployeeVector.size(); i++)	{
			if (badEmployee == ptrEmployeeVector.at(i))	{
				
				//delete badEmployee;
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

std::vector<Employee> Manager::FindAll(const std::string &jobName) const	{
	std::vector<Employee> employeeVector;

	//try{
		if (jobsFuncMap->find(jobName) != jobsFuncMap->end())	{
			//jobsFuncMap->at(jobName)
			Callback func = jobsFuncMap->at(jobName);
			for (int i = 0; i < ptrEmployeeVector.size(); i++)	{
				// predicate by jobFunc
				if ((func)(ptrEmployeeVector.at(i)->GetAge()))		employeeVector.push_back(*(ptrEmployeeVector.at(i)));
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

		Callback func = jobsFuncMap->at(jobName);
		for (int i = 0; i < ptrEmployeeVector.size(); i++)	{
			// predicate by jobFunc
			if ((func)(ptrEmployeeVector.at(i)->GetAge()))	{

				//delete ptrEmployeeVector.at(i);
				ptrEmployeeVector.erase(ptrEmployeeVector.begin() + i);	// vector.erase automatically trim the size of the vector
			}
		}
	}
	else
	{
		throw "no jobName exists to RemoveAll !";
	}
}

void Manager::Assign(const std::string &employeeName, const std::string &jobName
	, const Callback &ptrFunc)	{

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




bool Young(const int & a)
{
	if (a > 18 && a < 35)
		return true;
	else
		return false;
}

class CheckAge
{
public:
	bool Old(const int & a)
	{
		if (a >= 35 && a < 50)
			return true;
		else
			return false;
	}
};


#include <boost/bind.hpp>

int mainManager()
{
	//Person p;  // cannot instantiate abstract class	

	Employee * e1 = new Employee("Jack");
	Employee * e2 = new Employee("Rose");
	e1->SetAge(25);//print “Employee's Age is Set”
	e2->SetAge(40);//print “Employee's Age is Set”

	CheckAge cheAge;

	e1->AddJob("AgeCriteria1", boost::bind(&Young, _1));
	e1->AddJob("AgeCriteria2", boost::bind(&CheckAge::Old, cheAge, _1));

	e2->AddJob("AgeCriteria1", boost::bind(&Young, _1));
	e2->RemoveJob("AgeCriteria1");

	bool IsYoung20 = e1->InvokeJob("AgeCriteria1", 20);//IsYoung20 should be true
	bool IsOld40 = e1->InvokeJob("AgeCriteria2", 34);// 40);//IsOld40 should be true

	Manager::GetInstance()->SetManagerName("David");
	Manager::GetInstance()->SetManagerAge(31);//print “Employee's Age is Set”
	Manager::GetInstance()->AddManagerJob("YoungPredicate", boost::bind(&Young, _1));
	Manager::GetInstance()->AddManagerJob("OldPredicate", boost::bind(&CheckAge::Old, cheAge, _1));
	Manager::GetInstance()->Add(e2);
	Manager::GetInstance()->Add(e1);
	Manager::GetInstance()->Add(e1);
	Manager::GetInstance()->Assign("Rose", "AgeCriteria1", boost::bind(&Young, _1));
	bool IsYoung25 = Manager::GetInstance()->Find("Rose")->InvokeJob("AgeCriteria1", 25);//IsYoung25 should be true
	std::vector<Employee> v1 = Manager::GetInstance()->FindAll("YoungPredicate");//v1 should contain Jack only
	Manager::GetInstance()->RemoveAll("OldPredicate");//now only Jack remains in Manager's vector
	Manager::GetInstance()->Remove(e1);//now no Employee remains in Manager's vector

	delete e2;
	delete e1;

	getchar();

	return 0;
}
