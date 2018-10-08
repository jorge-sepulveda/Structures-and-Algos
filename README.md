Name: Jorge Sepulveda  
Instructor: Eduardo Nakamura  
Class: CSCE 221  
Date: October 8 2018  

# Vector Asignment

In this folder you will find the different implementations used to create a vector. This includes:
  - A fixed array
  - An Incremental Array
  - A doubling Array
  - A singly linked list
  - A doubly linked list
## File Structure

This folder will have different header files and .tpp files that are used to implement each header function. 

For testing, I have copied Harish's main file and copied it over to my main file to perform the same actions on every Vector implementation

## Functions


Below are the different functions each Vector implementation has:

* at(int i) - returns the value at index i.
* set(int i, T o) - sets the value of index i equal to the object T(also replaces values). 
* insert(int i, T o) - inserts the T object into the array and adjusts the indeces after i.
* erase(int i) - erases the value at index i and adjusts the array afterwards.
* size() - returns the amount of elements in the Vector.
* empty() - returns a boolean value if there are no elements .
* Some of the implementations also have a printElements() function which prints all the values of the Vector in increasing 
index order.
 
## **Running it**

I have included a makefile in the folder so you can run these commands in the terminal to run it.

```sh
$ make
$ ./main
```

You can also run a g++ command. There is no need to add any other files to the linker. There is only one .cpp file

```sh
 $ g++ -std=c++11 main.cpp -o main
 $ ./main
```
# *Sources Used*

[Geeks for geeks].  
[Github].  
[Stack overflow].  
Book.  
Lecture Materials.  

----


[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [Geeks for geeks]: <https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/>
   [stack overflow]: <https://stackpverflow.com>
   [Github]: <http://github.io>
