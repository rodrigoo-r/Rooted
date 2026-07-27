/*
        ==== The Zelix Programming Language ====
---------------------------------------------------------
  - This file is part of the Zelix Programming Language
    codebase. Zelix is a fast, statically-typed and
    memory-safe programming language that aims to
    match native speeds while staying highly ergonomic.
---------------------------------------------------------
  - Zelix is categorized as free software; you can
    redistribute it and/or modify it under the terms of
    the Apache License, Version 2.0.
---------------------------------------------------------
  - You should have received a copy of the Apache
    License v2.0 along with Zelix. If not, see
    <http://www.apache.org/licenses/LICENSE-2.0>.
*/

//
// Created by rodrigo on 12/31/25.
//

#pragma once
#include <iostream>
#include "Rooted/Block.h"

namespace Rooted
{
    template <typename Stream = std::ostream>
    class Factory
    {
        Draw_Pipe draw_pipe;
        Stream &stream;

    public:
        Factory() :
            stream(std::cout)
        {}

        Factory(Stream &s) :
            stream(s)
        {}

        Block<Stream> Add_Block()
        {
            Block<Stream> b(0, draw_pipe, stream);
            draw_pipe.push_back(Scope_Order::Body);
            return b;
        }

        ~Factory() = default;
    };
}