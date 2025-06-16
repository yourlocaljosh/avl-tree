#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tree.hpp"

using namespace std;

// NOTE: THIS TEST FILE USES Catch2 WHICH IS NOT INCLUDED IN THIS REPO
// DOWNLOAD IT AT https://github.com/catchorg/Catch2/releases TO UTILIZE THIS FILE CORRECTLY
// self balancing avl tree by joshsw
// NOTE: LLM was used in coming up with these specific test cases, but nowhere else in the project.

TEST_CASE("TEST_INSERTION_SORT") {
    Tree tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(50);

    REQUIRE(tree.find(10));
    REQUIRE(tree.find(25));
    REQUIRE(tree.find(30));
    REQUIRE_FALSE(tree.find(99));
}

TEST_CASE("TEST_IN_ORDER_TRAVERSAL") {
    Tree tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);

    ostringstream out;
    streambuf* old = cout.rdbuf(out.rdbuf());
    tree.printInOrder(tree.getRoot());
    cout.rdbuf(old);

    REQUIRE(out.str()=="1 2 3 ");
}