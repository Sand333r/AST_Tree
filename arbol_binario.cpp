#include <iostream>
#include <cctype>

struct ExprNode {
    char op;
    double value;
    ExprNode* left;
    ExprNode* right;

    ExprNode(char _op, ExprNode* _left, ExprNode* _right)
        : op(_op), value(0.0), left(_left), right(_right) {}

    ExprNode(double _value)
        : op('0'), value(_value), left(nullptr), right(nullptr) {};
};

ExprNode* createExprNode(char op, ExprNode* left, ExprNode* right) {
    return new ExprNode(op, left, right);
}

ExprNode* createExprNode(double value) {
    return new ExprNode(value);
}

ExprNode* buildExpressionTree(const std::string& expr, size_t& pos) {
    ExprNode* left = nullptr;

    if (isdigit(expr[pos]) || expr[pos] == '(') {
        if (isdigit(expr[pos])) {
            double value = 0.0;
            while (pos < expr.size() && isdigit(expr[pos])) {
                value = value * 10 + (expr[pos] - '0');
                pos++;
            }
            left = createExprNode(value);
        } else if (expr[pos] == '(') {
            pos++;
            left = buildExpressionTree(expr, pos);
            pos++;
        }
    } else {
        std::cerr << "Error: Se esperaba un número o paréntesis izquierdo." << std::endl;
        exit(EXIT_FAILURE);
    }

    while (pos < expr.size() && (expr[pos] == '+' || expr[pos] == '-' || expr[pos] == '*' || expr[pos] == '/')) {
        char op = expr[pos];
        pos++;
        ExprNode* right = buildExpressionTree(expr, pos);
        left = createExprNode(op, left, right);
    }

    return left;
}

void freeExpressionTree(ExprNode* root) {
    if (root == nullptr) {
        return;
    }
    freeExpressionTree(root->left);
    freeExpressionTree(root->right);
    delete root;
}

double evaluateExpressionTree(ExprNode* root) {
    if (root->op == '0') {
        return root->value;
    }

    double leftResult = evaluateExpressionTree(root->left);
    double rightResult = evaluateExpressionTree(root->right);

    switch (root->op) {
        case '+': return leftResult + rightResult;
        case '-': return leftResult - rightResult;
        case '*': return leftResult * rightResult;
        case '/': return leftResult / rightResult;
        default:
            std::cerr << "Error: Operador desconocido." << std::endl;
            exit(EXIT_FAILURE);
    }
}

int main() {
    std::string expression;
    std::cout << "Ingrese una expresión matemática: ";
    std::getline(std::cin, expression);

    size_t pos = 0;
    ExprNode* expressionTree = buildExpressionTree(expression, pos);

    double result = evaluateExpressionTree(expressionTree);
    std::cout << "Resultado: " << result << std::endl;

    freeExpressionTree(expressionTree);

    return 0;
}
