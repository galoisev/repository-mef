/**
 * author	: JBA
 * date  	: 28/09/2022
 * version	: 1.0.0
 * infos	: classe matrice
 * 
 * 	ENSX  All rights reserved Septembre 2022
 **/


#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include "assert.h"



template<class T>
class Matrix 
{
    public:
        int m,n;//dimension matrice(m ligne, n colonne)
        T **a;
        Matrix();// constructor par defaut
        ~Matrix();//destructor
        Matrix(int nx,int ny):m(nx),n(ny)//constructor
        {
            allocMatrix();
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    a[i][j] = 0;
                }
            }            
        } 
        Matrix(const Matrix& mat);//constructor par recopie
        Matrix& operator=(const Matrix& mat);//constructor par assignement
        
        void allocMatrix();
        void affichage(const char* msg);
        
        Matrix operator+(const Matrix& mat);
        Matrix operator-(const Matrix& mat);
        Matrix operator*(const Matrix& mat);
        Matrix operator/(T& c);
        Matrix operator*(T& c);
        Matrix& operator+=(const Matrix& mat);
        Matrix& operator-=(const Matrix& mat);
        T& operator()(int i,int j);
        void set(int i, int j, T val);
        
};

template<class T>
Matrix<T> Matrix<T>::operator*(T& c)
{
    assert(c != 0);
    Matrix<T>tmp(m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            tmp.a[i][j] = a[i][j]*c;
        }
    }
    return tmp;
}

template<class T>
Matrix<T> Matrix<T>::operator/(T& c)
{
    assert(c != 0);
    Matrix<T>tmp(m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            tmp.a[i][j] = a[i][j]/c;
        }
    }
    return tmp;
}


template<class T>
void Matrix<T>:: set(int i,int j, T val)
{
    assert(i<m);
    assert(j<n);
    a[i][j] = val;
}


template<class T>
T& Matrix<T>::operator()(int i, int j)
{
    assert(i<m);
    assert(j<n);
    return a[i][j];
}



template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix& mat)
{
    assert(n == mat.m);//ATTENTION aux DIMENSIONS  FIXME
    Matrix<T>tmp(m,mat.n);//ATTENTION
    for(int i=0;i<m;i++)
    {        
        for(int j=0;j<mat.n;j++)
        {
            for(int k=0;k<mat.m;k++) //ATTENTION
            {
                 tmp.a[i][j] += a[i][k]*mat.a[k][j];
            }            
        }
    }
    return tmp;
}


template<class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& mat)
{
    for(int i=0;i<mat.m;i++)
    {
        for(int j=0;j<mat.n;j++)
        {
            a[i][j] -= mat.a[i][j];
        }
    }
    return(*this);
}


template<class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& mat)
{
    for(int i=0;i<mat.m;i++)
    {
        for(int j=0;j<mat.n;j++)
        {
            a[i][j] += mat.a[i][j];
        }
    }
    return (*this);
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& mat)
{
    Matrix<T>tmp(*this);
    for(int i=0;i<mat.m;i++)
    {
        for(int j=0;j<mat.n;j++)
        {
            tmp.a[i][j] = a[i][j] + mat.a[i][j];
        }
    }
    return tmp;
}
template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& mat)
{
    Matrix<T>tmp(*this);
    for(int i=0;i<mat.m;i++)
    {
        for(int j=0;j<mat.n;j++)
        {
            tmp.a[i][j] = a[i][j] - mat.a[i][j];
        }
    }
    return tmp;
}


template<class T>
Matrix<T>::Matrix(const Matrix<T>& mat):m(mat.m),n(mat.n)
{
    allocMatrix();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j] = mat.a[i][j];
        }
    }
}

template<class T>
Matrix<T> & Matrix<T>::operator=(const Matrix<T>& mat)
{
    if(this == &mat)
    {
        //self void assignement
        return(*this);
    }
    else
    {
        if((m != mat.m) || (n != mat.n))
        {
            this->~Matrix();
            m = mat.m;
            n = mat.n;
            allocMatrix();
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j] = mat.a[i][j];
            }
        }
        return(*this);
    }
    
}



template<class T>
void Matrix<T>::allocMatrix()
{
    a = new T*[m];
    for(int i=0;i<m;i++)
    {
        a[i] = new T[n];
    }
}


template<class T> 
void Matrix<T>::affichage(const char* msg)
{
    std::cout << "\n";
    std::cout << "\t" << msg << "\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout << "\t" << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    
}

template<class T>
Matrix<T>::Matrix()
{
    m = 0;
    n = 0; 
    allocMatrix();
}


template<class T>
Matrix<T>::~Matrix()
{
    for(int i=0;i<m;i++)
    {
        delete []a[i];
    }
    delete []a;
}





#endif //__MATRIX_H__
