#include "header.h"
#include "RecordItem.h"

/*����� Ŭ����*/
/*����� �������� �����ϴ� Ŭ����*/
class AccountBook {
private:
    vector<RecordItem> dailyIncomeExpensesRecords; // �Ϻ� ���� �� ���� ����� �����ϴ� ����
    vector<vector<RecordItem>> monthlyIncomeExpensesRecords; // ���� ���� �� ���� ����� �����ϴ� ���� ����
    string fileName; // ���� �̸��� �����ϴ� ���ڿ�

public:
    // ������: ���� �̸��� ���ڷ� �޾� �ʱ�ȭ
    AccountBook(std::string _fileName);

    // ���� �߰� �Լ�: RecordItem ��ü�� ���ڷ� �޾� �Ϻ� ���� ��Ͽ� �߰�
    void addIncome(const RecordItem& income);

    // ���� �߰� �Լ�: RecordItem ��ü�� ���ڷ� �޾� �Ϻ� ���� ��Ͽ� �߰�
    void addExpense(const RecordItem& expense);

    // ���� ��� ������Ʈ �Լ�: ������ ��¥�� ���� ���� ���� �Ǵ� ������ ������Ʈ
    void updateMonthlyRecords(const string& date, double amount, bool isIncome);

    // �Ϻ� ��� ��� �Լ�: �Ϻ� ���� �� ���� ����� ȭ�鿡 ���
    void getDailyRecords();

    // ���� ��� ��� �Լ�: ���� ���� �� ���� ����� ȭ�鿡 ���
    void getMonthlyRecords();

    // ���Ͽ� �����ϴ� �Լ�
    void saveToFile();

    // ���Ͽ��� �ҷ����� �Լ�
    void loadFromFile();
};

