#ifndef CPPPARSER_H
#define CPPPARSER_H

#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include<ctype.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "srcfilemodel.h"
#include "stringutil.h"
#include "classmodel.h"

using namespace std;

#define INCLUDE                 10
#define CLASS                   20
#define TEMPLATE_CLASS          30
#define VARIABLE                40
#define FUNCTION                50
#define UNDEINED                65535
#define NOTFOUND                0
#define HAVEFOUND               1

/**
 * 目前出现的问题:
 * 1. 不用制表符首行推进，而是用空格。函数没有识别到。
 */

class CppParser
{
private:
    std::string classname_;                 //类的名字;
    vector<std::string> extends_;      //类的extends;
    vector<std::string> var_;              //类的变量;
    vector<std::string> properties_;  //类的属性;
    vector<std::string> function_;     //类的函数;

    vector<std::string> include_;       //include集合;
    vector<CppParser> classes_;       //类的结合;

    
public:
    CppParser();

    int parseCppFile(SrcFileModel srcFile);

private:
    inline std::string& rtrim(std::string &str);
    inline std::string& ltrim(std::string &str);
    std::string& trim(std::string &s); //去除空格和换行
    int judge(std::string s);//判断字符串名字返回不同的值
    void D(std::string& str,char c);//在字符串str中循环删除字符c
    void D(std::string& str,std::string s);//删除所有指定的字符串
    void R(std::string& str);//以\r为判断删除注释
    vector<std::string> divideByTab(std::string &str);//以制表符为分隔符分解字符串成vector
    void ignorespacetab(const std::string& str,size_t& fI);//fI停在非空格和制表符处
    void ignorealnum(const std::string&str ,size_t& fI);//fI停在非数字和字母处
    void display(SrcFileModel fileModel);//用文件输出流输出
    int findSubStrAtPos(std::string& str,std::string s,size_t& pos);//在pos处，str找s
    std::string findClassName(const std::string& str,size_t &begin);//在一个字符串上找类名
    vector<std::string> findExtendsName(const std::string& str,size_t pos);//在一个字符串上找扩展名
    int findFunctionAndVarsOfClass(std::string& str,std::string s,size_t& pos,CppParser& theclass);

    int findGlobalClassDeclares(std::string& str);//寻找全局类声明，和友元类;

    int findGlobalVarsAndFunctions(std::string& str);//寻找全局变量和全局函数
    void actionscope_ignore(const std::string& str,size_t& fI);//忽略一个大的作用域中的所有作用域
    vector<size_t> actionscope(const std::string& str,size_t& fI);//获取最大的作用域的位置
    vector<std::string> split(std::string str, std::string pattern);

    bool is_str_contain_space(std::string str);//是否包含空格
    
    bool handleCppIdentify(ClassModel &classModel);
};


#endif // CPPPARSER_H
