//
// Created by jondorito on 06/04/19.
//

#ifndef QUEUE_USING_OOP_PACKAGE_H
#define QUEUE_USING_OOP_PACKAGE_H

#include <string>


class NetPackage {
private:
    std::string from = "unassigned";
    std::string command = "NONE";
    std::string data =  "NONE";
public:
    NetPackage();
    std::string getJSONPackage();
    std::string getFrom();
    std::string getData();
    std::string getcommand();
    void setFrom(std::string);
    void setData(std::string);
    void setCommand(std::string);

};



#endif //QUEUE_USING_OOP_PACKAGE_H
