//
//  book.cpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/11.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#include "book.hpp"
#include <iostream>
using namespace std;
book *creatAbook()
{
    book *innerbook=(book*)calloc(1, sizeof(book));
    innerbook->price=0;
    return innerbook;
}
char *getName(book &b)
{
    return b.name;
}
void setName(book &b,char *newName)
{
    b.name=newName;
}
float getPrice(book &b)
{
    return b.price;
}
void setPrice(book &b,float newPrice)
{
    b.price=newPrice;
}
