#pragma once
// BinarySearchTree.cpp: определяет точку входа для консольного приложения.
//Реализовать класс "", имеющий интерфейс:
//вставка элемента в дерево
//поиск элемента в дереве
//файловый потоковый ввод/вывод
//потоковый вывод

#include <initializer_list>
#include <iostream>
#include <fstream>
template<typename T>
class BinarySearchTree;


template <typename T>
std::ofstream & operator << (std::ofstream & out, const BinarySearchTree<T> & tree)
{
	tree.Preorder(out, tree.GetRoot());
	return out;
};

template <typename T>
std::ostream & operator << (std::ostream & out, const BinarySearchTree<T> & tree)
{
	tree.Preorder(out, tree.GetRoot());
	return out;
};

template <typename T>
std::istream & operator >> (std::istream & in, BinarySearchTree<T> & tree)
{
	T value;
	int size;
	std::cout << "Size: ";
	in >> size;

	for (int i = 0; i < size; i++)
	{
		in >> value;
		tree.insert(value);
	}
	return in;
};

template<typename T>
class BinarySearchTree
{
private:
	struct Node {
		Node* left_; //указатель на левого сына
		Node* right_; //указатель на правого сына
		T value_; //значение

		Node(T value) : value_(value), left_(nullptr), right_(nullptr) {}; //конструктор, инициализирующий узел
		~Node()
		{
			delete left_;
			delete right_;
		}
	};

	Node* root_; //указатель на корень
	size_t size_; //размер дерева

public:
	BinarySearchTree() {};
	BinarySearchTree(const std::initializer_list<T> & list)
	{
		size_ = 0;
		root_ = nullptr;
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			insert(*it);
		};

	};
	void Preorder(std::ostream & str, Node* ThisNode) const noexcept //Прямой обход дерева
	{
		if (!ThisNode) { return; }
		str << ThisNode->value_ << " ";
		Preorder(str, ThisNode->left_);
		Preorder(str, ThisNode->right_);
	}
	Node* GetRoot() const
	{
		return root_;
	}
	~BinarySearchTree()
	{
		delete root_;
	};


	auto size() noexcept -> size_t
	{
		return size_;
	};


	auto insert(const T & value) noexcept -> bool
	{

		Node* ThisNode = root_;
		Node* x = nullptr;
		if (root_ == nullptr)
		{
			root_ = new Node(value);
			size_++;
			return true;
		}
		while (ThisNode)
		{
			x = ThisNode;
			if (value == x->value_)
			{
				return false;
			}
			else if (value < x->value_)
			{
				ThisNode = x->left_;
			}
			else if (value > x->value_)
			{
				ThisNode = x->right_;
			}
		}
		if (value < x->value_)
		{
			x->left_ = new Node(value);
		}
		else
		{
			x->right_ = new Node(value);
		};
		size_++;
		return true;
	};

	auto find(const T & value) const noexcept -> const T *
	{
		Node* ThisNode = root_;
	if (!root_)
	{
		return nullptr;
	};
	while (ThisNode)
	{
		if (value < ThisNode->value_)
		{
			ThisNode = ThisNode->left_;
		}
		else if (value > ThisNode->value_)
		{
			ThisNode = ThisNode->right_;
		}
		else if (value == ThisNode->value_)
		{
			return &ThisNode->value_;
		}
	}
	return nullptr;
	};
};
