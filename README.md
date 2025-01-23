# Introduction to Data Structures and Algorithms in C++

This repository is a comprehensive library of fundamental data structures and algorithms implemented in C++, with a focus on understanding and practical use cases.

## Table of Contents

1. **Binary Search Trees (BST)**
   - 1.1. [BST Implementation](#bst-implementation)
   - 1.2. [Key Features for BST](#key-features-for-bst)
  
2. **Circular Array Implementation**
   - 2.1. [Key Features for Circular Array](#key-features-for-circular-array)

3. **Linked Lists**
   - 3.1. [Overview](#overview)
   - 3.2. [Features](#features)
   - 3.3. [Integration with Derived Classes](#integration-with-derived-classes)
   - 3.4. [Benefits of Using BaseLinkedList](#benefits-of-using-baselinkedlist)
  
4. **Queues**
   - 4.1. [Overview](#overview)
   - 4.2. [Features](#features)
   - 4.3. [Integration with Derived Classes](#integration-with-derived-classes)
   - 4.4. [Benefits of Using Base Interface](#benefits-of-using-base-interface)

5. **Stacks**
   - 5.1. [Overview](#overview)
   - 5.2. [Features](#features)
   - 5.3. [Integration with Derived Classes](#integration-with-derived-classes)
   - 5.4. [Benefits of Using a Base Interface](#benefits-of-using-a-base-interface)

6. **Vectors**
   - 6.1. [Base Class (BaseVector)](#base-class-basevector)
   - 6.2. [Derived Class (MyVectorBack)](#derived-class-myvectorback)
   - 6.3. [Derived Class (MyVectorFront)](#derived-class-myvectorfront)
   - 6.4. [Error Handling](#error-handling)
   - 6.5. [Integration with Derived Classes](#integration-with-derived-classes)
   - 6.6. [Benefits of Using the Base Interface](#benefits-of-using-the-base-interface)

---

## Binary Search Trees (BST)

### 1.1. BST Implementation
The BST implementation allows for recursive insertion, deletion, and searching of elements. It supports tree traversal methods such as pre-order, in-order, and post-order to explore nodes in a given order.

### 1.2. Key Features for BST:
1. Recursive implementation for efficient operations.
2. Dynamic memory management.
3. Traversal methods: pre-order, in-order, and post-order.

---

## Circular Array Implementation

### 2.1. Key Features for Circular Array:
1. Dynamic resizing to accommodate changes in size.
2. Efficient circular indexing where the array wraps around.
3. Operations like push_back, push_front, pop_back, and pop_front are optimized.

---

## Linked Lists

### 3.1. Overview
A reusable base class for creating various types of linked lists. Derived classes include `SinglyLinkedList`, `DoublyLinkedList`, and `CircularLinkedList`.

### 3.2. Features
- Node management (creation, deletion).
- Dynamic growth with memory handling.
- Utility functions for insertion, deletion, and traversal.

### 3.3. Integration with Derived Classes
- **SinglyLinkedList**: Implements methods specific to singly linked lists.
- **DoublyLinkedList**: Extends functionality for backward traversal.
- **CircularLinkedList**: Ensures that the last node's `next` points to the head, forming a circle.

### 3.4. Benefits of Using BaseLinkedList
- **Code Reusability**: Common operations are encapsulated in the base class.
- **Extensibility**: Adding new linked list types is simple.
- **Maintainability**: Each list type can be modified independently.
- **Safety**: Error handling is incorporated.

---

## Queues

### 4.1. Overview
A base interface for queues, which is extended by concrete implementations like `CircularQueue`, `DequeQueue`, and `ListQueue`.

### 4.2. Features
- Polymorphism for interaction with any derived queue type.
- Dynamic memory management for efficient resizing.
- Error handling for invalid operations like underflow.

### 4.3. Integration with Derived Classes
- **Inheritance**: Derived classes implement the pure virtual functions from `BaseQueue`.
- **Polymorphism**: Allows the client code to interact with any queue type.
- **Memory Management**: Handled by STL containers in derived classes.

### 4.4. Benefits of Using Base Interface
- **Consistency**: A common interface for all derived queue types.
- **Flexibility**: New queue types can be added seamlessly.
- **Polymorphism**: Interact with queues generically, independent of their type.
- **Extensibility**: New features can be added without modifying existing code.

---

## Stacks

### 5.1. Overview
A base interface for stacks, extended by classes like `StackLinkedList`, `StackVector`, and `StackList`.

### 5.2. Features
- Abstraction of stack operations.
- Polymorphism for interacting with different stack types.
- Error handling for stack underflow and overflow.

### 5.3. Integration with Derived Classes
- **Inheritance**: Derived classes override the pure virtual functions in `BaseStack`.
- **Polymorphism**: Allows generic handling of any stack implementation.
- **Memory Management**: Handled by STL containers in derived classes.

### 5.4. Benefits of Using a Base Interface
- **Consistency**: Unified interface across all stack types.
- **Flexibility**: Easily switch between stack implementations.
- **Extensibility**: New stack types or operations can be added without disrupting existing code.
- **Code Reusability**: Avoids duplication of common stack functionality.

---

## Vectors

### 6.1. Base Class (BaseVector)
The base class for implementing vector operations like insertion, deletion, and access to elements.

### 6.2. Derived Class (MyVectorBack)
A derived class that optimizes vector operations for adding elements at the back.

### 6.3. Derived Class (MyVectorFront)
A derived class that optimizes vector operations for adding elements at the front.

### 6.4. Error Handling
Error handling is implemented to manage out-of-bounds access and invalid operations. It ensures safe access to vector elements.

### 6.5. Integration with Derived Classes
- **Inheritance**: MyVectorBack and MyVectorFront extend `BaseVector`.
- **Polymorphism**: Client code can interact with any vector implementation.

### 6.6. Benefits of Using the Base Interface
- **Consistency**: A single interface for all vector implementations.
- **Flexibility**: Easily switch between different vector types.
- **Extensibility**: Add new vector types with minimal changes to the code.
- **Code Reusability**: Common functionality is handled in the base class.
- **Separation of Concerns**: Focus on high-level operations without worrying about the underlying implementation details.

----
