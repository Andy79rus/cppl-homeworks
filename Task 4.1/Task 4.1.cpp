#include "List.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("Testing List base functions", "[List]")
{
    List test;
    CHECK(test.Empty() == true);
    test.PushFront(23);
    test.PushFront(12);
    test.PushBack(76);
    CHECK(test.Size() == 3);
    test.Clear();
    CHECK(test.Size() == 0);
    CHECK(test.Empty() == true);
}

int main()
{
	return Catch::Session().run();
}