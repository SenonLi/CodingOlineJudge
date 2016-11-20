
#include <string>

//using namespace std;


//#include "CTCI/Sen_Ch12_CppTest.h"
//#include "GeeksforGeeks/Sen_StringArrayTop10.h"
//#include "GeeksforGeeks/Sen_LinkedListTop10.h"

#include "ArchieMD_Test/Person.h"
#include "ArchieMD_Test/Employee.h"
//#include "ArchieMD_Test/Manager.h"

//int main(){
//
//	//Sen_StringArrayTop10 stringArrayObject;
//	//stringArrayObject.showAlphabetStringReverse();
//	//stringArrayObject.allPalPartitions(string("nitin"));
//
//	//Sen_Ch12_CppTest cppTestObject;
//	//cppTestObject.printLastKLines(12);
//
//
//	getchar();
//	return 0;
//}




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

int main()
{
	//Person p;  // cannot instantiate abstract class	

	Employee * e1 = new Employee("Jack");
	Employee * e2 = new Employee("Rose");
	e1->SetAge(25);//print “Employee's Age is Set”
	e2->SetAge(40);//print “Employee's Age is Set”
	e1->AddJob("AgeCriteria1", &Young);
	//e1->AddJob("AgeCriteria2", function pointer pointing to CheckAge::Old);

	//bool IsYoung20 = e1->InvokeJob(“AgeCriteria1”, 20);//IsYoung20 should be true
	//bool IsOld40 = e1->InvokeJob(“AgeCriteria2”, 40);//IsOld40 should be true
	//Manager::GetInstance().SetManagerName(“David”);
	//Manager::GetInstance().SetManagerAge(31);//print “Employee's Age is Set”
	//Manager::GetInstance().AddManagerJob(“YoungPredicate”, function pointer pointing to Young);
	//Manager::GetInstance().AddManagerJob(“OldPredicate”, function pointer pointing to CheckAge::Old);
	//Manager::GetInstance().Add(e1);
	//Manager::GetInstance().Add(e2);
	//Manager::GetInstance().Assign(“Rose”, “AgeCriteria1”, function pointer pointing to Young);
	//bool IsYoung25 = Manager::GetInstance().Find(“Rose”)->InvokeJob(“AgeCriteria1”, 25);//IsYoung25 should be true
	//std::vector v1 = Manager::GetInstance().FindAll(“YoungPredicate”);//v1 should contain Jack only
	//Manager::GetInstance().RemoveAll(“OldPredicate”);//now only Jack remains in Manager's vector
	//Manager::GetInstance().Remove(e1);//now no Employee remains in Manager's vector
	
	delete e1;
	delete e2;

	getchar();

	return 0;
}
