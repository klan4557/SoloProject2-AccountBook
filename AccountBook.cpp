#include "header.h"
#include "AccountBook.h"

// ������ ����
AccountBook::AccountBook(string _fileName) : fileName(_fileName) {}

// ���� �߰� �Լ� ����
void AccountBook::addIncome(const RecordItem& income) {
    dailyIncomeExpensesRecords.push_back(income);
    updateMonthlyRecords(income.getDate(), income.getAmount(), true);
}

// ���� �߰� �Լ� ����
void AccountBook::addExpense(const RecordItem& expense) {
    dailyIncomeExpensesRecords.push_back(expense);
    // ���� ��� ������Ʈ, ���⼭�� �ݾ��� �������� ����
    updateMonthlyRecords(expense.getDate(), expense.getAmount(), false); 
}

// ���� ��� ������Ʈ �Լ�
void AccountBook::updateMonthlyRecords(const string& date, double amount, bool isIncome) {
    string month = date.substr(0, 7); // �Էµ� ��¥���� �� ������ �����մϴ�. (YY-MM)

    // �ش� ���� ���� ����� ã���ϴ�.
    auto it = find_if(monthlyIncomeExpensesRecords.begin(), monthlyIncomeExpensesRecords.end(),
        [&](const vector<RecordItem>& monthlyRecord) {
            // ���� ��� �߿��� �ش� ���� ����� ã���ϴ�.
            return monthlyRecord[0].getDate().substr(0, 7) == month;
        });

    if (it != monthlyIncomeExpensesRecords.end()) {
        // �ش� ���� ����� �̹� �����ϴ� ���
        // ���� �Ǵ� ������ ������Ʈ�մϴ�.
        int index = isIncome ? 0 : 1; // ������ ��� index�� 0, ������ ��� index�� 1

        if (!isIncome) {
            // ������ �Էµ� ��� �� ������ ������Ʈ�մϴ�.
            double currentExpenses = 0;

            // �ش� ���� ��� �Ϻ� ����� Ȯ���ϸ� ���� �հ踦 ����մϴ�.
            for (const auto& record : dailyIncomeExpensesRecords) {
                if (record.getDate().substr(0, 7) == month) {
                    currentExpenses += record.getAmount();
                }
            }

            // �ش� ���� ������ ���� ��Ͽ� ������Ʈ�մϴ�.
            (*it)[1].setAmount(currentExpenses);
        }
        else {
            // ������ �Էµ� ��� �ش� ���� �� ������ ������Ʈ�մϴ�.
            (*it)[0].setAmount((*it)[0].getAmount() + amount);
        }
    }
    else {
        // �ش� ���� ����� �������� �ʴ� ���
        // ���ο� ���� ����� �߰��մϴ�.
        vector<RecordItem> newMonthlyRecord(2); // ���� ����, ���� ����� ���� ���� ����

        if (isIncome) {
            // ������ �Էµ� ��� �ش� ���� �� ������ ������Ʈ�մϴ�.
            newMonthlyRecord[0] = RecordItem(month + "-01", amount, "�� ����", "", "");
            // �ش� ���� ������ 0���� �����մϴ�.
            newMonthlyRecord[1] = RecordItem(month + "-01", 0, "�� ����", "", "");
        }
        else {
            // ������ �Էµ� ��� �ش� ���� ������ ����մϴ�.
            double currentExpenses = 0;

            // �ش� ���� ��� �Ϻ� ����� Ȯ���ϸ� ���� �հ踦 ����մϴ�.
            for (const auto& record : dailyIncomeExpensesRecords) {
                if (record.getDate().substr(0, 7) == month) {
                    currentExpenses += record.getAmount();
                }
            }

            // �ش� ���� ������ ���� ��Ͽ� �߰��մϴ�.
            newMonthlyRecord[0] = RecordItem(month + "-01", 0, "�� ����", "", "");
            newMonthlyRecord[1] = RecordItem(month + "-01", currentExpenses, "�� ����", "", "");
        }

        // ���ο� ���� ����� ���� ��� ���Ϳ� �߰��մϴ�.
        monthlyIncomeExpensesRecords.push_back(newMonthlyRecord);
    }
}



// �Ϻ� ��� ��� �Լ�
void AccountBook::getDailyRecords() {
    cout << "�Ϻ� ���:" << endl;

    // ���� �Ϻ� ����� ��¥ ������ �����մϴ�.
    sort(dailyIncomeExpensesRecords.begin(), dailyIncomeExpensesRecords.end(),
        [](const RecordItem& a, const RecordItem& b) {
            return a.getDate() < b.getDate(); // ��¥�� �������� ������������ �����մϴ�.
        });

    // ���ĵ� �Ϻ� ����� ��ȸ�ϸ� ����մϴ�.
    for (const auto& record : dailyIncomeExpensesRecords) {
        cout << "��¥: " << record.getDate() << ", �ݾ�: " << static_cast<int>(record.getAmount()) // ��¥�� �ݾ� ���
            << ", �з�: " << record.getCategory() << ", �ڻ�: " << record.getAsset() << ", ����: " // �з��� �ڻ� ���
            << record.getDescription() << endl; // ���� ���
    }
}


// ���� ��� ��� �Լ�
void AccountBook::getMonthlyRecords() {
    cout << "���� ���:" << endl;

    // ���� ����� ��¥ ������ �����մϴ�.
    sort(monthlyIncomeExpensesRecords.begin(), monthlyIncomeExpensesRecords.end(),
        [](const vector<RecordItem>& a, const vector<RecordItem>& b) {
            return a[0].getDate() < b[0].getDate(); // �� ������ ù ��° ����� ��¥�� ���Ͽ� �����մϴ�.
        });

    // ���ĵ� ���� ����� ��ȸ�ϸ� ����մϴ�.
    for (const auto& record : monthlyIncomeExpensesRecords) {
        size_t pos = record[0].getDate().find('-'); // ��¥���� ������ ���� �����ϴ� '-'�� ��ġ�� ã���ϴ�.
        if (pos != string::npos) { // '-'�� �߰ߵǾ��� ��
            string yearMonth = record[0].getDate().substr(0, pos + 3); // ������ ���� �����մϴ�.
            cout << "��, ��: " << setw(6) << left << yearMonth // ������ �� ���
                << ", �� ����: " << static_cast<int>(record[0].getAmount()) // ù ��° ����� ���� ���
                << ", �� ����: " << static_cast<int>(record[1].getAmount()) << endl; // �� ��° ����� ���� ���
        }
    }
}


// ���Ͽ� �����ϴ� �Լ� ����
void AccountBook::saveToFile() {
    ofstream file(fileName); // ������ ���� ���� ���ϴ�. ���ϸ��� ��� ���� fileName���� ������ ���Դϴ�.
    if (file.is_open()) { // ������ ���������� ���ȴ��� Ȯ���մϴ�.
        // �Ϻ� ����/���� ����� ���Ͽ� �����մϴ�.
        for (const auto& record : dailyIncomeExpensesRecords) {
            file << record.getDate() << "," // ��¥�� ���Ͽ� ���ϴ�.
                << record.getAmount() << "," // �ݾ��� ���Ͽ� ���ϴ�.
                << record.getCategory() << "," // �з��� ���Ͽ� ���ϴ�.
                << record.getAsset() << "," // �ڻ��� ���Ͽ� ���ϴ�.
                << record.getDescription() << endl; // ������ ���Ͽ� ���ϴ�. �� ���� ���� ������ �����մϴ�.
        }
        file.close(); // ������ �ݽ��ϴ�.
        cout << "���Ͽ� ����� ����Ǿ����ϴ�." << endl; // ���� ���� �Ϸ� �޽����� ����մϴ�.
    }
    else {
        cout << "������ �� �� �����ϴ�." << endl; // ���� ���� ���� �޽����� ����մϴ�.
    }
}


// ���Ͽ��� �ҷ����� �Լ� ����
void AccountBook::loadFromFile() {
    std::ifstream file(fileName); // ������ �б� ���� ���ϴ�. ���ϸ��� ��� ���� fileName���� ������ ���Դϴ�.
    if (file.is_open()) { // ������ ���������� ���ȴ��� Ȯ���մϴ�.
        string line; // �� �پ� ������ �о�� ������ �����մϴ�.
        while (getline(file, line)) { // ���Ͽ��� �� �پ� �о�ɴϴ�.
            std::stringstream ss(line); // �� ���� stringstream�� �����մϴ�.
            std::string date, category, asset, description; // �� �׸��� ������ ������ �����մϴ�.
            double amount; // �ݾ��� ������ ������ �����մϴ�.

            // �� ���� �� �׸����� �Ľ��մϴ�.
            getline(ss, date, ','); // ��¥�� ','�� �������� �Ľ��մϴ�.
            ss >> amount; // �ݾ��� �о�ɴϴ�.
            ss.ignore(); // ���� �׸��� �б� ���� ���۸� ���ϴ�.
            getline(ss, category, ','); // �з��� ','�� �������� �Ľ��մϴ�.
            getline(ss, asset, ','); // �ڻ��� ','�� �������� �Ľ��մϴ�.
            getline(ss, description, ','); // ������ ','�� �������� �Ľ��մϴ�.

            // ����� �����ϰ� �Ϻ� ��Ͽ� �߰��մϴ�.
            RecordItem record(date, amount, category, asset, description);
            dailyIncomeExpensesRecords.push_back(record);

            // ���� ����� ������Ʈ�մϴ�.
            updateMonthlyRecords(date, amount, category == "�� ����");
        }
        file.close(); // ������ �ݽ��ϴ�.
        cout << "���Ͽ��� ����� �ε�Ǿ����ϴ�." << endl; // ���� �ε� �Ϸ� �޽����� ����մϴ�.
    }
    else {
        cout << "������ �� �� �����ϴ�." << endl; // ���� ���� ���� �޽����� ����մϴ�.
    }
}
