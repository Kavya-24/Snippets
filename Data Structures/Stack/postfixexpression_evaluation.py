'''
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /.Each operand may be an integer or another expression.

'''

class Solution:
    def evaluateRPN(self, A):
        stack=[]
        top=-1
        for i in A:
            if(i!='+' and i!='-' and i!='*' and i!='/'):
                stack.append(i)
                top+=1
                continue
            else:
                y=int(stack.pop())
                top-=1
                x=int(stack.pop())
                top-=1
                if(i=='+'):
                    stack.append(x+y)
                    top+=1
                elif(i=='-'):
                    stack.append(x-y)
                    top+=1
                elif(i=='*'):
                    stack.append(x*y)
                    top+=1
                elif(i=='/'):
                    stack.append(x//y)
                    top+=1
        return stack[top]
                