#include <boost/variant.hpp>
#include <string>
#include <iostream>
#include <memory>
#include <limits>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

struct Node
{
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    int value;
};

//        5   
//       / \
//      /   \
//      3   7         6
//       \   \       / \
//        |   \     4   7
//        4    9   / \
//            /   3   5
//           /
//          8

void maxMin(const std::unique_ptr<Node>& node, boost::optional<int>& currentMaxMin,bool max)
{
    if (!node)
    {
	return;
    }
    if (!currentMaxMin)
    {
	currentMaxMin=node->value;
    }
    else if (max && node->value>currentMaxMin.value())
    {
	currentMaxMin=node->value;
    }
    else if (!max && node->value<currentMaxMin.value())
    {
	currentMaxMin=node->value;
    }
    maxMin(node->left, currentMaxMin, max);
    maxMin(node->right, currentMaxMin, max);
    
    std::cout << "node->value: " << node->value << " maxMin: " << currentMaxMin.value() << " max: " << max << std::endl;
}

bool isBST(const std::unique_ptr<Node>& node)
{
    if (!node)
    {
	return true;
    }
    boost::optional<int> max;
    maxMin(node->left, max, true);
    if (max && max.value() > node->value)
    {
	return false;
    }
    
    boost::optional<int> min;
    maxMin(node->right, min, false);
    if (min && min.value() < node->value)
    {
	return false;
    }
    return isBST(node->left) && isBST(node->right);
    
	
}

void printTree(const std::unique_ptr<Node>& node)
{
    if (!node)
    {
	return;
    }
    printTree(node->left);
    std::cout << node->value << ",";
    printTree(node->right);
}
 //         6	   
 //        / \	   
 //       4   7	   
 //      / \	
 //     3   5	   

bool isBSTUtil(const std::unique_ptr<Node>& node, int min, int max)
{

    if (!node)
    {
	return true;
    }
    std::cout << "node->value: " << node->value << " min: " << min << " max: " << max << std::endl;
    if (node->value < min || node->value > max)
    {
	return false;
    }
    return isBSTUtil(node->left, min, node->value) && isBSTUtil(node->right, node->value, max);
    
}

int main()
{
    {
	auto five = std::make_unique<Node>();    //   
	five->value=5;				 //
	auto three = std::make_unique<Node>();	 //
	three->value=3;				 //
	auto two = std::make_unique<Node>();	 //
	two->value=2;				 //
	auto four = std::make_unique<Node>();	 //
	four->value=4;				 //
	auto seven = std::make_unique<Node>();	 //
	seven->value=7;				 //
	auto eight = std::make_unique<Node>();	 //
	eight->value=8;				 //
	auto nine = std::make_unique<Node>();    //
	nine->value=9;

	three->right=std::move(four);
	three->left=std::move(two);
	five->left=std::move(three);
	nine->left=std::move(eight);
	seven->right=std::move(nine);
	five->right=std::move(seven);
    
	auto six = std::make_unique<Node>();
	six->value=6;

	auto ten = std::make_unique<Node>();
	ten->value=10;
	ten->left=std::move(five);    
//	std::cout << "printTree" << std::endl;
//	printTree(ten);


    }
    {


	auto three = std::make_unique<Node>();  
	three->value=3;				
	auto two = std::make_unique<Node>();	
	two->value=2;				
	auto four = std::make_unique<Node>();	
	four->value=4;				
	auto five = std::make_unique<Node>();	
	five->value=5;				
	auto six = std::make_unique<Node>();	
	six->value=6;				
	auto seven = std::make_unique<Node>();	
	seven->value=7;				
	auto eight = std::make_unique<Node>();	
	eight->value=8;				
	auto nine = std::make_unique<Node>();   
	nine->value=9;

	//             ___7
	//            /    \
	//           4      8
	//          / \   
	//         3   5   
	//              \ 
	//               6
	
	five->right=std::move(six);
	four->left=std::move(three);
	four->right=std::move(five);
	seven->left=std::move(four);
	seven->right=std::move(eight);

	
	std::cout << "printTree" << std::endl;
	printTree(seven);
//	std::cout << "isBST(six): " << isBST(six) << std::endl;    	
	std::cout << "\nisBSTUtil(seven): " << isBSTUtil(seven, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) << std::endl;    
    }
    
}
