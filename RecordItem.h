#ifndef RECORDITEM_H
#define RECORDITEM_H
#include "header.h"

class RecordItem {
private:
	string date;         // ��¥�� �����ϴ� ���ڿ� ��� ����
	double amount;       // �ݾ��� �����ϴ� �Ǽ��� ��� ����

	
	string category;     // �з��� �����ϴ� ���ڿ� ��� ���� (�ĺ�, �м�/�̿� ��)
	string asset;        // �ڻ��� �����ϴ� ���ڿ� ��� ���� (ī��, ���� ��)
	string description;  // ������ �����ϴ� ���ڿ� ��� ����

public:
	// �⺻ ������: ��� ������ �⺻������ �ʱ�ȭ�ϴ� ������
	RecordItem();

	// �Ű������� �ִ� ������: ��¥, �ݾ�, �з�, �ڻ�, ������ ���ڷ� �޾� �ʱ�ȭ�ϴ� ������
	RecordItem(string date, double amount, string category, string asset, string description);

	// �� ��� ������ Getter �Լ���
	string getDate() const;           // ��¥�� ��ȯ�ϴ� �Լ�
	double getAmount() const;         // �ݾ��� ��ȯ�ϴ� �Լ�
	string getCategory() const;       // �з��� ��ȯ�ϴ� �Լ�
	string getAsset() const;          // �ڻ��� ��ȯ�ϴ� �Լ�
	string getDescription() const;    // ������ ��ȯ�ϴ� �Լ�

	// �� ��� ������ Setter �Լ���
	void setDate(string date);         // ��¥�� �����ϴ� �Լ�
	void setAmount(double amount);     // �ݾ��� �����ϴ� �Լ�
	void setCategory(string category); // �з��� �����ϴ� �Լ�
	void setAsset(string asset);       // �ڻ��� �����ϴ� �Լ�
	void setDescription(string Description); // ������ �����ϴ� �Լ�
};

#endif // RECORDITEM_H