#include <iostream>
#include <fstream>
#include <sstream>
void circleArea();
void calculatorProgram();
void calculateHypotenuse();
void theory();
void numberIsEvenOrOdd();
void comparisonOperator();
void calculator();
void forStatement();
void factorial ();
int factorialWithRecursion(int number);
void averageCalculation();
void smallestToLargest();
int largest (int numberOne, int numberTwo, int numberThree);
int smallest (int numberOne, int numberTwo, int numberThree);
void matrixArray ();
void workHourCalculator();
void manipulateMatrices();
void introducingObjects();
void objectInteractionOne();
void objectInteractionTwo();
void usingConstructor();
void inheritance ();
void sumOfNumbers ();
void studentsFromAFile();
std::vector<std::string> getWords(std::string row);

int main() {
//  circleArea();
//  calculatorProgram();
//  calculateHypotenuse();
//  theory();
//  numberIsEvenOrOdd();
//  comparisonOperator();
//  calculator();
//  forStatement();
//  factorial();
//  averageCalculation();
//    smallestToLargest();
//    matrixArray();
//    workHourCalculator();
//    manipulateMatrices();
//    introducingObjects();
//    objectInteractionOne();
//    objectInteractionTwo();
//    usingConstructor();
//    inheritance();
//    sumOfNumbers();
//    studentsFromAFile();
    return 0;
}

//Exercise 3.10.2
void circleArea () {
    float circle_radius;

    std::cout << "Input circle radius:";
    std::cin >> circle_radius;

    float pi = 3.142;

    float circle_area = pi * std::pow(circle_radius, 2);

    std::cout << "Circle area with the given radius: " << circle_area << std::endl;
}

//Exercise 4.13.1
void calculatorProgram () {

    int first_number;
    int second_number;

    std::cout << "Input first integer: ";
    std::cin >> first_number;

    std::cout << "Input second integer: ";
    std::cin >> second_number;

    std::cout << first_number << "+" << second_number << " = " << (first_number + second_number) << std::endl;
    std::cout << first_number << "-" << second_number << " = " << (first_number - second_number) << std::endl;
    std::cout << first_number << "*" << second_number << " = " << (first_number * second_number) << std::endl;
    std::cout << "Remainder: " << first_number % second_number << std::endl;
}

//Exercise 4.13.2

void calculateHypotenuse () {

    int first_leg;
    int second_leg;

    std::cout << "Input first triangle leg: ";
    std::cin >> first_leg;
    std::cout << "Input second triangle leg: ";
    std::cin >> second_leg;

    double sum_of_legs = std::pow(first_leg, 2) + std::pow(second_leg, 2);
    double hypotenuse = sqrt(sum_of_legs);

    std::cout << "Hypotenuse length: " << hypotenuse << std::endl;

}

// For theory test

void theory () {
    int number1 = 7;
    int number2 = 3;

    int answer = 2 * 4 + 16 / 8;

    double test_number = 10 / 12;

    std::cout << number1 % number2 << std::endl;
    std::cout << answer << std::endl;
    std::cout << test_number << std::endl;

    int i;
    int variable;
    for(i=1; i<=5; i=i+2)
    {
        variable = i;
        std::cout << variable << " ";
    }
}

// Exercise 5.8.1

void numberIsEvenOrOdd () {

    int number;
    std::cout << "Input an integer: ";
    std::cin >> number;

    if (number % 2 == 0) {
        std::cout << "The number " << number << " is even." << std::endl;
        return;
    }

    std::cout << "The number " << number << " is odd." << std::endl;
}

// Exercise 5.8.2

void comparisonOperator () {

    char type;
    int cubes_of_sugar;
    std::cout << "Do you drink coffee or tea? (k/t) ";
    std::cin >> type;

    std::cout << "With how many cubes of sugar? ";
    std::cin >> cubes_of_sugar;

    if (type == 't') {

        if (cubes_of_sugar < 0) {
            std::cout << "An error occurred in the program!" << std::endl;
        }
        else if (cubes_of_sugar < 3) {
            std::cout << "Tea can have a soothing effect!" << std::endl;
        } else {
            std::cout << "Guess you enjoy your tea overly sweet?" << std::endl;
        }

        return;
    }

    if (cubes_of_sugar < 0) {
        std::cout << "An error occurred in the program!" << std::endl;
    }
    else if (cubes_of_sugar < 3) {
        std::cout << "Coffee certainly is invigorating!" << std::endl;
    } else {
        std::cout << "Well, coffee can taste pretty intense..." << std::endl;
    }

}

// Exercise 5.8.3

void calculator () {

    std::cout << "Choose desired calculation:" << std::endl;
    std::cout << "1: subtraction" << std::endl;
    std::cout << "2: addition" << std::endl;
    std::cout << "3: multiplication" << std::endl;
    std::cout << "4: division" << std::endl;
    std::cout << "5: Remainder" << std::endl;

    int calculation_selection;
    int first_number;
    int second_number;
    std::cout << "Choose a calculation:";
    std::cin >> calculation_selection;
    std::cout << "Input first number:";
    std::cin >> first_number;
    std::cout << "Input second number:";
    std::cin >> second_number;

    switch (calculation_selection) {
        case 1: std::cout << first_number << "-" << second_number << " = " << (first_number - second_number) << std::endl; break;
        case 2: std::cout << first_number << "+" << second_number << " = " << (first_number + second_number) << std::endl; break;
        case 3: std::cout << first_number << "*" << second_number << " = " << (first_number * second_number) << std::endl; break;
        case 4: std::cout << first_number << "/" << second_number << " = " << (first_number / second_number) << std::endl; break;
        case 5: std::cout << first_number << "%" << second_number << " = " << (first_number % second_number) << std::endl; break;
        default: break;
    }
}

//Exercise 6.7.1

void forStatement () {

    std::cout << "Input an integer: ";

    int number;
    std::cin >> number;

    for (int i=1; i<=number; i++){
        std::cout << i << std::endl;
    }
}

// Exercise 6.7.2

void factorial () {

    int number;
    std::cout << "Input an integer: ";
    std::cin >> number;

    int result = factorialWithRecursion(number);

    std::cout << "The factorial of number " << number << " is " << result << std::endl;
}



int factorialWithRecursion (int number) {

    int result = 1;

    if (number == 0) {
        return result;
    }

    int newResult = factorialWithRecursion(number -1);
    newResult *= number;
    return newResult;
}

// Exercise 6.7.3

void averageCalculation() {
    std::cout <<  "Program calculates the test grade average." << std::endl;
    std::cout <<  "Finish inputting with a negative number." << std::endl;
    int number;
    float total_grade = 0;
    float count_grade = 0;
    std::cout << "Input grade (4-10) ";
    std::cin >> number;

    while (number > 0) {
        if (number >= 4 && number <= 10) {
            count_grade++;
            total_grade += number;
        }

        std::cout << "Input grade (4-10) ";
        std::cin >> number;
    }

    std::cout << "You inputted " << count_grade << " grades." << std::endl;
    std::cout << "Grade average: " << (float) (total_grade / count_grade) << std::endl;

}

//Exercise 7.9.1

void smallestToLargest () {
    int number1, number2, number3, largestnumber,smallestnumber;

    std::cout << "Input the first integer";
    std::cin >> number1;

    std::cout << "Input the second integer:";
    std::cin >> number2;

    std::cout << "Input the third integer:";
    std::cin >> number3;

    largestnumber = largest(number1, number2, number3);
    smallestnumber = smallest(number1, number2, number3);

    std::cout << "The largest number was " << largestnumber;
    std::cout << " and the smallest " <<smallestnumber << "." << std::endl;
}

int largest (int first, int second, int third) {

    if (first > second > third) {
        return first;
    } else if (second > first > third) {
        return second;
    }

    return third;
}

int smallest (int first, int second, int third) {

    if (first < second < third) {
        return first;
    } else if (second < first < third) {
        return second;
    }

    return third;
}

void matrixArray () {

    int array[5][5] = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25},
    };

    int arrayTwo[3][5] = {
            {1, 2, 3, 4 , 5},
            {6, 7, 8, 9 , 10},
            {11, 12, 13, 14, 15},
    };

    for (int i=0; i<std::size(array); i++) {
        std::cout << std::endl;
        for (int j=0; j<std::size(array[i]); j++) {
            std::cout << array[i][j] << " ";
        }
    }

    for (int i=0; i < std::size(array[0]); i++) {
        std::cout << std::endl;
        for (int j=0; j<std::size(array); j++) {
            std::cout << array[j][i] << " ";
        }
    }

    for (int i=0; i<std::size(arrayTwo[0]); i++) {
        std::cout << "" << std::endl;
        for (int j=0; j<std::size(arrayTwo); j++) {
            std::cout << arrayTwo[j][i] << " ";
        }
    }
}

// Exercise 8.6.1

void workHourCalculator () {

    std::cout << "The program calculates the total amount of" << std::endl;
    std::cout << "work hours during a given time frame and the average work day length." << std::endl;
    std::cout << "How many days:" << std::endl;

    int number;

    std::cin >> number;

    float array[30];

    for (int i=0; i<number; i++) {
        std::cout << "Input hours of workday " << i + 1 << ": ";
        float hours;
        std::cin >> hours;
        array[i] = hours;
    }

    float total_working_hours = 0;
    for (int i=0; i<number; i++) {
        total_working_hours += array[i];
    }

    float average_work_day_length = total_working_hours / (float) number;

    std::cout << "Total work hours: " << total_working_hours << std::endl;
    std::cout << "Average work day length: " << average_work_day_length << std::endl;

    std::cout << "Inputted hours: ";

    for (int i=0; i < number; i++) {
        if (i == number - 1) {
            std::cout << array[i] << " " << std::endl;
        } else {
            std::cout << array[i] << " ";
        }
    }
}

//Exercise 9.6.1
class PrintClass {
public:
    void print (char charstring[50]) {
        std::cout << charstring << std::endl;
    }
};

void introducingObjects () {
    char charstring[50];
    std::cout << "Input a character string for printing: ";
    std::cin.get(charstring, 50);

    PrintClass printer;
    printer.print(charstring);
}

//Exercise 9.6.2

class AskAndPrint {
public:
    void DoYourThing (char textstring[]) {
        std::cout << textstring;

        std::string text;
        std::getline(std::cin, text);

        std::cout << text << std::endl;
    }
};

void objectInteractionOne() {
    char charstring[] = "Write the text for printing: ";
    AskAndPrint thing;
    thing.DoYourThing(charstring);
}

//Exercise 9.6.3

class Calculator
{
public:

    int Sum(int first, int second);
};

int Calculator::Sum(int first, int second)
{
    int sum = first + second;
    return sum;
}

class Printer {
public:
    void Print () {
        int first_integer;
        int second_integer;

        std::cout << "Give a first integer: ";
        std::cin >> first_integer;

        std::cout << "Give a second integer: ";
        std::cin >> second_integer;

        Calculator calculator1;
        int result = calculator1.Sum(first_integer, second_integer);

        std::cout << "Sum: " << result << std::endl;

    }
};


void objectInteractionTwo() {

    Printer object;
    object.Print();

}

//Exercise 9.6.4

class Dog {
public:
    std::string name;
    int age;
    std::string race;
    std::string voice;

    Dog () {

    }

    Dog (int age, std::string name, std::string race, std::string voice) {
        this->age = age;
        this->name = name;
        this->race = race;
        this->voice = voice;
    }

    void PrintInformation () {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Age: " << this->age << std::endl;
        std::cout << "Race: " << this->race << std::endl;

    }

    std::string Bark () {
        return this->voice;
    }
};

void usingConstructor() {
    Dog buffy(2, "Buffy", "Bulldog", "Hau!!!");
    buffy.PrintInformation();
    std::cout << "Dog says: " << buffy.Bark();
}

//Exercise 10.5.1

class Vehicle {
public:
    int weight;
    int top_speed;
    long driven_km;
    Vehicle(int weight, int top_speed, long driven_km);
    void Drive(int journey);
    int InputWeight();
    int InputTopSpeed();
    long InputDrivenKm();
};

Vehicle::Vehicle(int Aw, int Ats, long Akm)
{
    weight = Aw;
    top_speed = Ats;
    driven_km = Akm;
}

void Vehicle::Drive(int journey)
{
    driven_km += journey;
}

int Vehicle::InputWeight()
{
    return weight;
}

int Vehicle::InputTopSpeed()
{
    return top_speed;
}

long Vehicle::InputDrivenKm()
{
    return driven_km;
}

class Car : public Vehicle {
private:
    std::string brand;
    std::string model;
    std::string license;
    bool running;

public:
    Car(int weight, int top_speed, long driven_km, std::string brand, std::string model, std::string license, bool running);
    void turn_on ();
    void turn_off ();
    void check_up ();
};

Car::Car(int weight, int top_speed, long driven_km, std::string brand, std::string model, std::string license,
         bool running) : Vehicle(weight, top_speed, driven_km){
    this->weight = weight;
    this->top_speed = top_speed;
    this->driven_km = driven_km;
    this->brand = brand;
    this->model = model;
    this->license = license;
    this->running = running;
}

void Car::turn_on() {
    this->running = true;
};

void Car::turn_off() {
    this->running = false;
};

void Car::check_up() {
    std::cout << "Car info:" << std::endl;
    std::cout << "Brand: " << this->brand << std::endl;
    std::cout << "Model: " << this->model << std::endl;
    std::cout << "Kilometres: " << this->driven_km << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Top speed: " << this->top_speed << std::endl;
    std::cout << "License plate: " << this->license << std::endl;

    if (this->running) {
        std::cout << "Car is running." << std::endl;
        return;
    }

    std::cout << "Car is not running." << std::endl;
}

void inheritance () {

    int weight, speed;
    long km;
    std::string brand, model, license;

    // Ask for car information
    std::cout << "Input car brand: ";
    std::cin >> brand;

    std::cout << "Input car model: ";
    std::cin >> model;

    std::cout << "Input car license plate number: ";
    std::cin >> license;

    std::cout << "Input car weight: ";
    std::cin >> weight;

    std::cout << "Input car top speed: ";
    std::cin >> speed;

    std::cout << "Input distance traveled by car: ";
    std::cin >> km;
    std::cout <<std::endl;
    Car carX(weight, speed, km, brand, model, license, 0);

    carX.check_up();
    carX.turn_on();
    carX.Drive(95);
    std::cout << std::endl;
    carX.check_up();
}

//Exercise 11.16.1

void sumOfNumbers () {

    std::ifstream read ("../files/numbers.txt");
    int number;
    if (read.is_open()) {
        int sum = 0;
        while (read >> number) {
            sum += number;
        }

        std::cout << "Sum is " << sum << std::endl;

    } else {
        std::cout << "Failed to open file!" << std::endl;
        exit(-1);
    }

}

//Exercise 11.16.2

void studentsFromAFile() {

    std::ifstream read("../files/students.txt");

    std::string row;

    if (read.is_open()) {

        while (std::getline(read, row)) {
            std::vector<std::string> single_rows = getWords(row);

            std::string gen_class = single_rows[0];
            std::string full_name = single_rows[1] + " " + single_rows[2];

            std::string output = full_name + ": class " + gen_class;

            std::cout << output << std::endl;
        }
    } else {
        std::cout << "Failed to open file!" << std::endl;
        exit(-1);
    }
};

std::vector<std::string> getWords (std::string row) {

    std::vector<std::string> result;

    std::stringstream ss(row);

    for (std::string i; ss >> i;) {
        result.push_back(i);

        if (ss.peek() == ' ') {
            ss.ignore();
        }
    }

    return result;

}
