#include "TScanTable.h"
#include <gtest.h>

TEST(ScanTable, can_create_tab_with_positive_size)
{
  ASSERT_NO_THROW (TScanTable<int> s(1));
}

//-------------------------------------------------------------------------------------------------
TEST (ScanTable, throws_when_create_tab_with_negative_size)
{
  ASSERT_ANY_THROW (TScanTable<int> s(-8));
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, can_insert_to_tab)
{
  TRecord<int> rec("test", 1);
  TScanTable<int> tab(4);
  ASSERT_NO_THROW (tab.Insert(rec));
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, throws_when_put_to_full_tab)
{
	TRecord<int> rec1("test1", 1);
	TRecord<int> rec2("test2", 2);
	TRecord<int> rec3("test3", 3);
  TScanTable<int> tab(2);
	tab.Insert(rec1);
	tab.Insert(rec2);
  ASSERT_ANY_THROW (tab.Insert(rec3));
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, can_get_from_tab)
{
  TRecord<int> rec("test", 1);
  TScanTable<int> tab(4);
  tab.Insert(rec);
	tab.Find("test");
  ASSERT_NO_THROW (tab.GetCurrent());
}
//-------------------------------------------------------------------------------------------------
TEST(ScanTable, can_delete_from_tab)
{
	TRecord<int> rec("test", 2);
  TScanTable<int> tab(1);
  tab.Insert(rec);
  ASSERT_NO_THROW (tab.Delete("test"));
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, throws_when_delete_from_empty_Tab)
{
  TScanTable<int> tab(2);
  ASSERT_ANY_THROW(tab.Delete("test"));
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, get_gives_right_answer)
{
	TRecord<int> rec("test", 8);
  TScanTable<int> tab(2);
  tab.Insert(rec);
	tab.Find("test");
  EXPECT_EQ (8, tab.GetCurrent().GetData());
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, isfull_gives_right_true_answer)
{
	TRecord<int> rec("test", 1);
  TScanTable<int> tab(1);
  tab.Insert(rec);
  EXPECT_EQ (true, tab.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, isfull_gives_right_false_answer)
{
  TScanTable<int> tab(1);
  EXPECT_EQ (false, tab.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, isempty_gives_right_true_answer)
{
  TScanTable<int> tab(1);
  EXPECT_EQ (true, tab.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST (ScanTable, isempty_gives_right_false_answer)
{
	TRecord<int> rec("test", 1);
  TScanTable<int> tab(1);
  tab.Insert(rec);
  EXPECT_EQ (false, tab.IsEmpty());
}