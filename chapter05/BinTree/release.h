#ifndef DATA_STRUCTURE_RELEASE_H
#define DATA_STRUCTURE_RELEASE_H

template<typename T> struct Cleaner{
    static void clean(T x) {}
};

template<typename T> struct Cleaner<T*> {
    static void clean(T *x) {
        if (x) {
            delete x;
        }
    }
};

template<typename T>
void release(T x) {
    Cleaner<T>::clean(x);
}

#endif //DATA_STRUCTURE_RELEASE_H
