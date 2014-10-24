#include "stdafx.h"
#include "CppUnitTest.h"
#include "Actor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(TestCActor)
	{
	public:
		
		TEST_METHOD(TestCActorConstructor)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), actor.GetName());
		}

		TEST_METHOD(TestCActorDefaultEnableValue)
		{
			CActor actor(L"Harold");
			Assert::IsTrue(actor.IsEnabled());
		}

		TEST_METHOD(TestCActorClickableDefault)
		{
			CActor actor(L"Harold");
			Assert::IsTrue(actor.IsClickable());
		}

		TEST_METHOD(TestCActorDefaultPositionValue)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(0, actor.GetPosition().X);
			Assert::AreEqual(0, actor.GetPosition().Y);
		}
	};
}