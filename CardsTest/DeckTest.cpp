#include "stdafx.h"
#include "CppUnitTest.h"

#include "../CardsConsole/Cards.h"
#include "../CardsConsole/Card.h"
#include "../CardsConsole/Deck.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardsTest
{
	TEST_CLASS(DeckTest)
	{
	public:
		TEST_METHOD(DeckConstructor)
		{
			Deck d;
			Assert::AreEqual(d.size(), 0);
		}

		TEST_METHOD(DeckCopyConstructor)
		{
			Deck d;
			d.build();
			Deck e(d);
			// Didn't destroy d
			Assert::AreEqual(d.size(), 52);
			// Copied everything to e
			Assert::AreEqual(e.size(), 52);
			// Whole deck is equal
			int tests = 52;
			while (tests--) {
				Assert::IsTrue(*d.deal() == *e.deal());
			}
		}

		TEST_METHOD(DeckBuild)
		{
			Deck d;
			d.build();
			Assert::AreEqual(d.size(), 52);
		}

		TEST_METHOD(DeckDeal)
		{
			Deck d;
			d.build();
			std::shared_ptr<Card> pc = d.deal();
			Assert::AreEqual(d.size(), 51);
			Assert::AreEqual(pc->toString(), std::string("TWO of SPADES"));
		}

		TEST_METHOD(DeckShuffle)
		{
			Deck d;
			d.build();
			Deck e;
			e.build();
			Assert::AreEqual(d.deal()->toString(), e.deal()->toString());
			d.shuffle();
			e.shuffle();
			// Technically, there's a small chance these two are actually equal
			// This test can be improved for sure. At least verifies that the seeds change
			Assert::AreNotEqual(d.deal()->toString(), e.deal()->toString());
		}

		TEST_METHOD(ReceiveCard)
		{
			Deck d;
			shared_ptr<Card>c1 = make_shared<Card>(SPADES, FIVE);
			d.receive(c1);
			Assert::AreEqual(1, d.size());
			Assert::IsTrue(d.deal()->toString() == c1->toString());
		}

		TEST_METHOD(ReceiveDeck)
		{
			Deck d;
			shared_ptr<Card>c1 = make_shared<Card>(SPADES, FIVE);
			shared_ptr<Card>c2 = make_shared<Card>(SPADES, SIX);
			d.receive(c1);
			d.receive(c2);
			Deck e; 
			e.receive(d);
			Assert::AreEqual(e.size(), 2);
			Assert::AreEqual(d.size(), 0);
			Assert::AreEqual(e.deal()->toString(), c1->toString());
			Assert::AreEqual(e.deal()->toString(), c2->toString());
		}
	};
}