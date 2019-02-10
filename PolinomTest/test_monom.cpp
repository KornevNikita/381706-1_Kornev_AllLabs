#include "gtest.h"
#include "Monom.h"


TEST(TMonom, can_create_monom)
{
  ASSERT_NO_THROW(TMonom A(3));
}

TEST(TMonom, throws_when_create_monom_with_negative_index)
{
  ASSERT_ANY_THROW(TMonom A(-666));
}

TEST(TMonom, can_init_the_monom)
{
  int a[3] = { 1, 2, 3 };
  ASSERT_NO_THROW(TMonom A(3, a, 3.34));
}

TEST(TMonom, can_create_copy_of_the_monom)
{
  TMonom A;
  ASSERT_NO_THROW(TMonom B(A));
}

TEST(TMonom, can_set_next)
{
  TMonom A;
  TMonom B;
  ASSERT_NO_THROW(A.SetNext(&B));
}

TEST(TMonom, can_set_and_get_c)
{
  TMonom A;
  ASSERT_NO_THROW(A.SetC(3.14));
  ASSERT_EQ(3.14, A.GetC());
}

TEST(TMonom, can_set_and_get_power)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3);
  ASSERT_NO_THROW(A.SetPower(a));
  ASSERT_EQ(1, A.GetPower()[0]);
}


TEST(TMonom, can_set_next_element)
{
  TMonom A(2);
  TMonom B(4);
  ASSERT_NO_THROW(A.SetNext(&B));
}

TEST(TMonom, can_set_and_get_n)
{
  TMonom A(3);
  ASSERT_NO_THROW(A.SetN(5));
  ASSERT_EQ(5, A.GetN());
}

TEST(TMonom, assign_operator_monoms_work)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3);
  TMonom B(3);
  A.SetPower(a);
  B = A;
  ASSERT_EQ(1, B.GetPower()[0]);
}

TEST(TMonom, throws_when_assign_monoms_with_different_n)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3);
  TMonom B(4);
  A.SetPower(a);
  ASSERT_ANY_THROW(B = A);
}

TEST(TMonom, can_add_equal_monoms)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3, a, 3.1);
  TMonom B(3, a, 0.5);
  ASSERT_NO_THROW(A + B);
  TMonom C(3);
  C = A + B;
  ASSERT_EQ(3.6, C.GetC());
}

TEST(TMonom, trows_when_add_different_monoms)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3);
  TMonom B(3);
  TMonom C(4);
  A.SetPower(a);
  ASSERT_ANY_THROW(A + B);
  ASSERT_ANY_THROW(A + C);
}

TEST(TMonom, can_subtract_equal_monoms)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3, a, 3.1);
  TMonom B(3, a, 0.5);
  ASSERT_NO_THROW(A - B);
  TMonom C(3);
  C = A - B;
  ASSERT_EQ(2.6, C.GetC());
}

TEST(TMonom, trows_when_subtract_different_monoms)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3);
  TMonom B(3);
  TMonom C(4);
  A.SetPower(a);
  ASSERT_ANY_THROW(A - B);
  ASSERT_ANY_THROW(A - C);
}

TEST(TMonom, can_multiply_equal_monoms)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3, a, 3.1);
  TMonom B(3, a, 0.5);
  ASSERT_NO_THROW(A * B);
  TMonom C(3);
  C = A * B;
  ASSERT_EQ(3.1*0.5, C.GetC());
  ASSERT_EQ(2, C.GetPower()[0]);
}

TEST(TMonom, trows_when_multiply_different_monoms)
{
  int a[3];
  for (int i = 0; i < 3; i++)
    a[i] = i + 1;
  TMonom A(3);
  TMonom C(4);
  A.SetPower(a);
  ASSERT_ANY_THROW(A * C);
}

TEST(TMonom, can_equivalence_monoms)
{
  int a[3] = { 1, 2, 3 };
  TMonom A(3, a, 3.1);
  TMonom B(3, a, 3.1);
  ASSERT_NO_THROW(A == B);
  ASSERT_EQ(true, A == B);
}

TEST(TMonom, trows_when_equivalence_monoms_with_different_n)
{
  TMonom A(3);
  TMonom B(4);
  ASSERT_ANY_THROW(A == B);
}

TEST(TMonom, equivalence_different_monoms)
{
  int a[3] = { 1, 2, 3 },
    b[3] = { 1, 3, 2 };

  TMonom A(3);
  TMonom B(3);
  A.SetPower(a);
  B.SetPower(b);
  ASSERT_EQ(false, A == B);
  B.SetPower(a);
  A.SetC(3.1);
  A.SetC(3.4);
  ASSERT_EQ(false, A == B);
}

TEST(TMonom, trows_equivalence_monoms_with_different_n)
{
  TMonom A(3);
  TMonom B(4);
  ASSERT_ANY_THROW(A == B);
}

TEST(TMonom, can_compare_equal_monoms)
{
  int a[3] = { 1, 2, 3 },
    b[3] = { 1, 3, 2 };

  TMonom A(3);
  TMonom B(3);
  A.SetPower(a);
  B.SetPower(b);
  ASSERT_EQ(false, A > B);
  ASSERT_EQ(true, A < B);
}


TEST(TMonom, trows_compare_monoms_with_different_n)
{
  TMonom A(3);
  TMonom B(4);
  ASSERT_ANY_THROW(A > B);
  ASSERT_ANY_THROW(A < B);
}