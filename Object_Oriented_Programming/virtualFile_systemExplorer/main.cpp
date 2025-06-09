#include <iostream>
#include <cstring>
#include "FileSystem.h"
 
// Include your class definitions here

int main() {
    // Create aroot directory
    Directory root{"root", 5};

    // Create somefiles
    File* f1 =new File{"readme.txt", "This is a test."};
    File* f2 =new File{"todo.txt", "1. Write code\n2. Test"};
 
     // Create asubdirectory
    Directory* home= new Directory{"home", 3};
 
    // Add filesto the home directory
    home->add(f1);
    home->add(f2);
 
    // Add homedirectory to root
    root.add(home);
 
    // Create another file and add itdirectly to root
    File* license= new File{"license.md", "MIT License"};
    root.add(license);
 
    // Print thefile system tree
    std::cout << "Original tree:\n";
    root.print(0);
    
    // Test deepcopy
    Directory cpRoot= root;
    std::cout << "\nCopied tree:\n";
    cpRoot.print(0);
 
    // Modify original
    home->remove("todo.txt");
    std::cout <<"\nAfter removing todo.txt from original:\n";
    root.print(0);
 
    std::cout <<"\nCopied tree remains intact:\n";
    cpRoot.print(0);
 
    // Test searchfunctionality
    std::cout <<"\nSearching for 'readme.txt':\n";
    Node* found =root.search("readme.txt");
    if (found) {
        std::cout <<"Found: ";
        found->print(0);
     } else {
        std::cout <<"File not found!\n";
    }
 
    return 0;
}