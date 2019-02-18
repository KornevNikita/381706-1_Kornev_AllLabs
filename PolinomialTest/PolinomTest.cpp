#include <gtest.h>
#include "Polinom.h"

using namespace std;

TEST(TPolinom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolinom A(3));
}

TEST(TPolinom, throws_when_create_polynom_with_negative_size)
{
	ASSERT_ANY_THROW(TPolinom A(-3));
}

TEST(TPolinom, can_create_copy_of_polynom)
{
	int m1[4] = { 1, 2, 3 };
	TMonom tmp1(3, m1, 1);
	TPolinom A(3);
	A += tmp1;
	ASSERT_NO_THROW(TPolinom B(A));
	TPolinom B(A);
	ASSERT_TRUE(A == B);
}

TEST(TPolinom, can_get_size_polynom)
{
	int m[3] = { 1, 2, 3 };
	TMonom tmp(3, m, 1);
	TPolinom A(3);
	A += tmp;
	ASSERT_EQ(A.GetSize(), 1);
}

TEST(TPolinom, trows_when_add_polynoms_with_different_size)
{
	int m[3] = { 1, 2, 3 };
	TMonom tmp(3, m, 1);
	TPolinom A(3);
	TPolinom B(4);
	ASSERT_ANY_THROW(A + B);
}

TEST(TPolinom, can_add_polynoms)
{
	int m1[3] = { 1, 2, 3 };
	TMonom tmp1(3, m1, 1);
	TPolinom A(3);
	A += tmp1;
	int m2[3] = { 2, 1, 4 };
	TMonom tmp2(3, m2, 1);
	TPolinom B(3);
	B += tmp2;
	ASSERT_NO_THROW(A + B);
	TPolinom C = A + B;
	/*TMonom* a = C.GetStart();
	ASSERT_TRUE(*a == tmp2);
	a = a->GetNext();
	ASSERT_TRUE(*a == tmp1);
	a = a->GetNext();
	ASSERT_TRUE(a == NULL);*/
}

TEST(TPolinom, can_assign_operator_polynoms)
{
	int m1[3] = { 1, 2, 3 };
	TMonom tmp1(3, m1, 1);
	TPolinom A(3);
	A += tmp1;
	int m2[3] = { 2, 1, 4 };
	TMonom tmp2(3, m2, 1);
	TPolinom B(3);
	B += tmp2;
	ASSERT_NO_THROW(A = B);
	TMonom *temp = A.GetStart();
	ASSERT_TRUE(*temp == tmp2);
}

TEST(TPolinom, throws_when_assign_monoms_with_different_n)
{
	TPolinom A(4);
	TPolinom B(3);
	ASSERT_ANY_THROW(A = B);
}

TEST(TPolinom, trows_when_equivalence_polynoms_with_different_n)
{
	TPolinom A(3);
	TPolinom B(4);
	ASSERT_ANY_THROW(A == B);
}

TEST(TPolinom, can_multiply_equal_polynoms)
{
	TPolinom Rez(3);
	int m1[3] = { 1, 2, 3 };
	TMonom tmp1(3, m1, 1);
	TPolinom A(3);
	A += tmp1;
	int m2[3] = { 2, 1, 4 };
	TMonom tmp2(3, m2, 1);
	TPolinom B(3);
	B += tmp2;
	ASSERT_NO_THROW(A * B);	
 }

TEST(TPolinom, trows_when_multiply_different_polynoms)
{
	TPolinom A(3);
	TPolinom B(4);
	ASSERT_ANY_THROW(A * B);
}

TEST(TPolinom, can_add_monoms_to_polynoms)
{
	int m1[3] = { 1, 2, 3 };
	int m2[4] = { 2, 1, 4 };
	TMonom tmp1(3, m1, 1);
	TMonom tmp2(3, m2, 2);
	TPolinom A(3);
	A += tmp1;
	A += tmp2;
	TMonom* a = A.GetStart();
	ASSERT_TRUE(*a == tmp2);
	a = a->GetNext();
	ASSERT_TRUE(*a == tmp1);
	a = a->GetNext();
	ASSERT_TRUE(a == NULL);
}

