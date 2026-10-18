#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void checkNumber()
{
	double number;
	cout << "Enter a number: ";
	if (!(cin >> number))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid value.\n";
		return;
	}

	const bool isInteger = floor(number) == number;
	if (isInteger)
		cout << number << " is an integer.\n";
	else
		cout << number << " is a real number.\n";

	bool isPrime = isInteger && number >= 2;
	if (isPrime)
	{
		for (int divisor = 2; divisor <= sqrt(number); ++divisor)
		{
			if (static_cast<long long>(number) % divisor == 0)
			{
				isPrime = false;
				break;
			}
		}
	}
	cout << (isPrime ? "It is a prime number.\n" : "It is not a prime number.\n");

	const bool isPerfectSquare = number >= 0 && floor(sqrt(number)) == sqrt(number);
	cout << (isPerfectSquare ? "It is a perfect square.\n" : "It is not a perfect square.\n");
}

void findGcdAndLcm()
{
	int firstNumber, secondNumber;
	cout << "Enter a: ";
	cin >> firstNumber;
	cout << "Enter b: ";
	cin >> secondNumber;

	const int gcd = std::gcd(firstNumber, secondNumber);
	cout << "GCD of " << firstNumber << " and " << secondNumber << " is: " << gcd << '\n';
	if (gcd == 0)
		cout << "LCM is undefined for two zero values.\n";
	else
		cout << "LCM of " << firstNumber << " and " << secondNumber << " is: "
			 << abs(firstNumber / gcd * secondNumber) << '\n';
}

void calculateKaraokeCost()
{
	int startHour, endHour;
	constexpr double hourlyRate = 150000.0;
	while (true)
	{
		cout << "Start time: ";
		cin >> startHour;
		cout << "End time: ";
		cin >> endHour;
		if (startHour >= 12 && endHour <= 23 && startHour < endHour)
			break;
		cout << "Invalid time range. Please try again.\n";
	}

	const int totalHours = endHour - startHour;
	double totalCost = min(totalHours, 3) * hourlyRate;
	if (totalHours > 3)
		totalCost += (totalHours - 3) * hourlyRate * 0.7;
	if (startHour >= 14 && endHour <= 17)
		totalCost *= 0.9;
	cout << "Total cost: " << totalCost << " VND\n";
}

void calculateElectricityBill()
{
	const double rates[] = {1.678, 1.734, 2.014, 2.536, 2.834, 2.927};
	double kilowattHours;
	cout << "Enter electricity usage in kWh: ";
	cin >> kilowattHours;
	if (kilowattHours < 0)
	{
		cout << "Invalid electricity usage.\n";
		return;
	}

	double bill = 0;
	const double tierLimits[] = {50, 50, 100, 100, 100};
	double remaining = kilowattHours;
	for (int tier = 0; tier < 5 && remaining > 0; ++tier)
	{
		const double used = min(remaining, tierLimits[tier]);
		bill += used * rates[tier];
		remaining -= used;
	}
	if (remaining > 0)
		bill += remaining * rates[5];
	cout << kilowattHours << " kWh costs " << bill << " VND.\n";
}

void exchangeMoney()
{
	int amount;
	const int denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
	cout << "Enter the amount to exchange (in thousands of VND): ";
	cin >> amount;
	if (amount < 0)
	{
		cout << "Invalid amount.\n";
		return;
	}

	for (int denomination : denominations)
	{
		const int noteCount = amount / denomination;
		if (noteCount > 0)
			cout << noteCount << " note(s) of " << denomination << " thousand VND\n";
		amount %= denomination;
	}
}

void inputLoanAmount(double &loanAmount)
{
	cout << "Enter the loan amount: ";
	cin >> loanAmount;
}

void calculateLoanRepayment(double loanAmount)
{
	const double monthlyPrincipal = loanAmount / 12;
	for (int month = 1; month <= 12; ++month)
	{
		const double interest = loanAmount * 0.05;
		const double monthlyPayment = monthlyPrincipal + interest;
		loanAmount -= monthlyPrincipal;
		cout << "Month: " << month << " | Interest: " << interest
			 << " | Principal: " << monthlyPrincipal
			 << " | Payment: " << monthlyPayment
			 << " | Remaining balance: " << loanAmount << '\n';
	}
}

void calculateCarInstallments(double loanPercentage)
{
	if (loanPercentage < 0 || loanPercentage > 1)
	{
		cout << "The loan percentage must be between 0 and 1.\n";
		return;
	}

	constexpr double carPrice = 500000000;
	constexpr int termMonths = 12;
	const double downPayment = carPrice * (1.0 - loanPercentage);
	double remainingBalance = carPrice - downPayment;
	const double monthlyPrincipal = remainingBalance / termMonths;
	const double monthlyInterestRate = 0.072 / 12;

	cout << "Down payment: " << downPayment << '\n';
	cout << "Month\tInterest\tPrincipal\tPayment\tRemaining balance\n";
	for (int month = 1; month <= termMonths; ++month)
	{
		const double interest = remainingBalance * monthlyInterestRate;
		const double totalPayment = interest + monthlyPrincipal;
		remainingBalance -= monthlyPrincipal;
		cout << month << '\t' << interest << '\t' << monthlyPrincipal << '\t'
			 << totalPayment << '\t' << remainingBalance << '\n';
	}
}

void runCarLoanCalculator()
{
	double loanPercentage;
	cout << "Enter the loan percentage (0-1): ";
	cin >> loanPercentage;
	calculateCarInstallments(loanPercentage);
}

struct Student
{
	string fullName;
	double averageScore;
};

string getAcademicClassification(double score)
{
	if (score >= 9)
		return "Excellent";
	if (score >= 8)
		return "Very good";
	if (score >= 6.5)
		return "Good";
	if (score >= 5)
		return "Average";
	if (score >= 3)
		return "Poor";
	return "Fail";
}

void sortStudents()
{
	int studentCount;
	cout << "Enter the number of students: ";
	cin >> studentCount;
	if (studentCount <= 0)
	{
		cout << "Invalid number of students.\n";
		return;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<Student> students(studentCount);
	for (int index = 0; index < studentCount; ++index)
	{
		cout << "Enter the full name of student " << index + 1 << ": ";
		getline(cin, students[index].fullName);
		cout << "Enter the average score of student " << index + 1 << ": ";
		cin >> students[index].averageScore;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	for (int i = 0; i < studentCount - 1; ++i)
	{
		for (int j = i + 1; j < studentCount; ++j)
		{
			if (students[i].averageScore > students[j].averageScore)
				swap(students[i], students[j]);
		}
	}

	cout << "Student list\n";
	for (const Student &student : students)
	{
		cout << "Name: " << student.fullName << '\n';
		cout << "Average score: " << student.averageScore << '\n';
		cout << "Classification: " << getAcademicClassification(student.averageScore) << "\n\n";
	}
}

void playLottery()
{
	int firstGuess, secondGuess;
	cout << "Enter your first number: ";
	cin >> firstGuess;
	cout << "Enter your second number: ";
	cin >> secondGuess;

	const int firstLuckyNumber = rand() % 15 + 1;
	const int secondLuckyNumber = rand() % 15 + 1;
	cout << "The lucky numbers are: " << firstLuckyNumber << " and " << secondLuckyNumber;

	if ((firstLuckyNumber == firstGuess && secondLuckyNumber == secondGuess) ||
		(firstLuckyNumber == secondGuess && secondLuckyNumber == firstGuess))
		cout << "\nYou won the FIRST PRIZE!\n";
	else if (firstLuckyNumber == firstGuess || firstLuckyNumber == secondGuess ||
			 secondLuckyNumber == firstGuess || secondLuckyNumber == secondGuess)
		cout << "\nYou won the SECOND PRIZE!\n";
	else
		cout << "\nBetter luck next time!\n";
}

struct Fraction
{
	int numerator;
	int denominator;
};

Fraction inputFraction()
{
	Fraction fraction{};
	cout << "Enter the numerator: ";
	cin >> fraction.numerator;
	do
	{
		cout << "Enter the denominator (non-zero): ";
		cin >> fraction.denominator;
	} while (fraction.denominator == 0);
	return fraction;
}

void printFraction(const Fraction &fraction)
{
	cout << fraction.numerator << '/' << fraction.denominator << "\n\n";
}

Fraction addFractions(const Fraction &first, const Fraction &second)
{
	return {first.numerator * second.denominator + second.numerator * first.denominator,
			first.denominator * second.denominator};
}

void runFractionCalculator()
{
	const Fraction first = inputFraction();
	printFraction(first);
	const Fraction second = inputFraction();
	printFraction(second);
	cout << "Sum of the two fractions: \n";
	printFraction(addFractions(first, second));
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << "\nIntroduction to Programming Assignment\n";
	cout << "Author: Nguyen Phan Lam Hung\n";

	while (true)
	{
		char continueChoice;
		cout << "Press [Y] to continue or [N] to exit: ";
		cin >> continueChoice;
		if (continueChoice == 'n' || continueChoice == 'N')
		{
			cout << "Goodbye.\n";
			return 0;
		}
		if (continueChoice != 'y' && continueChoice != 'Y')
		{
			cout << "Please enter Y or N.\n";
			continue;
		}

		cout << "*---------------------------------------------------*\n";
        cout << "| [1]  Number properties                            |\n";
        cout << "| [2]  GCD and LCM                                  |\n";
        cout << "| [3]  Karaoke billing                              |\n";
        cout << "| [4]  Electricity billing                          |\n";
        cout << "| [5]  Currency exchange                            |\n";
        cout << "| [6]  Bank loan repayment                          |\n";
        cout << "| [7]  Car loan calculator                          |\n";
        cout << "| [8]  Sort student records                         |\n";
        cout << "| [9]  Lottery                                      |\n";
        cout << "| [10] Fraction calculator                          |\n";
        cout << "| [0]  Exit                                         |\n";
        cout << "*---------------------------------------------------*\n";
		
		int choice;
		cout << "Select an option: ";
		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid selection.\n";
			continue;
		}

		switch (choice)
		{
		case 0:
			cout << "Exiting the program.\n";
			return 0;
		case 1:
			checkNumber();
			break;
		case 2:
			findGcdAndLcm();
			break;
		case 3:
			calculateKaraokeCost();
			break;
		case 4:
			calculateElectricityBill();
			break;
		case 5:
			exchangeMoney();
			break;
		case 6:
		{
			double loanAmount;
			inputLoanAmount(loanAmount);
			calculateLoanRepayment(loanAmount);
			break;
		}
		case 7:
			runCarLoanCalculator();
			break;
		case 8:
			sortStudents();
			break;
		case 9:
			playLottery();
			break;
		case 10:
			runFractionCalculator();
			break;
		default:
			cout << "Please select a valid option.\n";
			break;
		}
	}
}
