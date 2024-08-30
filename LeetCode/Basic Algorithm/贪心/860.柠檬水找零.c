bool lemonadeChange(int* bills, int billsSize) {
	int b5 = 0;
	int b10 = 0;
	for (int i = 0; i < billsSize; i++) 
	{
		if (bills[i] == 5) {
			++b5;
		} 
		else if (bills[i] == 10) 
		{
			if (b5 < 1) 
			{
				return false;
			}
			--b5;
			++b10;
		}
		 else if (bills[i] == 20) 
		 {
			if (b10 > 0) 
			{
				--b10;
				if (b5 < 1) 
				{
					return false;
				}
				--b5;
			}
			 else 
			 {
				if (b5 < 3)
				{
					return false;
				}
				b5 -= 3;
			}
		}
	}
	return true;
}
