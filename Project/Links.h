#ifndef LINKS_H
#define LINKS_H

class Links {
private:
    int *user;
public:
    Links();
    Links(int);
    ~Links();
    int getData(int i) {
        return user[i];
    }
    void setData(int i, int data);
};

#endif /* LINKS_H */