#include "stdafx.h"
#include "CppUnitTest.h"
#include "PictureObserver.h"
#include "picture.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	class CPictureObserverMock : public CPictureObserver
	{
	public:
		CPictureObserverMock() : CPictureObserver() {}
		bool mUpdated = false;
		std::shared_ptr<CPicture> mPicture;
		virtual void UpdateObserver() override { mUpdated = true; }
		void SetPicture(std::shared_ptr<CPicture> picture) 
		{
			mPicture = picture;
			mPicture->AddObserver(this);
		}
		std::shared_ptr<CPicture> GetPicture() { return mPicture; }
	};

	TEST_CLASS(CPictureObserver)
	{
	public:
		
		TEST_METHOD(TestConstruct)
		{
			CPictureObserverMock observer;
		}

		TEST_METHOD(TestCPictureObserverOneObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);
		}

		TEST_METHOD(TestCPictureObserverGetPicture)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			Assert::IsTrue(observer.GetPicture() == picture);
		}

		TEST_METHOD(TestCPictureObserverTwoObservers)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// Allocate a CPicture object
			shared_ptr<CPicture> picture1 = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer1;

			// And set it for the observer:
			observer.SetPicture(picture);

			// And set it for the observer:
			observer1.SetPicture(picture1);

			picture->UpdateObservers();
			picture1->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);
			Assert::IsTrue(observer1.mUpdated);
		}

		TEST_METHOD(TestCPictureObserverObserverDeletion)
		{

			// Allocate a CPicture object
			shared_ptr<CPicture> picture1 = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer1;

			// And set it for the observer:
			observer1.SetPicture(picture1);

			{
				// Allocate a CPicture object
				shared_ptr<CPicture> picture = make_shared<CPicture>();

				// Create a mock observer object
				CPictureObserverMock observer;

				// And set it for the observer:
				observer.SetPicture(picture);
			}

			picture1->UpdateObservers();

			Assert::IsTrue(observer1.mUpdated);
		}
	};
}