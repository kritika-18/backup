void pushExpressionStack(ExpressionStack *s, double value) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = value;
    } else {
        printf("Expression stack overflow\n");
        exit(EXIT_FAILURE);
    }
}
