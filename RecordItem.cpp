#include "header.h"
#include "RecordItem.h"

RecordItem::RecordItem() {}
// 생성자: 각 멤버 변수를 매개변수로 초기화
RecordItem::RecordItem(string _date, double _amount, string _category, string _asset, string _description) :
    date(_date), amount(_amount), category(_category), asset(_asset), description(_description) {}

// 날짜를 반환하는 Getter 함수
string RecordItem::getDate() const {
    return date;
}

// 금액을 반환하는 Getter 함수
double RecordItem::getAmount() const {
    return amount;
}

// 분류를 반환하는 Getter 함수
string RecordItem::getCategory() const {
    return category;
}

// 자산을 반환하는 Getter 함수
string RecordItem::getAsset() const {
    return asset;
}

// 내용을 반환하는 Getter 함수
string RecordItem::getDescription() const {
    return description;
}

// 날짜를 설정하는 Setter 함수
void RecordItem::setDate(string _date) {
    date = _date;
}

// 금액을 설정하는 Setter 함수
void RecordItem::setAmount(double _amount) {
    // 지출일 경우 금액을 음수로 저장
    amount = _amount;
}

// 분류를 설정하는 Setter 함수
void RecordItem::setCategory(string _category) {
    category = _category;
}

// 자산을 설정하는 Setter 함수
void RecordItem::setAsset(string _asset) {
    asset = _asset;
}

// 내용을 설정하는 Setter 함수
void RecordItem::setDescription(string _description) {
    description = _description;
}

