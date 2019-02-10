#pragma once
template <class T>
class TField {
protected:
	T field;
	TField<T>* next;
public:
	TField(T _field = 0, TField<T>* _next = 0) : field(_field), next(_next) {}
	TField(TField &other) : field(other.field), next(other.next) {}
	T GetField() { return field; }
	TField* GetNext() { return next; }
	void SetField(T _field) { field = _field; }
	void SetNext(TField<T>* _next) { next = _next; }
};