bool parenthesis(char *expression) {
    int parenth = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        
        if (expression[i] == '(') parenth++;
        else if (expression[i] == ')') {
            parenth--;
            if (parenth < 0) {
                return false;  
            }
        }
    }

    return true;
}

