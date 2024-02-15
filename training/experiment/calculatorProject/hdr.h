#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<stdbool.h>

#define MAX 1000

typedef struct {
    double data[MAX];
    int top;
} ExpressionStack;

void initializeExpressionStack(ExpressionStack*);
void pushExpressionStack(ExpressionStack *, double );
double popExpressionStack(ExpressionStack *);
int isExpressionOperator(char);
int getExpressionPrecedence(char);
double performExpressionOperation(double, double, char);
double evaluateGivenExpression(const char *);
bool parenthesis(char*);
bool isValidFirstCharacter(char *);
bool valid_char(char *);
