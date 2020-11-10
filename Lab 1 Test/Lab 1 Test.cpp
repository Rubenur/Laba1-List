#include <stdexcept>
#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab 1\List.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1Test
{
	TEST_CLASS(Lab1Test)
	{
	public:
		
		Singly_Linked_List* TList;
		// before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			TList = new Singly_Linked_List();
		}
		// after each test
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete TList;
		}
		//////at
		TEST_METHOD(at_correct_index)
		{
			TList->push_back(1); // 1
			TList->push_back(2); // 1 2
			TList->push_back(3); // 1 2 3
			Assert::AreEqual(TList->at(3), 3);
		}
		TEST_METHOD(at_incorrect_index)
		{
			TList->push_back(1);
			TList->push_back(2);

			try
			{
				TList->at(3);
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("Index is greater than list size", error.what());
			}
		}
		TEST_METHOD(at_emty_list)
		{
			TList->clear();
			try
			{
				TList->at(2020);
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("The list is empty", error.what());
			}
		}
		////////////////////////////////////////////push_back
		TEST_METHOD(pushback_second)
		{
			TList->push_front(1); // 1
			TList->push_back(2);  // 1 2
			Assert::AreEqual(TList->at(2), 2);
		}
		TEST_METHOD(pushback_first)
		{
			TList->push_back(1); // 1
			Assert::AreEqual(TList->at(1), 1);
		}
		////////////////////////////////////////////push_front
		TEST_METHOD(pushfront_second)
		{
			TList->push_back(1); // 1
			TList->push_front(2); // 2 1
			Assert::AreEqual(TList->at(1), 2);
		}
		TEST_METHOD(pushfront_first)
		{
			TList->push_front(1); // 1
			Assert::AreEqual(TList->at(1), 1);
		}
		////////////////////////////////////////////pop_back
		TEST_METHOD(popback_from_list_with_one_element)
		{
			TList->push_front(1);
			TList->pop_back();
			Assert::AreEqual(TList->isEmpty(), true);
		}
		TEST_METHOD(popback_from_emty_list)
		{
			TList->clear();
			try
			{
				TList->pop_back();
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("The list is empty", error.what());
			}
		}
		TEST_METHOD(double_popback)
		{
			TList->push_back(1);
			TList->push_back(2);
			TList->pop_back();
			TList->pop_back();
			Assert::AreEqual(TList->isEmpty(), true);
		}
		////////////////////////////////////////////pop_front
		TEST_METHOD(popfront_from_list_with_one_element)
		{
			TList->push_front(1);
			TList->pop_front();
			Assert::AreEqual(TList->isEmpty(), true);
		}
		TEST_METHOD(popfront_from_emty_list)
		{
			TList->clear();
			try
			{
				TList->pop_front();
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("The list is empty", error.what());
			}
		}
		TEST_METHOD(double_popfront)
		{
			TList->push_back(1);
			TList->push_back(2);
			TList->pop_front();
			TList->pop_front();
			Assert::AreEqual(TList->isEmpty(), true);
		}
		////////////////////////////////////////////insert
		TEST_METHOD(insert_before_first)
		{
			TList->push_back(1);
			TList->insert(5, 1);
			Assert::AreEqual(TList->at(1), 5);
			Assert::AreEqual(TList->at(2), 1);
		}
		TEST_METHOD(insert_mid)
		{
			TList->push_back(1);
			TList->push_back(2);
			TList->insert(5, 2); // 1 5 2
			Assert::AreEqual(TList->at(1), 1);
			Assert::AreEqual(TList->at(2), 5);
			Assert::AreEqual(TList->at(3), 2);
		}
		////////////////////////////////////////////remove by index
		TEST_METHOD(remove_first_element)
		{
			TList->push_back(1);
			TList->push_back(2); // 1 2
			TList->remove(1); // 2
			Assert::AreEqual(TList->at(1), 2);
		}
		TEST_METHOD(remove_last_element) // and list with one element
		{
			TList->push_back(1);
			TList->push_back(2); // 1 2
			TList->remove(2); // 1
			TList->remove(1); // emply
			Assert::AreEqual(TList->isEmpty(), true);
		}
		TEST_METHOD(remove_mid_element)
		{
			TList->push_back(1);
			TList->push_back(2);
			TList->push_back(3); // 1 2 3
			TList->remove(2); // 1 3
			Assert::AreEqual(TList->at(1), 1);
			Assert::AreEqual(TList->at(2), 3);
		}
		////////////////////////////////////////////get size
		TEST_METHOD(emply_list)
		{
			size_t size = 0;
			TList->push_back(2);
			TList->remove(1);
			Assert::AreEqual(TList->get_size(), size);
		}
		////////////////////////////////////////////print to console
		TEST_METHOD(print_emply_list)
		{
			try
			{
				TList->print_to_console();
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("The list is empty", error.what());
			}
		}
		////////////////////////////////////////////clear
		TEST_METHOD(clear_emply_list)
		{
			TList->clear();
			Assert::AreEqual(TList->isEmpty(), true);
		}
		TEST_METHOD(standart_clear)
		{
			for (int pos = 1; pos <= 100; pos++)
			{
				TList->push_back(pos);
			}
			TList->clear();
			Assert::AreEqual(TList->isEmpty(), true);
		}
		////////////////////////////////////////////set
		TEST_METHOD(set_first)
		{
			TList->push_back(2);
			TList->push_back(2);
			TList->set(1, 1);
			Assert::AreEqual(TList->at(1), 1);
		}
		TEST_METHOD(set_lust)
		{
			TList->push_back(1);
			TList->push_back(1);
			TList->set(2, 2);
			Assert::AreEqual(TList->at(2), 2);
		}
		TEST_METHOD(set_emply_list)
		{
			try
			{
				TList->set(1, 1);
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("The list is empty", error.what());
			}
		}
		TEST_METHOD(incorrect_set)
		{
			TList->push_back(2);
			try
			{
				TList->set(3, 2);
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("Index is greater than list size", error.what());
			}
		}
		////////////////////////////////////////////isEmpty
		TEST_METHOD(not_empty_list)
		{
			TList->push_back(1);
			Assert::AreEqual(TList->isEmpty(), false);
		}
		////////////////////////////////////////////reverse
		TEST_METHOD(reverse_even_list)
		{
			for (int pos = 1; pos <= 100; pos++)
			{
				TList->push_back(pos);
			}
			TList->reverse();
			Assert::AreEqual(TList->at(33), 68); // 100 - 33 + 1
		}
		TEST_METHOD(reverse_odd_list)
		{
			for (int pos = 1; pos <= 101; pos++)
			{
				TList->push_back(pos);
			}
			TList->reverse();
			Assert::AreEqual(TList->at(33), 69); // 101 - 33 + 1
		}
		TEST_METHOD(reverse_one_elem)
		{
			TList->push_back(1);
			TList->reverse();
			Assert::AreEqual(TList->at(1), 1);
		}
		TEST_METHOD(reverse_emply_list)
		{
			try
			{
				TList->reverse();
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("The list is empty", error.what());
			}
		}
		////////////////////////////////////////////combo
		TEST_METHOD(combo_metods)
		{
			TList->push_back(7); // 7
			TList->push_back(4); // 74
			TList->push_front(2); // 274
			TList->insert(1, 1); // 1274
			TList->set(3, 3); // 1234
			TList->reverse(); // 4321
			TList->push_back(0); // 43210
			TList->reverse(); // 01234
			TList->pop_front(); // 1234
			TList->remove(3); // 124
			Assert::AreEqual(TList->at(1), 1);
			Assert::AreEqual(TList->at(2), 2);
			Assert::AreEqual(TList->at(3), 4);
		}
	};
}
