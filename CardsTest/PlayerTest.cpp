#include "stdafx.h"
#include "CppUnitTest.h"

#include "../CardsConsole/Player.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardsTest
{
	TEST_CLASS(PlayerTest)
	{
	public:
		TEST_METHOD(PlayerConstructor)
		{
			Player p;
			Assert::AreEqual(p.GetName().c_str(), "Player"); 
			Player p2("tester");
			Assert::AreEqual(p2.GetName().c_str(), "tester");
		}

		TEST_METHOD(PlayerReceive)
		{
			Deck d;
			shared_ptr<Card>c1 = make_shared<Card>(SPADES, FIVE);
			shared_ptr<Card>c2 = make_shared<Card>(SPADES, SIX);
			d.receive(c1);
			d.receive(c2);
			
			Player p; 
			p.Receive(d); 

			Assert::AreEqual(p.size(), 2);
			Assert::AreEqual(d.size(), 0); 
		}

		TEST_METHOD(PlayerPlayCardSimple)
		{
			Deck d;
			shared_ptr<Card>c1 = make_shared<Card>(SPADES, FIVE);
			shared_ptr<Card>c2 = make_shared<Card>(SPADES, SIX);
			d.receive(c1);
			d.receive(c2);

			Player p;
			p.Receive(d);

			Assert::AreEqual(p.size(), 2);
			
			shared_ptr<Card>player_card1 = p.PlayCard(); 
			Assert::AreEqual(p.size(), 1); 
			shared_ptr<Card>player_card2 = p.PlayCard();
			Assert::AreEqual(p.size(), 0);
		}

		TEST_METHOD(PlayerPlayCardRotate)
		{
			Deck d;
			shared_ptr<Card>c1 = make_shared<Card>(SPADES, FIVE);
			shared_ptr<Card>c2 = make_shared<Card>(SPADES, SIX);
			shared_ptr<Card>c3 = make_shared<Card>(SPADES, SEVEN);
			d.receive(c1);
			d.receive(c2);
			d.receive(c3); 

			Player p;
			p.Receive(d);
			Assert::AreEqual(p.size(), 3);

			for (int i = 0; i < 100; i++) {
				d.receive(p.PlayCard());
				d.receive(p.PlayCard());
				p.Receive(d); 
				Assert::AreEqual(p.size(), 3); 
			}
		}
	};
}