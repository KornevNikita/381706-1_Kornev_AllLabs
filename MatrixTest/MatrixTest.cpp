#include <gtest.h>
#include "Matrix.h"

TEST(TMatrix, can_create_Matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> Matrix(89));
}

TEST(TMatrix, throw_when_create_Matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> Matrix(-3));
}

TEST(TMatrix, can_create_copied_Matrix)
{
	TMatrix<int> Matrix(50);
	ASSERT_NO_THROW(TMatrix<int> Copy(Matrix));
}

TEST(TMatrix, throw_when_referring_to_a_nonexistent_element)
{
	TMatrix<int> Matrix(15);
	ASSERT_ANY_THROW(Matrix[15]);
}

TEST(TMatrix, can_referring_to_a_existent_element)
{
	TMatrix<int> Matrix(37);
	EXPECT_EQ(0, Matrix[0][0]);
}


TEST(TMatrix, operator_comparison_verification)
{
	TMatrix<int> Matrix(15);
	TMatrix<int> Copy(Matrix);
	ASSERT_TRUE(Matrix == Copy);
}
	
TEST(TMatrix, operator_equally_verification)
{
	TMatrix<int> Matrix(15);
	TMatrix<int> Copy(3);
	Copy = Matrix;
	ASSERT_TRUE(Matrix == Copy);
}


TEST(TMatrix, addition_operator_verification)
{
	TMatrix<int> One(4);
	TMatrix<int> Two(4);
	TMatrix<int> Result(4);
	for (int i = 0; i < One.GetSize(); i++)
		for (int j = 0; j < One.GetSize() - i; i++)
		{
			One[i][j] = 2;
			Two[i][j] = 4;
			Result[i][j] = 6;
		}
	One = One + Two;
	ASSERT_TRUE(One == Result);
}

TEST(TMatrix, multiply_operator_verification)
{
	TMatrix<int> One(2);
	TMatrix<int> Two(2);
	TMatrix<int> Result(2);
	One[0][0] = 2;
	One[0][1] = 2;
	One[1][0] = 2;

	Two[0][0] = 4;
	Two[0][1] = 4;
	Two[1][0] = 4;

	Result[0][0] = 8;
	Result[0][1] = 16;
	Result[1][0] = 8;
	One = One * Two;
	ASSERT_TRUE(One == Result);
}