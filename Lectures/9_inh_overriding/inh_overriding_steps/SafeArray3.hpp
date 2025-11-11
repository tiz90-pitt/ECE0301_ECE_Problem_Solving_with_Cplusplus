// This is SafeArray3.hpp
// Changes from SafeArray2.hpp:
<<<<<<< HEAD
// 1. add "virtual" BEFORE set( , ) function, which makes it "potentially" overridden in derived class
=======
// 1. add "virtual" to Line 27 of set( , ) function, which makes it "potentially" overridden in derived class
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05
// 2. temp change to protected for demo purposes

#ifndef _SAFE_ARRAY_HPP
#define _SAFE_ARRAY_HPP

<<<<<<< HEAD
class SafeArray
{
protected: // temp change to protected
    int *dataptr;
    int size;

public:
    SafeArray();
    SafeArray(int);
    ~SafeArray(); // has to include this due to dataptr

    // this is copy constructor
    SafeArray(const SafeArray &);

    // this is copy assignment
    SafeArray &operator=(SafeArray);

    int get_size() const;
    int get(int) const;
    virtual void set(int, int);
};

SafeArray operator+(const SafeArray &, int); // pass by const reference
SafeArray operator+(int, const SafeArray &); // pass by const reference
=======
class SafeArray {
    protected:         // temp change to protected
        int * dataptr;
        int size;
    
    public:
        SafeArray();
        SafeArray(int);
        ~SafeArray(); // has to include this due to dataptr

        // this is copy constructor
        SafeArray(const SafeArray&); 

        // this is copy assignment
        SafeArray &operator=(SafeArray);

        int get_size() const;
        int get(int) const;
        virtual void set(int, int);
};

SafeArray operator+(const SafeArray&, int); // pass by const reference
SafeArray operator+(int, const SafeArray&); // pass by const reference
>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05

#endif