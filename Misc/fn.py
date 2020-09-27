#Python Program for FUNCTION demo

'''#without args
def addition():
    n1=int(input('enter number 1: '))
    n2=int(input('enter number 2: '))
    n3=n1+n2
    print(n3)

def subtraction():
    n1=int(input('enter number 1: '))
    n2=int(input('enter number 2: '))
    n3=n1-n2
    print(n3)'''

#with arguments

def addition(n1,n2):
    n3=n1+n2
    print(n1,'+',n2,'=',n3)

def subtraction(n1,n2):
    n3=n1-n2
    print(n1,'-',n2,'=',n3)
