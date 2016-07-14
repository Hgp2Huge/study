// max2.cc

// maximum of two int values
inline int const& max(int const& a, int const& b)
{
    return a < b ? b : a;
}

// maximum of two values of any type
template <typename T>
inline T const& max(T const& a, T const& b)
{
    return a < b ? b : a;
}

//maximun of three values of any type
template <typename T>inline T const& max(T const& a, T const& b, T const& c)
{
    return max(max(a, b), c);
}

int main()
{
    ::max(7, 42, 68); // calls the template for three arguments
    ::max(7.0, 42.0); // calls max<double> (by arguments deduction)
    ::max('a', 'b'); // calls max<char> (by arguments deduction)
    ::max(7, 42); // calls the nontemplate for two ints
    ::max<>(7, 42); // calls max<int> (by arguments deduction)
    ::max<double>(7, 42); //calls max<double> (no arguments dedution)
    ::max('a', 42.7); //calls the nontemplate for two ints
}


// only the nontemplate function allows different argument types
