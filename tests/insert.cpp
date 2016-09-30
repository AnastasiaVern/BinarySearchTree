#include "catch.hpp"
#include "BinarySearchTree"
SCENARIO ("If object already exists")
{
    GIVEN ("object")
    {
        BinarySearchTree <int> tree={1,2};
        int object=5;
        WHEN ("insert")
        {
            tree.insert(object);
            THEN ("if it in the tree")
            {
                REQUIRE(!tree.insert(object));
            }
        };

    }
}
SCENARIO ("If object doesn't exist")
{
    GIVEN ("object")
    {
        BinarySearchTree <int> tree={1,2};
        int object=5;
        WHEN ("insert")
        {
            tree.insert(object);
            THEN ("if it is not in the tree")
            {
                REQUIRE(tree.insert(object));
            }
        };

    }
}
SCENARIO ("If object already exists")
{
    GIVEN ("object")
    {
        BinarySearchTree <int> tree={1,2};
        int object=5;
        auto currsize=tree.size();
        WHEN ("insert")
        {
            tree.insert(object);
            THEN ("if it in the tree")
            {
                REQUIRE(tree.size()==currsize);
            }
        };

    }
}
SCENARIO ("If object doesn't exist")
{
    GIVEN ("object")
    {
        BinarySearchTree <int> tree={1,2};
        int object=5;
        auto currsize=tree.size();
        WHEN ("insert")
        {
            tree.insert(object);
            THEN ("if it is not in the tree")
            {
                REQUIRE(currsize++);
            }
        };

    }
}
