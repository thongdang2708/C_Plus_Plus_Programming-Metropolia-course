#include <iostream>
#include <sstream>
#include <fstream>
void supermarket();
int getNumber(std::string title_string, int* number);
void employee();
std::string getEmployeeName (std::string title_string, std::string* employee_name);
void bubbleSortExercise();
int* bubblesort(int a[], int n);
void payrollSystem();
int getSalary(std::string salary);
void splitAndJoin();
std::vector<std::string> mysplit(std::string sentence, char sep);
std::string myjoin(std::vector<std::string> lst, char sep);
void salaryEmployeeToCSVFile();
void extendPayrollWithHourlyAndCommissionEmployee();
int getValueForCalculatingSalary(std::string title);
void finalExercise();
int getSalaryFromInput (std::string title);

int main() {
//    supermarket();
//    employee();
//    bubbleSortExercise();
//    payrollSystem();
//    splitAndJoin();
//    salaryEmployeeToCSVFile();
//    extendPayrollWithHourlyAndCommissionEmployee();
      finalExercise();
    return 0;
}

// Exercise 1.1: Supermarket

void supermarket () {
    std::cout << "Supermarket" << std::endl;
    std::cout << "===========" << std::endl;

    int number;
    std::string title_string = "Please select product (1-10) 0 to Quit: ";
    std::string incorrect_number_warning = "Please select correct product (1-10)";
    int prodprices[] = { 10, 14, 22, 33, 44, 13, 22, 55, 66, 77 };

    std::vector<int> selected_product_prices;

    while (true) {

        number = getNumber(title_string, &number);

        if (number <0 || number > 10) {
            std::cout << incorrect_number_warning << std::endl;
            continue;
        }

        if (number == 0) {
            break;
        }

        std::cout << "Product: " << number << " Price: " << prodprices[number-1] << std::endl;
        selected_product_prices.push_back(prodprices[number-1]);
    }

    int total = 0;

    for (int i=0; i<selected_product_prices.size(); i++) {
        total += selected_product_prices[i];
    }

    std::cout << "Total: " << total << std::endl;

    int payment;
    std::cout << "Payment: ";
    std::cin >> payment;

    int change = payment - total;

    std::cout << "Change: " << change << std::endl;
}

int getNumber (std::string title_string, int* number) {

    std::cout << title_string;
    std::cin >> *number;

    return *number;
}

// Exercise 1.2: Employee

void employee () {

    std::string title_string = "Please enter employee name (0 to quit): ";
    std::string employee_name;


    std::vector<std::string> names;

    while (true) {
        std::string get_employee_name = getEmployeeName(title_string, &employee_name);

        if (get_employee_name == "0") {
            break;
        }

        names.push_back(get_employee_name);
    }

    for (int i=0; i<names.size(); i++) {
        std::cout << "Id: " << (i+1) << " Name: " << names[i] << std::endl;
    }
};

std::string getEmployeeName (std::string title_string, std::string* employee_name) {
    std::cout << title_string;
    std::getline(std::cin >> std::ws, *employee_name);
    return *employee_name;
}

// Exercise 1.3: Bubble Sort

void bubbleSortExercise () {
    int number;
    std::cout << "Please Enter the Total Number of Elements : ";
    std::cin >> number;
    int list[number];
    for (int i=0;i<number;i++)
    {
        int value;
        std::cout << "Please enter the " << i+1 << " Element: ";
        std::cin >> value;
        list[i] = value;
    }
    int *sorted = bubblesort(list,number);
    std::cout << "The Sorted List in Ascending Order: [";
    for(int i = 0; i<number-1; i++) {
        std::cout << sorted[i] << ", ";
    }
    std::cout << sorted[number-1] << "]" << std::endl;
}

int* bubblesort (int a[], int n) {

    for (int i=n-1; i>=0; i--) {
        for (int f=0; f<i; f++) {
            if (a[f] > a[f+1]) {
                int temp = a[f];
                a[f] = a[f+1];
                a[f+1] = temp;
            }
        }
    }

    return a;
}

//Exercise: PayrollSystem

class EmployeeWithPayroll {
private:
    std::string name;
    int amount;

public:
    EmployeeWithPayroll() {

    }

    EmployeeWithPayroll(std::string name, int amount) {
        this->name = name;
        this->amount = amount;
    }

    std::string getName () {
        return this->name;
    }

    int getAmount () {
        return this->amount;
    }
};

int getSalary (std::string salary) {
    std::cout << "Please enter salary: ";
    std::getline(std::cin, salary);
    return std::stoi(salary);
}

void payrollSystem() {

    std::string title_string = "Please enter employee name (0 to quit): ";
    std::string employee_name;
    std::string salary;
    std::vector<EmployeeWithPayroll> list;

    while (true) {
        employee_name = getEmployeeName(title_string, &employee_name);

        if (employee_name == "0") {
            break;
        }

        int get_salary = getSalary(salary);

        EmployeeWithPayroll* employeeWithPayroll = new EmployeeWithPayroll(employee_name, get_salary);
        list.push_back(*employeeWithPayroll);

        delete employeeWithPayroll;
    }

    for (int i=0; i<list.size(); i++) {
        std::cout << "Employee Payroll" << std::endl;
        std::cout << "================" << std::endl;
        std::cout << "Payroll for: " << (i+1) << " - " << list[i].getName() << std::endl;
        std::cout << "- Check amount: " << list[i].getAmount() << std::endl;
    }
}

//Exercise 1.5: My own split and join
void splitAndJoin () {
    std::string sentence;
    std::cout << "Please enter sentence: ";
    std::getline (std::cin,sentence);
    std::cout << myjoin(mysplit(sentence, ' '), ',') << std::endl;
    std::cout << myjoin(mysplit(sentence, ' '), '\n') << std::endl;
}

std::string myjoin(std::vector<std::string> lst, char sep) {

    std::string result = "";

    for (int i=0; i < lst.size(); i++) {
        if (i != lst.size() - 1) {
            result += lst[i] + sep;
        } else {
            result += lst[i];
        }
    }

    return result;

}

std::vector<std::string> mysplit(std::string sentence, char sep) {

    std::vector<std::string> result;

    std::stringstream ss(sentence);

    for (std::string i; ss >> i;) {
        result.push_back(i);

        if (ss.peek() == sep) {
            ss.ignore();
        }
    }
    return result;
}


// Exercise 1.6: SalaryEmployee to CSV-file

class Employee
{
public:
    int id;
    std::string name;
    Employee(int id, std::string name) : id(id), name(name)
    {
    }
    virtual void Print()
    {
        std::cout << "Id: " << id << " Name: " << name << std::endl;
    }
    virtual int CalculateSalary() {
        return 0;
    };


};

class SalaryEmployee : public Employee
{
public:
    int monthly_salary;
    SalaryEmployee(int id, std::string name, int monthly_salary) : Employee(id, name), monthly_salary(monthly_salary)
    {
    }
    virtual void Print()
    {
        std::cout << "Id: " << id << " Name: " << name << " Salary: " << monthly_salary << std::endl;
    }
    virtual int CalculateSalary()
    {
        return monthly_salary;
    }

};


class Employeelist
{
public:
    std::vector<Employee*> employees;
    void Menu()
    {
        int value = 9;
        int quit = 0;

        while (value != quit)
        {
            std::cout << "Payroll Menu" <<std::endl;
            std::cout << "============" <<std::endl;
            std::cout << "(1) Add employees" <<std::endl;
            std::cout << "(2) Write employees to file" <<std::endl;
            std::cout << "(3) Read employees from file" <<std::endl;
            std::cout << "(4) Print employees" <<std::endl;
            std::cout << "(0) Quit" <<std::endl;
            std::cout << "Please select: ";
            std::cin >> value;
            std::cout << std::endl;
            switch (value) {
                case 1:
                    std::cin.ignore();
                    Insert();
                    std::cout << std::endl;
                    break;
                case 2:
                    WriteToFile(employees);;
                    std::cout << std::endl;
                    break;
                case 3:
                    ReadFromFile();
                    std::cout << std::endl;
                    break;
                case 4:
                    Print(employees);
                    std::cout << std::endl;
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Incorrect selection\n" << std::endl;
                    break;
            }
        }
    }
    void Insert()
    {
        std::string name = " ";
        std::string quit = "0";
        int id = 1, salary;

        while (name != quit)
        {
            std::cout << "Please enter employee name (0 to quit): ";
            getline (std::cin,name);
            if (name != quit)
            {
                std::cout << "Please enter salary: ";
                std::cin >> salary;
                employees.push_back(new SalaryEmployee(id,name,salary));
                id++;
                std::cin.ignore();
            }
        }
    }

    void WriteToFile (std::vector<Employee*> employees) {
        std::fstream fout;

        std::string filename = "../files/salary_employee.csv";
        // opens an existing csv file or creates a new file.
        fout.open(filename, std::ios::out | std::ios::app);

        for (int i=0; i<employees.size(); i++) {
            fout << employees[i]->id << "," << employees[i]->name << "," << employees[i]->CalculateSalary() << "\n";
        }

        std::cout << employees.size() << " employee(s) added to file " << filename << std::endl;

    }

    void ReadFromFile () {
        std::string filename = "../files/salary_employee.csv";
        std::fstream file (filename, std::ios::in);

        std::vector<std::vector<std::string>> content;
        std::vector<std::string> row;

        std::string line, word;
        if (file.is_open()) {
            while(getline(file, line))
            {
                row.clear();

                std::stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }

        } else {
            std::cout<<"Could not open the file\n";
            exit(-1);
        }

        std::cout << employees.size() << " employee(s) read from file " << filename << std::endl;
    }

    void Print(std::vector<Employee*> employees)
    {
        for(int i=0;i<employees.size();i++)
        {
            employees[i]->Print();
        }
    }
};

void salaryEmployeeToCSVFile() {
    Employeelist myList = *new Employeelist();
    myList.Menu();
}

//Exercise 1.7: Extend PayrollSystem with HourlyEmployee and CommissionEmployee

class HourlyEmployee : public SalaryEmployee {

public:

    HourlyEmployee(int id, std::string name, int hour_rate, int hour_worked);

    void AskSalary (int id, std::string name, int hour_rate, int hour_worked) {
        this->id = id;
        this->name = name;
        this->monthly_salary = hour_rate * hour_worked;
    };

    int CalculateSalary()
    {
        return monthly_salary;
    }
};

HourlyEmployee::HourlyEmployee(int id, std::string name, int hour_rate, int hour_worked) : SalaryEmployee(id, name, hour_rate * hour_worked){
    this->id = id;
    this->name = name;
    this->monthly_salary = hour_rate * hour_worked;
}


class CommissionEmployee : public SalaryEmployee {

public:

    CommissionEmployee(int id, std::string name, int monthly_salary, int commission);

    void AskSalary (int id, std::string name, int monthly_salary, int commission) {
        this->id = id;
        this->name = name;
        this->monthly_salary = monthly_salary + commission;
    };

    int CalculateSalary()
    {
        return monthly_salary;
    }
};

CommissionEmployee::CommissionEmployee(int id, std::string name, int monthly_salary, int commission) : SalaryEmployee(id, name, monthly_salary + commission){
    this->id = id;
    this->name = name;
    this->monthly_salary = monthly_salary + commission;
}

class PayrollSystem {
public:
    void Menu () {

        std::string title_string_to_ask_employee_name = "Please enter employee name: ";
        int salary_type;
        std::string employee_name;
        std::vector<Employee*> employees;
        int id = 1;
        while (true) {

            std::cout << "Salary type" << std::endl;
            std::cout << "-----------" << std::endl;
            std::cout << "(1) Monthly" << std::endl;
            std::cout << "(2) Hourly" << std::endl;
            std::cout << "(3) Commission" << std::endl;
            std::cout << "(0) Quit" << std::endl;

            std::cout << "Please enter salary type: ";
            std::cin >> salary_type;

            std::string employee_name;

            if (salary_type == 0) {
                break;
            }

            if (salary_type < 0 || salary_type > 3) {
                std::cout << "Incorrect selection\n" << std::endl;
                break;
            }

            if (salary_type == 1) {
                std::cin.ignore();
                std::cout << "" << std::endl;
                employee_name = getEmployeeName("Please enter employee name: ", &employee_name);
                int monthly_salary = getValueForCalculatingSalary("Please enter monthly salary: ");
                Employee *salary_employee = new SalaryEmployee(id, employee_name, monthly_salary);
                employees.push_back(salary_employee);
                id++;
            }

            if (salary_type == 2) {
                std::cin.ignore();
                std::cout << "" << std::endl;
                employee_name = getEmployeeName("Please enter employee name: ", &employee_name);
                int hour_rate = getValueForCalculatingSalary("Please enter hour rate: ");
                int hour_worked = getValueForCalculatingSalary("Please enter hours worked: ");
                Employee *hourly_employee = new HourlyEmployee(id, employee_name, hour_rate, hour_worked);
                employees.push_back(hourly_employee);
                id++;
            }

            if (salary_type == 3) {
                std::cin.ignore();
                std::cout << "" << std::endl;
                employee_name = getEmployeeName("Please enter employee name: ", &employee_name);
                int monthly_salary = getValueForCalculatingSalary("Please enter monthly salary: ");
                int commission = getValueForCalculatingSalary("Please enter commission: ");
                Employee* commission_employee = new CommissionEmployee(id, employee_name, monthly_salary, commission);
                employees.push_back(commission_employee);
                id++;
            }

        }
        std::cout << "" << std::endl;
        for (int i=0; i<employees.size(); i++) {
            std::cout << "Employee Payroll" << std::endl;
            std::cout << "================" << std::endl;
            std::cout << "Payroll for: " << employees[i]->id << " - " << employees[i]->name << std::endl;
            std::cout << "- Check amount: " << employees[i]->CalculateSalary() << std::endl;
            std::cout << "" << std::endl;
        }
    }
};

int getValueForCalculatingSalary(std::string title) {

    std::string get_value;
    std::cout << title;
    std::getline(std::cin, get_value);

    return std::stoi(get_value);
}

void extendPayrollWithHourlyAndCommissionEmployee()  {
    PayrollSystem payrollSystem1;
    payrollSystem1.Menu();
}









//Exercise 1.8: Complete Payroll with File handling

class EmployeeFinal
{
public:
    int id;
    std::string name;
    EmployeeFinal(int id, std::string name) : id(id), name(name)
    {
    }
    virtual void Print()
    {
        std::cout << "Id: " << id << " Name: " << name << std::endl;
    }
    virtual int CalculateSalary() {
        return 0;
    };

    virtual void SecondPrint () {
        std::cout << "Id: " << id << " Name: " << name << std::endl;
    }

    virtual void addToCSV () {
        std::cout << "Print to CSV" << std::endl;
    }

};



class SalaryEmployeeFinal : public EmployeeFinal
{
public:
    int monthly_salary;
    SalaryEmployeeFinal(int id, std::string name, int monthly_salary) : EmployeeFinal(id, name), monthly_salary(monthly_salary)
    {
    }
    virtual void Print()
    {
        std::cout << "Id: " << id << " Name: " << name << " Salary: " << monthly_salary << std::endl;
    }
    virtual int CalculateSalary()
    {
        return monthly_salary;
    }
    virtual void SecondPrint () {
        std::cout << "Employee Payroll" << std::endl;
        std::cout << "================" << std::endl;
        std::cout << "Payroll for: " <<  this->id << " - " << this->name <<std::endl;
        std::cout << "- Check amount: " << this->monthly_salary << std::endl;
        std::cout << "" << std::endl;
    }

    virtual void addToCSV () {

        std::fstream fout;

        std::string filename = "../files/employee.csv";

        fout.open(filename, std::ios::out | std::ios::app);

        fout << this->id << "," << this->name << "," << "S," << this->monthly_salary << "\n";
    }
};

class HourlyEmployeeFinal : public SalaryEmployeeFinal {
private:
    int hour_rate;
    int hour_worked;

public:
    HourlyEmployeeFinal(int id, std::string name, int hour_rate, int hour_worked);

    virtual void SecondPrint () {
        std::cout << "Employee Payroll" << std::endl;
        std::cout << "================" << std::endl;
        std::cout << "Payroll for: " <<  this->id << " - " << this->name <<std::endl;
        std::cout << "- Check amount: " << this->monthly_salary << std::endl;
        std::cout << "" << std::endl;
    }

    void addToCSV () {

        std::fstream fout;

        std::string filename = "../files/employee.csv";

        fout.open(filename, std::ios::out | std::ios::app);

        fout << this->id << "," << this->name << "," << "H," << this->hour_rate << "," << this->hour_worked << "\n";
    }
};

HourlyEmployeeFinal::HourlyEmployeeFinal(int id, std::string name, int hour_rate, int hour_worked) : SalaryEmployeeFinal(id, name, hour_rate * hour_worked) {
    this->id = id;
    this->name = name;
    this->hour_rate = hour_rate;
    this->hour_worked = hour_worked;
    this->monthly_salary = hour_rate * hour_worked;
};

class CommissionEmployeeFinal : public SalaryEmployeeFinal {
private:
    int prev_monthly_salary;
    int commission;

public:
    CommissionEmployeeFinal (int id, std::string name, int monthly_salary, int commission);

    virtual void SecondPrint () {
        std::cout << "Employee Payroll" << std::endl;
        std::cout << "================" << std::endl;
        std::cout << "Payroll for: " <<  this->id << " - " << this->name <<std::endl;
        std::cout << "- Check amount: " << this->monthly_salary << std::endl;
        std::cout << "" << std::endl;
    }

    void addToCSV () {

        std::fstream fout;

        std::string filename = "../files/employee.csv";

        fout.open(filename, std::ios::out | std::ios::app);

        fout << this->id << "," << this->name << "," << "C," << this->prev_monthly_salary << "," << this->commission << "\n";
    }
};

CommissionEmployeeFinal::CommissionEmployeeFinal(int id, std::string name, int monthly_salary, int commission) : SalaryEmployeeFinal(id, name, monthly_salary + commission) {
    this->id = id;
    this->name = name;
    this->commission = commission;
    this->prev_monthly_salary = monthly_salary;
    this->monthly_salary = monthly_salary + commission;
};

int getSalaryFromInput (std::string title) {

    int number_input;
    std::cout << title;
    std::cin >> number_input;

    return number_input;
}

std::string getEmployeeNameWithCheck (std::string title, std::string* employee_name, std::vector<EmployeeFinal*>& employees);

class PayrollSystemFinal {
public:
    void Menu (std::vector<EmployeeFinal*>& employees, int* id) {

        std::string employee_name;
        while (true) {

            std::cout << "Salary type" << std::endl;
            std::cout << "-----------" << std::endl;
            std::cout << "(1) Monthly" << std::endl;
            std::cout << "(2) Hourly" << std::endl;
            std::cout << "(3) Commission" << std::endl;
            std::cout << "(0) Quit" << std::endl;

            int salary_type;
            std::cout << "Please enter salary type: ";
            std::cin >> salary_type;

            if (salary_type == 0) {
                break;
            }

            if (salary_type < 0 or salary_type > 3) {
                std::cout << "Incorrect selection\n" << std::endl;
                break;
            }

            if (salary_type == 1) {
                std::cin.ignore();
                std::cout << "" << std::endl;
                employee_name = getEmployeeNameWithCheck("Please enter employee name: ", &employee_name, employees);
                int monthly_salary = getValueForCalculatingSalary("Please enter monthly salary: ");
                EmployeeFinal* salary_employee = new SalaryEmployeeFinal(*id, employee_name, monthly_salary);
                employees.push_back(salary_employee);
                *id = *id + 1;
            }

            if (salary_type == 2) {
                std::cin.ignore();
                std::cout << "" << std::endl;
                employee_name = getEmployeeNameWithCheck("Please enter employee name: ", &employee_name, employees);
                int hour_rate = getValueForCalculatingSalary("Please enter hour rate: ");
                int hour_worked = getValueForCalculatingSalary("Please enter hours worked: ");
                EmployeeFinal* hourly_employee = new HourlyEmployeeFinal(*id, employee_name, hour_rate, hour_worked);
                employees.push_back(hourly_employee);
                *id = *id + 1;
            }

            if (salary_type == 3) {
                std::cin.ignore();
                std::cout << "" << std::endl;
                employee_name = getEmployeeNameWithCheck("Please enter employee name: ", &employee_name, employees);
                int monthly_salary = getValueForCalculatingSalary("Please enter monthly salary: ");
                int commission = getValueForCalculatingSalary("Please enter commission: ");
                EmployeeFinal* salary_employee = new CommissionEmployeeFinal(*id, employee_name, monthly_salary, commission);
                employees.push_back(salary_employee);
                *id = *id + 1;
            }
        }
    }
};

class EmployeelistFinal
{
public:
    std::vector<EmployeeFinal*> employees;
    void Menu()
    {
        int value = 9;
        int quit = 0;
        int id = 1;

        while (value != quit)
        {
            std::cout << "Payroll menu" <<std::endl;
            std::cout << "============" <<std::endl;
            std::cout << "(1) Add employees" <<std::endl;
            std::cout << "(2) Write employees to file" <<std::endl;
            std::cout << "(3) Read employees from file" <<std::endl;
            std::cout << "(4) Print payroll" <<std::endl;
            std::cout << "(0) Quit" <<std::endl;
            std::cout << "Please select: ";
            std::cin >> value;
            std::cout << std::endl;
            switch (value) {
                case 1:
                    std::cin.ignore();
                    Insert(&id);
                    std::cout << std::endl;
                    break;
                case 2:
                    WriteToFile(employees);;
                    break;
                case 3:
                    ReadFromFile();
                    break;
                case 4:
                    Print(employees);
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Incorrect selection\n" << std::endl;
                    break;
            }
        }
    }
    void Insert(int* id)
    {
        PayrollSystemFinal payrollSystemFinal;
        payrollSystemFinal.Menu(employees, id);
    }

    void WriteToFile (std::vector<EmployeeFinal*> employees) {

        for (int i=0; i<employees.size(); i++) {
            employees[i]->addToCSV();
        }

        std::cout << employees.size() << " employee(s) added to file " << "../files/employee.csv" << std::endl;
    }

    void ReadFromFile () {

        std::string filename = "../files/employee.csv";
        std::fstream file (filename, std::ios::in);

        std::vector<std::vector<std::string>> content;
        std::vector<std::string> row;

        std::string line, word;
        if (file.is_open()) {
            while(getline(file, line))
            {
                row.clear();

                std::stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }

        } else {
            std::cout<<"Could not open the file\n";
            exit(-1);
        }

        std::cout << employees.size() << " employee(s) read from file " << filename << std::endl;
    }

    void Print(std::vector<EmployeeFinal*> employees)
    {
        for(int i=0;i<employees.size();i++)
        {
            employees[i]->SecondPrint();
        }
    }
};


void finalExercise () {

    EmployeelistFinal employeelistFinal;
    employeelistFinal.Menu();
}

//Common format
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int number;
//    int number_square;
//
//    cout << "Input an integer: ";
//    cin >> number;
//    number_integer = number * number;
//    cout << "The square if the number is: " << number_square << endl;
//}

std::string getEmployeeNameWithCheck (std::string title, std::string* employee_name, std::vector<EmployeeFinal*>& employees) {
    std::cout << title;

    std::getline(std::cin >> std::ws, *employee_name);

    for (int i=0; i<employees.size(); i++) {
        if (employees[i]->name == *employee_name) {
            std::cout << "Duplicate employees are not allowed. Please enter again!" << std::endl;
            std::string get_name = getEmployeeNameWithCheck(title, employee_name, employees);
            return get_name;
        }
    }

    return *employee_name;

}

