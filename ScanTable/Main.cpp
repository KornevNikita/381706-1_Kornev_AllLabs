#include "TScanTable.h"
#include "TRecord.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	TRecord<int> e1("a", 1); // �������� ������� �1 � ������ � � ������� 1
	TRecord<int> e2("b", 2); // �������� ������� �2 � ������ � � ������� 2
	TRecord<int> e3("c", 3); // �������� ������� �3 � ������ � � ������� 3
	TRecord<int> e4(e1); // �������� ������� �4 � ������� ����������� ����������� �� �1
	TRecord<int> e5; // �������� ������� �5 �� ��������� (�� ���������� "" � 0)
  TScanTable<int> t1(5); // �������� ������� ��� �������� ���������
  t1.Insert(e1); // �������� � ������� �1
  t1.Insert(e2); // �������� � ������� �2
	t1.Insert(e3); // �������� � ������� �3
	t1.Insert(e4); // �������� � ������� �4
	t1.Insert(e5); // �������� � ������� �5
	bool finding, deleting;
	finding = t1.Find(3); // ������ ������� �� ��������� 3
	finding = t1.Find(6); // ��������� ����� ������� �� ��������� 6
	deleting = t1.Delete(2) // ������ ������� �� ��������� 2
	return 0;
}
