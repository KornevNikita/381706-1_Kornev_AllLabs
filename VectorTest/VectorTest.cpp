#include <gtest.h>
#include "Vector.h"

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> Vector(89));
}

TEST(TVector, throw_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> Vector(-3));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> Vector(50);
	ASSERT_NO_THROW(TVector<int> Copy(Vector));
}

TEST(TVector, throw_when_referring_to_a_nonexistent_element)
{
	TVector<int> Vector(15);
	ASSERT_ANY_THROW(Vector[15]);
}

TEST(TVector, can_referring_to_a_existent_element)
{
	TVector<int> Vector(37);
	EXPECT_EQ(0, Vector[0]);
}

TEST(TVector, increment_verification)
{
	TVector<int> Vector(3);
	Vector++;
	int result = Vector[0] + Vector[1] + Vector[2];
	EXPECT_EQ(3, result);
}

TEST(TVector, operator_comparison_verification)
{
	TVector<int> Vector(15);
	TVector<int> Copy(Vector);
	EXPECT_EQ(1, Vector == Copy);
}
	
TEST(TVector, operator_equally_verification)
{
	TVector<int> Vector(15);
	TVector<int> Copy(3);
	Copy = Vector;
	EXPECT_EQ(1, Vector == Copy);
}

TEST(TVector, decrement_verification)
{
	TVector<int> Vector(3);
	Vector--;
	int result = Vector[0] + Vector[1] + Vector[2];
	EXPECT_EQ(-3, result);
}

TEST(TVector, addition_operator_verification)
{
	TVector<int> One(5);
	TVector<int> Two(5);
	One++;
	Two++;
	One = One + Two;
	EXPECT_EQ(2, One[2]);
}

TEST(TVector, negation_operator_verification)
{
	TVector<int> Vector(3);
	Vector++;
	Vector = -Vector;
	EXPECT_EQ(-1, Vector[0]);
}

TEST(TVector, multyply_operator_verification)
{
	TVector<int> One(5);
	TVector<int> Two(5);
	One++;
	Two++;
	One++;
	Two++;
	One++;
	Two++;
	One = One * Two;
	EXPECT_EQ(9, One[3]);
}