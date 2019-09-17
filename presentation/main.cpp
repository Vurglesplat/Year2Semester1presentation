#include <iostream>
#include <iterator> // this is needed to use these items



    // when an iterator is made, it is created using std::iterator
    
    // template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T * , class Reference = T & >
    
class exampleInputIterator : public std::iterator<std::input_iterator_tag, std::string, std::string, const std::string, std::string>
    {
    private:
        int *elementPointer;
    public: 

        // a lot of this code is taken from http://www.cplusplus.com/reference/iterator/iterator/
        // all rights belong to them
        exampleInputIterator(int* x) :elementPointer(x) {}
        exampleInputIterator(const exampleInputIterator& mit) : elementPointer(mit.elementPointer) {}
        exampleInputIterator& operator++() { ++elementPointer; return *this; }
        exampleInputIterator operator++(int) { exampleInputIterator tmp(*this); operator++(); return tmp; }
        bool operator==(const exampleInputIterator& rhs) const { return elementPointer == rhs.elementPointer; }
        bool operator!=(const exampleInputIterator& rhs) const { return elementPointer != rhs.elementPointer; }
        int& operator*() { return *elementPointer; }
    };

    int main() 
{

        int arr[] = { 1,2,3,4,5,6,7,8,9,10 };



        std::cout << "Normal iteration: ";

        for(int i = 0; i < 10; i++)
        {
            std::cout << arr[i] << ' ';
        }


        std::cout << "\n\nCustom Iteration: ";

        for (exampleInputIterator i = std::begin(arr); i != std::end(arr); i++)
        {
            std::cout << *i << ' ';
        }

        std::cin.get();
        return 0;
}