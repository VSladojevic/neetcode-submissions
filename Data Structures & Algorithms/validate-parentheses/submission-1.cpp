class Solution {
public:
    bool isValid(string s) {
        stack<char> openBrackets;

        for(char &c: s)
        {
            if(c=='[' || c=='{' || c=='(') openBrackets.push(c);
            else
            {
                if(openBrackets.empty()) return false;
                char top = openBrackets.top();
                if(c==']' && top!='[') return false;
                if(c=='}' && top!='{') return false;
                if(c==')' && top!='(') return false;
                // else
                openBrackets.pop();
            }
        }

        if(!openBrackets.empty()) return false;
        return true;
    }
};
