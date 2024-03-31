#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 100;

class Employee {
private:
    string name;
    double hourlyRate;
public:
    Employee(const string& n, double hr) : name(n), hourlyRate(hr) {}
    const string& getName() const {
        return name; 
    }
    double getHourlyRate() const { 
        return hourlyRate;
    }
};

class Payroll {
private:
    Employee* employees[MAX_EMPLOYEES];
    int numEmployees;
public:
    Payroll() : numEmployees(0) {
        for (int i = 0; i < MAX_EMPLOYEES; ++i) {
            employees[i] = nullptr;
        }
    }

    ~Payroll() {
        for (int i = 0; i < numEmployees; ++i) {
            delete employees[i];
        }
    }

    void addEmployee(const Employee& emp) {
        if (numEmployees < MAX_EMPLOYEES) {
            employees[numEmployees] = new Employee(emp);
            numEmployees++;
        } else {
            cout << "Cannot add more employees. Maximum limit reached." << endl;
        }
    }

    void enterHoursWorked(const string& name, double hoursWorked) {
        bool found = false;
        for (int i = 0; i < numEmployees; ++i) {
            if (employees[i]->getName() == name) {
                double salary = employees[i]->getHourlyRate() * hoursWorked;
                cout << "Salary for " << name << " is: $" << salary << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Employee not found." << endl;
        }
    }

    void generatePayrollReport() {
        cout << "Payroll Report:" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < numEmployees; ++i) {
            cout << "Name: " << employees[i]->getName() << ", Hourly Rate: $" << employees[i]->getHourlyRate() << endl;
        }
    }
};

int main() {
    Payroll payroll;

    payroll.addEmployee(Employee("Ansh", 20.0));
    payroll.addEmployee(Employee("Rahul", 25.0));

    payroll.enterHoursWorked("Ansh", 40);
    payroll.enterHoursWorked("Rahul", 35);
    payroll.enterHoursWorked("Raj", 45); 

    payroll.generatePayrollReport();

    return 0;
}

