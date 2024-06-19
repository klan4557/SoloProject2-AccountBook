#include "header.h"
#include "AccountBook.h"

// 생성자 구현
AccountBook::AccountBook(string _fileName) : fileName(_fileName) {}

// 수입 추가 함수 구현
void AccountBook::addIncome(const RecordItem& income) {
    dailyIncomeExpensesRecords.push_back(income);
    updateMonthlyRecords(income.getDate(), income.getAmount(), true);
}

// 지출 추가 함수 구현
void AccountBook::addExpense(const RecordItem& expense) {
    dailyIncomeExpensesRecords.push_back(expense);
    // 월별 기록 업데이트, 여기서는 금액을 변경하지 않음
    updateMonthlyRecords(expense.getDate(), expense.getAmount(), false); 
}

// 월별 기록 업데이트 함수
void AccountBook::updateMonthlyRecords(const string& date, double amount, bool isIncome) {
    string month = date.substr(0, 7); // 입력된 날짜에서 월 정보를 추출합니다. (YY-MM)

    // 해당 월의 월별 기록을 찾습니다.
    auto it = find_if(monthlyIncomeExpensesRecords.begin(), monthlyIncomeExpensesRecords.end(),
        [&](const vector<RecordItem>& monthlyRecord) {
            // 월별 기록 중에서 해당 월의 기록을 찾습니다.
            return monthlyRecord[0].getDate().substr(0, 7) == month;
        });

    if (it != monthlyIncomeExpensesRecords.end()) {
        // 해당 월의 기록이 이미 존재하는 경우
        // 수입 또는 지출을 업데이트합니다.
        int index = isIncome ? 0 : 1; // 수입인 경우 index는 0, 지출인 경우 index는 1

        if (!isIncome) {
            // 지출이 입력된 경우 총 지출을 업데이트합니다.
            double currentExpenses = 0;

            // 해당 월의 모든 일별 기록을 확인하며 지출 합계를 계산합니다.
            for (const auto& record : dailyIncomeExpensesRecords) {
                if (record.getDate().substr(0, 7) == month) {
                    currentExpenses += record.getAmount();
                }
            }

            // 해당 월의 지출을 월별 기록에 업데이트합니다.
            (*it)[1].setAmount(currentExpenses);
        }
        else {
            // 수입이 입력된 경우 해당 월의 총 수입을 업데이트합니다.
            (*it)[0].setAmount((*it)[0].getAmount() + amount);
        }
    }
    else {
        // 해당 월의 기록이 존재하지 않는 경우
        // 새로운 월별 기록을 추가합니다.
        vector<RecordItem> newMonthlyRecord(2); // 월별 수입, 지출 기록을 가진 벡터 생성

        if (isIncome) {
            // 수입이 입력된 경우 해당 월의 총 수입을 업데이트합니다.
            newMonthlyRecord[0] = RecordItem(month + "-01", amount, "총 수입", "", "");
            // 해당 월의 지출은 0으로 설정합니다.
            newMonthlyRecord[1] = RecordItem(month + "-01", 0, "총 지출", "", "");
        }
        else {
            // 지출이 입력된 경우 해당 월의 지출을 계산합니다.
            double currentExpenses = 0;

            // 해당 월의 모든 일별 기록을 확인하며 지출 합계를 계산합니다.
            for (const auto& record : dailyIncomeExpensesRecords) {
                if (record.getDate().substr(0, 7) == month) {
                    currentExpenses += record.getAmount();
                }
            }

            // 해당 월의 지출을 월별 기록에 추가합니다.
            newMonthlyRecord[0] = RecordItem(month + "-01", 0, "총 수입", "", "");
            newMonthlyRecord[1] = RecordItem(month + "-01", currentExpenses, "총 지출", "", "");
        }

        // 새로운 월별 기록을 월별 기록 벡터에 추가합니다.
        monthlyIncomeExpensesRecords.push_back(newMonthlyRecord);
    }
}



// 일별 기록 출력 함수
void AccountBook::getDailyRecords() {
    cout << "일별 기록:" << endl;

    // 먼저 일별 기록을 날짜 순으로 정렬합니다.
    sort(dailyIncomeExpensesRecords.begin(), dailyIncomeExpensesRecords.end(),
        [](const RecordItem& a, const RecordItem& b) {
            return a.getDate() < b.getDate(); // 날짜를 기준으로 오름차순으로 정렬합니다.
        });

    // 정렬된 일별 기록을 순회하며 출력합니다.
    for (const auto& record : dailyIncomeExpensesRecords) {
        cout << "날짜: " << record.getDate() << ", 금액: " << static_cast<int>(record.getAmount()) // 날짜와 금액 출력
            << ", 분류: " << record.getCategory() << ", 자산: " << record.getAsset() << ", 내용: " // 분류와 자산 출력
            << record.getDescription() << endl; // 내용 출력
    }
}


// 월별 기록 출력 함수
void AccountBook::getMonthlyRecords() {
    cout << "월별 기록:" << endl;

    // 월별 기록을 날짜 순으로 정렬합니다.
    sort(monthlyIncomeExpensesRecords.begin(), monthlyIncomeExpensesRecords.end(),
        [](const vector<RecordItem>& a, const vector<RecordItem>& b) {
            return a[0].getDate() < b[0].getDate(); // 각 벡터의 첫 번째 기록의 날짜를 비교하여 정렬합니다.
        });

    // 정렬된 월별 기록을 순회하며 출력합니다.
    for (const auto& record : monthlyIncomeExpensesRecords) {
        size_t pos = record[0].getDate().find('-'); // 날짜에서 연도와 월을 구분하는 '-'의 위치를 찾습니다.
        if (pos != string::npos) { // '-'가 발견되었을 때
            string yearMonth = record[0].getDate().substr(0, pos + 3); // 연도와 월을 추출합니다.
            cout << "년, 월: " << setw(6) << left << yearMonth // 연도와 월 출력
                << ", 총 수입: " << static_cast<int>(record[0].getAmount()) // 첫 번째 기록의 수입 출력
                << ", 총 지출: " << static_cast<int>(record[1].getAmount()) << endl; // 두 번째 기록의 지출 출력
        }
    }
}


// 파일에 저장하는 함수 구현
void AccountBook::saveToFile() {
    ofstream file(fileName); // 파일을 쓰기 모드로 엽니다. 파일명은 멤버 변수 fileName으로 지정된 값입니다.
    if (file.is_open()) { // 파일이 성공적으로 열렸는지 확인합니다.
        // 일별 수입/지출 기록을 파일에 저장합니다.
        for (const auto& record : dailyIncomeExpensesRecords) {
            file << record.getDate() << "," // 날짜를 파일에 씁니다.
                << record.getAmount() << "," // 금액을 파일에 씁니다.
                << record.getCategory() << "," // 분류를 파일에 씁니다.
                << record.getAsset() << "," // 자산을 파일에 씁니다.
                << record.getDescription() << endl; // 내용을 파일에 씁니다. 한 줄이 끝날 때마다 개행합니다.
        }
        file.close(); // 파일을 닫습니다.
        cout << "파일에 기록이 저장되었습니다." << endl; // 파일 저장 완료 메시지를 출력합니다.
    }
    else {
        cout << "파일을 열 수 없습니다." << endl; // 파일 열기 실패 메시지를 출력합니다.
    }
}


// 파일에서 불러오는 함수 구현
void AccountBook::loadFromFile() {
    std::ifstream file(fileName); // 파일을 읽기 모드로 엽니다. 파일명은 멤버 변수 fileName으로 지정된 값입니다.
    if (file.is_open()) { // 파일이 성공적으로 열렸는지 확인합니다.
        string line; // 한 줄씩 파일을 읽어올 변수를 선언합니다.
        while (getline(file, line)) { // 파일에서 한 줄씩 읽어옵니다.
            std::stringstream ss(line); // 한 줄을 stringstream에 저장합니다.
            std::string date, category, asset, description; // 각 항목을 저장할 변수를 선언합니다.
            double amount; // 금액을 저장할 변수를 선언합니다.

            // 한 줄을 각 항목으로 파싱합니다.
            getline(ss, date, ','); // 날짜를 ','를 기준으로 파싱합니다.
            ss >> amount; // 금액을 읽어옵니다.
            ss.ignore(); // 다음 항목을 읽기 위해 버퍼를 비웁니다.
            getline(ss, category, ','); // 분류를 ','를 기준으로 파싱합니다.
            getline(ss, asset, ','); // 자산을 ','를 기준으로 파싱합니다.
            getline(ss, description, ','); // 내용을 ','를 기준으로 파싱합니다.

            // 기록을 생성하고 일별 기록에 추가합니다.
            RecordItem record(date, amount, category, asset, description);
            dailyIncomeExpensesRecords.push_back(record);

            // 월별 기록을 업데이트합니다.
            updateMonthlyRecords(date, amount, category == "총 수입");
        }
        file.close(); // 파일을 닫습니다.
        cout << "파일에서 기록이 로드되었습니다." << endl; // 파일 로드 완료 메시지를 출력합니다.
    }
    else {
        cout << "파일을 열 수 없습니다." << endl; // 파일 열기 실패 메시지를 출력합니다.
    }
}
