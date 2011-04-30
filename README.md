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


nevermind that sorts does no sorting... yet.

g++ sorts.cpp -o sorts

 what the f 0 sum 11.5

 what the f 1000000 sum 1.15e+07

 what the f 2000000 sum 2.3e+07

 what the f 3000000 sum 3.45e+07

 what the f 4000000 sum 4.6e+07

 what the f 5000000 sum 5.75e+07

 what the f 6000000 sum 6.9e+07

 what the f 7000000 sum 8.05e+07

 what the f 8000000 sum 9.2e+07

 what the f 9000000 sum 1.035e+08

test 0	1	2	3	5.5 folded sum 10000000 times 1.15e+08

