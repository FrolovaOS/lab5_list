#pragma once
#include "../base/TMonom.h"
#include "../gtest/gtest.h"

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom mn);
}

TEST(TMonom, can_create_monom_with_value)
{
	ASSERT_NO_THROW(TMonom mn(0,-1));
}

TEST(TMonom, can_get_coef_of_monom_)
{
	TMonom mn(0, -1);

	EXPECT_EQ(mn.GetCoef(),0);
}


TEST(TMonom, can_get_power_of_monom_)
{
	TMonom mn(0, -1);

	EXPECT_EQ(mn.GetPower(), -1);
}

TEST(TMonom, can_set_coef_of_monom_)
{
	TMonom mn;
	mn.SetCoef(1);

	EXPECT_EQ(mn.GetCoef(), 1);
}

TEST(TMonom, can_set_power_of_monom_)
{
	TMonom mn;
	mn.SetPower(1);

	EXPECT_EQ(mn.GetPower(), 1);
}

TEST(TMonom, can_set_val_of_monom_)
{
	TMonom mn;
	TMonom mn1(0,1);
	mn.SetValue(0,1);

	EXPECT_TRUE(mn1 == mn);
}

TEST(TMonom, can_clear_monom_)
{
	TMonom mn(1,1);
	TMonom mn1(0, 0);
	mn.Clear();
	EXPECT_TRUE(mn1 == mn);
}

TEST(TMonom, EQ_of_monoms)
{
	TMonom mn(0, 0);
	TMonom mn1(0, 0);
	EXPECT_TRUE(mn1==mn);
}

TEST(TMonom, not_EQ_of_monoms)
{
	TMonom mn(0, 0);
	TMonom mn1(0, 1);
	EXPECT_TRUE(mn1 != mn);
}

TEST(TMonom, multiplication_of_two_monoms)
{
	TMonom mn(3, 3);
	TMonom mn1(2, 2);
	TMonom mn2 = mn * mn1;
	TMonom mn3(6,5);
	EXPECT_TRUE(mn2 == mn3);
}

TEST(TMonom, copy_another_monom)
{
	TMonom mn(3, 3);
	TMonom mn1(2, 2);
	mn1 = mn;
	
	EXPECT_TRUE(mn1 == mn);
}