//
//  book.hpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/11.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#ifndef book_hpp
#define book_hpp
#include "LzgStatus.h"
#include <stdio.h>
typedef struct
{
    char *name;
    float price;
}book;
book *creatAbook();
char *getName(book &b);
void setName(book &b,char *newName);
float getPrice(book &b);
void setPrice(book &b,float newPrice);
#endif /* book_hpp */
