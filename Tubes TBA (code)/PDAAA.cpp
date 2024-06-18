#include <iostream>
#include <stack>
using namespace std;

enum State {
    START,
    S_FOUND,
    P_FOUND,
    O_FOUND,
    K_FOUND,
    INVALID
};

class PushdownAutomaton {
public:
    bool processInput(string inputString) {
        stack<char> stk;
        State currentState = START;

        for (char c : inputString) {
            switch (currentState) {
                case START:
                    stk.push('#');
                    if (c == 's') {
                        stk.push(c);
                        currentState = S_FOUND;
                    } else {
                        currentState = INVALID;
                    }
                    break;
                case S_FOUND:
                    if (c == 'p') {
                        stk.pop();
                        currentState = P_FOUND;
                    } else {
                        currentState = INVALID;
                    }
                    break;
                case P_FOUND:
                    if (c == 'o') {
                        stk.pop();
                        currentState = O_FOUND;
                    } else if (c == 'k') {
                        stk.pop();
                        currentState = K_FOUND;
                    } else {
                        currentState = INVALID;
                    }
                    break;
                case O_FOUND:
                    if (c == 'k') {
                        currentState = K_FOUND;
                    } else {
                        currentState = INVALID;
                    }
                    break;
                case K_FOUND:
                    currentState = INVALID;  // Tidak ada transisi valid dari K_FOUND
                    break;
                case INVALID:
                    break;  // Tetap di state INVALID
            }
        }

        return currentState == S_FOUND || currentState == P_FOUND || currentState == O_FOUND || currentState == K_FOUND;
    }
};

int main() {
    string inputString;
    for (int i=1;i<=7;i++){
        cin >> inputString;
        PushdownAutomaton automaton;
        bool result = automaton.processInput(inputString);

        if (result) {
            cout << "'" << inputString << "' adalah string yang valid." << endl;
        } else {
            cout << "'" << inputString << "' bukan string yang valid." << endl;
        }
    }
    return 0;
}
