#include "catch.hpp"
#include <BinarySearchTree.hpp>
SCENARIO ("If there's neither left and right son")
{
    GIVEN("node")
    {
        BinarySearchTree<int> tree1={6,3,8,9,7,2};
        BinarySearchTree<int> tree2={6,3,8,9,7};
        WHEN("delete node")
        {
            tree1.remove(2);
            THEN("If it was deleted")
            {
                REQUIRE(tree1 ==tree2);
            }

        }
    }

}
SCENARIO ("If there's only left son")
{
    GIVEN("node")
    {
        BinarySearchTree<int> tree1={6,3,8,9,7,2};
        BinarySearchTree<int> tree2={6,8,9,7,2};
        WHEN("delete node")
        {
        tree1.remove(3);
        THEN("If it was deleted")
        {
            REQUIRE(tree1 == tree2);
        }
        }
    }

}
SCENARIO ("If there's only right son")
{
    GIVEN("node")
    {
        BinarySearchTree<int> tree1={6,3,8,9,2};
        BinarySearchTree<int> tree2={6,3,9,2};
        WHEN("delete node")
        {
            tree1.remove(8);
            THEN("If it was deleted")
            {
                REQUIRE(tree1==tree2);
            }
        }
    }
}
SCENARIO("If there are both sons")
{
    BinarySearchTree<int> tree1={6,3,8,9,7,2};
    BinarySearchTree<int> tree2={6,3,9,7,2};
    WHEN("delete node")
    {
        tree1.remove(8);
        THEN("If it was deleted")
        {
            REQUIRE(tree1==tree2);
        }
    }

}
SCENARIO("If we want to delete non existent node")
{
    BinarySearchTree<int> tree={6,3,8,9,2};
    WHEN("delete node")
    {
        tree.remove(120);
        auto curr_size=tree.size();
        THEN("If it's not in the tree")
        {
            REQUIRE(tree.size()==curr_size);
        }
    }
}
