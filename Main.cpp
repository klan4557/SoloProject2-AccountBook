#include "header.h"
#include "RecordItem.h"
#include "AccountBook.h"

// 버퍼 비우는 함수
void clearBuffer() {
	cin.ignore(INT_MAX, '\n');
}

void printMenu() {
	cout << "\n<===================================메뉴 창================================== = > " << endl;
	cout << "1. 가계부 작성" << endl;
	cout << "2. 가계부 일간 기록 열람" << endl;
	cout << "3. 가계부 월간 기록 열람" << endl;
	cout << "4. 정보 저장" << endl;
	cout << "5. 정보 불러오기" << endl;
    cout << "6. 종료" << endl;
	cout << "\n<===================================메뉴 창================================== = > " << endl;
}

// 가계부 객체 생성 (전역 변수로 가정)
AccountBook accountBook("Ledger.csv");

// 가계부 작성 함수 
void writeLedger() {
    string date, category, asset, description;
    double amount;

    // 날짜 입력
    while (true) {
        cout << "날짜를 입력하세요 (YY-MM-DD 형식): ";
        cin >> date;
        if (date.size() != 8 || date[2] != '-' || date[5] != '-') {
            cout << "잘못된 형식입니다. 다시 입력하세요." << endl;
            cin.clear();
            clearBuffer();
        }
        else
            break;
    }

    // 금액 입력
    while (true) {
        cout << "금액을 입력하세요: ";
        cin >> amount;
        if (cin.fail()) {
            cout << "숫자를 입력하세요." << endl;
            cin.clear();
            clearBuffer();
        }
        else
            break;
    }

    cin.ignore(); // 버퍼 비우기

    // 분류 입력
    while (true) {
        cout << "분류를 입력하세요 (수입 또는 지출): ";
        getline(cin, category);
        if (category != "수입" && category != "지출") {
            cout << "수입 또는 지출로 입력하세요." << endl;
        }
        else
            break;
    }

    // 자산 입력
    while (true) {
        cout << "자산을 입력하세요 (현금 또는 카드): ";
        getline(cin, asset);
        if (asset != "현금" && asset != "카드") {
            cout << "현금 또는 카드로 입력하세요." << endl;
        }
        else
            break;
    }

    // 내용 입력
    cout << "내용을 입력하세요: ";
    getline(cin, description);

    // 사용자가 분류를 "지출"로 선택했을 때
    if (category == "지출") {
        double expenseAmount = amount;
        accountBook.addExpense(RecordItem(date, expenseAmount, category, asset, description));

        // 해당 금액이 월별 총 지출에 반영되도록 업데이트
        accountBook.updateMonthlyRecords(date, expenseAmount, false);
    }
    else {
        // 다른 분류를 선택한 경우에는 입력받은 금액으로 수입 기록 추가
        accountBook.addIncome(RecordItem(date, amount, category, asset, description));
    }
}

// 일별 가계부 열람 함수
void viewDailyLedger() {
	accountBook.getDailyRecords();
}

// 월별 가계부 열람 함수
void viewMonthlyLedger() {
	accountBook.getMonthlyRecords();
}

// 정보를 저장하는 함수
void saveInformation() {
	accountBook.saveToFile();
}

// 정보 불러오기 함수
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
			cout << "올바른 선택지를 입력하세요." << endl;
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
            cout << "프로그램을 종료합니다" << endl;
            return 0;
		default:
			cout << "올바른 선택지를 입력하세요." << endl;
			break;
		}
	}
}