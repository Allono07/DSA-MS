// //Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

package LeetCode;

import java.util.Stack;

class Q20 {
 public static boolean isValid(){
            String s = "()}";
            Stack<Character> stack = new Stack<Character>();
            for(char c:s.toCharArray()){
                if(c=='(' || c=='{'||c=='['){
                    stack.push(c);
                }
                else{
                    if(stack.isEmpty()){
                        return false;
                    }
                    char top = stack.peek();
                    if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                        // If it is, pop the opening bracket from the stack
                        System.out.println("Matching parenthisis");
                    }

                    else{
                        return false;
                    }
                }
            }

            return false;
        }
    public static void main(String[] args) {
       isValid();
    }
    
}
