/*
 *Exercise 4.4
 *A user profile consists of a login, the actual user name, the number of times logged on, the number
 *of guesses made, the number of correct guesses, the current level — one of beginner, intermediate,
 *advanced, or guru — and the percentage correct (this latter may be computed or stored). Provide a
 *UserProfile class. Support input and output, equality and inequality. The constructors should allow
 *for a default user level and default login name of "guest." How might you guarantee that each
 *guest login for a particular session is unique?
 */

#include "user_profile.h"

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    UserProfile user;
    cout << user;

    UserProfile user_2;
    cout << user_2;

    UserProfile anna("AnnaL", UserProfile::Guru);
    cout << anna;

    anna.bump_guess_count(27);
    anna.bump_guess_correct(25);
    anna.bump_login_count();
    cout << anna;

    cin >> user;
    cout << user;

}
