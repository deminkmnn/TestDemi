#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Проект\ConsoleApplication1\ConsoleApplication1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_tests)
	{
	public:

		TEST_METHOD(calculate_get3and4_minus11returned)
		{
			int n = 3;
			double x = -4;
			double expected = -6.0;

			double actual = calculateY(x, n);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(calculate_get6and5_10000returned)
		{
			int n = 6;
			double x = -5;
			double expected = 10000.0;

			double actual = calculateY(x, n);

			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(checkvalidn)
	{
	public:
		TEST_METHOD(chackVariableForN10)
		{
			int n = 10;

			try {
				if (n > 1) {
					Assert::IsTrue(true);
				}

			}
			catch (...) {
				Assert::Fail();
			}
		}
	
	public:
		TEST_METHOD(checkVariableForN1)
		{
			int n = 1;

			if (n > 1) {
				Assert::IsTrue(true);
			}
			else {
				Assert::Fail();
			}
		}
	};
	TEST_CLASS(checkstep)
	{
	public:
		TEST_METHOD(CHECKSTEP10a13b)
		{
			double a = 10;
			double b = 13;
			try {
				if (a < b) {
					Assert::IsTrue(true);
				}
			}
			catch (...) {
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(CHECKSTEP3a3b)
		{
			double a = 3;
			double b = 3;
			int n = 3;
			int x;
			double expected = 10332;

			double actual = calculateY(x = b, n);

			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(CHECKSTEP10a6b)
		{
			double a = 10;
			double b = 6;
			try {
				if (a > b) {
					Assert::Fail();
				}
			}
			catch (...) {
				Assert::IsTrue(true);
			}

		}
	};
}
