#pragma once
#include <string>
#include <iostream>
using namespace std;

class MyException {
	int id;
	string type;
public:
	MyException(int _id, string _type) :id(_id), type(_type){};
	void Print() {
		setlocale(LC_ALL, "Russian");
		cout << "Ошибка " << id << ". " << type << endl;
	};
};
