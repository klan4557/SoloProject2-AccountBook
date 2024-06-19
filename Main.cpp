#include "header.h"
#include "RecordItem.h"
#include "AccountBook.h"

// ���� ���� �Լ�
void clearBuffer() {
	cin.ignore(INT_MAX, '\n');
}

void printMenu() {
	cout << "\n<===================================�޴� â================================== = > " << endl;
	cout << "1. ����� �ۼ�" << endl;
	cout << "2. ����� �ϰ� ��� ����" << endl;
	cout << "3. ����� ���� ��� ����" << endl;
	cout << "4. ���� ����" << endl;
	cout << "5. ���� �ҷ�����" << endl;
    cout << "6. ����" << endl;
	cout << "\n<===================================�޴� â================================== = > " << endl;
}

// ����� ��ü ���� (���� ������ ����)
AccountBook accountBook("Ledger.csv");

// ����� �ۼ� �Լ� 
void writeLedger() {
    string date, category, asset, description;
    double amount;

    // ��¥ �Է�
    while (true) {
        cout << "��¥�� �Է��ϼ��� (YY-MM-DD ����): ";
        cin >> date;
        if (date.size() != 8 || date[2] != '-' || date[5] != '-') {
            cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
            cin.clear();
            clearBuffer();
        }
        else
            break;
    }

    // �ݾ� �Է�
    while (true) {
        cout << "�ݾ��� �Է��ϼ���: ";
        cin >> amount;
        if (cin.fail()) {
            cout << "���ڸ� �Է��ϼ���." << endl;
            cin.clear();
            clearBuffer();
        }
        else
            break;
    }

    cin.ignore(); // ���� ����

    // �з� �Է�
    while (true) {
        cout << "�з��� �Է��ϼ��� (���� �Ǵ� ����): ";
        getline(cin, category);
        if (category != "����" && category != "����") {
            cout << "���� �Ǵ� ����� �Է��ϼ���." << endl;
        }
        else
            break;
    }

    // �ڻ� �Է�
    while (true) {
        cout << "�ڻ��� �Է��ϼ��� (���� �Ǵ� ī��): ";
        getline(cin, asset);
        if (asset != "����" && asset != "ī��") {
            cout << "���� �Ǵ� ī��� �Է��ϼ���." << endl;
        }
        else
            break;
    }

    // ���� �Է�
    cout << "������ �Է��ϼ���: ";
    getline(cin, description);

    // ����ڰ� �з��� "����"�� �������� ��
    if (category == "����") {
        double expenseAmount = amount;
        accountBook.addExpense(RecordItem(date, expenseAmount, category, asset, description));

        // �ش� �ݾ��� ���� �� ���⿡ �ݿ��ǵ��� ������Ʈ
        accountBook.updateMonthlyRecords(date, expenseAmount, false);
    }
    else {
        // �ٸ� �з��� ������ ��쿡�� �Է¹��� �ݾ����� ���� ��� �߰�
        accountBook.addIncome(RecordItem(date, amount, category, asset, description));
    }
}

// �Ϻ� ����� ���� �Լ�
void viewDailyLedger() {
	accountBook.getDailyRecords();
}

// ���� ����� ���� �Լ�
void viewMonthlyLedger() {
	accountBook.getMonthlyRecords();
}

// ������ �����ϴ� �Լ�
void saveInformation() {
	accountBook.saveToFile();
}

// ���� �ҷ����� �Լ�
void loadInformation() {
	accountBook.loadFromFile();
}

int main() {
	while (true)
	{
		char select;
		printMenu();
		cin >> select;
		if (select > '7' || select < '0') {
			cout << "�ùٸ� �������� �Է��ϼ���." << endl;
			continue;
		}
		switch (select - '0')
		{
		case 1:
			system("cls");
			writeLedger();
			break;
		case 2:
			system("cls");
			viewDailyLedger();
			break;
		case 3:
			system("cls");
			viewMonthlyLedger();
			break;
		case 4:
            system("cls");
            saveInformation();
            break;
		case 5:
            system("cls");
            loadInformation();
            break;
		case 6:
            cout << "���α׷��� �����մϴ�" << endl;
            return 0;
		default:
			cout << "�ùٸ� �������� �Է��ϼ���." << endl;
			break;
		}
	}
}