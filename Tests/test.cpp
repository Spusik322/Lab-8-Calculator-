#include "pch.h"
#include "C:\Users\Spusik\Documents\GitHub\Lab-8(Calculator)\Calculator.cpp"
#include "C:\Users\Spusik\Documents\GitHub\Lab-8(Calculator)\stack.h"

TEST(Stack, Is_Empty) {
	StackMinecraft<int> test = StackMinecraft<int>();
  EXPECT_EQ(test.isEmpty(), true);
  EXPECT_TRUE(true);
}

TEST(Stack, Size) {
	StackMinecraft<int> test = StackMinecraft<int>();
	test << 2 << 3;
	EXPECT_EQ(test.size(), 2);
	EXPECT_TRUE(true);
}

TEST(Stack, Top) {
	StackMinecraft<int> test = StackMinecraft<int>();
	test << 2 << 3;
	EXPECT_EQ(test.top(), 3);
	EXPECT_TRUE(true);
}

TEST(Stack, Push) {
	StackMinecraft<int> test = StackMinecraft<int>();
	test.push(3);
	EXPECT_EQ(test.top(), 3);
	EXPECT_TRUE(true);
}

TEST(Stack, Pop) {
	StackMinecraft<int> test = StackMinecraft<int>();
	test.push(52);
	EXPECT_EQ(test.pop(), 52);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Push) {
	StackMinecraft<int> test = StackMinecraft<int>();
	test << 3 << 52;
	EXPECT_EQ(test.top(), 52);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Pop) {
	StackMinecraft<int> test = StackMinecraft<int>();
	test << 3 << 52;
	int n;
	test >> n;
	EXPECT_EQ(n, 52);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Assignment) {
	StackMinecraft<int> test = StackMinecraft<int>();
	StackMinecraft<int> test1 = StackMinecraft<int>();
	test << 3 << 52;
	test1 = test;
	EXPECT_EQ(test1 == test, true);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Square_Brackets) {
	StackMinecraft<int> test = StackMinecraft<int>();
	test << 3 << 52;
	EXPECT_EQ(test[0], 3);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Equal) {
	StackMinecraft<int> test = StackMinecraft<int>();
	StackMinecraft<int> test1 = StackMinecraft<int>();
	test << 3 << 52;
	test1 = test;
	bool b = test1 == test;
	EXPECT_EQ(b, true);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Not_Equal) {
	StackMinecraft<int> test = StackMinecraft<int>();
	StackMinecraft<int> test1 = StackMinecraft<int>();
	test << 3 << 52;
	test1 = test;
	test1 << 42;
	bool b = test1 != test;
	EXPECT_EQ(b, true);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Greater) {
	StackMinecraft<int> test = StackMinecraft<int>();
	StackMinecraft<int> test1 = StackMinecraft<int>();
	test << 3 << 52;
	test1 = test;
	test1 << 42;
	bool b = test1 > test;
	EXPECT_EQ(b, true);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Greater_Or_Equal) {
	StackMinecraft<int> test = StackMinecraft<int>();
	StackMinecraft<int> test1 = StackMinecraft<int>();
	test << 3 << 52;
	test1 = test;
	bool b = test1 >= test;
	EXPECT_EQ(b, true);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Less) {
	StackMinecraft<int> test = StackMinecraft<int>();
	StackMinecraft<int> test1 = StackMinecraft<int>();
	test << 3 << 52;
	test1 = test;
	test1 << 42;
	bool b = test < test1;
	EXPECT_EQ(b, true);
	EXPECT_TRUE(true);
}

TEST(Stack, Operator_Less_Or_Equal) {
	StackMinecraft<int> test = StackMinecraft<int>();
	StackMinecraft<int> test1 = StackMinecraft<int>();
	test << 3 << 52;
	test1 = test;
	bool b = test1 >= test;
	EXPECT_EQ(b, true);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Transformation) {
	std::string t = "(8       +     4)/      5";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.transformation(t), "(8+4)/5");
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If1) {
	std::string t = "((";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If1_If1) {
	std::string t = "8(((";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If2) {
	std::string t = "8)))";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If2_If1) {
	std::string t = ")))";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If4_1) {
	std::string t = "5 +";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If4_2) {
	std::string t = "5 *";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If4_3) {
	std::string t = "5 /";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If4_If1_1) {
	std::string t = "+";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If4_If1_2) {
	std::string t = "*";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If4_If1_3) {
	std::string t = "/";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If5_1) {
	std::string t = "(--8)";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If5_2) {
	std::string t = "(-8)";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), true);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If5_3) {
	std::string t = "-8";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If5_4) {
	std::string t = "(-(-8))";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), true);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If6) {
	std::string t = "2^";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If6_If1) {
	std::string t = "+^";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If7_1) {
	std::string t = ".";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If7_2) {
	std::string t = "8.";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If7_3) {
	std::string t = ".5";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If7_4) {
	std::string t = "8.35";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), true);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If7_5) {
	std::string t = "8.3.5";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If7_6) {
	std::string t = "3.5 + 3.5";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), true);
	EXPECT_TRUE(true);
}

TEST(Calculatur, IsValidInput_If7_7) {
	std::string t = "3.5 + 3.6.5";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.isValidInput(), false);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Execute_1) {
	std::string t = "";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Execute('+', 3, 5), 8);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Execute_2) {
	std::string t = "";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Execute('-', 3, 5), -2);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Execute_3) {
	std::string t = "";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Execute('*', 3, 5), 15);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Execute_4) {
	std::string t = "";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Execute('/', 10, 5), 2);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Execute_5) {
	std::string t = "";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Execute('^', 3, 3), 27);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Execute_6) {
	std::string t = "";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Execute('!', 3, 3), 0);
	EXPECT_TRUE(true);
}

TEST(Calculatur, GetStringNumber_1) {
	std::string t = "5.55+4";
	Calculator test = Calculator(t);
	int i = 0;
	EXPECT_EQ(test.GetStringNumber(t, i), "5.55");
	EXPECT_TRUE(true);
}

TEST(Calculatur, GetStringNumber_2) {
	std::string t = "5.55+4";
	Calculator test = Calculator(t);
	int i = 5;
	EXPECT_EQ(test.GetStringNumber(t, i), "4");
	EXPECT_TRUE(true);
}

TEST(Calculatur, ToPostfix_1) {
	std::string t = "5.55+4";
	Calculator test = Calculator(t);
	int i = 5;
	EXPECT_EQ(test.ToPostfix(t), "5.55 4 +");
	EXPECT_TRUE(true);
}

TEST(Calculatur, ToPostfix_2) {
	std::string t = "(3 + 7/7 -4)*2";
	Calculator test = Calculator(t);
	int i = 5;
	EXPECT_EQ(test.ToPostfix(t), "3 7 7 /+4 -2 *");
	EXPECT_TRUE(true);
}

TEST(Calculatur, ToPostfix_3) {
	std::string t = "((15-7)/2+(28-6)/11)/2 + 52";
	Calculator test = Calculator(t);
	int i = 5;
	EXPECT_EQ(test.ToPostfix(t), "15 7 -2 /28 6 -11 /+2 /52 +");
	EXPECT_TRUE(true);
}

TEST(Calculatur, Calc_1) {
	std::string t = "5.55+4";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Calc(), 9.55);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Calc_2) {
	std::string t = "(3 + 7/7 -4)*2";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Calc(), 0);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Calc_3) {
	std::string t = "((15-7)/2+(28-6)/11)/2 + 52";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Calc(), 55);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Calc_4) {
	std::string t = "(15.25-7)/5+8.35";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Calc(), 10);
	EXPECT_TRUE(true);
}

TEST(Calculatur, Calc_5) {
	std::string t = "1 - (35*2 - 13 +15^2 - 5^3)";
	Calculator test = Calculator(t);
	EXPECT_EQ(test.Calc(), -156);
	EXPECT_TRUE(true);
}