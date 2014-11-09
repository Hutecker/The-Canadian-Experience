/**
* \file HelgaFactory.cpp
*
* \author Stephan Hutecker
*/


#include "stdafx.h"
#include "HelgaFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"
#include "TextBubbleDrawable.h"

using namespace Gdiplus;
using namespace std;


/**
* \brief constructor
*/
CHelgaFactory::CHelgaFactory()
{
}


/**
* \brief destructor
*/
CHelgaFactory::~CHelgaFactory()
{
}

/** \brief This is a concrete factory method that creates our Harold actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CHelgaFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Helga");

	auto shirt = make_shared<CImageDrawable>(L"Shirt", L"images/dress.png");
	shirt->SetCenter(Point(44, 138));
	shirt->SetPosition(Point(0, -114));
	actor->SetRoot(shirt);

	auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/lleg2.png");
	lleg->SetCenter(Point(11, 9));
	lleg->SetPosition(Point(27, 0));
	shirt->AddChild(lleg);

	auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/rleg2.png");
	rleg->SetCenter(Point(39, 9));
	rleg->SetPosition(Point(-27, 0));
	shirt->AddChild(rleg);

	auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/headb3.png");
	headb->SetCenter(Point(44, 31));
	headb->SetPosition(Point(0, -130));
	shirt->AddChild(headb);

	auto headt = make_shared<CHeadTop>(L"Head Top", L"images/headt4.png");
	headt->SetCenter(Point(75, 109));
	headt->SetPosition(Point(0, -31));
	headt->SetFirstEyebrow(Point(52, 63), Point(66, 60));
	headt->SetSecondEyebrow(Point(83, 59), Point(97, 62));
	headt->SetFirstEye(Point(60, 76));
	headt->SetSecondEye(Point(87, 76));
	headb->AddChild(headt);

	auto larm = make_shared<CPolyDrawable>(L"Left Arm");
	larm->SetColor(Color(32, 105, 75));
	larm->SetPosition(Point(50, -130));
	larm->AddPoint(Point(-7, -7));
	larm->AddPoint(Point(-7, 96));
	larm->AddPoint(Point(8, 96));
	larm->AddPoint(Point(8, -7));
	shirt->AddChild(larm);


	auto rarm = make_shared<CPolyDrawable>(L"Right Arm");
	rarm->SetColor(Color(32, 105, 75));
	rarm->SetPosition(Point(-45, -130));
	rarm->AddPoint(Point(-7, -7));
	rarm->AddPoint(Point(-7, 96));
	rarm->AddPoint(Point(8, 96));
	rarm->AddPoint(Point(8, -7));
	shirt->AddChild(rarm);

	auto lhand = make_shared<CPolyDrawable>(L"Left Hand");
	lhand->SetColor(Color(253, 218, 180));
	lhand->SetPosition(Point(0, 96));
	lhand->AddPoint(Point(-12, -2));
	lhand->AddPoint(Point(-12, 17));
	lhand->AddPoint(Point(11, 17));
	lhand->AddPoint(Point(11, -2));
	larm->AddChild(lhand);

	auto rhand = make_shared<CPolyDrawable>(L"Right Hand");
	rhand->SetColor(Color(253, 218, 180));
	rhand->SetPosition(Point(0, 96));
	rhand->AddPoint(Point(-12, -2));
	rhand->AddPoint(Point(-12, 17));
	rhand->AddPoint(Point(11, 17));
	rhand->AddPoint(Point(11, -2));
	rarm->AddChild(rhand);

	auto textBubbleLeft = make_shared<CTextBubbleDrawable>(L"Text Bubble Left");
	textBubbleLeft->SetBubblePosition(50, -90);
	textBubbleLeft->SetText(L"");
	headt->AddChild(textBubbleLeft);

	auto textBubbleRight = make_shared<CTextBubbleDrawable>(L"Text Bubble Right");
	textBubbleRight->SetMirror(true);
	textBubbleRight->SetText(L"");
	textBubbleRight->SetBubblePosition(-50, -90);
	headt->AddChild(textBubbleRight);

	actor->AddDrawable(larm);
	actor->AddDrawable(rarm);
	actor->AddDrawable(rhand);
	actor->AddDrawable(lhand);
	actor->AddDrawable(rleg);
	actor->AddDrawable(lleg);
	actor->AddDrawable(shirt);
	actor->AddDrawable(headb);
	actor->AddDrawable(headt);
	actor->AddDrawable(textBubbleLeft);
	actor->AddDrawable(textBubbleRight);

	return actor;
}