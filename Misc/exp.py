#Python Program for EXPONENT
num=int(input('Enter the number : '))
exp=int(input('Enter the number : '))
result=1
for i in range(exp):
    result=result*num
print(num,"^",exp,'=',result);
input('Press enter to exit')
