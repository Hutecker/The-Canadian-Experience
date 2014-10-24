#include "stdafx.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(TestCPolyDrawablecpp)
	{
	public:
		
		TEST_METHOD(TestCPolyDrawableContructor)
		{
			CPolyDrawable polyDrawable(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), polyDrawable.GetName());
		}

		TEST_METHOD(TestCPolyDrawableDefaultColor)
		{
			CPolyDrawable polyDrawable(L"Harold");
			Gdiplus::Color black = Gdiplus::Color::Black;

			Assert::IsTrue(polyDrawable.GetColor().GetA() == black.GetA());
			Assert::IsTrue(polyDrawable.GetColor().GetB() == black.GetB());
			Assert::IsTrue(polyDrawable.GetColor().GetG() == black.GetG());

			Gdiplus::Color test(1, 1, 1);
			polyDrawable.Setcolor(test);

			Assert::IsTrue(polyDrawable.GetColor().GetA() == test.GetA());
			Assert::IsTrue(polyDrawable.GetColor().GetB() == test.GetB());
			Assert::IsTrue(polyDrawable.GetColor().GetG() == test.GetG());
		}
	};
}