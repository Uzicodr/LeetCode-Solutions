class Solution {
public:
    string fractionAddition(string expression) {
        int finalNumerator = 0;
        int finalDenominator = 1;

        for (int i = 0; i < expression.length();) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }

            int currNumerator = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                currNumerator = currNumerator * 10 + (expression[i] - '0');
                i++;
            }
            currNumerator *= sign;

            i++;

            int currDenominator = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                currDenominator = currDenominator * 10 + (expression[i] - '0');
                i++;
            }

            finalNumerator = finalNumerator * currDenominator + currNumerator * finalDenominator;
            finalDenominator *= currDenominator;
        }

        int reduced = gcd(abs(finalNumerator), abs(finalDenominator));
        finalNumerator /= reduced;
        finalDenominator /= reduced;

        return to_string(finalNumerator) + "/" + to_string(finalDenominator);
    }
};