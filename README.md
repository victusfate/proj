<h1>c++ funky utility library in formation</h1>
1. First step was to curry functions with va_args [curry in c++](http://www.victusspiritus.com/2011/04/28/currying-in-c/)
2. Step two arrays and folding, change curry to take in arrays of functions 
3. to be continued...


Example (at terminal prompt):
g++ curry.cpp -o curry
./curry 2
Address to base numeric 0x7fff5fbfdbc8 base val 2
sCurry n 2
temp 2 val 1
temp 2 val 1
addOne-> 3 curried addOne 3

start curry val 3
sCurry n 5
temp 3 val 1
temp 4 val 2
temp 8 val 7
temp 1 val 10
curried output f10(f7(f2(f1(val)))) or ((val+1)*2-7)/10 = 0.1
