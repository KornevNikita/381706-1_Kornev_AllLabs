#include <gtest.h>
#include "PN.h"

TEST(PN, can_create_rpn_with_positive_length)
{
	char* _mas = new char[3];
	ASSERT_NO_THROW(PN pn(3, _mas));
}

TEST(PN, throw_when_create_rpn_with_negative_length)
{
	char* _mas = new char[3];
	ASSERT_ANY_THROW(PN pn(-5, _mas));
}

TEST(PN, can_copied_rpn)
{
	char* _mas = new char[3];
	PN pn(3, _mas);
	ASSERT_NO_THROW(PN copy(pn));
}

TEST(PN, can_get_size_of_rpn)
{
	char* _mas = new char[3];
	PN pn(3, _mas);
	EXPECT_EQ(3, pn.GetSize());
}

TEST(PN, can_get_result)
{
	char* A = new char[3];
	A[0] = '3';
	A[1] = '+';
	A[2] = '3';
	PN B(3, A);
	int result = (int)B.Result();
	EXPECT_EQ(6, result);
}