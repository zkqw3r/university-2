#include "pch.h"
#include "CppUnitTest.h"
#include "C:/Users/Admin/source/repos/ConsoleApplication6/ConsoleApplication6/Logic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MyTests
{
	TEST_CLASS(MyTests)
	{
	public:
		
		TEST_METHOD(TestNormalValues)
		{
			float x = 1.0f;
			float y = 1.0f;
			float s = 0.0f;
			float r = 0.0f;
			float c = 0.0f;
			float expected_s = 2.718f;
			float expected_r = 1.189f;
			Calculate(x, y, s, r, c);

			Assert::AreEqual(expected_s, s, 0.001f, L"S is incorrect");
		}

		TEST_METHOD(TestDivisionByZero) {
			float x = 7.0f;
			float y = 0.0f;
			float s = 0.0f;
			float r = 0.0f;
			float c = 0.0f;
			auto func = [&] { Calculate(x, y, s, r, c); };
			Assert::ExpectException<std::invalid_argument>(func, L"Division by zero");
		}
	};
}
