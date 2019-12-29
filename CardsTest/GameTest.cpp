#include "stdafx.h"
#include "CppUnitTest.h"

#include "../CardsConsole/Cards.h"
#include "../CardsConsole/Card.h"
#include "../CardsConsole/Deck.h"
#include "../CardsConsole/Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardsTest
{
	TEST_CLASS(GameTest)
	{
		TEST_METHOD(GameJudge) {
			Card c1(SPADES, SIX);
			Card c2(DIAMONDS, ACE);
			Game g;
			Assert::IsTrue(g.judge(c1, c2) == PLAYER2_WIN);
			Assert::IsTrue(g.judge(c2, c1) == PLAYER1_WIN);
			Assert::IsTrue(g.judge(c1, c1) == TIE);
		}

		TEST_METHOD(GetPlayerScores)
		{
			Game g;
			g.start();
			Assert::AreEqual(26, g.getScore1());
			Assert::AreEqual(26, g.getScore2());
		}
	};
}