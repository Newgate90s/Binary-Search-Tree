#ifndef BST_H
#define BST_H


template<typename T> // Templated class for binary search tree
class bst 
{

public:
	struct node // Structured node with parent, left, child pointers and T type data
	{
		node* parent;
		node* left_child;
		node* right_child;
		T data;
		
		node(T new_data) // Node constructor, sets parent, left and right child to nullptr at start, and data as new data
		{
			parent = nullptr;
			left_child = nullptr;
			right_child = nullptr;
			data = new_data;
		}
	};


	bst() // Bst constructor, sets root to nullptr at start
	{
		root = nullptr;
	}


	~bst()
	{
		while (root != nullptr)
		{
			remove(root->data);
		}
	} 

	node* get_root()
	{
		return root;
	}

	bool insert(T data_insert) // Insert function as a bool to check if data was inserted or not, this helps with knowing if a duplicate was found
	{	
		
		if (root == nullptr) // If root is equal to nullptr while inserting, set root to the new data
		{
			node* new_node = new node(data_insert);
			root = new_node;
			return true;
		}
		else // Else loop
		{
			if (data_insert > root->data) // If data being inserted is greater than root, go to the right
			{
				return insert_helper(data_insert, root->right_child, root);
			}
			else if (data_insert < root->data) // If data being inserted is less than root, go to the left
			{
				return insert_helper(data_insert, root->left_child, root);
			}
			else // Anything else exits the loop
			{
				return false;
			}
		}
	
	}


	node* find(T data_find) // Find function using node pointer
	{
		if (root == nullptr) // If root is equal to nullptr return nullptr
		{
			return nullptr;
		}

		else // else loop
		{
			node* current = root; // Sets root as current data
			while(current != nullptr && current->data != data_find) // While current data is not equal to nullptr and the data in current isn't the data being looked for
			{
				if (current->data > data_find) // If the curente data is greater than the data being looked for go to the left
				{
					current = current->left_child;
				}
				else // Else go to the right
				{
					current = current->right_child; 
				}
			}

			return current; // Returns current data being looked at
		}

	}

	void remove(T data_delete) // Delete function
	{
		node* delete_node = find(data_delete); // The data found is data to be deleted

		if (delete_node == nullptr) // If data set to be deleted is equal to nullptr break out of if loop
		{
			return;
		}
		else
		{


			if(delete_node->right_child == nullptr && delete_node->left_child == nullptr) // If loop for deleting a node with no children, aka leaf
			{
				if (delete_node == root)
				{
					root = nullptr;
					delete delete_node;
				}
				else if(delete_node->data > delete_node->parent->data)
				{
					delete_node->parent->right_child = nullptr;
					delete_node->parent = nullptr;
					delete delete_node;
				}
				else
				{
					delete_node->parent->left_child = nullptr;
					delete_node->parent = nullptr;
					delete delete_node;
				}
			}
			else if (delete_node->right_child != nullptr && delete_node->left_child == nullptr) // If loop for deleting node with a right child but no left child
			{
				if (delete_node == root) 
				{
					root = delete_node->right_child;
					delete_node->right_child = nullptr;
					delete delete_node;
				}
				else if (delete_node->data > delete_node->parent->data)
				{
					delete_node->parent->right_child = delete_node->right_child;
					delete_node->parent = nullptr;
					delete_node->right_child = nullptr;
					delete delete_node;
				}
				else
				{
					delete_node->parent->left_child = delete_node->right_child;
					delete_node->parent = nullptr;
					delete_node->right_child = nullptr;
					delete delete_node;
				}
			}
			else if (delete_node->right_child == nullptr && delete_node->left_child != nullptr) // Else if loop for deleting a node with a left child but no right child
			{
				if (delete_node == root)
				{
					root = delete_node->left_child;
					delete_node->left_child = nullptr;
					delete delete_node;
				}
				else if (delete_node->data > delete_node->parent->data)
				{
					delete_node->parent->right_child = delete_node->left_child;
					delete_node->parent = nullptr;
					delete_node->left_child = nullptr;
					delete delete_node;
				}
				else
				{
					delete_node->parent->left_child = delete_node->left_child;
					delete_node->parent = nullptr;
					delete_node->left_child = nullptr;
					delete delete_node;
				}
			}
			else if(delete_node->right_child != nullptr && delete_node->left_child != nullptr) // Else if loop for deleting a node with a a right and left child, could be a root or parent
			{
				node* replacement_node = find_min_branch(delete_node->right_child);

				if (replacement_node->data > replacement_node->parent->data)
				{
					replacement_node->parent->right_child = nullptr;
				}
				else
				{
					replacement_node->parent->left_child = nullptr;
				}
				delete_node->data = replacement_node->data;
				delete replacement_node;
			}
			else // Anything else breaks out of the loop
			{
				return;
			}
		}
	}

	T maximum() // Function to find the maximum value in the bst
	{
		if (root == nullptr) // If root is equal to nullptr, return NULL
		{
			return NULL;
		}
		else // Starts with current being root, if currents node is not a nullptr, go right , continue until maximum node is found
		{
			node* current = root;
			while (current->right_child != nullptr)
			{
				current = current->right_child;
			}
			return current->data;
		}
	}

	T minimum() // Function to find the minimum value in the bst
	{
		if (root == nullptr) // If root is equal to nullptr return NULL
		{
			return NULL;
		}
		else // Start with root being current, if current's left child is not a nullptr go left, continue until minimum value is found
		{
			node* current = root;
			while (current->left_child != nullptr)
			{
				current = current->left_child;
			}
			return current->data;
		}
	}

private:
	node* root; // Root is a node pointer

	bool insert_helper(T data_insert, node* check_node, node* parent_node) // Insert function helper as a bool to assist with inserting and finding duplicates
	{
		if (check_node == nullptr) // Checks the node to see i it's equal to nullptr
		{
			
			node* new_node = new node(data_insert); // Add new node with data
			if (data_insert > parent_node->data) // If data being inserted is greather than parent node, right child is the new node
			{
				parent_node->right_child = new_node;
			}
			else // Else left child is new node
			{
				parent_node->left_child = new_node;
			}
			new_node->parent = parent_node;
			return true;
		}
		else if (data_insert > check_node->data) // If data being inserted is greater than node being checked, insert helper function for right child is used
		{
			return insert_helper(data_insert, check_node->right_child, check_node);
		}
		else if (data_insert < check_node->data) // If data being inserted is less than node being checked, insert function for left child is used
		{
			return insert_helper(data_insert, check_node->left_child, check_node);
		}
		else // Anything else breaks the loop
		{
			return false;
		}
	}

	node* find_min_branch(node* branch) // Finds the minimum branch
	{
		while(branch->left_child != nullptr) // If the branch left child is not equal to null ptr go branch equals branch left child
		{
			branch = branch->left_child;
		}
		return branch; // Return branch
	}

	
};


#endif // BST_H 
