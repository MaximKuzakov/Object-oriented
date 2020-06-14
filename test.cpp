#include "pch.h"
#include "../Laba1.2/Program.h"
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

int main(int argc, char** argv) {
	InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

// ���� �������� ����� input
TEST(LAB1_test, test_fileInpName) {
	ifstream ifst("input.txt");
	EXPECT_TRUE(ifst.is_open());
}
// ���� �������� ����� output
TEST(LAB1_test, test_fileOutName) {
	std::ofstream ofst("output.txt");
	EXPECT_TRUE(ofst.is_open());
}

// ���� ������ ����������
TEST(LAB1_test, test_Read) {
	ifstream ifst("input.txt");
	container c{};
	// ���� �� ����� ������� ����������, ���� �������
	EXPECT_NO_THROW(c.In(ifst));
}

// ���� ������ ����������
TEST(LAB1_test, test_Write) {
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	container c{};
	// ���� �� ����� ������� ����������, ���� �������
	c.Out(ofst);
	EXPECT_NO_THROW(c.Out(ofst));
}