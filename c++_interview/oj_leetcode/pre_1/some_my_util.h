//
//  some_my_util.h
//  My_C++
//
//  Created by NLP (password:NLP) on 2/19/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#ifndef My_C___some_my_util_h
#define My_C___some_my_util_h

#include <iostream>
#include <string>

class Arrays {
public:
    // cout the array
  template <class val_type> static void to_console(val_type *a, int len) {
    std::cout << "array begin to cout" << std::endl;
    for (int i = 0; i < len; i++) {
      std::cout << (*(a + i)) << std::endl;
    }
    std::cout << "array end" << std::endl;
  }
};


#endif
