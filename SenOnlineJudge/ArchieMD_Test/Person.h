#pragma once

#ifndef __Person__
#define __Person__

#include <string>

class Person
{
public:
	Person(): age(0)	{; }
	virtual ~Person()	{; }

	void inline SetName(const std::string strName)	{ name = strName; }
	std::string GetName() const { return name; }

	virtual void SetAge(const int iAge) = 0;
	int GetAge() const { return age;  }

protected:
	void assignAge(const int iAge) { age = iAge; }

private:
	std::string name;
	int age;

};

#endif // __Person__

