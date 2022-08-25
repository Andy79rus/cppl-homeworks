#include "List.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "catch2/matchers/catch_matchers.hpp"

TEST_CASE("Testing List base functions", "[List]")
{
    List test;
    CHECK_THROWS_WITH(test.PopFront(), "list is empty");
    CHECK_THROWS_WITH(test.PopBack(), "list is empty");
    test.PushFront(23);
    test.PushFront(12);
    test.PushBack(76);
    CHECK(test.PopFront() == 12);
    test.PushBack(21);
    CHECK(test.PopFront() == 23);
    CHECK(test.Size() == 2);
    CHECK(test.PopBack() == 21);
    CHECK(test.PopFront() == 76);
    test.PushFront(35);
    CHECK(test.PopBack() == 35);
    CHECK(test.Size() == 0);
    CHECK_THROWS_WITH(test.PopFront(), "list is empty");
    CHECK_THROWS_WITH(test.PopBack(), "list is empty");
    test.PushFront(5);
    test.PushFront(4);
    test.PushFront(3);
    test.PushFront(2);
    test.PushFront(1);
    CHECK(test.PopFront() == 1);
    CHECK(test.PopFront() == 2);
    CHECK(test.PopFront() == 3);
    CHECK(test.PopFront() == 4);
    CHECK(test.PopBack() == 5);
    test.PushBack(5);
    test.PushBack(4);
    test.PushBack(3);
    test.PushBack(2);
    test.PushBack(1);
    CHECK(test.PopBack() == 1);
    CHECK(test.PopBack() == 2);
    CHECK(test.PopBack() == 3);
    CHECK(test.PopBack() == 4);
    CHECK(test.PopFront() == 5);
    CHECK_THROWS_WITH(test.PopFront(), "list is empty");
    CHECK_THROWS_WITH(test.PopBack(), "list is empty");
    test.Clear();
    CHECK(test.Size() == 0);
    CHECK(test.Empty() == true);
}

int main()
{
	return Catch::Session().run();
}