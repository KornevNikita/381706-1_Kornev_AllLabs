#include "gtest.h"
#include "MultiStack.h"

using namespace std;

TEST(TMStack, can_create_mstack_with_positive_length)
{
	ASSERT_NO_THROW(TMStack<int> A(5, 25));
}

TEST(TMStack, cant_create_mstack_with_negative_length)
{
	ASSERT_ANY_THROW(TMStack<int> A(5, -1));
}

TEST(TMStack, can_copy_mstack)
{
	TMStack<int> A(5, 25);
	ASSERT_NO_THROW(TMStack<int> B(A));
}

TEST(TMStack, can_set_element)
{
	TMStack<int> A(5, 25);
	ASSERT_NO_THROW(A.Set(1, 2));
}

TEST(TMStack, throws_when_set_element_in_negative_index)
{
	TMStack<int> A(5, 25);
	ASSERT_ANY_THROW(A.Set(-2, 2));
}

TEST(TMStack, can_set_element_in_full_stack)
{
	TMStack<int> A(2, 4);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	EXPECT_NO_THROW(A.Set(1, 43));
}

TEST(TMStack, throws_when_set_element_in_full_mstack)
{
	TMStack<int> A(2, 5);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	EXPECT_ANY_THROW(A.Set(1, 43));
}

TEST(TMStack, can_get_element)
{
	TMStack<int> A(5, 25);
	A.Set(2, 43);
	EXPECT_EQ(43, A.Get(2));
}

TEST(TMStack, correct_order_return_value)
{
	TMStack <int> A(2,5);
	A.Set(1,1);
	A.Set(1,2);
	A.Set(1,3);
	ASSERT_EQ(3, A.Get(1));
	ASSERT_EQ(2, A.Get(1));
	ASSERT_EQ(1, A.Get(1));
}

TEST(TMStack, throws_when_get_element_from_negative_index)
{
	TMStack<int> A(5, 25);
	A.Set(1, 43);
	ASSERT_ANY_THROW(A.Get(-1));
}

TEST(TMStack, throws_when_get_element_from_empty_mstack)
{
	TMStack<int> A(2, 5);
	EXPECT_ANY_THROW(A.Get(1));
}

TEST(TMStack, can_check_is_empty)
{
	TMStack<int> A(5, 25);
	EXPECT_EQ(true, A.isEmpty(1));
}

TEST(TMStack, can_check_is_full)
{
	TMStack<int> A(5, 25);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	EXPECT_EQ(1, A.isFull(1));
}



