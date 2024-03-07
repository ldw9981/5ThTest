#pragma once
#include <windows.h>

template <typename T>
class Singleton 
{
public:
    static T* GetInstance() {
        if (instance == NULL) {
            instance = new T;
        }

        return instance;
    }

private:
    static T* instance;
};

template <typename T>
T* Singleton<T>::instance = NULL;