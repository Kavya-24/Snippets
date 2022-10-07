def areBracketsBalanced(expr):
    stack = []

    #Traversing the Expression
    for char in expr:
        if char in ["(","{","["]:

            #Push the elements in the stack
            stack.append(char)
        elif char in [')','}',']']: 
                      

            
            if not stack:
                return False
            current_char = stack.pop()

            if current_char == '(':
                if char != ")":
                    return False
            if current_char == '{':
                if char != "}":
                    return False
            if current_char == '[':
                if char != "]":
                    return False
    #CHeck Empty STack
    if stack:
        return False
    return True


#Driver code
if __name__ == "__main__":
    expr = "(function(){ let a =1,b =2; return a+b;{}[]  })()"

    #Function call
    if areBracketsBalanced(expr):
        print('Balanced')
    else:
        print('Not Balanced')
