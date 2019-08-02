#include <iostream>
#include "bst.h"


bool bst_test(); // Bool for our binary search tree testing

int main()
{
	bst<int>  bst_main;

	// Inserts multiple values(10,7,13,9,4,11,15)
	std::cout << "==============================================================================" << std::endl;
	std::cout << "Inserting values 10,7,13,9,4,11 and 15 into our Binary Search Tree." << std::endl;
	std::cout << "==============================================================================" << std::endl;
	bst_main.insert(10);
	bst_main.insert(7);
	bst_main.insert(13);
	bst_main.insert(9);
	bst_main.insert(4);
	bst_main.insert(11);
	bst_main.insert(15);

	std::cout << "The maximum value in our Binary Search Tree is: " << bst_main.maximum() << std::endl; // Finds the maximum value in the bst
	std::cout << "\nThe minimum value in our Binary Search Tree is: " << bst_main.minimum() << std::endl; // Finds the minimum value in the bst
	std::cout << "==============================================================================" << std::endl;


	// Prints out the nodes of the values we inserted
	std::cout << "Node containing 10: " << bst_main.find(10) << std::endl;
	std::cout << "Node containing 7: " << bst_main.find(7) << std::endl;
	std::cout << "Node containing 13: " << bst_main.find(13) << std::endl;
	std::cout << "Node containing 9: " << bst_main.find(9) << std::endl;
	std::cout << "Node containing 4: " << bst_main.find(4) << std::endl;
	std::cout << "Node containing 11: " << bst_main.find(11) << std::endl;
	std::cout << "Node containing 15: " << bst_main.find(15) << std::endl;
	std::cout << "==============================================================================" << std::endl;

	// Removes all the values individually and tries to find it to make sure they were deleted
	bst_main.remove(15);
	std::cout << "Deleted 15 \nNode containing 15: " << bst_main.find(15) << std::endl;
	bst_main.remove(11);
	std::cout << "\nDeleted 7 \nNode containing 7: " << bst_main.find(11) << std::endl;
	bst_main.remove(4);
	std::cout << "\nDeleted 13 \nNode containing 13: " << bst_main.find(4) << std::endl;
	bst_main.remove(9);
	std::cout << "\nDeleted 9 \nNode containing 9: " << bst_main.find(9) << std::endl;
	bst_main.remove(13);
	std::cout << "\nDeleted 4 \nNode containing 4: " << bst_main.find(13) << std::endl;
	bst_main.remove(7);
	std::cout << "\nDeleted 11 \nNode containing 11: " << bst_main.find(7) << std::endl;
	bst_main.remove(10);
	std::cout << "\nDeleted 15 \nNode containing 15: " << bst_main.find(10) << std::endl;
	std::cout << "==============================================================================" << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	bst_test(); // Bst testing function
	
	system("pause");
}


bool bst_test() // Bool to run all our tests
{
	bool pass = true;
	bst<int> data_test = bst<int>();
	
	std::cout << ">TESTING<" << std::endl;
	// Initialization test
	std::cout << "\nIs our root set to nullptr at the start?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	if (data_test.get_root() == nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;

	// Inserting 1 value test
	data_test.insert(10);
	std::cout << "\nInserting 10 and finding 10 to make sure it was inserted." << std::endl;
	std::cout << "\nResult:" << std::endl;
	if (data_test.find(10) != nullptr )
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;


	// Inserting left test
	data_test.insert(9);
	std::cout << "\nDoes our insert function insert to the left properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	if(data_test.get_root()->left_child == data_test.find(9))
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;

	// Inserting right test
	data_test.insert(11);
	std::cout << "\nDoes our insert function insert to the right properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	if (data_test.get_root()->right_child == data_test.find(11))
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;

	// Inserting duplicate test
	data_test.insert(10);
	std::cout << "\nDoes our insert function stop us from insterting duplicate values?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	if(data_test.insert(10) == false)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Inserting multiple values test
	data_test.insert(12);
	data_test.insert(8);
	data_test.insert(13);
	data_test.insert(7);
	std::cout << "\nDoes our insert function insert multiple values properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	if (data_test.find(12) != nullptr && data_test.find(8) != nullptr && data_test.find(13) != nullptr && data_test.find(7) != nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Find testing
	std::cout << "\nDoes our find function find values properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	if (data_test.find(10) == data_test.get_root())
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Finding maximum value test
	std::cout << "\nDoes our maximum value function work properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	if (data_test.maximum() == data_test.find(13)->data)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Finding minimum value test
	std::cout << "\nDoes our minimum value function work properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	if (data_test.minimum() == data_test.find(7)->data)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;

	
	// Deleting leaf node test
	std::cout << "\nDoes our delete function delete leaf nodes properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	data_test.remove(7);

	if (data_test.find(7) == nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Deleting node with righ child test
	std::cout << "\nDoes our delete function delete nodes with only a right child properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	data_test.remove(12);

	if (data_test.find(12) == nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Deleting node with left child test
	data_test.remove(9);
	std::cout << "\nDoes our delete function delete nodes with only a left child properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;

	if (data_test.find(9) == nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Deleting node with both left and right child test
	std::cout << "\nDoes our delete function delete nodes with both a left and right child properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;
	data_test.remove(10);
	
	if (data_test.find(10) == nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Deleting root test 
	data_test.remove(11);
	std::cout << "\nDoes our delete function delete the root properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;

	if (data_test.find(11) == nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Deleting all nodes test
	data_test.remove(8);
	data_test.remove(13);
	std::cout << "\nDoes our delete function delete all the remaining nodes properly?" << std::endl;
	std::cout << "\nResult:" << std::endl;

	if (data_test.find(8) == nullptr && data_test.find(13) == nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	// Test to make sure bst is empty
	std::cout << "\nAfter all the tests and deletes is our BST empty?" << std::endl;
	std::cout << "\nResult:" << std::endl;

	if (data_test.get_root() == nullptr)
	{
		std::cout << "Test passed" << std::endl;
	}
	else
	{
		std::cout << "Test failed" << std::endl;
		pass = false;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
return pass;
}
