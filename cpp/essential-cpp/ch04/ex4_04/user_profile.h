#include <string>
#include <map>
#include <iostream>

class UserProfile {
public:
    enum uLevel { Beginner, Intermediate, Advanced, Guru };
    friend std::ostream& operator<<(std::ostream&, const UserProfile&);
    friend std::istream& operator>>(std::istream&, UserProfile&);

    UserProfile(std::string login, uLevel = Beginner);
    UserProfile();

    bool operator==(const UserProfile&);
    bool operator!=(const UserProfile&);

    // read access functions
    std::string login() const { return _login; }
    std::string get_user_name() const { return _user_name; }
    int login_count() const { return _times_logged; }
    int guess_count() const { return _guesses; }
    int guess_correct() const { return _correct_guesses; }
    double guess_average() const;
    std::string level() const;

    // write access functions
    void reset_login(const std::string &val) { _login = val; }
    void set_user_name(const std::string &val) { _user_name = val; }

    void reset_level(const std::string&);
    void reset_level(uLevel newlevel) { _user_level = newlevel; }

    void reset_login_count(int val) { _times_logged = val; }
    void reset_guess_count(int val) { _guesses = val; }
    void reset_guess_correct(int val) { _correct_guesses = val; }

    void bump_login_count(int cnt=1) { _times_logged += cnt; }
    void bump_guess_count(int cnt=1) { _guesses += cnt; }
    void bump_guess_correct(int cnt=1) { _correct_guesses += cnt; }

private:
    std::string _login;
    std::string _user_name;
    int         _times_logged;
    int         _guesses;
    int         _correct_guesses;
    uLevel      _user_level;

    static std::map<std::string, uLevel> _level_map;
    static void init_level_map();
    static std::string guest_login();
};

inline double UserProfile::guess_average() const
{
     return _guesses
            ? double (_correct_guesses) / double(_guesses) * 100
            : 0.0;
}

inline UserProfile::UserProfile(std::string login, uLevel level)
    : _login(login), _user_level(level),
      _times_logged(1), _guesses(0), _correct_guesses(0) {}

inline UserProfile::UserProfile()
    : _login("guest"), _user_level(Beginner),
      _times_logged(1), _guesses(0), _correct_guesses(0)
{
    static int id = 0;
    std::string id_str = std::to_string(id);

    _login += id_str;
}

inline bool UserProfile::operator==(const UserProfile &rhs)
{
    if (_login == rhs._login && _user_name == rhs._user_name)
        return true;
    return false;
}

inline bool UserProfile::operator!=(const UserProfile &rhs)
{
    return !(*this == rhs);
}

inline std::string UserProfile::level() const
{
    static std::string _level_table[] = { "Beginner", "Intermediate", "Advanced", "Guru" };
    return _level_table[_user_level];
}

inline void UserProfile::reset_level(const std::string &level)
{
    std::map<std::string, uLevel>::iterator it;
    if (_level_map.empty())
        init_level_map();
    _user_level = ((it = _level_map.find(level)) != _level_map.end() ? it->second : Beginner);
}

