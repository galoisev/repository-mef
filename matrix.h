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
};


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
Matrix<T>::Matrix():Matrix(1,1){}


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
