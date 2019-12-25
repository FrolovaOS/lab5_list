#pragma once
#include "../base/TLists.h"
#include "../gtest/gtest.h"

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> t);
}

TEST(TList, can_add_Fict_node)
{
	TList<int> t;
	t.InsFict(2);
	EXPECT_EQ(t.GetVal(),2);
}

TEST(TList, can_add_First_node)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.Reset();
	EXPECT_EQ(t.GetVal(), 3);
}

TEST(TList, can_add_Last_node)
{
	TList<int> t;
	t.InsFict(2);
	t.InsLast(3);
	EXPECT_EQ(t.GetVal(), 3);
}

TEST(TList, can_add_Curr_node)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.InsCurrent(4);
	t.StepBack();
	EXPECT_EQ(t.GetVal(), 4);
}

TEST(TList, list_Is_not_Empty)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	EXPECT_TRUE(t.IsEmpty()==0);
}

TEST(TList, list_Is_Empty)
{
	TList<int> t;
	t.InsFict(2);
	EXPECT_TRUE(t.IsEmpty()==1);
}

TEST(TList, list_Is_End)
{
	TList<int> t;
	t.InsFict(2);
	EXPECT_TRUE(t.IsListEnded() == 1);
}

TEST(TList, list_Is_not_End)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	EXPECT_TRUE(t.IsListEnded() == 0);
}

TEST(TList, can_Set_Curr_val)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.SetCurrentVal(3);
	EXPECT_EQ(t.GetVal(), 3);
}

TEST(TList, can_Reset)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.InsLast(4);
	t.Reset();
	EXPECT_EQ(t.GetVal(), 3);
}

TEST(TList, can_go_next_node)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.InsLast(4);
	t.Reset();
	t.GoNext();
	EXPECT_EQ(t.GetVal(), 4);
}

TEST(TList, can_go_previous_node)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.StepBack();
	EXPECT_EQ(t.GetVal(), 2);
}

TEST(TList, can_delite_First_node)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.InsLast(4);
	t.DelFirst();
	EXPECT_EQ(t.GetVal(), 4);
}
TEST(TList, can_not_delite_First_node)
{
	TList<int> t;
	t.InsFict(2);

	ASSERT_ANY_THROW(t.DelFirst(););
}

TEST(TList, can_delite_Last_node)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.InsLast(4);
	t.DelLast();
	t.StepBack();
	EXPECT_EQ(t.GetVal(), 3);
}

TEST(TList, can_delite_Curr_node)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.InsCurrent(4);
	t.InsCurrent(5);
	t.DelCurrent();
	EXPECT_EQ(t.GetVal(), 5);
}

TEST(TList, can_delite_all_list)
{
	TList<int> t;
	t.InsFict(2);
	t.InsFirst(3);
	t.InsCurrent(4);
	t.DelList();
	EXPECT_TRUE(t.IsEmpty()==1);
}