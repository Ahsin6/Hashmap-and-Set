# Hashmap-and-Set
Overview

This project implements a utility library in C++ for managing hash maps and sets. It uses vectors to implement the hash map (MapArray) and linked lists to implement the set (SetList). Additionally, the project includes functionality to process text inputs using a stopword list, providing an example use case for testing and validation.

Project Structure

Makefile: Contains the instructions for building and cleaning the project. This includes compiling the source code and linking the object files to create the executable.
MapArray.h: This header file defines the MapArray class, which uses vectors to implement a hash map. The class provides typical hash map operations such as:
Insertion of key-value pairs
Removal of key-value pairs
Retrieval of values based on keys
Handling hash collisions
SetList.h: This header file defines the SetList class, which implements a set using linked lists. The class supports typical set operations, including:
Adding elements
Removing elements
Checking if an element exists
Determining the size of the set
mapset.cpp: The source file containing the implementation of the functions declared in MapArray.h and SetList.h. It includes the logic for managing the vector-based hash map and linked list-based set, as well as helper functions for collision resolution, traversal, and memory management.
stopwords.txt: This file is used as an input for testing the set implementation by filtering out irrelevant words in a document.
sample_doc.txt: This file is used as input for testing the hash map and set functionality, specifically for testing stopword filtering and word frequency counting.
