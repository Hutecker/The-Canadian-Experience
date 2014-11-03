#include "stdafx.h"
#include "CppUnitTest.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "Picture.h"
#include <memory>

using namespace std;
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

		TEST_METHOD(TestCActorSetPicture)
		{
			// Create a picture object
			auto picture = make_shared<CPicture>();

			// Create an actor and add it to the picture
			auto actor = make_shared<CActor>(L"Actor");

			// Create a drawable for the actor
			auto drawable = make_shared<CPolyDrawable>(L"Drawable");
			actor->SetRoot(drawable);
			actor->AddDrawable(drawable);

			picture->AddActor(actor);

			auto channel = drawable->GetAngleChannel();
			Assert::IsTrue(channel->GetTimeline() == picture->GetTimeline());
		}
	};
}