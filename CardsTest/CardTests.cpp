#include "stdafx.h"
#include "CppUnitTest.h"

#include "../CardsConsole/Cards.h"
#include "../CardsConsole/Card.h"
#include "../CardsConsole/Deck.h"
#include "../CardsConsole/Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardsTest
{		
	TEST_CLASS(CardTest)
	{
	public:
		
		TEST_METHOD(TestGetValue)
		{
			Card c(HEARTS, THREE);
			Assert::AreEqual(static_cast<int>(c.getValue()), static_cast<int>(THREE));
		}

		TEST_METHOD(TestEquals)
		{
			Card diamondThree(DIAMONDS, THREE);
			Card spadeThree(SPADES, THREE);
			Assert::IsTrue(diamondThree == spadeThree);
			Card diamondFour(DIAMONDS, FOUR);
			Assert::IsFalse(diamondThree == diamondFour);
		}

		TEST_METHOD(TestLessThan)
		{
			Card diamondThree(DIAMONDS, THREE);
			Card spadeThree(SPADES, THREE);
			Card diamondFour(DIAMONDS, FOUR);
			Assert::IsTrue(diamondThree < diamondFour);
			Assert::IsFalse(diamondThree < spadeThree);
		}

		TEST_METHOD(TestGreaterThan)
		{
			Card diamondThree(DIAMONDS, THREE);
			Card spadeThree(SPADES, THREE);
			Card diamondFour(DIAMONDS, FOUR);
			Assert::IsTrue(diamondFour > diamondThree);
			Assert::IsFalse(diamondThree > spadeThree);
		}

		TEST_METHOD(TestToString)
		{
			Card c(SPADES, JACK);
			std::string expected = "JACK of SPADES";
			Assert::AreEqual(c.toString(), expected);
		}

	};
}