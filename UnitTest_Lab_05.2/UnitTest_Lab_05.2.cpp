#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05.2/Lab_05.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
    TEST_CLASS(UnitTest52)
    {
    public:

        // A(x, n, a): наступний доданок = a * (-x / n);  A(2, 1, 1) = -2
        TEST_METHOD(TestA)
        {
            double t = A(2, 1, 1);
            Assert::AreEqual(-2.0, t);
        }

        // при x = 0 сума ряду дорівнює 1, порахований 1 доданок після першого
        TEST_METHOD(TestS_Zero)
        {
            int n;
            double t = S(0, 0.0001, n);
            Assert::AreEqual(1.0, t);
            Assert::AreEqual(1, n);
        }

        // сума ряду при x = 1 має збігатися з exp(-1) з точністю eps
        TEST_METHOD(TestS_One)
        {
            int n;
            double t = S(1, 0, n);
            Assert::AreEqual(exp(-1.0), t, 0);
        }
    };
}

