#include "pch.h"
#include "CppUnitTest.h"
#include "D:\попытка в учебу\4 курс\2\методы программирования\Lab1Proc\Lab1Proc\container.cpp"
#include "D:\попытка в учебу\4 курс\2\методы программирования\Lab1Proc\Lab1Proc\node.cpp"
#include "D:\попытка в учебу\4 курс\2\методы программирования\Lab1Proc\Lab1Proc\text.cpp"
#include "D:\попытка в учебу\4 курс\2\методы программирования\Lab1Proc\Lab1Proc\proverb.cpp"
#include "D:\попытка в учебу\4 курс\2\методы программирования\Lab1Proc\Lab1Proc\aphorism.cpp"
#include "D:\попытка в учебу\4 курс\2\методы программирования\Lab1Proc\Lab1Proc\riddle.cpp"
#include "D:\попытка в учебу\4 курс\2\методы программирования\Lab1Proc\Lab1Proc\TryInt32.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace type_texts;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(fill_list3)
		{
			ifstream ifst("in3.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			ifst.close();
			ifstream input_file("in3.txt");
			string s;
			int len = 0;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
				len++;
			}
			input_file.close();
			Assert::AreEqual((int)c->size, len);
			clear_list(c);
		}
		TEST_METHOD(fill_list0)
		{
			ifstream ifst("in0.txt");
			container* c = new container;
			init_list(c); 
			fill_list(c, ifst);
			ifst.close();
			Assert::AreEqual((int)c->size, 0);
			clear_list(c);
		}
		TEST_METHOD(clear_list3)
		{
			ifstream ifst("in3.txt");
			container* c = new container;
			init_list(c); 
			fill_list(c, ifst);
			int size = (int)c->size;
			clear_list(c);
			ifst.close();
			Assert::AreEqual((int)c->size, 0);
		}
		TEST_METHOD(clear_list0)
		{
			ifstream ifst("in0.txt");
			container* c = new container;
			init_list(c); 
			fill_list(c, ifst);
			clear_list(c);
			ifst.close();
			Assert::AreEqual((int)c->size, 0);
		}
		TEST_METHOD(output_list3)
		{
			ifstream ifst("in3.txt");
			ofstream ofst("out3.txt");
			container* c = new container;
			init_list(c); 
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();
			int res = compareFiles("pout3.txt", "out3.txt");
			Assert::AreEqual(res, 0);
		}
		TEST_METHOD(wrongkey)
		{
			ifstream ifst("inkey5.txt");
			ofstream ofst("outkey5.txt");
			container* c = new container;
			init_list(c); 
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();
			int res = compareFiles("poutkey5.txt", "outkey5.txt");
			Assert::AreEqual(res, 0);
		}
		TEST_METHOD(wrongrating)
		{
			ifstream ifst("inrat3.txt");
			ofstream ofst("outrat3.txt");
			container* c = new container;
			init_list(c); 
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();
			int res = compareFiles("poutrat3.txt", "outrat3.txt");
			Assert::AreEqual(res, 0);
		}
		TEST_METHOD(sort3)
		{
			ifstream ifst("insort3.txt");
			ofstream ofst("outsort3.txt");
			container* c = new container;
			init_list(c); 
			fill_list(c, ifst);
			sort(c->size, c->head);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();
			int res = compareFiles("outsort3.txt", "poutsort3.txt");
			Assert::AreEqual(res, 0);
		}

		int compareFiles(string p1, string p2)
		{
			ifstream f1(p1);
			ifstream f2(p2);

			if (f1.fail() || f2.fail()) {
				return 1;
			}

			if (f1.tellg() != f2.tellg()) {
				return 1;
			}
			f1.seekg(0, ifstream::beg);
			f2.seekg(0, ifstream::beg);
			if (equal(istreambuf_iterator<char>(f1.rdbuf()),
				istreambuf_iterator<char>(),
				istreambuf_iterator<char>(f2.rdbuf()))) return 0;
			else return 1;
		}
	};
}
