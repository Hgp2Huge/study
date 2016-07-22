#include <iostream>

typedef float elemType;

class Matrix
{
    friend Matrix operator+(const Matrix&, const Matrix&);
    friend Matrix operator*(const Matrix&, const Matrix&);

public:
    Matrix(const elemType*);
    Matrix( elemType=0., elemType=0., elemType=0., elemType=0.,
            elemType=0., elemType=0., elemType=0., elemType=0.,
            elemType=0., elemType=0., elemType=0., elemType=0.,
            elemType=0., elemType=0., elemType=0., elemType=0. );

    int rows() const { return 4; }
    int cols() const { return 4; }

    std::ostream& print(std::ostream&) const;
    void operator+=(const Matrix&);

    elemType& operator()(int row, int col) { return _matrix[row][col]; }
    elemType operator()(int row, int col) const { return _matrix[row][col]; }

private:
    elemType _matrix[4][4];
};

inline std::ostream& operator<<(std::ostream &os, const Matrix &m)
{
    return m.print(os);
}

