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


#include "draw_pipe.h"
#include "scope.h"

namespace Rooted
{
    class Block
    {
    protected:
        Draw_Pipe &draw_pipe;
        size_t depth;

        template<Scope_Order Order>
        void Base_Print(auto &&...args)
        {
            // Print branch
            if (depth > 0)
            {
                for (int i = 0; i < depth - 1; ++i)
                {
                    if (draw_pipe[i] == Scope_Order::Last)
                        std::cout << "│   ";
                    else
                        std::cout << "    ";
                }

                if constexpr (Order == Scope_Order::Last)
                    std::cout << "└── ";
                else
                    std::cout << "├── ";
            }

            (std::cout << ... << args);
            std::cout << std::endl;

            // Update pipe state for this depth
            if (depth > 0)
            {
                draw_pipe[depth - 1] =
                    Order == Scope_Order::Last ?
                        Scope_Order::Body :
                        Scope_Order::Last;
            }
        }

    public:
        Block(
            size_t,
            Draw_Pipe &
        );

        template <Scope_Order Order>
        void Print(auto &&...args)
        {
            Base_Print<Order>(std::forward<decltype(args)>(args)...);
        }

        void Body(auto &&...args)
        {
            Print<Scope_Order::Body>(std::forward<decltype(args)>(args)...);
        }

        void Last(auto &&...args)
        {
            Print<Scope_Order::Last>(std::forward<decltype(args)>(args)...);
        }

        Block &operator=(const Block &other)
        {
            if (this != &other)
            {
                // Copy depth and draw_pipe reference
                this->depth = other.depth;
                this->draw_pipe = other.draw_pipe;
            }
            return *this;
        }

        [[nodiscard]] Block Nest();

        ~Block() = default;
    };
}