

// Note that size of Int is 4 
// it's 64-bit windows 


/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

Q1)


class A{

};


sizeof(A); 



/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

class B{
	
private:
	int x;
};


sizeof(B); 


/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

class C{
	
private:
	char y; 
	int x; 

};


sizeof(C); 




/*************************************************************************************/


class D{
	
private:
	void func(){
	
	}
};


sizeof(D); 

/*************************************************************************************/

class F{
	
	static int x = 1;
};


sizeof(f); 



/*************************************************************************************/


class E{
	
	char x;
	int y ;
};


sizeof(E);


/*************************************************************************************/


class base {
  	

 public : 
	int baseX;

};


class derived : public base{

  public:
  int derivedX;
  
};



sizeof(base);
sizeof(derived);



/*************************************************************************************/


class base {
  	

 public : 
	int baseX;

};


class derived : private base{

  public:
  int derivedX;
  
};



sizeof(base);
sizeof(derived);


/*************************************************************************************/

	class base {
	  	
	  	
	    public : 		
	    void print(){
	    cout<<"print base class"<<endl;

	    }

	};


	class derived : public base{

	  public:
	  
	  void print(){
	    cout<<"print driverd class"<<endl;  
	  }
	};

	 derived derivedObject;
	 base* basePtr = &derivedObject;
	 
   	 basePtr->print();  

	sizeof(derivedObject); 
/*************************************************************************************/


	class base {
	  	
	  	
	    public : 		
	    virtual void print(){
	    cout<<"print base class"<<endl;

	    }

	};


	class derived : public base{

	  public:
	  
	  void print(){
	    cout<<"print driverd class"<<endl;  
	  }
	};



	 derived derivedObject;
	 base* basePtr = &derivedObject;
   	 basePtr->print();         // Question Heree 




	sizeof(derivedObject); 
	
/*************************************************************************************/