// NAME :ZUBAIR ALI
// DISICIPLINE: SE

////////////////////////////////     OOPS(OBJECT ORIENTED PROGRAMMING IN C++) //////////////////////////////////////////////////////
/////////////?????????????????????   FIRST LECTURE ABOUT OOPS (EMPLOYEE CLASS)  ??????????????///////////////////////////////////// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                        #include<iostream>
                                        using std::string;

//class
  /*                                                            
class Employee{      
//std::string Name;
 // class include its attributes an its behevaior
         
         //there are three type of modifier
          //private
      //protected
      //public
         //IN our class all this are private by default like
     //ATTRIBUTES
public:      
string Name;         
string Company;
int Age;
    // Behaviour of thuis class is the function
    void IntroduceYourself(){
    std::cout<<Name<<std::endl;
    std::cout<<Company<<std::endl;
    std::cout<<Age<<std::endl;
    
    }
    // how to construct our class
    //throee rules 1=it has same name as class 2=it has no return starement 3=it has public
    
    Employee(string name ,string company ,int age){
    Name=name;
    Company=company;
    Age=age;
    }
    
};

int main(){
 // how we can create the object of yhe class
    // so the object is
  Employee employee1=Employee("zubair ali","amazon",20);
  // Acees of this class is given as;
/*  employee1.Name="ZUBAIR ALI";
  employee1.Company="ZUBAIR SOFTWRE HOUSE";
  employee1.Age=19;*/  //employee1.IntroduceYourself();
  
//}*/


         //PILLARS OF OOPS
         //ENCAPSULATION(HIDE DATA)
         //ABSTRACTION(DATA HIHE)
         //INHERITANCE(REUSABILITY)
         //POLYMORPHISM(OBJECT TO TAKE MANY FORMS)
  
  
  
  
/////////////////////////////////////////       ENCAPSULATION(HIDE data)
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                                                        

/*class Employee{      

      //how to acess private modifiers
 private:
string Name;         
string Company;
int Age;

public:  
//you can acess by seter and getter   
void setname(string name){
Name=name;
}
string getname(){
return Name;
}
void setage(int age){
Age=age;
}
int getage(){
return Age;
}

    
};

int main(){
  Employee employee1;
 employee1.setname("zubair");
 employee1.setage(12);
 std::cout<<employee1.getname()<<"is"<<employee1.getage()<<"year old";
  
}
*/

////////////////////////////////////////       ABSTRACTION(DATA HIHE)       //////////////////////////////////////////////////

//abstract class

/*
class AbstractEmployee{
virtual void AskforPromotion()=0;

};
class Employee:AbstractEmployee {      
public:
  string Name;         
string Company;
int Age;
    Employee(string name ,string company ,int age){
    Name=name;
    Company=company;
    Age=age;
    }
    void AskforPromotion(){
    if(Age>30)
    std::cout<<"promoted"<<std::endl;
    else
     std::cout<<"not promoted"<<std::endl;
}

};


int main(){
  Employee employee1=Employee("zubair ali","amazon",20);
  employee1.AskforPromotion();
  
  
  }
*/

////////////////////////////////////////       //INHERITANCE(REUSABILITY)       //////////////////////////////////////////////////

/*
class Employee {      
private:
           
string Company;
int Age;
protected:
string Name;

public:
string getname(){
return Name; 
}
    Employee(string name ,string company ,int age){
    Name=name;
    Company=company;
    Age=age;
    }
int getage(){
return Age;
}
    void AskforPromotion(){
    if(Age>30)
    std::cout<<"promoted"<<std::endl;
    else
     std::cout<<"not promoted"<<std::endl;
}
 void work(){
 std::cout<<Name<<"is good man"<<std::endl;
 }
 
};

class Developer:public Employee{
public:
string Favprog;
Developer(string name,string company,int age,string favprog):Employee(name,company,age){
Favprog=favprog;
}
void fixBug(){
std::cout<<Name<<getage()<<Favprog;
}
void work(){
 std::cout<<Name<<"is good programmar"<<std::endl;
 }

};
int main(){
  
Developer d=Developer("zubair ali","amazon",20,"c++");
  d.fixBug();
 d.AskforPromotion();
 d.work();
}
*/



////////////////////////////////////////           //POLYMORPHISM(OBJECT TO TAKE MANY Forms) ///////////////////////////////////// F//////////////////////////////////////////////////

/*
class Employee {      
private:
           
string Company;
int Age;
protected:
string Name;

public:
string getname(){
return Name; 
}
    Employee(string name ,string company ,int age){
    Name=name;
    Company=company;
    Age=age;
    }
int getage(){
return Age;
}
    void AskforPromotion(){
    if(Age>30)
    std::cout<<"promoted"<<std::endl;
    else
     std::cout<<"not promoted"<<std::endl;
}
  virtual  void work(){
 std::cout<<Name<<"is good man"<<std::endl;
 }
 
};

class Developer:public Employee{
public:
string Favprog;
Developer(string name,string company,int age,string favprog):Employee(name,company,age){
Favprog=favprog;
}
void fixBug(){
std::cout<<Name<<getage()<<Favprog;
}
 void work(){
 std::cout<<Name<<"is good programmar"<<std::endl;
 }

};
int main(){
  
Developer d=Developer("zubair ali","amazon",20,"c++");
  d.fixBug();
 d.AskforPromotion();
 d.work();
 Employee *e=&d;
 e->work();
}

*/















