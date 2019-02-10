#include "List.h"
#include <gtest.h>
TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> A());
}

TEST(TList, can_create_copy_of_the_list)
{
	TList<int> A;
	ASSERT_NO_THROW(TList<int> B(A));
}

TEST(TList, can_put_begin)
{
	TList<int> A;
	ASSERT_NO_THROW(A.PutBegin(1));
}

TEST(TList, can_put_end)
{
	TList<int> A;
	ASSERT_NO_THROW(A.PutEnd(10));
}

TEST(TList, can_get_begin)
{
	TList<int> A;
	A.PutBegin(1);
	A.PutBegin(2);
	ASSERT_EQ(2, A.GetBegin());
}

TEST(TList, can_get_end)
{
	TList<int> A;
	A.PutBegin(1);
	A.PutBegin(2);
	ASSERT_EQ(A.GetEnd(), 1);
}

TEST(TList, throws_when_get_begin_from_empty_list)
{
	TList<int> A;
	ASSERT_ANY_THROW(A.GetBegin());
}

TEST(TList, throws_when_get_end_from_empty_list)
{
	TList<int> A;
	ASSERT_ANY_THROW(A.GetEnd());
}

TEST(TList, can_use_empty_check_true)
{
	TList<int> A;
	ASSERT_TRUE(A.IsEmpty());
}

TEST(TList, can_use_empty_check_false)
{
	TList<int> A;
	A.PutBegin(1);
	ASSERT_FALSE(A.IsEmpty());
}
