#dictionaries
mon={1:'jan',2:'feb',3:'mar',4:'apr',5:'may',6:'june'}
stud={'kiran':23,'kumar':20,'dinesh':19,'rakesh':21}
print("mon Dictionary is ",str(mon))
print("The element in the key position 3 is :",mon[3])
print("The mon dictionary values are: ",mon.values())
print("The mon dictionary keys are: ",mon.keys()) 
print("Before addition")
for item in mon.values():
   print(item,end=' ')
mon[7]='july' 
print()
print("After addition")
for item in mon.values():
   print(item,end=' ')
   print()
print("Before deletion")
for item in stud.values():
   print(item,end=' ')
   print()
del stud['kumar']
print("After deletion")
for item in stud.values():
    print(item,end=' ')
    print()
print("Before change")
print("stud Dictionary is ",str(stud))
stud['dinesh']=55
print("After change")
print("stud Dictionary is ",str(stud))
print("Key value pair of dictionary")
print(stud.items())
......................................
#largest of three numbers
num1 = float(input("Enter number 1: ")) 
num2 = float(input("Enter number 2: ")) 
num3 = float(input("Enter number 3: "))
big=num1
if (big<num2): big=num2
if (big<num3): big=num3
print("The Biggest number among the three is : ",big)
..............................................
#Celsius, Fahrenheit. [Formula : c/5 = f-32/9]
celsius=float(input("Enter the temperature in celcius:"))
f=(celsius*1.8)+32
print("Temperature in farenheit is:", round(f,1))
fahrenheit = float(input("Enter Temperature in Fahrenheit: ")) 
c = (fahrenheit-32)/1.8
print("Temperature in Celsius is =", round(c,1))
........................................
'''*
**
***
****
*****
****
***
**
*'''
n = int(input("Enter the number of rows"))  
for i in range(0, n):
  for j in range(0, i + 1): 
    print("* ", end="")       
  print()
for i in range(n, 1, -1): 
      for j in range(1,i):
        print("*",end="")
      print()
  ......................................
#prime numbers less than 20.
Program:
start_val = 1
n = int(input("Enter the n number:"))
for num in range(start_val, n+1):
  if(num>1):
    for i in range(2,num):
      if(num%i)==0:
        break
      else:
        print(num)
...........................................
#factorial of a number using Recursion.
Program:
def factorial(n):
  if n == 1:
    return n
  else:
    return n* factorial(n-1)
num = int(input("Enter a number: "))
if num < 0:
  print("Sorry, factorial does not exist for negative numbers")
elif num == 0:
  print("The factorial of 0 is 1")
else:
   print("The factorial of",num,"is", factorial(num))
............................
#whether or not the triangle is a right triangle
s1=int(input("Side 1 of the triangle ")) 
s2=int(input("Side 2 of the triangle "))
s3=int(input("Side 3 of the triangle "))
big = max(s1,s2,s3)
if(big==s1):
  if(s1**2 == (s2**2 + s3**2)):
    print("The triangle sides given is a right angled triangle", s1**2, (s2**2+s3**2))
  else:
    print("The triangle sides given is not right angled triangle",s1**2, (s2**2+s3**2))
  elif(big==s2):
    if(s2**2==(s1**2+s3**2)):
      print("The triangle sides given is a right angled triangle",s2**2,(s1**2+s3**2))
  else:
    print("The triangle sides given is not right angled triangle", s2**2,(s1**2+s3**2))
  elif(big==s3):
if(s3**2==(s1**2+s2**2)):
  print("The triangle sides given is a right angled triangle",s3**2,(s1**2+s2**2))
else:
  print("The triangle sides given is not right angled triangle", s3**2, (s1**2+s2**2))
  .........................................................
#define a module to find Fibonacci Numbers and import the module to another program.
Program:
def fib(n):
    a, b = 0, 1
    while b < n:
        print(b, end =" ")
        a, b = b, a+b
#import fibonacci module
import fibonacci 
num=int(input("Enter any number to print Fibonacci series "))
             fibonacci.fib(num)
...................................................................... 
#define a module and import a specific function in that module to another program.
def Add(a,b):
    c=a+b
    return c
def Sub(a,b):
    c=a-b
    return c
def Mul(a,b):
    c=a*b
    return c
from arth import Add
num1=float(input("Enter first Number : "))
num2=float(input("Enter second Number : "))
print("Addition is : ",Add(num1,num2))
print("Subtraction is : ",Sub(num1,num2)) #gives error:Not importing Sub function from arth Module
....................................................................
#To write a script named copyfile.py. This script should prompt the user for the names of two text files. The contents of the first file should be input and written to the second file.
file1=input("Enter First Filename : ")
file2=input("Enter Second Filename : ")
fn1 = open(file1, 'r') 
fn2 = open(file2, 'w') 
cont = fn1.readlines() 
for i in range(0, len(cont)):
    fn2.write(cont[i]) 
fn2.close() 
print("Content of first file copied to second file ")
fn2 = open(file2, 'r') 
cont1 = fn2.read() 
print("Content of Second file :")
print(cont1) 
fn1.close() 
fn2.close()
.......................................................................
# write a program that inputs a text file. The program should print all of the unique words in the file in alphabetical order.
fname = input("Enter file name: ")
fh = open(fname)
lst = []  
words=[];
for line in fh:           
    words += line.split()
words.sort()
print("The unique words in  alphabetical order are:")
for word in words:
    if word in lst:       
            continue             
    else:                     
            lst.append(word)
            print(word)
      
#convert an integer to a roman numeral
import sys
ROMAN_NUMERAL_TABLE = [ ("M", 1000), ("CM", 900), ("D", 500),
("CD", 400), ("C", 100), ("XC", 90),
("L", 50),	("XL", 40), ("X", 10),
("IX", 9),	("V", 5),	("IV", 4),
("I", 1)
]
class Roman(object):
   def convert_to_roman(self, number):
         roman_numerals = []
         for numeral, value in ROMAN_NUMERAL_TABLE:
            while value <= number:
               number -= value
               roman_numerals.append(numeral)
         return ''.join(roman_numerals)
n=int(input("Enter a number: "))
r = Roman()
print("The roman value of ",n,"is = ", r.convert_to_roman(n))
.....................................................................
#To write a Python class to implement pow(x, n)
class py_solution: 
   def pow(self, x, n):
      if x==0 or x==1 or n==1:
         return x
      if x==-1:
         if n%2 ==0:
            return 1
         else:
            return -1
      if n==0:
         return 1
      if n<0:
         return 1/self.pow(x,-n)
      val = self.pow(x,n//2)
      if n%2 ==0:
        return val*val
      return val*val*x
while True:
   print("Enter q or Q to quit ")
   x=input("Enter x value: ")
   if (x=='q' or x=='Q'):
      break
   else:
      n=input("Enter n value: ")
      n=int(n)
      x=int(x)
      p=py_solution().pow(x,n)
      print(x," to the power ",n," is = ",p)
      print()
      continue
...............................................................
#To write a Python class to reverse a string word by word.
Program:
class py_solution:
   def reverse_words(self, s):
      lst = s.strip().split(" ")
      lst = lst[::-1]
      st=""
      for w in lst:
         st = st + " " + w
      return st.strip()
s=input("Enter a string: ")
rs=py_solution()
r = rs.reverse_words(s) 
print("The reversed sentence: ",r)
