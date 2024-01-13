package LeetCode;

import java.util.Stack;

public class Q20a {
   public static boolean isValid() {
        // Create an empty stack to keep track of opening brackets
          String s = "()}";
        Stack<Character> stack = new Stack<Character>();
        
        // Loop through every character in the string
        for (char c : s.toCharArray()) {
            // If the character is an opening bracket, push it onto the stack
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else { // If the character is a closing bracket
                // If the stack is empty, there is no matching opening bracket, so return false
                if (stack.isEmpty()) {
                System.out.println("not matching4");
                    return false;
                }
                // Otherwise, get the top of the stack and check if it's the matching opening bracket
                char top = stack.peek();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                    
                    System.out.println("Matching parenthisis");// If it is, pop the opening bracket from the stack
                    stack.pop();
                } else { // Otherwise, the brackets don't match, so return false
                System.out.println("not matching2");    
                return false;
                }
            }
        }
        // If the stack is empty, all opening brackets have been closed, so return true
        System.out.println("not matching3");
        // Otherwise, there are unmatched opening brackets, so return false
        return stack.isEmpty();
    }
    public static void main(String[] args) {
        isValid();
    }
}
