#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <cstddef>

class Node {
    private:
        char* name;

    public:
        Node(const char* name);
        Node(const Node& other);
        Node& operator=(const Node& other);
        virtual ~Node();
        const char* getName() const;
        virtual void print(int indent) const = 0;
        virtual bool isDirectory() const;
};

class File : public Node {
    private:
        char* content;
        size_t size;
    
    public:
        File(const char* name, const char* content);
        File(const File& other);
        File& operator=(const File& other);
        ~File();
        void print(int indent) const override;
        void setContent(const char* newContent);
        size_t getSize() const;
        bool isDirectory() const override;
};

class Directory : public Node {
    private:
        Node** children;
        int childCount;
        int maxChildren;

    public:
        Directory(const char* name, int maxChildren);
        Directory(const Directory& other);
        Directory& operator=(const Directory& other);
        ~Directory();
        void print(int indent) const override;
        bool add(Node* node);
        bool remove(const char* name);
        int getChildCount() const;
        Node* search(const char* name) const;
        bool isDirectory() const override;
};

#endif