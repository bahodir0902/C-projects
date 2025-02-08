#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <condition_variable>

using namespace std;

class TimedMathChallenges {
private:
    string operators[3] = { "+", "-", "*" };
    int min_value, max_value, time_lim;
    int wrong_answers = 0;
    int correct = 0;
    int numbers = 0;
    int skipped = 0;
    bool running = true;
    int points = 0;
    double total_time = 0;
    mutex mtx;
    condition_variable cv;
    bool time_up = false;
    vector<int> errors;


    void set_difficulty() {
        string mode;
        cout << "Do you want to set a difficulty for the game? (y/n): ";
        cin >> mode;
        if (mode == "y") {
            cout << "Set a time for each question: ";
            cin >> time_lim;
            cout << "Input the minimum value: ";
            cin >> min_value;
            cout << "Input the maximum value: ";
            cin >> max_value;
        }
        else if (mode == "n") {
            cout << "Default time for each question: 10 seconds\n";
            cout << "Default minimum and maximum range: -10 and 15\n";
            time_lim = 10;
            min_value = rand() % 21 - 10;
            max_value = rand() % 26 + min_value;
        }
        else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }

    pair<string, int> generate_problem() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 2);
        string op = operators[dis(gen)];
        uniform_int_distribution<> dis_num(min_value, max_value);
        int left_digit = dis_num(gen);
        int right_digit = dis_num(gen);
        string problem;
        int answer;
        if (op == "-" && right_digit < 0) {
            problem = to_string(left_digit) + " + " + to_string(abs(right_digit));
            answer = left_digit + abs(right_digit);
        }
        else if (op == "+") {
            if (right_digit < 0) {
                problem = to_string(left_digit) + " - " + to_string(abs(right_digit));
                answer = left_digit - abs(right_digit);
            }
            else {
                problem = to_string(left_digit) + " + " + to_string(right_digit);
                answer = left_digit + right_digit;
            }
        }
        else {
            problem = to_string(left_digit) + " * " + to_string(right_digit);
            answer = left_digit * right_digit;
        }
        return make_pair(problem, answer);
    }

    void timer() {
        this_thread::sleep_for(chrono::seconds(time_lim));
        if (running) {
            time_up = true;
            points -= 5;
        }
    }

public:
    TimedMathChallenges() {
        set_difficulty();
    }

    void play() {
        cout << "Welcome to the Timed mathematical challenges game!\n";
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "You will be presented with a series of math problems.\n";
        cout << "You have 10 seconds to solve each problem.\n";
        cout << "Enter 'n' to skip a problem at a penalty of 10 points.\n";
        cout << "Enter 'q' to quit the game.\n";
        cout << "Let's get started!\n";
        this_thread::sleep_for(chrono::milliseconds(550));
        auto start_time = (chrono::system_clock::now());
        while (running) {
            pair<string, int> problem_answer = generate_problem();
            numbers++;
            thread timer_thread(&TimedMathChallenges::timer, this);
            timer_thread.detach();
            while (true) {
                string user_answer;
                cout << "Problem #" << numbers << ": " << problem_answer.first << ": ";
                cin >> user_answer;
                if(time_up) {
                    cout << "\rTime is up! -5 points! Moving to the next question...\n";
                    time_up = false;
					break;
				}
                if (user_answer == "n") {
                    skipped++;
                    points -= 10;
                    break;
                }
                else if (user_answer == "q") {
                    running = false;
                    break;
                }
                try {
                    int user_answer_int = stoi(user_answer);
                    if (problem_answer.second == user_answer_int) {
                        cout << "Congratulations! +10 points\n";
                        correct++;

                        points += 10;
                        break;
                    }
                    else {
                        cout << "Ooops! Try again! -5 points\n";
                        points -= 5;
                        wrong_answers++;
                        errors.push_back(numbers);
                    }
                }
                catch (invalid_argument& e) {
                    cout << "Invalid output. Enter an integer. -3 points\n";
                    points -= 3;
                }
            }
            
            if (running) continue;
        }
        auto end_time = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end_time - start_time;
        total_time = elapsed_seconds.count();
        cout << "\nGame over!\n";
    }



    void show_statistics() {
        cout << "You have:\n" << correct << " correct answers\n" << wrong_answers << " wrong answers\n" << numbers << " total questions\n" << skipped << " skipped questions\n" << "in total " << total_time << " seconds.\n";
        if (!errors.empty()) {
            cout << "You have errors in ";
            for (int i : errors) {
                cout << i << " ";
            }
            cout << "'s problem\n";
        }
        cout << "Your total game points: " << points << "\n";
        if (points < 0) {
            cout << "You lose the game :(\n";
        }
    }

};

int main() {
    srand(time(0));
    TimedMathChallenges game;
    game.play();
    game.show_statistics();
    system("pause");
    return 0;
}
