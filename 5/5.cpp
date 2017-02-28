#include "stdafx.h"
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Stack.h"
#include "catch.hpp"
using namespace std;

class EqTest{
public:
	EqTest(){}

	EqTest operator=(const EqTest& value){
		throw std::exception("Test exception 1");
	}
};

int main(int argc, char* argv[])
{
	Catch::Session().run(argc, argv);
	getchar();
	return 0;
}

TEST_CASE("Correct top"){
	Stack<int> s;
	for (int i = 0; i < 5; i++) CHECK_NOTHROW(s.push(i));
	for (int i = 4; i >= 0 ; i--) {
		CHECK(s.getTop() == i);
		REQUIRE_NOTHROW(s.pop());
	}
}

TEST_CASE("Correct isEmpty()"){
	Stack<int> s;
	CHECK(s.isEmpty());
	s.push(1);
	CHECK(!s.isEmpty());
	s.pop();
	CHECK(s.isEmpty());
}

TEST_CASE("Push throw"){
	Stack<EqTest> s;
	EqTest a;
	CHECK_THROWS(s.push(a));
}

TEST_CASE("Empty throw"){
	Stack<int> s;
	CHECK_THROWS(s.pop());
	CHECK_THROWS(s.getTop());
	s.push(20);
	CHECK(s.getTop() == 20);
	CHECK_NOTHROW(s.pop());
	CHECK_THROWS(s.getTop());
	CHECK_THROWS(s.pop());
}