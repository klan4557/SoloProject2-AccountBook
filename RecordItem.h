#ifndef RECORDITEM_H
#define RECORDITEM_H
#include "header.h"

class RecordItem {
private:
	string date;         // 날짜를 저장하는 문자열 멤버 변수
	double amount;       // 금액을 저장하는 실수형 멤버 변수

	
	string category;     // 분류를 저장하는 문자열 멤버 변수 (식비, 패션/미용 등)
	string asset;        // 자산을 저장하는 문자열 멤버 변수 (카드, 현금 등)
	string description;  // 내용을 저장하는 문자열 멤버 변수

public:
	// 기본 생성자: 멤버 변수를 기본값으로 초기화하는 생성자
	RecordItem();

	// 매개변수가 있는 생성자: 날짜, 금액, 분류, 자산, 내용을 인자로 받아 초기화하는 생성자
	RecordItem(string date, double amount, string category, string asset, string description);

	// 각 멤버 변수의 Getter 함수들
	string getDate() const;           // 날짜를 반환하는 함수
	double getAmount() const;         // 금액을 반환하는 함수
	string getCategory() const;       // 분류를 반환하는 함수
	string getAsset() const;          // 자산을 반환하는 함수
	string getDescription() const;    // 내용을 반환하는 함수

	// 각 멤버 변수의 Setter 함수들
	void setDate(string date);         // 날짜를 설정하는 함수
	void setAmount(double amount);     // 금액을 설정하는 함수
	void setCategory(string category); // 분류를 설정하는 함수
	void setAsset(string asset);       // 자산을 설정하는 함수
	void setDescription(string Description); // 내용을 설정하는 함수
};

#endif // RECORDITEM_H