
#pragma once
#include "../base/TPolinom.h"
#include "../base/TMonom.h"
#include "../gtest/gtest.h"
#include <string>

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p(""));
}

TEST(TPolinom, can_derivative_of_polinom_X)
{
	TPolinom p("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p1("");
	p1=p.Derivative('X');
	EXPECT_EQ(p1.GetPolinom(), "+8X^3Y^5Z^2-9X^2Y^2Z^8+7Y^1Z^6");
}

TEST(TPolinom, can_derivative_of_polinom2_X)
{
	TPolinom p("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3");
	TPolinom p1("");
	p1 = p.Derivative('X');

	EXPECT_EQ(p1.GetPolinom(), "+25X^4Y^3Z^2+4X^3Y^5Z^2-99X^2Y^5+10X^1Y^5Z^6");
}

TEST(TPolinom, can_derivative_of_polinom_Y)
{
	TPolinom p("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p1("");
	p1 = p.Derivative('Y');

	EXPECT_EQ(p1.GetPolinom(), "+10X^4Y^4Z^2-6X^3Y^1Z^8+7X^1Z^6");
}

TEST(TPolinom, can_derivative_of_polinom2_Y)
{
	TPolinom p("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3");
	TPolinom p1("");
	p1 = p.Derivative('Y');

	EXPECT_EQ(p1.GetPolinom(), "+15X^5Y^2Z^2+5X^4Y^4Z^2-165X^3Y^4+25X^2Y^4Z^6");
}

TEST(TPolinom, can_derivative_of_polinom_Z)
{
	TPolinom p("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p1("");
	p1 = p.Derivative('Z');

	EXPECT_EQ(p1.GetPolinom(), "+4X^4Y^5Z^1-24X^3Y^2Z^7+42X^1Y^1Z^5+2");
}

TEST(TPolinom, can_derivative_of_polinom2_Z)
{
	TPolinom p("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3");
	TPolinom p1("");
	p1 = p.Derivative('Z');

	EXPECT_EQ(p1.GetPolinom(), "+10X^5Y^3Z^1+2X^4Y^5Z^1+30X^2Y^5Z^5");
}

TEST(TPolinom, can_Integration_of_polinom_X)
{
	TPolinom p("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p1("");
	p1 = p.Integration('X');

	EXPECT_EQ(p1.GetPolinom(), "+0.4X^5Y^5Z^2-0.75X^4Y^2Z^8+3.5X^2Y^1Z^6+2X^1Z^1");
}

TEST(TPolinom, can_Intagration_of_polinom2_X)
{
	TPolinom p("5X^4Y^3Z^2+X^4Y^5Z^2-33X^2Y^5+6X^2Y^5Z^6+3");
	TPolinom p1("");
	p1 = p.Integration('X');
	EXPECT_EQ(p1.GetPolinom(), "+0.2X^5Y^5Z^2+1X^5Y^3Z^2+2X^3Y^5Z^6-11X^3Y^5+3X^1");
}

TEST(TPolinom, can_Integration_of_polinom_Y)
{
	TPolinom p("12X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p1("");
	p1 = p.Integration('Y');

	EXPECT_EQ(p1.GetPolinom(), "+2X^4Y^6Z^2-1X^3Y^3Z^8+3.5X^1Y^2Z^6+2Y^1Z^1");
}

TEST(TPolinom, can_Integration_of_polinom2_Y)
{
	TPolinom p("5X^4Y^3Z^2+X^4Y^4Z^2-33X^2Y^5+6X^2Y^5Z^6+3");
	TPolinom p1("");
	p1 = p.Integration('Y');
	EXPECT_EQ(p1.GetPolinom(), "+0.2X^4Y^5Z^2+1.25X^4Y^4Z^2+1X^2Y^6Z^6-5.5X^2Y^6+3Y^1");
}

TEST(TPolinom, can_Integration_of_polinom_Z)
{
	TPolinom p("3X^4Y^5Z^2-9X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p1("");
	p1 = p.Integration('Z');

	EXPECT_EQ(p1.GetPolinom(), "+1X^4Y^5Z^3-1X^3Y^2Z^9+1X^1Y^1Z^7+1Z^2");
}

TEST(TPolinom, can_Integration_of_polinom2_Z)
{
	TPolinom p("6X^5Y^3Z^2+X^4Y^5Z-33X^3Y^5+5X^2Y^5Z^4+3 ");
	TPolinom p1("");
	p1 = p.Integration('Z');

	EXPECT_EQ(p1.GetPolinom(), "+2X^5Y^3Z^3+0.5X^4Y^5Z^2-33X^3Y^5Z^1+1X^2Y^5Z^5+3Z^1");
}

TEST(TPolinom, 1_can_get_value_in_point_of_polinom)
{
	TPolinom p("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	

	EXPECT_EQ(p.ValueInPoint(1, 1, 1),8);
}

TEST(TPolinom, 1_can_get_value_in_point_of_polinom2)
{
	TPolinom p("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");

	EXPECT_EQ(p.ValueInPoint(1,1,1), -19);
}

TEST(TPolinom, 2_can_get_value_in_point_of_polinom)
{
	TPolinom p("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");


	EXPECT_EQ(p.ValueInPoint(2, 0, 1), 2);
}

TEST(TPolinom, 2_can_get_value_in_point_of_polinom2)
{
	TPolinom p("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");

	EXPECT_EQ(p.ValueInPoint(2, 0, 1), 3);
}

TEST(TPolinom, 3_can_get_value_in_point_of_polinom)
{
	TPolinom p("2X^4Y^5-3X^3Y^2Z^8+7XYZ^6+2Z");


	EXPECT_EQ(p.ValueInPoint(2, 1, 0), 32);
}

TEST(TPolinom, 3_can_get_value_in_point_of_polinom2)
{
	TPolinom p("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");

	EXPECT_EQ(p.ValueInPoint(2, 1, 0), -261);
}

TEST(TPolinom, can_sort_polinom)
{
	TPolinom p("Y^2Z+XZ+X^6+X^5Y^2+4");
	p.Sort();
	EXPECT_EQ(p.GetPolinom(), "+1X^6+1X^5Y^2+1X^1Z^1+1Y^2Z^1+4");
}

TEST(TPolinom, can_add_two__polinoms)
{
	TPolinom p1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p2("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");
	TPolinom p3("");
	p3 = p1 + p2;

	EXPECT_EQ(p3.GetPolinom(),"+5X^5Y^3Z^2+3X^4Y^5Z^2-33X^3Y^5-3X^3Y^2Z^8+5X^2Y^5Z^6+7X^1Y^1Z^6+2Z^1+3");
}

TEST(TPolinom, can_sub_two_polinoms)
{
	TPolinom p1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p2("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");
	TPolinom p3("");
	p3 = p1 - p2;

	EXPECT_EQ(p3.GetPolinom(), "-5X^5Y^3Z^2+1X^4Y^5Z^2+33X^3Y^5-3X^3Y^2Z^8-5X^2Y^5Z^6+7X^1Y^1Z^6+2Z^1-3");
}

TEST(TPolinom, EQ_of_two_polinoms)
{
	TPolinom p1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p2("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	

	EXPECT_EQ(p1==p2, 1);
}

TEST(TPolinom, not_EQ_of_two_polinoms)
{
	TPolinom p1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	TPolinom p2(" + 5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");


	EXPECT_EQ(p1 == p2, 0);
}

TEST(TPolinom, 1_multiplication_of_polynomials)
{
	TPolinom p1("X^2Y^7+XY^5+Z");
	TPolinom p2("X^5+Y^6Z+5");
	TPolinom p3 = p1 * p2;
	
	EXPECT_EQ(p3.GetPolinom(),"+1X^7Y^7+1X^6Y^5+1X^5Z^1+1X^2Y^13Z^1+5X^2Y^7+1X^1Y^11Z^1+5X^1Y^5+1Y^6Z^2+5Z^1" );
}

TEST(TPolinom, 2_multiplication_of_polynomials)
{
	TPolinom p1("X^4+X^2");
	TPolinom p2("X^2+1");
	TPolinom p3 = p1 * p2;

	EXPECT_EQ(p3.GetPolinom(), "+1X^6+2X^4+1X^2");
}

TEST(TPolinom, 1_the_whole_part_division_of_polynomials)
{
	TPolinom p1("X^3-12X^2-42");
	TPolinom p2("X-3");
	TPolinom p3("");
	TPolinom p4("");
	p3 = p1.Division(p2,p4);

	EXPECT_EQ(p3.GetPolinom(), "+1X^2-9X^1-27");
}

TEST(TPolinom, 1_the_remainder_division_of_polynomials)
{
	TPolinom p1("X^3-12X^2-42");
	TPolinom p2("X-3");
	TPolinom p3("");
	TPolinom p4("");
	p3 = p1.Division( p2, p4);

	EXPECT_EQ(p4.GetPolinom(), "-123");
}

TEST(TPolinom, 2_the_whole_part_division_of_polynomials)
{
	TPolinom p1("X^2Y^2+3Y^7+12Z-1");
	TPolinom p2("XY-Z");
	TPolinom p3("");
	TPolinom p4("");
	p3 = p1.Division(p2, p4);

	EXPECT_EQ(p3.GetPolinom(), "+1X^1Y^1+1Z^1");
}

TEST(TPolinom, 2_the_remainder_division_of_polynomials)
{
	TPolinom p1("X^2Y^2+3Y^7+12Z-1");
	TPolinom p2("XY-Z");
	TPolinom p3("");
	TPolinom p4("");
	p3 = p1.Division( p2, p4);

	EXPECT_EQ(p4.GetPolinom(), "+3Y^7+1Z^2+12Z^1-1");
}

TEST(TPolinom, can_not_division)
{
	TPolinom p1("X^2Y^2+3Y^7+12Z-1");
	TPolinom p2("XY-Z");
	TPolinom p4("");

	ASSERT_ANY_THROW(p2.Division(p1, p4));
}