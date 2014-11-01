#include "stdafx.h"
#include "CppUnitTest.h"
#include "Drawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	/**
	* \brief Mock class for abstract base class
	*/
	class CDrawableMock : public CDrawable
	{
	public:
		/**
		* \brief constructor
		* \param name the objects name
		*/
		CDrawableMock(const std::wstring &name) : CDrawable(name) {}

		virtual void Draw(Gdiplus::Graphics *graphics) override {}
		virtual bool HitTest(Gdiplus::Point pos) override { return false; }

	};

	TEST_CLASS(TestCDrawable)
	{
	public:
		
		TEST_METHOD(TestCDrawableContructor)
		{
			CDrawableMock drawable(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), drawable.GetName());
		}

		TEST_METHOD(TestCDrawableDefaultPosition)
		{
			CDrawableMock drawable(L"Harold");
			Assert::AreEqual(0, drawable.GetPosition().X);
			Assert::AreEqual(0, drawable.GetPosition().Y);
		}

		TEST_METHOD(TestCDrawableDefaultRotation)
		{
			CDrawableMock drawable(L"Harold");
			Assert::AreEqual(0.0, drawable.GetRotation(), 0.00001);
		}

		TEST_METHOD(TestCDrawableAssociation)
		{
			CDrawableMock body(L"Body");
			auto arm = std::make_shared<CDrawableMock>(L"Arm");
			auto leg = std::make_shared<CDrawableMock>(L"Leg");

			body.AddChild(arm);
			body.AddChild(leg);

			Assert::IsTrue(arm->GetParent() == &body);
			Assert::IsTrue(leg->GetParent() == &body);
		}
	};
}