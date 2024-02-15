double evaluateGivenExpression(const char *givenExpression) {
    ExpressionStack operandStack;
    ExpressionStack operatorStack;
    initializeExpressionStack(&operandStack);
    initializeExpressionStack(&operatorStack);

    while (*givenExpression) {
        if (isspace(*givenExpression)) {
            
            givenExpression++;
        } else if (isdigit(*givenExpression) || (*givenExpression == '.' && isdigit((*givenExpression + 1)))) {
            
            double operand = strtod(givenExpression, (char **)&givenExpression);
            pushExpressionStack(&operandStack, operand);
        } else if (isExpressionOperator(*givenExpression)) {
            
            while (operatorStack.top >= 0 && getExpressionPrecedence(operatorStack.data[operatorStack.top]) >= getExpressionPrecedence(*givenExpression)) {
                
                double operand2 = popExpressionStack(&operandStack);
                double operand1 = popExpressionStack(&operandStack);
                char op = popExpressionStack(&operatorStack);
                double result = performExpressionOperation(operand1, operand2, op);
                pushExpressionStack(&operandStack, result);
            }
            
            pushExpressionStack(&operatorStack, *givenExpression);
            givenExpression++;
        } else if (*givenExpression == '(') {
            
            pushExpressionStack(&operatorStack, *givenExpression);
            givenExpression++;
        } else if (*givenExpression == ')') {
            
            while (operatorStack.top >= 0 && operatorStack.data[operatorStack.top] != '(') {
                
                double operand2 = popExpressionStack(&operandStack);
                double operand1 = popExpressionStack(&operandStack);
                char op = popExpressionStack(&operatorStack);
                double result = performExpressionOperation(operand1, operand2, op);
                pushExpressionStack(&operandStack, result);
            }
            
            popExpressionStack(&operatorStack);
            givenExpression++;
        } else {
           
            printf("Error: Invalid character in given expression: %c\n", *givenExpression);
            exit(EXIT_FAILURE);
        }
    }

   
    while (operatorStack.top >= 0) {
        double operand2 = popExpressionStack(&operandStack);
        double operand1 = popExpressionStack(&operandStack);
        char op = popExpressionStack(&operatorStack);
        double result = performExpressionOperation(operand1, operand2, op);
        pushExpressionStack(&operandStack, result);
    }

    
    return popExpressionStack(&operandStack);
}
