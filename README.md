#C Vector
Naive test implementation of the STL C++ *std::vector* in C.

Simil-Templates are implemented via macro. Only few functions 
are implemented:

 * reserve
 * clear
 * push
 * pop


## Usage
You need to create your vector type:

```C
Vector_template(int);
Vector_template(float);
Vector_template(double);
Vector_template(*YourCustomType*);
```

after that:

```C
Vector_init(vec, int);
Vector_reserve(vec, 1000);
Vector_push(vec, -999);
Vector_clear(vec);
```
## Performance
If you reserve the memory before start pushing, there is no story.
Otherwise seems that memory reallocation is faster in the C version if
the reallocation amount is high.
![Without reserve](vector_test.png)

## Build
Compile with:

```sh
g++ main.cpp -Ivectorc.h -o test
```
## Note
This is only a game, not to use in real code.