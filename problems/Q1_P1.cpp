#include <iostream>
using namespace std ;

void resize (int *& arr , int oldCap , int newCap ) {
    int *jar = new int[newCap];
    for(int i{0}; i < min(oldCap,newCap); i++) {
        //std::cout << "arr at index " << i << " is: " << arr[i] << std::endl;
        jar[i] = arr[i];
    }
    int *temp = arr;
    arr = jar;
    delete[] temp;
 // TODO : allocate new array , copy min ( oldCap , newCap ) items ,
 // delete [] the old one , point arr to the new one
}

int main () {
int capacity = 2;
int size = 0;
int resizes = 0;
int *jar = new int[capacity];
bool numRecieve{true};


 // TODO : read numbers until -1 , growing the jar when full
while(numRecieve) {
    int currNum{};
    std::cout << "Drop a number in the jar (-1 to stop): ";
    std::cin >> currNum;
    if(currNum == -1) {
        numRecieve = false;
        break;
    }
    if(size+1 > capacity) {
        std::cout << "Jar full! Growing from " << capacity << " to " << capacity*2 << "." << std::endl;
        resize(jar, capacity, capacity*2);
        ++resizes;
        capacity = capacity*2;
    }
    jar[size] = currNum;
    ++size;
    
    
}

if(size == 0) {
    std::cout << "the jar is empty" << std::endl; 
    return 0;
}

 // TODO : shrink to fit
 
resize(jar, capacity, size);
if(capacity > size) {
    std::cout << "Shrinking jar from " << capacity << " to " << size << "." << std::endl;
    resizes++;
}
capacity = size;


 // TODO : remove duplicates ( compact in place , update size )
//int *sortedJar = new int[capacity];
std::cout << "Removing duplicates" << std::endl;

    
for(int i{0}; i<size; i++) {
    for(int j{i+1}; j<size; j++) {
        if(jar[i] == jar[j]) {
                jar[j] = -1;
        }
    }
}
int index{0};
int newSize = size;
for(int i{0}; i<size; i++) {
    if(jar[i] != -1) {
        jar[index] = jar[i];
        index++;
    } else {
        newSize--;
    }
}
size = newSize;

 // TODO : shrink to fit again
resize(jar, capacity, size);
if(capacity > size) {
    std::cout << "Shrinking jar from " << capacity << " to " << size << "." << std::endl;
    resizes++;
}
capacity = size;


 // TODO : print results
 std::cout << "Final Jar: ";

 for(int i{0}; i < size; i++) {
    std::cout << jar[i] << " ";
 }

 std::cout << std::endl << "Size: " << size << std::endl;
 std::cout << "Capacity: " << capacity << std::endl;
 std::cout << "Times Resized: " << resizes << std::endl; 

 delete [] jar ;
 //delete [] sortedJar;
 jar = nullptr ;
 return 0;
 }