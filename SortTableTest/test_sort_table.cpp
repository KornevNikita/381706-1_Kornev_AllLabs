#include "SortTable.h"
#include <gtest.h>


TEST(SortTable, can_create_tab_with_positive_size)
{
  ASSERT_NO_THROW (TSortTable<int> s(1));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTable, throws_when_create_tab_with_negative_size)
{
  ASSERT_ANY_THROW (TSortTable<int> s(-8));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTable, can_put_record_to_tab)
{
	TRecord<int> rec("test", 1);
	TSortTable<int> tab(4);
  ASSERT_NO_THROW (tab.Insert(rec));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTable, can_get_from_tab)
{
	TRecord<int> rec("test", 8);
	TSortTable<int> tab(4);
  tab.Insert(rec);
	tab.Find("test");
  ASSERT_NO_THROW (tab.GetCurrent().GetData());
}
//-------------------------------------------------------------------------------------------------
TEST (SortTable, get_gives_right_answer)
{
	TRecord<int> rec("test", 8);
	TSortTable<int> tab(4);
	tab.Insert(rec);
	tab.Find("test");
	EXPECT_EQ(8, tab.GetCurrent().GetData());

}
//-------------------------------------------------------------------------------------------------
TEST(SortTable, can_delete_from_tab)
{
	TRecord<int> rec("test", 8);
	TSortTable<int> tab(3);
	tab.Insert(rec);
	ASSERT_NO_THROW (tab.Delete("test"));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTable, isfull_gives_right_true_answer)
{
	TRecord<int> rec("test", 1);
	TSortTable<int> tab(1);
	tab.Insert(rec);
	EXPECT_EQ(true, tab.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (SortTable, isfull_gives_right_false_answer)
{
	TScanTable<int> tab(1);
	EXPECT_EQ(false, tab.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (SortTable, isempty_gives_right_true_answer)
{
	TSortTable<int> tab(1);
	EXPECT_EQ(true, tab.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST (SortTable, isempty_gives_right_false_answer)
{
	TRecord<int> rec("test", 1);
	TSortTable<int> tab(1);
	tab.Insert(rec);
	EXPECT_EQ(false, tab.IsEmpty());
}
