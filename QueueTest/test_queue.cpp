#include "gtest.h"
#include "Queue.h"


TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> q(10));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-10));
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q1(10);
	for (int i = 0; i < 10; i++)
	  q1.Put(i);
	ASSERT_NO_THROW(TQueue<int> B(q1));
}

TEST(TQueue, check_full_queue)
{
	TQueue<int> q(10);
	for(int i = 0; i < 10; i++)
	  q.Put(i);
	EXPECT_EQ(1, q.IsFull());
}

TEST(TQueue, check_not_full_queue) 
{
  TQueue<int> q(10);
  for (int i = 0; i < 7; i++)
	q.Put(i);
  EXPECT_EQ(0, q.IsFull());
}

TEST(TQueue, check_empty_queue)
{
	TQueue<int> q(6);
	EXPECT_EQ(1, q.IsEmpty());
}

TEST(TQueue, can_put_element_in_not_full_queue) 
{
  TQueue<int> q(4);
  for (int i = 0; i < 3; i++)
	q.Put(i);

  ASSERT_NO_THROW(q.Put(5));
}

TEST(TQueue, cant_put_element_in_full_queue)
{
	TQueue<int> q(4);
	for(int i = 0; i < 4; i++)
		q.Put(i);

	ASSERT_ANY_THROW(q.Put(5));
}

TEST(TQueue, cant_get_element_from_empty_queue)
{
	TQueue<int> q(4);

	ASSERT_ANY_THROW(q.Get());
}

TEST(TQueue, can_put_element)
{
	TQueue<int> q(4);

	ASSERT_NO_THROW(q.Put(5));
}

TEST(TQueue, can_get_element)
{
	TQueue<int> q(4);
	q.Put(5);

	EXPECT_EQ(5, q.Get());
}

