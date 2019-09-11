//
// Created by lhw on 9/4/19.
//

#include <cctype>
using namespace std;
#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

class IdNode
{
private:
    char *id;
    double value;
    friend class Statement;  //友元类
    friend ostream &operator<<(ostream &out, const IdNode &node);
public:
    IdNode(char *s = "", double e = 0){
        id = strdup(s); //申请空间并复制字符串
        value = e;
    }
    bool operator==(const IdNode& node) const{
        return strcmp(id, node.id) == 0;
    }
};
class Statement
{
private:
    list<IdNode> idList;
    char ch;
    double factor();
    double term();
    double expression();
    void readId(char *);
    void issueError(char *s){
        cerr << s << endl;
        exit(1);
    }
    double findValue(char *);
    void processNode(char *id, double e);
    friend ostream & operator<<(ostream &out, const Statement &s);
public:
    Statement(){ }
    void getStatement();
};

double Statement::findValue(char *id)   //返回对应的值
{
    IdNode tmp(id);
    list<IdNode>::iterator i = find(idList.begin(), idList.end(), tmp);
    if(i != idList.end())
        return i->value;
    else
        issueError("unknown variable");
    return 0;
}
void Statement::processNode(char *id, double e) //更新值或者加到链表中去
{
    IdNode tmp(id, e);
    list<IdNode>::iterator i = find(idList.begin(), idList.end(), tmp);
    if(i != idList.end())
        i ->value = e;
    else
        idList.push_front(tmp);
}
void Statement::readId(char *id)  //读输入到一个数组中
{
    int i = 0;
    if(isspace(ch))
        cin >> ch;
    if(isalpha(ch)){ //是字母的话就将后续的数字或者字母都保存
        while(isalnum(ch)){
            id[i++] = ch;
            cin.get(ch);
        }
        id[i] = '\0';
    }
    else
        issueError("Identifier expected");
}
double Statement::factor()  //因子的处理
{
    double var, minus = 1.0;
    static char id[200];
    cin >> ch;
    while(ch == '+' || ch == '-'){ //是数字前的符号
        if(ch == '-')   //确定正负
            minus *= -1.0;
        cin >> ch;
    }
    if(isdigit(ch) || ch == '.'){   //数字
        cin.putback(ch);
        cin >> var >> ch; //保存数字
    }
    else if(ch == '('){ //等于左括号就处理括号内的表达式
        var = expression(); //递归处理括号内的表达式
        if(ch == ')')   //右括号就继续处理ch
            cin >> ch;
        else
            issueError("right paren left out");
    }
    else{
        readId(id);
        if(isspace(ch))
            cin >> ch;
        var = findValue(id);
    }
    return minus * var;
}
double Statement::term()
{
    double f = factor();
    while(true){
        switch(ch){
            case '*':
                f *= factor();
                break;
            case '/':
                f /= factor();
                break;
            default:
                return f;
        }
    }
}
double Statement::expression()
{
    double t = term();
    while(true){
        switch(ch){
            case '+':
                t += term();
                break;
            case '-':
                t -= term();
                break;
            default:
                return t;
        }
    }
}
void Statement::getStatement()
{
    char id[20];
    char command[20];
    double e;
    cout << "enter a statement: ";
    cin >> ch;
    readId(id);
    strupr(strcpy(command, id));
    if(strcmp(command, "STATUS") == 0)
        cout << *this;
    if(strcmp(command, "PRINT") == 0){
        readId(id);
        cout << id << " = " << findValue(id) << endl;
    }
    else if(strcmp(command, "END") == 0)
        exit(0);
    else{
        if(isspace(ch))
            cin >> ch;
        if(ch == '='){
            e = expression();
            if(ch != ';')
                issueError("there are some extras in the statement. ");
            else
                processNode(id, e);
        }
        else
            issueError("'=' is missing");
    }
}
ostream &operator<<(ostream &out, const Statement &s)
{
    list<IdNode>::const_iterator i = s.idList.begin();
    for( ; i != s.idList.end(); i++)
        out << *i;
    out << endl;
    return out;
}
ostream &operator<<(ostream &out, const IdNode &r)
{
    out << r.id << " = " << r.value << endl;
    return out;
}

int main()
{
    Statement statement;
    cout << "the program processes statements  of the following format:\n"
         << "\t<id> = <expr>;\n\tprint <id>\n\tstatus\n\tend\n\n";
    while(true)
        statement.getStatement();

    return 0;
}