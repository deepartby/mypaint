#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QMessageBox>

class MemoryException        		//класс исключений памяти
{
private:
    QString excepMessage;
public:
    MemoryException();
    MemoryException(QString);
    void showMessage();
    virtual ~MemoryException()
    {}
};


#endif // EXCEPTION_H
