#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr9.1/Pr9.1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 3;
			Student* p = new Student[n];

			p[0].prizv = "Test1";
			p[0].Fizik = 4;

			p[1].prizv = "Test2";
			p[1].Fizik = 5;

			p[2].prizv = "Test3";
			p[2].Fizik = 3;

			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			SearchStudens(p, n);

			std::string output = buffer.str();
			Assert::IsTrue(output.find("Test1") != std::string::npos);
			Assert::IsTrue(output.find("Test2") != std::string::npos);
			Assert::IsFalse(output.find("Test3") != std::string::npos);

			std::cout.rdbuf(old);

			delete[] p;
		}
	};
}