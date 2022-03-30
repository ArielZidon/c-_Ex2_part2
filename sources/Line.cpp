#include "Line.hpp"


Line::Line()
{
    for(unsigned int i=0;i<maxLength;i++)
    {
        this->line.push_back('_');
    }
}

void Line::hasBeenWrited(unsigned int & column,const std::string & str)
{
    for(unsigned int i=0; i<str.length();i++)
    {
        if(this->line.at(column+i)!='_')
        {
            throw std::runtime_error("this place has been writed");
        }
    }
}

void Line::checkChar(unsigned int & column,char write_char)
{
    if(write_char=='\n' || write_char < ' ' || write_char>'~')
    {
        throw std::runtime_error("error with trying to write");
    }
}

void Line::inLine(unsigned int & column,unsigned int len)
{
    if(column+len>maxLength || column< 0)
    {
        throw std::runtime_error ("The writing will eceed the line length");
    }
}

void Line::write(unsigned int column,const std::string & str)
{
    hasBeenWrited(column,str);
    inLine(column,str.length());

    for(unsigned int i = 0;i<str.length();i++)
    {
        if(std::isprint(str.at(i))==0)
        {
            throw std::runtime_error ("this is illigal char");
        }
    }

    for(unsigned int i = 0;i<str.length();i++)
    {
        checkChar(column, line.at(column+i));
        line.at(column+i) = str.at(i);
    }
}

std::string Line::read(unsigned int column,unsigned int len)
{
    inLine(column,len);
    std::string str;

    for(unsigned int i=column;i<column+len;i++)
    {
        str+=line.at(i);
    }
    return str;
}
    
void Line::erase(unsigned int  column,unsigned int len)
{
    inLine(column,len);

    for(unsigned  int i = 0;i<len;i++)
    {
        line.at(column+i) =  '~';
    }
}

char Line::getchar(unsigned long index)
{
    if(index>maxLength-1)
    {
        throw std::runtime_error("out of range");
    }
    return line.at(index);
}