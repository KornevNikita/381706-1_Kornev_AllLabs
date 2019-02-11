#include "gtest.h"
#include "List.h"

TEST(TList, can_create_list_btgin)
{
	ASSERT_NO_THROW(TList<int> A);
}

TEST(TList, can_put_begin)
{
	TList<int> test1;

	ASSERT_NO_THROW(test1.PutBegin(43));
}

TEST(TList, can_put_end)
{
	TList<int> test1;
	test1.PutBegin(43);
	ASSERT_NO_THROW(test1.PutEnd(43));
}

TEST(TList, can_get_begin)
{
	TList<int> test1;
	test1.PutBegin(42);
	test1.PutEnd(43);
	EXPECT_EQ(42, test1.GetBegin());
}

TEST(TList, can_get_end)
{
	TList<int> test1;
	test1.PutBegin(42);
	test1.PutEnd(43);
	EXPECT_EQ(43, test1.GetEnd());
}

TEST(TList, cant_get_begin_free)
{
	TList<int> test1;
	ASSERT_ANY_THROW(test1.GetBegin());
}

TEST(TList, cant_get_end_free)
{
	TList<int> test1;
	ASSERT_ANY_THROW(test1.GetEnd());
}
