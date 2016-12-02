
// Happy numbers
// 7 => 49 => 16 + 81 => 97 => 81 + 49 => 130 => 10 => 1

// 4 => 16 => 37 => 56 
  
// 4, 16, 37, 58, 89, 145, 42, 20, 4

bool checkHappyNumber(const unsigned int &init)  {
  
	if (init == 1) return true;
	if (init == 0)  return false;

    bool isHappy, isFinal = false;
    int total, temp, singleNum = -1;

    if (init < 10) singleNum = init;
  
    do {
        total = 0;
        temp = init;
        
        while (temp > 0) {
            total += (temp - temp % 10 * 10) * (temp - temp % 10 * 10);
            temp %= 10;
        }

        if (singleNum == -1 && total < 10)  singleNum = total;
      
        if(singleNum > -1)  {
            if (total == singleNum)   {
                isFinal = true;
                isHappy = false;
            }else if(total == 1)  {
                isFinal = true;
                isHappy = true;
            }
        }
      
    }while (!isFinal);
  
    return isHappy;
}




int getDigits(const unsigned int &init)  {

	int digitCout = 0;
	if (init > 0)  digitCout = 1;
	else if (init == 0) return 0;
  
  
	int left = init;
	while (left >= 10)  {
		if (left / 10 > 0) {
			digitCout++;
			left %= 10;
		}
	}
  
	return digitCount;
}
