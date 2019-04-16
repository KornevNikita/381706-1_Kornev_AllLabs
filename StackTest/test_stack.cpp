#include "gtest.h"
#include "Stack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> st(1)); 
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-1)); 
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st1(4);
	ASSERT_NO_THROW(TStack<int> st2(st1));
}

TEST(TStack, can_check_full_stack)
{
	TStack<int> st(1);
	st.Put(1);
	EXPECT_EQ(1, st.IsFull());
}

TEST(TStack, can_check_empty_stack)
{
	TStack<int> st(4);
	EXPECT_EQ(1, st.IsEmpty());
}

TEST(TStack, cant_put_element_in_full_stack)
{
	TStack<int> st(4);
	st.Put(1);
	st.Put(2);
	st.Put(3);
	st.Put(4);
	ASSERT_ANY_THROW(st.Put(5));
}

TEST(TStack, cant_get_element_from_empty_stack)
{
	TStack<int> st(4);
	ASSERT_ANY_THROW(st.Get());
}

TEST(TStack, can_put_and_get_element)
{
	TStack<int> st(4);
	st.Put(1);
	st.Put(2);
	st.Put(3);
	EXPECT_EQ(3, st.Get());
}














