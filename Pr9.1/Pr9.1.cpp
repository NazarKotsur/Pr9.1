#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { KN, IT, ME, FI, TN };

struct Student {
	string prizv;
	int kurs;
	Specialty specialty;
	union {
		int Math;
		int Fizik;
		int Informat;
		int Program;
		int Num_met;
		int Pedagogik;
	};
};

void Create(Student* p, const int n);
void Print(Student* p, const int n);
double Search(Student* p, const int n);
void SearchStudens(Student* p, const int n);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "������ ������� ��������: ";
	cin >> n;

	Student* p = new Student[n];

	Create(p, n);
	Print(p, n);

	double proc = Search(p, n);
	cout << "������� ���� �� ������� ��� 3: " << proc << " %" << endl;

	cout << "�������� � ���� � ������ 4 ��� 5" << endl;
	SearchStudens(p, n);

	return 0;
}

void Create(Student* p, const int n) {
	int specialty;
	for (int i = 0; i < n; i++) {
		cout << "C������ � " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << "�������: "; getline(cin, p[i].prizv);
		cout << "����: "; cin >> p[i].kurs;
		cout << "������ � ����������: "; cin >> p[i].Math;
		cout << "������ � ������: "; cin >> p[i].Fizik;
		cout << "������������ (0 - ��, 1 - ��, 2 - ��, 3 - Բ, 4 - �Ҳ): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;

		switch (p[i].specialty)
		{
		case KN:
			cout << "������ � �������������: "; cin >> p[i].Program;
			break;
		case IT:
			cout << "������ � ��������� ������: "; cin >> p[i].Num_met;
			break;
		case ME:
		case FI:
		case TN:
			cout << "������ � ���������: "; cin >> p[i].Pedagogik;
			break;
		}
		cout << endl;
	}
};

void Print(Student* p, const int n) {
	cout << "============================================================================================================"
		<< endl;
	cout << "| � | ������� | ���� | ���������� | Գ���� | ������������ | ������������� | ������� ������ | ��������� |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < n; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(10) << left << p[i].Math << " "
			<< "| " << setw(6) << left << p[i].Fizik << " "
			<< "| " << setw(14) << left << p[i].specialty;

		switch (p[i].specialty)
		{
		case KN:
			cout << "| " << setw(13) << setprecision(2) << fixed << right
				<< p[i].Program << " |" << setw(18) << right << "|"
				<< setw(13) << right << "|" << endl;
			break;
		case IT:
			cout << "| " << setw(15) << right << "|"
				<< setw(16) << setprecision(2) << fixed << right << p[i].Num_met << " |"
				<< setw(13) << right << "|" << endl;
			break;
		case ME:
		case FI:
		case TN:
			cout << "| " << setw(15) << right << "|"
				<< setw(18) << right << "|"
				<< setw(11) << setprecision(2) << fixed << right << p[i].Num_met << " |" << endl;
			break;
		}
	}
	cout << "============================================================================================================"
		<< endl;
	cout << endl;
};

double Search(Student* p, const int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].Fizik > 3 && p[i].Informat > 3 && p[i].Math > 3 && p[i].Num_met > 3 && p[i].Pedagogik > 3) {
			k++;
		}
	}
	return 100.0 * k / n;
};

void SearchStudens(Student* p, const int n) {
	for (int i = 0; i < n; i++) {
		if (p[i].Fizik == 4 || p[i].Fizik == 5) {
			cout << setw(3) << right << i + 1
				<< ". " << p[i].prizv << endl;
		}
	}
}