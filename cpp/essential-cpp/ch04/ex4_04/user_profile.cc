#include "user_profile.h"

std::map<std::string, UserProfile::uLevel> UserProfile::_level_map;

void UserProfile::init_level_map()
{
    _level_map["Beginner"] = Beginner;
    _level_map["Intermediate"] = Intermediate;
    _level_map["Advanced"] = Advanced;
    _level_map["Guru"] = Guru;
}

std::ostream& operator<<(std::ostream &os, const UserProfile &user)
{
    os << user.login() << ' '
       << user.level() << ' '
       << user.login_count() << ' '
       << user.guess_count() << ' '
       << user.guess_correct() << ' '
       << user.guess_average() << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, UserProfile &user)
{
    std::string login, level;
    is >> login >> level;

    int lcount, gcount, gcorrect;
    is >> lcount >> gcount >> gcorrect;
    user.reset_login(login);
    user.reset_level(level);

    user.reset_login_count(lcount);
    user.reset_guess_count(gcount);
    user.reset_guess_correct(gcorrect);

    return is;
}
