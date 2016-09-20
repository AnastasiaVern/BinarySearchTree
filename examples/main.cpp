#include "stdafx.h"
#include "BinarySearchTree.h"
int main()
{
	BinarySearchTree<int> tree= { 8,10,3,6,7,14,13 }; 
	tree.find(10);
	tree.insert(5);
	std::cout << tree;
	std::ofstream file("C:\\tree.txt");
	file << tree;
	BinarySearchTree<int> tree2;
	std::cin >> tree2;
}
