#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include <iostream>


template<typename T>
class my_matrix
{
private:
    T* matriz;
    int x;
    int y;
public:
    my_matrix();
    my_matrix(int a, int b);
    ~my_matrix();
    void resize(int a, int b, T fillElem);
    int insert(T elem, int a, int b);
    T returnValue(int a, int b);
    void print();
};


template<typename T>
my_matrix<T>::my_matrix()
{
    x = y = 0;
    matriz = NULL;
}

template<typename T>
my_matrix<T>::my_matrix(int a, int b)
{
    x = a;
    y = b;
    matriz = new T [a*b*(sizeof (T))];
    for(int i = 0; i < x*y; i++)
    {
        matriz[i] = 0;
    }
}

template<typename T>
my_matrix<T>::~my_matrix()
{
    x = y = 0;
    delete [] matriz;
}

template<typename T>
void my_matrix<T>::resize(int a, int b, T fillElem)
{
    if(x == 0 || y == 0)
    {
        x = a;
        y = b;
        matriz = new T [a*b*(sizeof (T))];
        for(int i = 0; i < x*y; i++)
        {
            matriz[i] = fillElem;
        }
    }
    else
    {
        delete [] matriz;
        x = a;
        y = b;
        matriz = new T [a*b*(sizeof (T))];
        for(int i = 0; i < x*y; i++)
        {
            matriz[i] = 0;
        }
    }
}

template<typename T>
int my_matrix<T>::insert(T elem, int a, int b)
{
    if(a < x && b < y)
    {
        matriz[a + b*y] = elem;
        return 1;
    }
    else
    {
        std::cout << "Valores fora dos limites da matriz." << std::endl;
        return 0;
    }
}

template<typename T>
T my_matrix<T>::returnValue(int a, int b)
{
    return matriz[a + b*y];
}

template<typename T>
void my_matrix<T>::print()
{
    for(int j = 0; j < y; j++)
    {
        for(int i = 0; i < x; i++)
        {
            std::cout << returnValue(i,j) << " ";
        }
        std::cout << std::endl;
    }
}

#endif // MY_MATRIX_H
