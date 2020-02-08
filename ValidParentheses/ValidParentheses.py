#Link on task -> https://www.codewars.com/kata/52774a314c2333f0a7000688

def valid_parentheses(input_str):
  stack = []
  for parent in input_str:
    if (parent == '(' or parent == ')'):
      if parent == '(':
        stack.append(parent)
      else:
        if not stack:
           return False;
        else:
          top = stack[-1]
  
        if parent == ')' and top == '(': 
            stack.pop()
  if not stack:
     return True;
  else:
     return False;


#Test cases from Codewars
print(valid_parentheses("  (") == False);
print(valid_parentheses(")test") == False);
print(valid_parentheses("") == True);
print(valid_parentheses("hi())(") == False);
print(valid_parentheses("hi(hi)()") == True);
