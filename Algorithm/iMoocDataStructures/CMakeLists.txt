cmake_minimum_required(VERSION 3.8)
project(_DataStructure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinearList/LinearList.cpp LinearList/LinearList.h LinkedList/LinkedList.cpp LinkedList/LinkedList.h LinkedList/Node.cpp LinkedList/Node.h BinaryTree/BinaryTreeByArray/BinaryTree.cpp BinaryTree/BinaryTreeByArray/BinaryTree.h BinaryTree/BinaryTreeByLinkedList/Node.cpp BinaryTree/BinaryTreeByLinkedList/Node.h BinaryTree/BinaryTreeByLinkedList/BinaryTreeL.cpp BinaryTree/BinaryTreeByLinkedList/BinaryTreeL.h Map/Mnode.cpp Map/Mnode.h Map/CMap.cpp Map/CMap.h Map/Edge.cpp Map/Edge.h)
add_executable(_DataStructure ${SOURCE_FILES})