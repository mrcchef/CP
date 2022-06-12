code_str = """ 
num = int(input())

# define a flag variable
flag = False

# prime numbers are greater than 1
if num > 1:
    # check for factors
    for i in range(2, num):
        if (num % i) == 0:
            # if factor is found, set flag to True
            flag = True
            # break out of loop
            break

# check if flag is True
if flag:
    print("NO")
else:
    print("YES")"""
code = compile(code_str,'',"exec")  
 
exec(code)  

