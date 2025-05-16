class Solution {
public:
    void eval(stack<char>& optr,stack<char>& oprnd){
        char op=optr.top();
        optr.pop();

        bool ans;

        if(op=='|'){
            ans=false;
            while(oprnd.top()!='('){
                ans|=(oprnd.top()=='t');
                oprnd.pop();
            }
            oprnd.pop(); //pop the ')'
        }
        else if(op=='&'){

            ans=true;
            while(oprnd.top()!='('){
                ans&=(oprnd.top()=='t');
                oprnd.pop();
            }
            oprnd.pop();
        }
        else if(op=='!'){
            ans=(oprnd.top()=='t');
            ans=!ans;
            oprnd.pop();
            oprnd.pop();
        }
        if(ans) oprnd.push('t');
        else{
            oprnd.push('f');
        }

    }
    bool parseBoolExpr(string expression) {

        stack<char> opt;
        stack<char> oprnd;
        int idx=0;

        while(idx!=expression.size()){

            if(expression[idx]=='&'|| expression[idx]=='|'|| expression[idx]=='!'){
                opt.push(expression[idx]); //push in operator stack
            }

            else if(expression[idx]=='t'|| expression[idx]=='f'|| expression[idx]=='('){
                oprnd.push(expression[idx]); //push in operand stack
            }

            else if(expression[idx]==')'){
                eval(opt,oprnd); // start evaluating if we encounter a closed bracket
            }

            idx++;
        }
        return oprnd.top()=='t';
    }
};