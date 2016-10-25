// Lidar.h
#ifndef __Lidar__
#define __Lidar__

#include "Sensor.h"
#include "glm.hpp"
#include <vector>

class Lidar : public Sensor
{
public:
	Lidar();
	~Lidar() override;

	inline glm::vec3 getWorldAddress(const int index) const
	{
		if (index >= 0 && index < worldAddressVector.size())
			return worldAddressVector[index];
		else
			return glm::vec3(0, 0, 0);
	}

	inline glm::vec3 getInlineWorldAddress(const int index) const	  { return worldAddressVector.at(index); }


	void sortAddress(vector<glm::vec3> &addressVector);

private:
	std::vector<glm::vec3> worldAddressVector;
	void swapAddress(glm::vec3 &current, glm::vec3 &next) { glm::vec3 temp = current; current = next; next = temp; }
	float getDistance(glm::vec3 address)	{ return address.x * address.x + address.y * address.y + address.z * address.z; }

};

#endif // __Lidar__

// Lidar.cpp


#include "Lidar.h"

void Lidar::sortAddress(vector<glm::vec3> &addressVector)	{
	if (addressVector.size() <= 1)	{
		return;
	}

	// float curDistance = getDistance(addressVector[0]);
	// float nextDistance = getDistance(addressVector[1]);

	for (int i = addressVector.size() - 1; i >= 0; i--)	{
		float curDistance = getDistance(addressVector[i]);
		int currentPtr = i;

		for (int j = i - 1; j >= 0; j--)	{
			float nextDistance = getDistance(addressVector[j]);

			if (curDistance < nextDistance) {
				//glm::vec3 tempAddress = addressVector[j];
				//	addressVector[j] = addressVector[currentPtr];
				//addressVector[currentPtr] = tempAddress;

				swapAddress(addressVector[currentPtr], addressVector[j]);
				currentPtr = j;
			}
			else break;

		}
	}

}
