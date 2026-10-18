#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Struct definitions
struct Student
{
	char fullName[50];
	float gpa;
};

struct Fraction
{
	int numerator, denominator;
};

// 1
void checkNumber()
{
	printf("Moi nhap so: ");
	float num;
	scanf("%f", &num);
	// so nguyen
	if (num == (int)num)
	{
		printf("%.0f la so nguyen\n", num);
	}
	else
	{
		printf("%.1f la so thuc\n", num);
	}

	/* so nguyen to */
	int count = 0;
	int i;
	for (i = 1; i <= (int)num; i++)
	{
		if ((int)num % i == 0)
		{
			count++;
		}
	}
	if (count == 2)
	{
		printf("%.0f la so nguyen to\n", num);
	}
	else
	{
		printf("KHONG PHAI so nguyen to\n");
	}

	// so chinh phuong
	if (sqrt(num) == (int)sqrt(num))
	{
		printf("%.0f la so chinh phuong\n", num);
	}
	else
	{
		printf("KHONG PHAI so chinh phuong\n");
	}
}

// 2
void findGcdLcm()
{
	int a, b;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	int i, gcd = 1;
	for (i = 1; i <= a && i <= b; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcd = i;
		}
	}
	printf("UCLN cua %d va %d la: %d\n", a, b, gcd);
	int lcm = (a * b) / gcd;
	printf("BCNN cua %d va %d la: %d", a, b, lcm);
}

// 3
void calculateKaraokeFee()
{
	int checkIn, checkOut;
	const int price = 150000;
	double totalAmount;
AGAIN:
	printf("Gio bat dau: ");
	scanf("%d", &checkIn);
	printf("Gio ket thuc: ");
	scanf("%d", &checkOut);
	if (checkIn < 12 || checkOut > 23 || checkIn >= checkOut)
	{
		printf("Quan chua hoat dong\n");
		goto AGAIN;
	}
	// so gio
	int totalHours = checkOut - checkIn;
	if (totalHours <= 3)
	{
		totalAmount = totalHours * price;
	}
	else
	{
		totalAmount = 3 * price + (totalHours - 3) * price * 0.7;
		printf("%.1lf", totalAmount);
	}
	if (checkIn >= 14 && checkOut <= 17)
	{
		totalAmount = totalAmount * 0.9;
		printf("%.1lf", totalAmount);
	}
}

// 4
void calculateElectricityBill()
{
	const float tier1 = 1.678,
				tier2 = 1.734,
				tier3 = 2.014,
				tier4 = 2.536,
				tier5 = 2.834,
				tier6 = 2.927;
	float kwh, electricityBill;
	printf("Moi nhap vao so kWh: ");
	scanf("%f", &kwh);
	if (kwh < 50)
	{
		electricityBill = kwh * tier1;
	}
	else if (kwh < 100)
	{
		electricityBill = (50 * tier1) + (kwh - 50) * tier2;
	}
	else if (kwh < 200)
	{
		electricityBill = (50 * tier1) + (50 * tier2) + (kwh - 100) * tier3;
	}
	else if (kwh < 300)
	{
		electricityBill = (50 * tier1) + (50 * tier2) + (100 * tier3) + (kwh - 200) * tier4;
	}
	else if (kwh < 400)
	{
		electricityBill = (50 * tier1) + (50 * tier2) + (100 * tier3) + (100 * tier4) + (kwh - 300) * tier5;
	}
	else
	{
		electricityBill = (50 * tier1) + (50 * tier2) + (100 * tier3) + (100 * tier4) + (100 * tier5) + (kwh - 400) * tier6;
	}
	printf(" %.2f kWh tuong unng %.2f VND", kwh, electricityBill);
}

// 5
void exchangeMoney()
{
	int amount, noteCount, i, denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1}; // 9 menh gia
	printf("Nhap so tien can doi (x1000 VND): ");
	scanf("%d", &amount);
	while (amount)
	{ // dk true la so tien > 0
		for (i = 0; i < 9; i++)
		{
			noteCount = amount / denominations[i];
			if (noteCount != 0)
			{
				printf("Co %d to %d\n", noteCount, denominations[i]);
			}
			amount = amount - noteCount * denominations[i]; // cap nhat gia tien, neu con du -> thuc hien tiep vong lap voi menh gia khac
		}
	}
}

// 6
void inputLoanAmount(double *loanAmount)
{
	printf("Nhap so tien can vay: ");
	scanf("%lf", loanAmount);
}

void calculateInterest(double loanAmount)
{
	int i;
	double principal = loanAmount / 12; // khong de trong vong lap vi so tien vay se bi thay doi
	for (i = 1; i <= 12; i++)
	{
		double interest = loanAmount * 0.05;
		double totalPayment = principal + interest;
		loanAmount = loanAmount - principal;
		printf("Thang: %d | Lai phai tra: %.1lf | Goc phai tra: %.1lf | Tien phai tra: %.1lf | Tien con lai: %.1lf \n", i, interest, principal, totalPayment, loanAmount);
		printf("\n");
	}
}

// 7
void calculateInstallmentLoan(float loanPercentage)
{
	double downPaymentPercentage = 1.0 - loanPercentage;
	double totalAmount = 500000000;
	double monthlyInterestRate = 0.072 / 12; // tinh theo nam khong can chia 12
	int duration = 12;						 // thoi han 24 nam = 288 thang

	double downPaymentAmount = totalAmount * downPaymentPercentage;
	totalAmount = totalAmount - downPaymentAmount;

	double monthlyPrincipal = totalAmount / duration;

	printf("So tien tra truoc: %.2f\n", downPaymentAmount);
	printf("So tien tra hang thang: \n");
	printf("Ky han\tLai phai tra\tGoc phai tra\tSo tien phai tra\tSo tien con no\n");

	for (int i = 1; i <= duration; i++)
	{
		double interestPayment = totalAmount * monthlyInterestRate;
		double totalMonthlyPayment = interestPayment + monthlyPrincipal;
		totalAmount = totalAmount - monthlyPrincipal;

		printf("%d\t%.2lf\t%.2lf\t%.2lf\t\t%.2lf\n", i, interestPayment, monthlyPrincipal, totalMonthlyPayment, totalAmount);
	}
}

void function_7()
{
	double loanPercentage;
	printf("Nhap phan tram vay (0 - 1): ");
	scanf("%lf", &loanPercentage);
	calculateInstallmentLoan(loanPercentage);
}

// 8
void sortStudents()
{
	int n, i, j;
	printf("Nhap so SV muon them:\t");
	scanf("%d", &n);
	struct Student studentList[n];
	for (i = 0; i < n; i++)
	{
		printf("Nhap ho va ten sinh vien thu %d: ", i + 1);
		fflush(stdin);
		gets(studentList[i].fullName);

		printf("Nhap diem TB sinh vien thu %d: ", i + 1);
		fflush(stdin);
		scanf("%f", &studentList[i].gpa);
		// getchar();
		printf("\n");
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (studentList[i].gpa > studentList[j].gpa)
			{
				// hoan vi
				float tempGpa = studentList[i].gpa;
				studentList[i].gpa = studentList[j].gpa;
				studentList[j].gpa = tempGpa;

				// hoan vi ten (ky tu chuoi)
				char tempName[50];
				strcpy(tempName, studentList[i].fullName);
				strcpy(studentList[i].fullName, studentList[j].fullName);
				strcpy(studentList[j].fullName, tempName);
			}
		}
	}

	printf("Danh sach sinh vien\n");
	for (i = 0; i < n; i++)
	{
		printf("Ho ten: %s\n", studentList[i].fullName);
		printf("Diem TB: %.1f\n", studentList[i].gpa);

		if (studentList[i].gpa >= 9)
		{
			printf("Hoc luc: Xuat sac\n");
		}
		else if (studentList[i].gpa >= 8)
		{
			printf("Hoc luc: Gioi\n");
		}
		else if (studentList[i].gpa >= 6.5)
		{
			printf("Hoc luc: Kha\n");
		}
		else if (studentList[i].gpa >= 5)
		{
			printf("Hoc luc: Trung binh\n");
		}
		else if (studentList[i].gpa >= 3)
		{
			printf("Hoc luc: Yeu\n");
		}
		else
		{
			printf("Hoc lai\n");
		}
		printf("\n");
	}
}

// 9
void lottery()
{
	int a, b;
	printf("Nhap so a: ");
	scanf("%d", &a);
	printf("Nhap so b: ");
	scanf("%d", &b);

	srand((unsigned int)time(NULL));
	int random1 = rand() % 15 + 1;
	int random2 = rand() % 15 + 1;
	printf("con so may man la: %d va %d", random1, random2);

	if ((random1 == a && random2 == b) || (random1 == b && random2 == a))
	{
		printf("\nBan da trung GIAI NHAT");
	}
	else if (random1 != a || random2 == b || random1 == a || random2 != b)
	{
		printf("\nBan da trung GIAI NHI");
	}
	else
	{
		printf("\nChuc ban may man lan sau");
	}
}

// 10
void inputFraction(struct Fraction *f)
{
	printf("Nhap tu so: ");
	scanf("%d", &f->numerator);
	printf("Nhap mau so: ");
	scanf("%d", &f->denominator);
}

void printFraction(struct Fraction f)
{
	printf("%d/%d\n\n", f.numerator, f.denominator);
}

struct Fraction addFractions(struct Fraction f1, struct Fraction f2)
{
	struct Fraction sum;
	sum.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	sum.denominator = f1.denominator * f2.denominator;
	return sum;
}

int main()
{
	printf("\nAssignment Nhap Mon Lap Trinh\n");
	printf("Nguoi thuc hien: Nguyen Phan Lam Hung\n");
	printf("\n");
	printf("Nhan [Y] de chon chuong trinh, [N] de thoat chuong trinh\n");

	int option;
	char choice;
	printf("Chon de tiep tuc hoac dung lai\n");

LABEL:
	scanf("%c%*c", &choice);
	if (choice == 'y' || choice == 'Y')
	{
		goto MENU;
	}
	else if (choice == 'n' || choice == 'N')
	{
		printf("Da thoat");
		return 0;
	}
	else
	{
		printf("Hay chon Y hoac N de tiep tuc\n");
		goto LABEL;
	}
MENU:
	system("cls");
	printf("*---------------------------------------------------*\n");
	printf("|   [1]  Kiem tra so nguyen                         |\n");
	printf("|   [2]  Tim uoc chung, boi chung                   |\n");
	printf("|   [3]  Chuong trinh tinh tien gio karaoke         |\n");
	printf("|   [4]  Tinh tien dien                             |\n");
	printf("|   [5]  Chuc nang doi tien                         |\n");
	printf("|   [6]  Vay lai xuat ngan hang                     |\n");
	printf("|   [7]  Vay mua xe                                 |\n");
	printf("|   [8]  Sap xep thong tin sinh vien                |\n");
	printf("|   [9]  Lottery                                    |\n");
	printf("|   [10] Lam viec voi phan so                       |\n");
	printf("|   [0]  Thoat khoi chuong trinh                    |\n");
	printf("*---------------------------------------------------*\n");
	do
	{
		printf("*---------------------------------------------------*\n");
		printf("Xin moi chon chuc nang: \t");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			printf("\nChuc nang so 1: Kiem tra so nguyen\n");
			checkNumber();
			break;
		case 2:
			printf("\nChuc nang so 2: Tim Uoc & Boi chung cua 2 so\n");
			findGcdLcm();
			break;
		case 3:
			printf("\nChuc nang so 3: Tinh tien Karaoke\n");
			calculateKaraokeFee();
			break;
		case 4:
			printf("\nChuc nang so 4: Tinh tien dien\n");
			calculateElectricityBill();
			break;

		case 5:
			printf("\nChuc nang so 5: Doi tien le\n");
			exchangeMoney();
			break;

		case 6:
			printf("\nChuc nang so 6: Tinh lai suat vay ngan hang\n");
			double loanAmount;
			inputLoanAmount(&loanAmount);
			calculateInterest(loanAmount);
			break;

		case 7:
			printf("\nChuc nang so 7: Vay tien mua xe\n");
			function_7();
			break;

		case 8:
			printf("\nChuc nang so 8: Sap xep thong tin sinh vien\n");
			sortStudents();
			break;

		case 9:
			printf("\nChuc nang so 9: loterry\n");
			lottery();
			break;

		case 10:
			printf("\nChuc nang so 10: Tinh toan phan so\n");
			struct Fraction f1, f2;
			inputFraction(&f1);
			printFraction(f1);
			inputFraction(&f2);
			printFraction(f2);
			printf("Tong 2 phan so: \n");
			printFraction(addFractions(f1, f2));
			break;

		case 11:
			printf("\nThoat khoi chuong trinh\n");
			break;
		default:
			printf("\nVui long chon dung chuc nang\n");
			break;
		}
	} while (option < 0 || option > 11);
	printf("\nNhan bat ky de tiep tuc\n");
	getch();
	goto MENU;
	return 0;
}