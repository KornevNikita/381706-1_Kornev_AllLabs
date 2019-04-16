#include <gtest.h>
#include "TNode.h"

TEST(TNode, can_create_node_level_3)
{
	ASSERT_NO_THROW(TNode S('c'));
}

TEST(TNode, can_create_node_any_level)
{
	ASSERT_NO_THROW(TNode S(2));
}

TEST(TNode, can_create_node_level_2)
{
	ASSERT_NO_THROW(TNode S(2));
}

TEST(TNode, can_copied_node)
{
	TNode S('f');
	ASSERT_NO_THROW(TNode copy(S));
}
