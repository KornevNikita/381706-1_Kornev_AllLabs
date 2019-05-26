#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class TValue>
class TRecord
{
protected:
  string key;
  TValue data;
public:
  void SetKey(string _key);
  void SetData(TValue _data);
  string GetKey();
  TValue GetData();

  TRecord<TValue>(string _key = "", TValue _data = 0);
  TRecord(TRecord<TValue> &A);
  TRecord<TValue>& operator = (TRecord<TValue> &A);
  bool operator == (TRecord<TValue> &A);
  bool operator != (TRecord<TValue> &A);
};
//-------------------------------------------------------------------------------------------------
template <class TValue>
void TRecord<TValue>::SetKey(string _key)
{
  key = _key;
}
//-------------------------------------------------------------------------------------------------
template <class TValue>
void TRecord<TValue>::SetData(TValue _data)
{
  data = _data;
}
//-------------------------------------------------------------------------------------------------
template <class TValue>
string TRecord<TValue>::GetKey()
{
  return key;
}
//-------------------------------------------------------------------------------------------------
template <class TValue>
TValue TRecord<TValue>::GetData()
{
  return data;
}
//-------------------------------------------------------------------------------------------------
template <class TValue>
TRecord<TValue>::TRecord(string _key, TValue _data)
{
  key = _key;
  data = _data;
}
//-------------------------------------------------------------------------------------------------
template <class TValue>
TRecord<TValue>::TRecord(TRecord<TValue> &A)
{
  key = A.key;
  data = A.data;
}
//-------------------------------------------------------------------------------------------------
template <class TValue>
TRecord<TValue>& TRecord<TValue>::operator = (TRecord<TValue> &A)
{
  key = A.key;
  data = A.data;
  return *this;
}
//-------------------------------------------------------------------------------------------------
template <class TValue>
bool TRecord<TValue>::operator == (TRecord<TValue> &A)
{
  return ((key == A.key) && (data == A.data));
}
//-------------------------------------------------------------------------------------------------
template <class TValue>
bool TRecord<TValue>::operator != (TRecord<TValue> &A)
{
  return ((key != A.key) || (data != A.data));
}