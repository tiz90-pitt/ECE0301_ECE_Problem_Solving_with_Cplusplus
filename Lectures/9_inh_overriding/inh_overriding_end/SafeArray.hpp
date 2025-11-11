// This is final version of SafeArray.hpp
<<<<<<< HEAD
// No changes from
// SafeArray4.hpp
=======
// No changes from SafeArray4.hpp:


>>>>>>> ad4b5081d9c95051f0fe346333fb5fbe9fa3ed05

#ifndef _SAFE_ARRAY_HPP
#define _SAFE_ARRAY_HPP

<<<<<<< HEAD
class SafeArray
{
private:
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
    private:
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