#include "header.h"
#include "RecordItem.h"

RecordItem::RecordItem() {}
// ������: �� ��� ������ �Ű������� �ʱ�ȭ
RecordItem::RecordItem(string _date, double _amount, string _category, string _asset, string _description) :
    date(_date), amount(_amount), category(_category), asset(_asset), description(_description) {}

// ��¥�� ��ȯ�ϴ� Getter �Լ�
string RecordItem::getDate() const {
    return date;
}

// �ݾ��� ��ȯ�ϴ� Getter �Լ�
double RecordItem::getAmount() const {
    return amount;
}

// �з��� ��ȯ�ϴ� Getter �Լ�
string RecordItem::getCategory() const {
    return category;
}

// �ڻ��� ��ȯ�ϴ� Getter �Լ�
string RecordItem::getAsset() const {
    return asset;
}

// ������ ��ȯ�ϴ� Getter �Լ�
string RecordItem::getDescription() const {
    return description;
}

// ��¥�� �����ϴ� Setter �Լ�
void RecordItem::setDate(string _date) {
    date = _date;
}

// �ݾ��� �����ϴ� Setter �Լ�
void RecordItem::setAmount(double _amount) {
    // ������ ��� �ݾ��� ������ ����
    amount = _amount;
}

// �з��� �����ϴ� Setter �Լ�
void RecordItem::setCategory(string _category) {
    category = _category;
}

// �ڻ��� �����ϴ� Setter �Լ�
void RecordItem::setAsset(string _asset) {
    asset = _asset;
}

// ������ �����ϴ� Setter �Լ�
void RecordItem::setDescription(string _description) {
    description = _description;
}

