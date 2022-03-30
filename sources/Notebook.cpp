#include "Notebook.hpp"

namespace ariel{

Notebook::Notebook()
{
    this->_pages = 0;
    this->_page.push_back(page(0));
}

bool Notebook::legal_num_of_page(int page) const
{
    return(page<=_pages);
}

void check_positiv(int page, int row, int col)
{
    if(page<0 || row < 0 || col < 0  || col> maxLength-1)
    {
        throw std::runtime_error ("bad num");
    }
}

page Notebook::getPage(int page_num)
{
    if(legal_num_of_page(page_num))
    {
        return this->_page.at((unsigned int) page_num);
    }
    throw std::runtime_error ("this page_num is not exists");
}



void Notebook::setPage(int page_num)
{
    if(page_num < 0)
    {
        throw std::runtime_error ("you have enough of paper to use");
    }

    while(_pages<page_num)
    {
        this->_pages+=1;
        this->_page.push_back(page(this->_pages));
    }
}

void Notebook::show(int numpage)    //show the things that we have write.
{
    try 
    {
        setPage(numpage);
        this->_page.at((unsigned int)numpage).show();
    }catch(std::exception&)
    {
        throw std::runtime_error ("cant do this");
    }
}

void Notebook::write(int s, int r, int col, ariel::Direction sideOrUpDown,const std::string & str)  //write to the notebook
{
    try{
        check_positiv(s,r,col);

        setPage(s);

        unsigned int page = (unsigned int) s;
        unsigned int row =(unsigned int) r;
        unsigned int column =(unsigned int) col;

        this->_page.at(page).write(row,column,sideOrUpDown,str);}catch(std::exception&)
    {
        throw std::runtime_error ("cant write there");
    }
}

std::string Notebook::read(int p, int r, int col, ariel::Direction sideOrUpDown,int len)  //read from the notebook
{
    try{
        check_positiv(p,r,col);
        if(len<0)
        {
            throw std::runtime_error("negative num");
        }

        setPage(p);

        unsigned int page = (unsigned int) p;
        unsigned int row =(unsigned int) r;
        unsigned int column =(unsigned int) col;

        return this->_page.at(page).read(row,column,sideOrUpDown,(unsigned int) len);

    }catch(std::exception&)
    {
        throw std::runtime_error ("cant read this");
    }
}

void Notebook::erase(int p,int r, int col, ariel::Direction sideOrUpDown,int l)    //delete things from the notebook
{
    try{
        check_positiv(p,r, col);
        setPage(p);
        if(l <0)
        {
            throw std::runtime_error ("negativ num");
        }
        
        unsigned int page = (unsigned int) p;
        unsigned int row =(unsigned int) r;
        unsigned int column =(unsigned int) col;
        unsigned int len =(unsigned int) l;

        this->_page.at(page).erase(row,column,sideOrUpDown,len);
    }catch(std::exception&)
    {
        throw std::runtime_error ("cant do this act");
    }
}

}


