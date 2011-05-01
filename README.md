<h1>a funky c++ utility library in formation</h1>
1. First step was to curry functions with va_args [curry in c++](http://www.victusspiritus.com/2011/04/28/currying-in-c/)
2. Step two is arrays and folding, refactor curry to take in arrays of functions 
3. an easy to implement qsort was added (shh, I know there's one in [std lib](http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/) )
4. an in place qsort was added, along with a timer class
5. to be continued...

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

-----------------------------------------------------------------------------------------------------------------
update, sorts actually well uh, sorts.

g++ sorts.cpp -o sorts

testing concatentation
c cat (...) 0	11.6	2	4.3	5.5	9	112	8	77.4	4
d cat (arr) 0	11.6	2	4.3	5.5	9	112	8	77.4	4

-------------------------------------------------------------------------
folding a 1000000 times

 what the f 0 sum 11.5

 what the f 100000 sum 1.15001e+06

 what the f 200000 sum 2.30001e+06

 what the f 300000 sum 3.45001e+06

 what the f 400000 sum 4.60001e+06

 what the f 500000 sum 5.75001e+06

 what the f 600000 sum 6.90001e+06

 what the f 700000 sum 8.05001e+06

 what the f 800000 sum 9.20001e+06

 what the f 900000 sum 1.035e+07
test 0	1	2	3	5.5 folded sum 1000000 times 1.15e+07

-------------------------------------------------------------------------
`in place sorting 1000000 arrays 
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.000
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.097
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.194
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.292
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.388
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.485
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.583
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.680
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.777
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
in place method: 0.874`

-------------------------------------------------------------------------
`temporary lists sorting 1000000 arrays 
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 0.972
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 1.401
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 1.830
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 2.259
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 2.685
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 3.114
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 3.544
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 3.970
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 4.399
sorted 0	2	4	4.3	5.5	8	9	11.6	77.4	112
temporary lists method: 4.828`
