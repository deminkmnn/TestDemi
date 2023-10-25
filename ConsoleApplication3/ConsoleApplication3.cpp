#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

double calculateY(double x, double n) {
    double y = 1.0;
    if (x < 0) {
        double sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += (x + i) * (x + i);
        }
        y = (n > 0) ? (sum + 5 * x) : sum;
    }
    else {
        if (x >= 0) {
            for (int i = 0; i <= n; ++i) {
                double mlt = 1.0;
                for (int j = 1; j <= n - 1; ++j) {
                    mlt *= (i + x * x / (i + j) + 3 * j);
                    if (j > n) {
                        break;
                    }
                }
                y *= mlt;
                ++i;
                if (i > n) {
                    break;
                }
            }
        }
    }
    return y;
}

int main() {
    string userInput;
    int n;
    double a, b, step;

    cout << "Welcome to the program! Type 'run' if you want to calculate a single value of y." << endl;
    cout << "If you want to calculate a range of y, you need to type 'range'." << endl;
    cout << "If you need some help, type 'help'." << endl;

    while (true) {
    out_from_loop:
        cout << "> ";
        cin >> userInput;

        if (userInput == "run") {
            double x;
        restart_first_loop:
            while (true) {
                cout << "Enter a value of n (n > 1): ";
                if (cin >> n && n > 1 && cin.peek() == '\n') {
                    cout << "You entered a valid n." << endl;
                    break;
                }
                else {
                    cout << "You entered an invalid n. Please try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            while (true) {
                cout << "Enter a value of x: ";

                if (cin >> x && cin.peek() == '\n') {
                    cout << "You entered a valid x." << endl;
                    break;
                }
                else {
                    cout << "You entered an invalid x. Please try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            }

            double result = calculateY(x, n);
            cout << "For x = " << x << ", y = " << result << endl;
        }
        else if (userInput == "exit") {
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        }
        else if (userInput == "help") {
            cout << "The program calculates 'y' based on the provided 'x' and 'n' values." << endl;
        }
        else if (userInput == "range") {
        restart_2:
            start_a_b:
            while (true) {
                cout << "Enter a value of a: ";
                if (cin >> a && cin.peek() == '\n') {
                    cout << "You entered a valid a." << endl;
                    break;
                }
                else {
                    cout << "You entered an invalid a. Please try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            while (true) {
                cout << "Enter a value of b: ";
                if (cin >> b && cin.peek() == '\n') {
                    cout << "You entered a valid b." << endl;
                    if (a == b) {
                        while (true) {
                            cout << "Enter a value of n (n > 1): ";
                            if (cin >> n && n > 1 && cin.peek() == '\n') {
                                cout << "You entered a valid n." << endl;
                                break;
                            }
                            else {
                                cout << "You entered an invalid n. Please try again." << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                        cout << "You entered the same value for a and b, calculating a single value." << endl;
                        double result = calculateY(a, n);
                        cout << "For x = " << a << ", y = " << result << endl;
                        goto out_from_loop;
                    }
                    if (a > b) {
                        std::cout << "You input a wrong data for a and b." << endl;
                        goto start_a_b;
                    }
                    if (a < b) {
                        while (true) {
                            cout << "Enter a value of step: ";
                            if (cin >> step && step >= 0 && cin.peek() == '\n') {
                                if (a + step > b) {
                                    while (true) {
                                        cout << "Enter a value of n (n > 1): ";
                                        if (cin >> n && n > 1 && cin.peek() == '\n') {
                                            cout << "You entered a valid n." << endl;
                                            break;
                                        }
                                        else {
                                            cout << "You entered an invalid n. Please try again." << endl;
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        }
                                    }
                                    cout << "The specified range is too small for the given step. Calculating a single value." << endl;
                                    cout << "Next time input correct value of step." << endl;
                                    double result = calculateY(a, n);
                                    cout << "For x = " << a << ", y = " << result << endl;
                                    goto out_from_loop;
                                }
                                cout << "You entered a valid step." << endl;
                                break;
                            }
                            else {
                                cout << "You entered an invalid step. Please try again." << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                    }
                    break;
                }
                else {
                    cout << "You entered an invalid b. Please try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            while (true) {
                cout << "Enter a value of n (n > 1): ";
                if (cin >> n && n > 1 && cin.peek() == '\n') {
                    cout << "You entered a valid n." << endl;
                    break;
                }
                else {
                    cout << "You entered an invalid n. Please try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            

            vector<double> yValues;

            for (double x = a; x <= b; x += step) {
                double result = calculateY(x, n);
                yValues.push_back(result);
                cout << "x = " << x << ", y = " << result << endl;
            }

            cout << "Range calculation complete." << endl;
        }
        
    }
    
    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}
