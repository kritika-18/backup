double popExpressionStack(ExpressionStack *s) {
    if (s->top >= 0) {
        return s->data[s->top--];
    } else {
        printf("Expression stack underflow\n");
        exit(EXIT_FAILURE);
    }
}
