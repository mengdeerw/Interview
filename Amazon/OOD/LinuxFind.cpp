// https://leetcode.com/discuss/interview-question/369272/Amazon-or-Onsite-or-Linux-Find-Command
/*
I have my amazon interview coming up for SDE in seattle. One of my friends recently went on-site in Seattle and was asked this question in OOD. I have not been able to find a good approach to this question. Any suggestions would be helpful

implemnet linux find command as an api ,the api willl support finding files that has given size requirements and a file with a certain format like

find all file >5mb
find all xml
Assume file class
{
get name()
directorylistfile()
getFile()
create a library flexible that is flexible
Design clases,interfaces.
*/

class File {
public:
    string name;
    int size;
    int type;
    bool isDirectory;
    vector<File*> children;

    File (const string& name, int size, int type, bool isDirectory=false) {
        this->name = name;
        this->size = size;
        this->type = type;
        this->isDirectory = isDirectory;
    }

    void addChildren(const vector<File*>& children) {
        this->children = children;
    }
};

class Filter {
public:
    virtual bool apply(const File* file) const=0;
};

class MinSizeFilter: public Filter {

    int minSize;
public:
    MinSizeFilter(int minSize) {
        this->minSize = minSize;
    }

    bool apply(const File* file) const {
        return file->size > minSize;
    }
};

class TypeFilter: public Filter {

    int type;
public:
    TypeFilter(int type) {
        this->type = type;
    }

    bool apply(const File* file) const {
        return file->type == type;
    }
};

class FindCommand {
    void findWithFilters(const File* directory, const vector<Filter*> &filters, vector<File*>& output) {
        if (directory->children.empty()) {
            return;
        }
        for (const auto &file : directory->children) {
            if (file->isDirectory) {
                findWithFilters(file, filters, output);
            } else {
                bool selectFile = true;
                for (const auto &filter : filters) {
                    if (!filter->apply(file)) {
                        selectFile = false;
                        break;
                    }
                }
                if (selectFile) {
                    output.push_back(file);
                }
            }
        }
    }

public:
    vector<File*> findWithFilters(const File* directory, const vector<Filter*> &filters) {
        if (!directory->isDirectory) {
            cout<<"Exception"<<endl;
            return {};
        }
        vector<File*> output;
        findWithFilters(directory, filters, output);
        return output;
    }
};
