

// gcd is a sequance of reminders  

	int gcd(int a, int b) {
	  int result = a % b;
	  while (result != 0) {
	    a = b;
	    b = result;
	    result = a % b;
	  }
	  return b;
	}
