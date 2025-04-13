#include <iostream>
#include <string>
using namespace std;

class Professor {
private:
    string name;
    int employeeID;
    string designation;

public:
    Professor() : name(""), employeeID(0), designation("") {}


    string getName() const { return name; }
    void setName(std::string n) { name = n; }

    int getEmployeeID() const { return employeeID; }
    void setEmployeeID(int id) { employeeID = id; }

    string getDesignation() const { return designation; }
    void setDesignation(std::string desig) { designation = desig; }
};

class Department {
private:
    std::string name;
    int deptID;
    Professor* profList;
    int noOfProfessors;

public:
    Department() : name(""), deptID(0), noOfProfessors(0) {
        profList = new Professor[50]; 
    }

    ~Department() {
        delete[] profList; 
    }

 
    string getName() const { return name; }
    void setName(std::string n) { name = n; }

    int getDeptID() const { return deptID; }
    void setDeptID(int id) { deptID = id; }

    bool addProfessor(Professor p) {
        if (noOfProfessors >= 50) {
            std::cout << "Cannot add more professors to the department." << std::endl;
            return false;
        }
        profList[noOfProfessors++] = p;
        return true;
    }

    bool deleteProfessor(int id) {
        for (int i = 0; i < noOfProfessors; ++i) {
            if (profList[i].getEmployeeID() == id) {
                for (int j = i; j < noOfProfessors - 1; ++j) {
                    profList[j] = profList[j + 1];
                }
                noOfProfessors--;
                return true;
            }
        }
        return false;
    }

    bool updateProfessor(int id, std::string newDesignation) {
        for (int i = 0; i < noOfProfessors; ++i) {
            if (profList[i].getEmployeeID() == id) {
                profList[i].setDesignation(newDesignation);
                return true;
            }
        }
        return false;
    }

    void Display() {
        cout << "Department: " << name << " (ID: " << deptID << ")" << endl;
        cout << "Professors in this department:" << endl;
        for (int i = 0; i < noOfProfessors; ++i) {
            cout << "Professor " << i + 1 << ": Name - " << profList[i].getName()
                << ", ID - " << profList[i].getEmployeeID()
                << ", Designation - " << profList[i].getDesignation() << endl;
        }
    }
};

class University {
private:
    string name;
    Department* dept;
    int numberOfDepartments;

public:
    University() : name(""), numberOfDepartments(0) {
        dept = new Department[20]; 
    }

    ~University() {
        delete[] dept; 
    }

 
    string getName() const { return name; }
    void setName(string n) { name = n; }

    bool addDepartment(Department D) {
        if (numberOfDepartments >= 20) {
            cout << "Cannot add more departments to the university." << endl;
            return false;
        }
        dept[numberOfDepartments++] = D;
        return true;
    }

    bool deleteDepartment(string name) {
        for (int i = 0; i < numberOfDepartments; ++i) {
            if (dept[i].getName() == name) {
                for (int j = i; j < numberOfDepartments - 1; ++j) {
                    dept[j] = dept[j + 1];
                }
                numberOfDepartments--;
                return true;
            }
        }
        return false;
    }

    bool updateDepartment(int id, string name) {
        for (int i = 0; i < numberOfDepartments; ++i) {
            if (dept[i].getDeptID() == id) {
                dept[i].setName(name);
                return true;
            }
        }
        return false;
    }

    void Display() {
        cout << "University: " << name << endl;
        cout << "Departments in this university:" << endl;
        for (int i = 0; i < numberOfDepartments; ++i) {
            dept[i].Display();
            cout << endl;
        }
    }
};

int main() {
    University myUniversity;
    Department department1;
    Department department2;
    Professor professor1;
    Professor professor2;

  
    professor1.setName("John Doe");
    professor1.setEmployeeID(1);
    professor1.setDesignation("Associate Professor");

    professor2.setName("Alice Smith");
    professor2.setEmployeeID(2);
    professor2.setDesignation("Professor");

    
    department1.addProfessor(professor1);
    department1.addProfessor(professor2);

  
    myUniversity.addDepartment(department1);
    myUniversity.addDepartment(department2);


    myUniversity.Display();

   
    myUniversity.deleteDepartment("DeptName");
    myUniversity.updateDepartment(2, "NewDeptName");

    
    myUniversity.Display();

    return 0;
}
