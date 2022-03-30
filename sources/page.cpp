#include "page.hpp"

page::page(unsigned int numPage)
{
    this->numPage = numPage;
    this->num_Of_Lines =-1;
    add_number_of_Line();
}

bool page::setLine(unsigned int numLine){
    while(this->num_Of_Lines<numLine)
    {
        add_number_of_Line();
    }
    return true;
}

void page::add_number_of_Line()
{
    for(unsigned int i=0;i<add_10_lines;i++)
    {
        this->lines.push_back(Line());
    }
    num_Of_Lines+=add_10_lines;
}

Line page::getLine(int numLine)
{
    return lines.at((unsigned long) num_Of_Lines);
}

unsigned int page::getNumOfPage() const
{
    return numPage;
} 

void page::write(unsigned int row, unsigned int col, ariel::Direction sideOrUpDown,const std::string & str)
{
    if(setLine(row))
    {
        for(unsigned int i=1; i<str.length();i++)
        {
            if(str.at(i)=='~' || 0==std::isprint(str.at(i)))
            {
                throw std::runtime_error("cant print this char");
            }
        }
        if(sideOrUpDown==ariel::Direction::Horizontal)
        {
            this->lines.at(row).write(col,str);
        }

        if(sideOrUpDown==ariel::Direction::Vertical && col >=0 && col <maxLength)
        {
            for(unsigned int i=0;i<str.length();i++)
            {
                std::string s;
                s.push_back(str[i]);
                lines.at(row+i).write(col, s);
                lines.push_back(Line());
                this->num_Of_Lines++;
            }
        }
    }
}

void page::erase(unsigned int row, unsigned int col, ariel::Direction sideOrUpDown,unsigned int len)
{
    if(ariel::Direction::Horizontal==sideOrUpDown)
    {
        this->lines.at(row).erase(col, len);
    }

    if(ariel::Direction::Vertical ==sideOrUpDown)
    {
        if(col>maxLength-1 || col<0)
        {
            throw std::runtime_error ("out of bounds!");
        }

        for(unsigned i=0;i<(unsigned int) len;i++)
        {
            lines.at(row+i).erase(col,1);
            lines.push_back(Line());
            this->num_Of_Lines++;
        }
    }
}

std::string page::read(unsigned int row,unsigned int col, ariel::Direction sideOrUpDown,unsigned int len)
{
    if(col<0 && col>maxLength)
    {
        throw std::runtime_error ("you have no col..");
    }

    if(ariel::Direction::Horizontal==sideOrUpDown)
    {
        return this->lines.at(row).read(col,len);
    }

    std::string s;
  
    for(unsigned int i=0; i<len;i++)
    {
        if(row+i >num_Of_Lines)
        {
            this->lines.push_back(Line());
            this->num_Of_Lines++;
        }
        s+=lines.at(row+i).getchar(col);
    }
    return s;
} 

void page::show()
{
    unsigned int s=0;
    unsigned int e=(unsigned int) this->num_Of_Lines;
    
    for(unsigned int i=s;i<=e;i++)
    {
            std::cout << lines.at(i).read(0,maxLength) <<std::endl;
    }
} 

