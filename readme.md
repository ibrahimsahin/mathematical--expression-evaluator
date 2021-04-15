PROBLEM
In  this  experiment,  your  aim  will  be  to  create  a  mathematical  expression  evaluator  using  arbitrary  precision 
arithmetic.  You  have  to  implement  addition,  subtraction,  multiplication,  division  and  power  operations  for 
arbitrary precision numbers. To accomplish this, you have to use operator overloading, and your operators will 
be  +  for addition,  -  for subtraction,  *  for multiplication,  /  for division and  ^  for power (Note that while  the ^ 
operator is the bitwise XOR  operator on integers, you  will use it to raise an arbitrary precision number to a 
power).
Your design should be able to represent and operate  on positive and negative arbitrary precision numbers.  The 
arbitrary precision numbers you are going to implement will be whole numbers; there will be no fraction part. 
Also all operations should result in whole numbers; so “5 / 3” will be equal to “1”, “4 ^ -2” will be equal to “0”.
When there is a division by zero, the result should  be NaN (not a number) and any operation with at least one 
NaN operator should result as NaN.
Your  program  should  evaluate  the  arithmetic  expressions  given  in  a  custom  stacked  notation  and  write  the 
results to the output file. For I/O operations, you should use the I/O streams library of C++.
The  arithmetic  expressions  can  be  evaluated  using  the  stack  data  structure.  As  one  of  the  aims  of  this 
experiment  is  to  make  use  of  templates,  you  are  expected  to  write  your  own  stack  implementation  using 
templates. Also when  evaluating expressions, you should use separate stacks for operators and APNs (If your 
APN class is named Apn, Your APN stack should be of the type Stack<Apn>).
An  arithmetic  expression  in  the  custom  stacked  notation  consists  of  N  operators  after  N+1  numbers.  The 
algorithm to evaluate expressions in the custom stacked notation is as follows:
1.  Take  an operator from  the end of the operator sequence,  and  two numbers  from the end of the number 
sequence, and perform the operation according to the operator (addition, subtraction …).
2.  Add the result of the operation to the end of the number sequence.
3.  Return to step 1 until there are no more operators left.
Here is an example of an arithmetic expression and how it looks after each iteration:
3  4  7  5  +  *  -3  4  2  +  *
3   8  +
11

INPUT/OUTPUT   FORMAT
In the input file, every line will represent a  separate  arithmetic  expression. There will be  whitespace  (spaces 
and/or  tabs)  between  operators  and  numbers.  You  do  not  need  to  check  the  input  for  syntax  or  semantic 
errors, every line will be a meaningful expression. An example input file can be given as follows:
49  13  +
5  3  ^
12  -5  +
-5  -34  -4  *  -9  6  -8  /  +
-11  55  ^
5  0  6  2  3  +  /  -  *
Your program should write the results of the expressions to the output file, so that  each  line  in  the output file 
will contain the result of the expression in the corresponding line of the input file.  Given the example input file 
above, the output file should be:
62
125
7
150
-4
-1890591424712781041871514584574319778449301246603238034051
NaNEXECUTION
The name of the compiled executable  program should  be “apncalc”. Your  program should  read input/output
file names from the command line, so it will be executed as follows:
apncalc [input file name] [output file name] 