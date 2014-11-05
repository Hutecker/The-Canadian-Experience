#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "AnimChannelAngle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CAnimChannelAngleTest)
	{
	public:
		
		TEST_METHOD(GetterandSetterTest)
		{
			CAnimChannelAngle channel;
			channel.SetName(L"Test");
			wstring name = L"Test";
			Assert::AreEqual(name, channel.GetName());
		}

	};
}