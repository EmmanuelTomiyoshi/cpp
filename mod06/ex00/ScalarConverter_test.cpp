#include "doctest.h"
#include "ScalarConverter.hpp"

TEST_CASE("test with char")
{
	CHECK_EQ(parse("a"), CHAR);
	CHECK_EQ(parse("."), CHAR);
	CHECK_EQ(parse("-"), CHAR);
	CHECK_EQ(parse("+"), CHAR);
	CHECK_EQ(parse("&"), CHAR);
	CHECK_EQ(parse("\\"), CHAR);
	CHECK_EQ(parse("\""), CHAR);
	CHECK_EQ(parse("\n"), CHAR);
	CHECK_EQ(parse("\a"), CHAR);
	CHECK_EQ(parse("\0"), UNKNOWN);
	CHECK_EQ(parse("aa"), UNKNOWN);
	CHECK_EQ(parse("aa1"), UNKNOWN);
}

TEST_CASE("test with int")
{
	CHECK_EQ(parse("0"), INT);
	CHECK_EQ(parse("000000"), INT);
	CHECK_EQ(parse("1"), INT);
	CHECK_EQ(parse("11"), INT);
	CHECK_EQ(parse("9"), INT);
	CHECK_EQ(parse("10"), INT);
	CHECK_EQ(parse("-1"), INT);
	CHECK_EQ(parse("-10"), INT);
	CHECK_EQ(parse("-255555"), INT);
	CHECK_EQ(parse("+255555"), INT);
	CHECK_EQ(parse("0001"), INT);
	CHECK_EQ(parse("-0001"), INT);
	CHECK_EQ(parse("-1-"), UNKNOWN);
	CHECK_EQ(parse("a000000"), UNKNOWN);
	CHECK_EQ(parse("000000a"), UNKNOWN);
	CHECK_EQ(parse("--1"), UNKNOWN);
	CHECK_EQ(parse("+-1"), UNKNOWN);
	CHECK_EQ(parse("-0"), INT);
	CHECK_EQ(parse("+0"), INT);
}

TEST_CASE("test with float")
{
	CHECK_EQ(parse(".2f"), FLOAT);
	CHECK_EQ(parse(".2F"), FLOAT);
	CHECK_EQ(parse("0.2f"), FLOAT);
	CHECK_EQ(parse("0.2F"), FLOAT);
	CHECK_EQ(parse("0000000.2f"), FLOAT);
	CHECK_EQ(parse("000000F"), FLOAT);
	CHECK_EQ(parse("000000f"), FLOAT);
	CHECK_EQ(parse("01010101.2f"), FLOAT);
	CHECK_EQ(parse("1.235434534f"), FLOAT);
	CHECK_EQ(parse("0000000.2F"), FLOAT);
	CHECK_EQ(parse("01010101.2F"), FLOAT);
	CHECK_EQ(parse("2.f"), FLOAT);
	CHECK_EQ(parse("2.F"), FLOAT);
	CHECK_EQ(parse("2.0f"), FLOAT);
	CHECK_EQ(parse("2.0F"), FLOAT);
	CHECK_EQ(parse("-2.0f"), FLOAT);
	CHECK_EQ(parse("-2.0F"), FLOAT);
	CHECK_EQ(parse("-2.f"), FLOAT);
	CHECK_EQ(parse("-2.F"), FLOAT);
	CHECK_EQ(parse("01010101..2F"), UNKNOWN);
	CHECK_EQ(parse("01010101..2f"), UNKNOWN);
	CHECK_EQ(parse("a01010101.2f"), UNKNOWN);
	CHECK_EQ(parse("01010101.2af"), UNKNOWN);
	CHECK_EQ(parse("a01010101.2af"), UNKNOWN);
	CHECK_EQ(parse("a01010101.2F"), UNKNOWN);
	CHECK_EQ(parse("01010101.2aF"), UNKNOWN);
	CHECK_EQ(parse("a01010101.2aF"), UNKNOWN);
	CHECK_EQ(parse("01010101.2Ff"), UNKNOWN);
	CHECK_EQ(parse("01010101.2afF"), UNKNOWN);
	CHECK_EQ(parse("F01010101.2f"), UNKNOWN);
	CHECK_EQ(parse("f01010101.2aF"), UNKNOWN);
}

TEST_CASE("test with double")
{
	CHECK_EQ(parse(".2"), DOUBLE);
	CHECK_EQ(parse("0.2"), DOUBLE);
	CHECK_EQ(parse("0000000.2"), DOUBLE);
	CHECK_EQ(parse("01010101.2"), DOUBLE);
	CHECK_EQ(parse("1.2"), DOUBLE);
	CHECK_EQ(parse("2."), DOUBLE);
	CHECK_EQ(parse("2.0"), DOUBLE);
	CHECK_EQ(parse("2.1"), DOUBLE);
	CHECK_EQ(parse("1.235434534"), DOUBLE);
	CHECK_EQ(parse("01010101..2"), UNKNOWN);
	CHECK_EQ(parse("a01010101.2"), UNKNOWN);
	CHECK_EQ(parse("01010101.2a"), UNKNOWN);
	CHECK_EQ(parse("a01010101.2a"), UNKNOWN);
}
