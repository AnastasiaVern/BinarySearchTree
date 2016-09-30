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

//вывод
template <typename T>
std::ostream & operator << (std::ostream & out, const BinarySearchTree<T> & tree)
{
	tree.DoInorderWalk(out, tree.GetRoot());
	return out;
};
//ввод
template <typename T>
std::istream & operator >> (std::istream & in, BinarySearchTree<T> & tree)
{
	T value;
	int size;
	std::cout << "Size: ";
	if (in >> size) {
		for (int i = 0; i < size; i++)
		{
			if (in >> value) {
				tree.insert(value);
			}
		}
	}
	return in;
};
//вывод в файл
template <typename T>
std::ofstream & operator << (std::ofstream & out, const BinarySearchTree<T> & tree)
{
	tree.DoPreorderWalk(out, tree.GetRoot());
	return out;
};
//ввод в файл
template <typename T>
std:: ifstream & operator >> (std::ifstream& in, BinarySearchTree<T>& tree)
{
	T value;
		while (in >> value) {
				tree.insert(value);
		};
	return in;
};


template<typename T>
class BinarySearchTree
{

private:
	struct Node {
		Node * left_; //указатель на левого сына
		Node * right_; //указатель на правого сына
		T value_; //значение

		
		Node(T value) : value_(value), left_(nullptr), right_(nullptr) {}; //конструктор, инициализирующий узел
		Node* memcpy() 
		{
			auto node = new Node(value_);
			if (right_ != nullptr) 
			{
				node->right_ = right_->memcpy();
			}
			if (left_ != nullptr) 
			{
				node->left_ = left_->memcpy();
			}
			return node;
		}
		~Node()
		{
			delete left_;
			delete right_;
		}

	};
	
	Node* root_; //указатель на корень
	size_t size_; //размер дерева

public:

	BinarySearchTree() : size_(0), root_(nullptr) {};
	BinarySearchTree(const std::initializer_list<T> & list) : size_(0), root_(nullptr)
	{
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			insert(*it);
		};

	};
	BinarySearchTree(const BinarySearchTree& tree) //Конструктор копирования
	{
		root_ = tree.root_->memcpy();
	};
	BinarySearchTree(BinarySearchTree&& tree) //Конструктор перемещения
	{
		size_ = tree.size_;
		tree.size_ = 0;
		root_ = tree.root_;
		tree.root_ = nullptr;
	};
	void DoPreorderWalk(std::ostream & str, Node *this_node) const noexcept //Прямой обход дерева
	{
		if (!this_node) { return; }
		str << this_node->value_ << " ";
		DoPreorderWalk(str, this_node->left_);
		DoPreorderWalk(str, this_node->right_);
	}
	void DoInorderWalk(std::ostream &str, Node *this_node) const noexcept //Симметричный обход дерева
	{
		if (!this_node) { return;  }
		DoInorderWalk(str, this_node->right_);
		str << this_node->value_ << " ";
		DoInorderWalk(str, this_node->left_);
	}
	Node* GetRoot() const
	{
		return root_;
	}
	auto compare(const Node * node1, const Node * node2) const noexcept -> bool {

		if (node1 == nullptr && node2 == nullptr) return(true);
		else if (node1 != nullptr && node2 != nullptr)
		{
			return(
				node1->value_ == node2->value_ &&
				compare(node1->left_, node2->left_) &&
				compare(node1->right_, node2->right_)
				);
		}
		else return(false);
	}
	auto size() const noexcept -> size_t
	{
		return size_;
	};

	~BinarySearchTree()
	{
		delete root_;
	};

	auto insert(const T & value) noexcept -> bool
	{

		Node* this_node = root_;
		Node* my_node = nullptr;
		if (root_ == nullptr)
		{
			root_ = new Node(value);
			size_++;
			return true;
		}
		while (this_node)
		{
			my_node = this_node;
			if (value == my_node->value_)
			{
				return false;
			}
			else if (value < my_node->value_)
			{
				this_node = my_node->left_;
			}
			else if (value > my_node->value_)
			{
				this_node = my_node->right_;
			}
		}
		if (value < my_node->value_)
		{
			my_node->left_ = new Node(value);
		}
		else
		{
			my_node->right_ = new Node(value);
		};
		size_++;
		return true;
	};

	auto find(const T & value) const noexcept -> const T *
	{
		Node *this_node = root_;
	if (size_ == 0)
	{
		return nullptr;
	};
	while (this_node)
	{
		if (value < this_node->value_)
		{
			this_node = this_node->left_;
		}
		else if (value > this_node->value_)
		{
			this_node = this_node->right_;
		}
		else if (value == this_node->value_)
		{
			return &this_node->value_;
		}
	}
	return nullptr;
	};
	auto operator = (const BinarySearchTree& tree)->BinarySearchTree& //оператор копирования
	{
		if (this == &tree)
		{
			return *this;
		}
		delete root_;
		size_ = tree.size_;
		root_ = tree.root_->memcpy();
		return *this;
	};
	auto operator = (BinarySearchTree&& tree)->BinarySearchTree& //оператор перемещения
	{
		if (this == &tree)
		{
			return *this;
		}
		delete root_;
		size_ = tree.size_;
		size_ = 0;
		root_ = tree.root_;
		tree.root_ = nullptr;

		return *this;
	};
	auto operator == (const BinarySearchTree& tree) -> bool //оператор сравнения
	{
		if (size_ != tree.size_) { return false; }
		else
		{
			compare(root_, tree.root_);
		}
	};
	
};
