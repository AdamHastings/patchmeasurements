#ifndef PAGES_H
#define PAGES_H

#include <QWidget>
#include <string>

class GoodbyePage : public QWidget {
    
    public:
        explicit GoodbyePage(std::string name_in);
        ~GoodbyePage();

    private:
        std::string name;
};

#endif