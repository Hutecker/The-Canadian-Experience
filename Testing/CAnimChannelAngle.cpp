#include "stdafx.h"
#include "CppUnitTest.h"
#include "AnimChannelAngle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CAnimChannelAngle)
	{
	public:
		
		TEST_METHOD(GetterandSetterTest)
		{
			CAnimChannelAngle channel;
			channel.SetName("Test");
			channel::SetName("Test");
		}

	};
}