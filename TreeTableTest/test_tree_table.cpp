#include "TTreeNode.h"
#include "TTreeTable.h"
#include <gtest.h>

using namespace std;

TEST(TreeTable, can_create_treetable)
{
	ASSERT_NO_THROW(TTreeTable<int> s());
}
//-------------------------------------------------------------------------------------------------
TEST(TreeTable, can_put_record_to_treetable)
{
	TRecord<int> rec("test", 8);
	TTreeTable<int> tab;
	ASSERT_NO_THROW(tab.Insert(rec));
}
//-------------------------------------------------------------------------------------------------
TEST(TreeTable, can_delete_from_tab)
{
	TRecord<int> rec("test", 8);
	TTreeTable<int> tab;
	tab.Insert(rec);
	ASSERT_NO_THROW(tab.Delete("test"));
}
//-------------------------------------------------------------------------------------------------
TEST(TreeTable, isempty_gives_right_true_answer)
{
	TTreeTable<int> tab;
	EXPECT_EQ(true, tab.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST(TreeTable, isempty_gives_right_false_answer)
{
	TRecord<int> rec("test", 1);
	TTreeTable<int> tab;
	tab.Insert(rec);
	EXPECT_EQ(false, tab.IsEmpty());
}


