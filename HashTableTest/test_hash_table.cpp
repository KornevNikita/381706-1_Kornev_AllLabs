#include "THashTable.h"
#include <gtest.h>

TEST(HashTable, can_create_tab_with_positive_size)
{
	ASSERT_NO_THROW(TArrayHash<int> tab(1));
}
//-------------------------------------------------------------------------------------------------
TEST(HashTable, throws_when_create_tab_with_negative_size)
{
	ASSERT_ANY_THROW(TArrayHash<int> s(-8));
}
//-------------------------------------------------------------------------------------------------
TEST(HashTable, can_put_key_to_tab)
{
	TRecord<int> rec("test", 1);
	TArrayHash<int> tab(3);
	ASSERT_NO_THROW(tab.Insert(rec));
}
//-------------------------------------------------------------------------------------------------
TEST(HashTable, throws_when_delete_from_empty_tab)
{
	TArrayHash<int> tab(3);
	ASSERT_ANY_THROW(tab.Delete("test"));
}
//-------------------------------------------------------------------------------------------------
TEST(HashTable, isempty_gives_right_true_answer)
{
	TArrayHash<int> tab(1);
	EXPECT_EQ(true, tab.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST(HashTable, isempty_gives_right_false_answer)
{
	TRecord<int> rec("test", 1);
	TArrayHash<int> tab(1);
	tab.Insert(rec);
	EXPECT_EQ(false, tab.IsEmpty());
}
