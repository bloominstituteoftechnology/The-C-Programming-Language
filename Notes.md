1. Dereference : Grabbing the underlying value that is located in a particular address
  * int x  = 10; 
    int *p = &x;  // address of x

    printf("%d\n", *p) // deference the pointer and grab 10 from x 
                       // which p is pointing to. *p will print 10. 

2. Heap - is where all your allocated memory variables live and variables can be passed from one function to the next. 

3. Stack - This is where all your static variables live and so it does not live outside the scope of the function. 