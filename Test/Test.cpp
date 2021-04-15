#include <D:\Program Files\Microsoft Visual Studio\2019\Community\VC\Auxiliary\VS\UnitTest\include\CppUnitTest.h>		
#include "..\Lab1Proc\aphorism.h"
#include "..\Lab1Proc\container.h"
#include "..\Lab1Proc\node.h"
#include "..\Lab1Proc\text.h"
#include "..\Lab1Proc\proverb.h"
#include "..\Lab1Proc\riddle.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace type_texts;

namespace UnitTestsForLab3
{
	TEST_CLASS(UnitTestsForLab3)
	{
	public:
		// ���� ������� fill_list()
		TEST_METHOD(TestInputContainerWithElem)
		{
			ifstream ifst("InputContainer4.txt"); // 4 ��������
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			ifst.close();

			ifstream input_file("InputContainer4.txt");
			string s;
			int real_len = 0;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
				real_len++;
			}
			input_file.close();

			Assert::AreEqual((int)c->size, real_len / 4);
			clear_list(c);
		}
		// ���� ������� fill_list()
		TEST_METHOD(TestInputContainerEmpty)
		{
			ifstream ifst("InputContainer0.txt"); // 0 ��������
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			ifst.close();

			Assert::AreEqual((int)c->size, 0);
		}


		// ���� ������� clear_list()
		TEST_METHOD(ContainerClean0)
		{
			ifstream ifst("InputContainer0.txt"); // 0 ���������
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			clear_list(c);
			ifst.close();

			Assert::AreEqual((int)c->size, 0);
		}
		// ���� ������� clear_list()
		TEST_METHOD(ContainerCleanWithElem)
		{
			ifstream ifst("InputContainer4.txt"); // 4 ���������
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			clear_list(c);
			ifst.close();

			Assert::AreEqual((int)c->size, 0);
		}


		// ���� ������� output_list()
		TEST_METHOD(TestOutputContainerWithElem)
		{
			ifstream ifst("InputContainer4.txt"); // 4 ��������
			ofstream ofst("OutputContainer4.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_list(c, ofst);
			ifst.close();
			ofst.close();

			ifstream input_file("OutputContainer4.txt");
			string s;
			int return_len = 0;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
				return_len++;
			}
			input_file.close();

			Assert::AreEqual((int)c->size, (return_len - 1) / 4);
			clear_list(c);
		}


		// ���� ������� phrase_Input() �� ������������ �����
		TEST_METHOD(PhraseInputWithElem)
		{
			ifstream ifst("InputPhraseIncorrectKey.txt"); //� ����� 8 ���������, 4 �� ������� � ������������� �������
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			ifst.close();

			Assert::AreEqual((int)c->size, 4); //OK
			clear_list(c);
		}
		// �������� ��������� � ������ ��������� ������� ����� (����������� ������ Type of wisdom)
		TEST_METHOD(PhraseInputWithoutKey)
		{
			ifstream ifst("InputPhraseNoKey.txt"); // � ����� 2 ��������, ���� �� ������� ��� Type of wisdom
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			ifst.close();

			Assert::AreEqual((int)c->size, 1);
			clear_list(c);
		}
		// �������� ��������� � ������ ������������ ������� ����� (���� ���� string ��������)
		TEST_METHOD(PhraseInputUnexpectedFields)
		{
			ifstream ifst("InputPhraseUnexpectedFields.txt"); // � ����� 1 �������� �� ���������� ������
			ofstream ofst("OutputPhraseUnexpectedFields.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			ifst.close();

			Assert::AreEqual((int)c->size, 1);
			clear_list(c);
		}
		// �������� ��������� ��� ������� ������ ����� ����� �������
		TEST_METHOD(PhraseInputEmptyLines)
		{
			ifstream ifst("InputPhraseEmptyLines.txt"); //� ����� 4 �������� � ������� �������� ����� ����
			ofstream ofst("OutputPhraseEmptyLines.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			ifst.close();

			Assert::AreEqual((int)c->size, 4);
			clear_list(c);
		}


		// ���� ������� sort()
		TEST_METHOD(ContainerSortWithElem)
		{
			ifstream ifst("InputContainer4.txt"); // 4 ��������
			ofstream ofst("OutputSortCont4.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			sort(c->size, c->head);
			output_list(c, ofst);
			ifst.close();
			ofst.close();

			ifstream input_file("InputContainer4.txt");
			string s;
			int real_len = 0;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
				real_len++;
			}
			input_file.close();

			Assert::AreEqual((int) c->size, real_len / 4);
			clear_list(c);
		}
		// ���� ������� sort() ��� ������� ����������
		TEST_METHOD(ContainerSortWithoutElem)
		{
			ifstream ifst("InputContainer0.txt"); // � ����� �����
			ofstream ofst("OutputSortCont0.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			sort(c->size, c->head);
			output_list(c, ofst);
			ifst.close();
			ofst.close();

			Assert::AreEqual((int) c->size, 0);
			clear_list(c);
		}
		// ���� ������� sort() ��� ���������� � ����� ���������
		TEST_METHOD(ContainerSortOneElem)
		{
			ifstream ifst("InputContainer1.txt"); // � ����� ���� �������
			ofstream ofst("OutputSortCont1.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			sort(c->size, c->head);
			output_list(c, ofst);
			ifst.close();
			ofst.close();

			Assert::AreEqual((int) c->size, 1);
			clear_list(c);
		}
		// ���� ������� sort() ��� ���������� � ����� ����������
		TEST_METHOD(ContainerSortTwoElem)
		{
			ifstream ifst("InputContainer2.txt"); // � ����� ��� ��������
			ofstream ofst("OutputSortCont2.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			sort(c->size, c->head);
			output_list(c, ofst);
			ifst.close();
			ofst.close();

			Assert::AreEqual((int) c->size, 2);
			clear_list(c);
		}


		// ���� ������� output_aphorism() ��� ������� ����������
		TEST_METHOD(OutputOnlyAphorismsFromEmptyCont)
		{
			ifstream ifst("InputContainer0.txt"); // � ����� �����
			ofstream ofst("OutputOnlyAphorism0.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_aphorism(c, ofst); // � �������� ����� "Only aphorisms"
			clear_list(c);
			ifst.close();
			ofst.close();

			ifstream input_file("OutputOnlyAphorism0.txt");
			string s;
			int real_len = 0;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
				real_len++;
			}
			input_file.close();

			Assert::AreEqual((real_len - 1) / 4, 0);
		}
		// ���� ������� output_aphorism() ��� ��������� � ����������
		TEST_METHOD(OutputAphorismsFromContWithoutAphors)
		{
			ifstream ifst("InputContWithoutAphos.txt"); //� ����� 2 ��������
			ofstream ofst("OutputContWithoutAphos.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_aphorism(c, ofst); // � �������� ����� "Only aphorisms"
			clear_list(c);
			ifst.close();
			ofst.close();

			ifstream input_file("OutputContWithoutAphos.txt");
			string s;
			int real_len = 0;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
				real_len++;
			}
			input_file.close();

			Assert::AreEqual((real_len - 1) / 4, 0);
		}


		// �������� ������� num_punct_marks() � ������ ��������� ������ ����������
		TEST_METHOD(NumPunctMarks0)
		{
			ifstream ifst("InputPhrasePunctMarks0.txt"); // � ��������� ��� �������
			ofstream ofst("OutputPhrasePunctMarks0.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();

			ifstream input_file("OutputPhrasePunctMarks0.txt");
			string s;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
			}
			input_file.close();
			s = s[s.length() - 2];

			Assert::AreEqual(atoi(s.c_str()), 0);
		}
		// �������� ������� num_punct_marks() � ������ 1 ����� ����������
		TEST_METHOD(NumPunctMarks1)
		{
			ifstream ifst("InputContainer1.txt"); //� ��������� 1 �������
			ofstream ofst("OutputPhrasePunctMarks1.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();

			ifstream input_file("OutputPhrasePunctMarks1.txt");
			string s;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
			}
			s = s[s.length() - 2];
			input_file.close();

			Assert::AreEqual(atoi(s.c_str()), 1);
		}
		// �������� ������� num_punct_marks() � ������ 4 ������ ����������
		TEST_METHOD(NumPunctMarks4)
		{
			ifstream ifst("InputPhrasePunctMarks4.txt"); //� ��������� 4 ����� ����������
			ofstream ofst("OutputPhrasePunctMarks4.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();

			ifstream input_file("OutputPhrasePunctMarks4.txt");
			string s;
			while (input_file.peek() != EOF) {
				getline(input_file, s);
			}
			s = s[s.length() - 2];
			input_file.close();

			Assert::AreEqual(atoi(s.c_str()), 4);
		}


		// ���� ������� output_aphorismput()
		TEST_METHOD(TestOutputAphorism)
		{
			ifstream ifst("InputAphorism.txt");
			ofstream ofst("OutputAphorism.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();

			ifstream pattern("PatternOutputAphorism.txt");
			ifstream current("OutputAphorism.txt");
			int res = Compare(current, pattern);
			pattern.close();
			current.close();

			Assert::AreEqual((res + 1), 0);
		}
		// ���� ������� proverb_Output()
		TEST_METHOD(TestOutputProverb)
		{
			ifstream ifst("InputProverb.txt");
			ofstream ofst("OutputProverb.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();

			ifstream pattern("PatternOutputProverb.txt");
			ifstream current("OutputProverb.txt");
			int res = Compare(current, pattern);
			pattern.close();
			current.close();

			Assert::AreEqual((res + 1), 0);
		}
		// ���� ������� riddle_Output()
		TEST_METHOD(TestOutputRiddle)
		{
			ifstream ifst("InputRiddle.txt");
			ofstream ofst("OutputRiddle.txt");
			container* c = new container;
			init_list(c);
			fill_list(c, ifst);
			output_list(c, ofst);
			clear_list(c);
			ifst.close();
			ofst.close();

			ifstream pattern("PatternOutputRiddle.txt");
			ifstream current("OutputRiddle.txt");
			int res = Compare(current, pattern);
			pattern.close();
			current.close();

			Assert::AreEqual((res + 1), 0);
		}

		int Compare(ifstream& ifst_1, ifstream& ifst_2)
		{
			char c1;
			char c2;
			int pos = -1;
			while (ifst_1.get(c1) && ifst_2.get(c2)) {
				pos++;
				if (c1 != c2)
				{
					return pos;
				}
			}
			return -1;
		}

	};
}