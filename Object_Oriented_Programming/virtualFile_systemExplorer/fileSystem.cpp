#include "FileSystem.h"
#include <cstring>
#include <iostream>

Node::Node(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Node::Node(const Node& other) {
    const char* otherName = other.getName();
    name = new char[strlen(otherName) + 1];
    strcpy(name, otherName);
}

Node& Node::operator=(const Node& other) {
    if(this == &other) return *this;

    delete[] name;

    const char* otherName = other.getName();
    name = new char[strlen(otherName) + 1];
    strcpy(name, otherName);

    return *this;
}

Node::~Node() {
    delete[] name;  
}

const char* Node::getName() const {
    return name;
}

bool Node::isDirectory() const {
    return false;
}

File::File(const char* name, const char* content) : Node(name) {
    this->content = new char[strlen(content) + 1];
    strcpy(this->content, content);
    this->size = strlen(content);
}

File::File(const File& other) : Node(other) {
    content = new char[strlen(other.content) + 1];
    strcpy(content, other.content);
    size = other.size;
}

File& File::operator=(const File& other) {
    if(this == &other) return *this;

    Node::operator=(other);
    delete[] content;

    content = new char[strlen(other.content) + 1];
    strcpy(content, other.content);
    size = other.size;

    return *this;
}

File::~File() {
    delete[] content;
}

void File::print(int indent) const {
    for(int i = 0; i < indent; i++) {
        std::cout << " ";
    }  
    std::cout << "File: " << getName() << " (size = " << size << " bytes)" << std::endl;
}

void File::setContent(const char* newContent) {
    delete[] content;
    content = new char[strlen(newContent) + 1];
    strcpy(content, newContent);
    size = strlen(newContent);
}

size_t File::getSize() const {
    return size;
}

bool File::isDirectory() const {
    return false;
}

Directory::Directory(const char* name, int maxChildren) : Node(name) {
    children = new Node*[maxChildren];
    this->maxChildren = maxChildren;
    childCount = 0;
}

Directory::Directory(const Directory& other) : Node(other) {
    children = new Node*[other.maxChildren];
    maxChildren = other.maxChildren;
    childCount = other.childCount;
    
    for(int i = 0; i < childCount; i++) {
        if(other.children[i]->isDirectory()) {
            children[i] = new Directory(static_cast<Directory&>(*other.children[i]));
        }
        else {
            children[i] = new File(static_cast<File&>(*other.children[i]));
        }
    }
}

Directory& Directory::operator=(const Directory& other) {
    if(this == &other) return *this;

    Node::operator=(other);
    
    for(int i = 0; i < childCount; i++) {
        delete children[i];
    }
    delete[] children;

    children = new Node*[other.maxChildren];
    maxChildren = other.maxChildren;
    childCount = other.childCount;

    for(int i = 0; i < childCount; i++) {
        if(other.children[i]->isDirectory()) {
            children[i] = new Directory(static_cast<Directory&>(*other.children[i]));
        }
        else {
            children[i] = new File(static_cast<File&>(*other.children[i]));
        }
    }

    return *this;
}

Directory::~Directory() {
    for(int i = 0; i < childCount; i++) {
        delete children[i];
    }
    delete[] children;
}

void Directory::print(int indent) const {
    for(int i = 0; i < indent; i++) {
        std::cout << " ";
    }
    std::cout << "Dir: " << getName() << "/" << std::endl;
    for(int k = 0; k < childCount; k++) {
        children[k]->print(indent + 2);
    }
}

bool Directory::add(Node* node) {
    if(childCount >= maxChildren) return false;

    children[childCount] = node;
    childCount++;
    return true;
}

bool Directory::remove(const char* name) {
    for(int i = 0; i < childCount; i++) {
        if(strcmp(name, children[i]->getName()) == 0) {
            delete children[i];
            for(int k = i; k + 1 < childCount; k++) {
                children[k] = children[k + 1];
            }
            childCount--;
            return true;
        }
    }
    return false;
}

int Directory::getChildCount() const {
    return childCount;
}

Node* Directory::search(const char* name) const {
    for(int i = 0; i < childCount; i++) {
        if(strcmp(name, children[i]->getName())) {
            return children[i];
        }
        else if(children[i]->isDirectory()) {
            Node* result = search(name);
            if(result != nullptr) return result;
        };
    }
    return nullptr;
}

bool Directory::isDirectory() const {
    return true;
}