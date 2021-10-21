'''
Given an infix expression convert to postfix expression.
Example Input:

2+3*7-9/5

Output:

237*+95/-
'''

class Fixes:
    def __init__(self,s):
        self.s=s
    def prec(self,ch):
        if(ch=='+' or ch=='-'):
            return 1
        elif(ch=='*' or ch=='/'):
            return 2
        else:
            return 3
    def convert(self):
        stack=[]
        top=-1
        ans=[]
        n=len(self.s)
        for i in range(n):
            if(self.s[i].isdigit()):
                ans.append(self.s[i])
            elif(self.s[i]=='('):
                stack.append(self.s[i])
                top+=1
            elif(self.s[i]==')'):
                while(top>-1 and stack[top]!='('):
                    ans.append(stack.pop())
                    top-=1
                if(stack[top]=='('):
                    stack.pop()
                    top-=1
            else:
                while top>-1 and stack[top]!='(' and self.prec(self.s[i])<=self.prec(stack[top]):
                        ans.append(stack.pop())
                        top-=1
                stack.append(self.s[i])
                top+=1
        
        while(top>-1):
            ans.append(stack.pop())
            top-=1
        s=''
        for i in ans:
            if i!='\r':
                s+=i
        self.postfix=s

testcases = int(input())
for _ in range(testcases):
    equation = input()
    fix = Fixes(equation)
    print(f'Infix: {equation}')
    fix.convert()
    print(f'Postfix: {fix.postfix}')
    print('---')