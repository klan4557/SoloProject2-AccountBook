#include "header.h"
#include "RecordItem.h"

/*가계부 클래스*/
/*기록한 정보들을 저장하는 클래스*/
class AccountBook {
private:
    vector<RecordItem> dailyIncomeExpensesRecords; // 일별 수입 및 지출 기록을 저장하는 벡터
    vector<vector<RecordItem>> monthlyIncomeExpensesRecords; // 월별 수입 및 지출 기록을 저장하는 이중 벡터
    string fileName; // 파일 이름을 저장하는 문자열

public:
    // 생성자: 파일 이름을 인자로 받아 초기화
    AccountBook(std::string _fileName);

    // 수입 추가 함수: RecordItem 객체를 인자로 받아 일별 수입 기록에 추가
    void addIncome(const RecordItem& income);

    // 지출 추가 함수: RecordItem 객체를 인자로 받아 일별 지출 기록에 추가
    void addExpense(const RecordItem& expense);

    // 월별 기록 업데이트 함수: 지정된 날짜에 대한 월별 수입 또는 지출을 업데이트
    void updateMonthlyRecords(const string& date, double amount, bool isIncome);

    // 일별 기록 출력 함수: 일별 수입 및 지출 기록을 화면에 출력
    void getDailyRecords();

    // 월별 기록 출력 함수: 월별 수입 및 지출 기록을 화면에 출력
    void getMonthlyRecords();

    // 파일에 저장하는 함수
    void saveToFile();

    // 파일에서 불러오는 함수
    void loadFromFile();
};

