// CCarryMatrixCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#ifndef LAB1_CARRAYMATRIX_H
#define LAB1_CARRAYMATRIX_H
#include <cstddef>
#include <iostream>
class CArrayMatrix
{
public:
    CArrayMatrix() = delete;
    explicit CArrayMatrix(size_t dimP)
        : dim(dimP)
    {
        matrix = new double* [dim];
        for (size_t i = 0; i < dim; ++i)
        {
            matrix[i] = new double[dim];
        }
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                matrix[i][j] = 0.0;
            }
        }
    }
    CArrayMatrix(const CArrayMatrix& other)
        : dim(other.dim)
    {
        // this->dim = other.dim;
        matrix = new double* [dim];
        for (size_t i = 0; i < dim; ++i)
        {
            matrix[i] = new double[dim];
        }
        /*for (size_t i = 0; i < dim; ++i)
        {
        for (size_t j = 0; j < dim; ++j)
        {
        matrix[i][j] = other.matrix[i][j];
        }
        }*/
        std::copy(other.matrix, other.matrix + dim * dim, matrix);
    }
    CArrayMatrix& operator=(const CArrayMatrix& other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < dim; ++i)
            {
                delete[]matrix[i];
            }
            delete[]matrix;
            dim = other.dim;
            matrix = new double* [dim];
            for (size_t i = 0; i < dim; ++i)
            {
                matrix[i] = new double[dim];
            }
            std::copy(other.matrix, other.matrix + dim * dim, matrix);
        }
        return *this;
    }
    // a && b => a and b
    // a || b => a or b
    // && a
    // int a = 4;
    // int *b=&a;
    CArrayMatrix(CArrayMatrix&& other) noexcept
    {
        this->matrix = other.matrix;
        other.matrix = nullptr; //NULL
        this->dim = other.dim;
        other.dim = 0;
    }
    CArrayMatrix& operator=(CArrayMatrix&& other) noexcept
    {
        if (this != &other)
        {
            for (size_t i = 0; i < dim; ++i)
            {
                delete[]matrix[i];
            }
            delete[]matrix;
            this->matrix = other.matrix;
            other.matrix = nullptr; //NULL
            this->dim = other.dim;
            other.dim = 0;
        }
        return *this;
    }
    ~CArrayMatrix()
    {
        for (size_t i = 0; i < dim; ++i)
        {
            delete[]matrix[i];
        }
        delete[]matrix;
    }
    void print()
    {
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
private:
    size_t dim;
    double** matrix;
};
#endif //LAB1_CARRAYMATRIX_H


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
