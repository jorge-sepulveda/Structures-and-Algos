# Programming Assignment 2 

## Tree

### Public Tree Functions: 
  - insert(T item) : inserts e into the tree.
  - inOrder() : does an inorder traversal of the tree.
  - levelOrder() : does a level order traversal of the tree.
  - maxDepth() : returns the maximum depth of the tree.
  - getCount() : returns the number of nodes in the tree, regardless of status(internal, external node, root)

There are other private functions that actually handle some of the functions so that way a user doesn't need to mess with pointers from the main function.


### Test case

We are going to see if an inorder and level order traversal works for the int tree alongside a couple of insertions. This should help us verify that the three functions are implemented properly.

```c++
t1.insert(5);
t1.insert(3);
t1.insert(2);
t1.insert(4);
t1.insert(8);
t1.insert(7);
t1.insert(9);
t1.inOrder();
t1.levelOrder();
```
Expected output for inorder: 2 3 4 5 7 8 9
Actual output: 2 3 4 5 7 8 9

Expected output for order level: 5 3 8 2 4 7 9
Actual output: 
5
3 8
2 4 7 9

Test Case: Passed



### how to run it

I've included a makefile so we can easily compile it by typing make.

```sh
$ make
$ ./main
```

You can also compile it running g++
```sh
g++ -std=c++11 main.cpp -o main
./main
```




[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
