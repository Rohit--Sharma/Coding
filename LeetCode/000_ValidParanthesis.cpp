/*
Welcome to Facebook!

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

Enjoy your interview!
*/


// validParenthesis = "[[[]]]" valid.. "][" invalid, "[][]" valid

bool isValid(String str) {
    int counter = 0;
    for (char bracket: str) {
        if (bracket == '[') {
            counter++;
        }
        else if (bracket == ']') {
            counter--;
            if (counter < 0) {
                return false;
            }
        }
    }
    
    if (counter == 0) {
        return true;
    }
    else {
        return false;
    }
}


---- 
  
  "[[[]]]"  , "[]" the only to fix it, is to remove characters
  
/**
Pseudo code:
    [[]]]: [[]]
    [[]]][]: [[]][]
    [[][]]]: [[[]]], [[][]]
    ][: ""
    ][[] : []
    
    [[][]
    [][]
    countLeftBrackets, countRightBrackets
*/

// Stack: [[
string fixParanthesis (string str) {
    stack<char> myStack;
    string result = "";
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '[') {
            myStack.push(str[i]);
        } 
        else if (str[i] == ']') {
            if (!myStack.empty() && myStack.top() == '[') {
                // result = myStack.top() + result + str[i];
                // myStack.pop();
                myStack.push(str[i]);
            }
            // else discard
        }
    }
    
    while (!myStack.empty()) {
        result += myStack.top();
        myStack.pop();
    }
    
    // the last few characters in the string might not be valid.
    // remove the last chars which make the string invalid
    int openCount = 0, closeCount = 0;
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == '[') {
            openCount++;
        }
        else if (result[i] == ']') {
            closeCount++;
        }
        
    }
    // for i from the end, keep removing the opening brackets till the count becomes equal to closeCount
    
    
    
    return result;
}


String fix(String str) {
    int countLeftBrackets = 0, countRightBrackets = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '[') {
            countLeftBrackets++;
        }
        else if (str[i] == ']') {
            countRightBrackets++;
        }
        
    }
    
    string fixedString = "";
    if (countRightBrackets > countLeftBrackets) {
        int rightBracketsToRemove = countRightBrackets - countLeftBrackets;
        int removedBrackets = 0;
        for (int i = 0; i < str.size(); i++) {
            
            if (str[i] != ']' || (str[i] == ']' && removedBrackets == rightBracketsToRemove)) {
                fixedString += str[i];    // append the character to string
            }
            else {
                removedBrackets++;    // dont append the first few ] chars
            }
        }
        if (isValid(fixedString)) {
            return fixedString;
        }
    }
    else if () {
        // do the same thing for opening brackets
    }
    
    
}
  