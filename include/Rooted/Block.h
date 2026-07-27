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


#include "Rooted/Draw_Pipe.h"
#include "Rooted/Scope.h"

namespace Rooted
{
    template <typename Stream>
    class Block
    {
    protected:
        Draw_Pipe &draw_pipe;
        size_t depth;
        Stream &stream;

        template<Scope_Order Order, bool Print_New_Line>
        void Base_Print(auto &&...args)
        {
            // Print branch
            if (depth > 0)
            {
                for (int i = 0; i < depth - 1; ++i)
                {
                    if (draw_pipe[i] == Scope_Order::Last)
                        stream << "│   ";
                    else
                        stream << "    ";
                }

                if constexpr (Order == Scope_Order::Last)
                    stream << "└── ";
                else
                    stream << "├── ";
            }

            (stream << ... << args);

            if constexpr (Print_New_Line)
            {
                stream << std::endl;
            }

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
            const size_t depth_const,
            Draw_Pipe &draw_pipe_ref,
            Stream &stream
        ) :
            draw_pipe(draw_pipe_ref),
            depth(depth_const),
            stream(stream)
        {
            if (draw_pipe.size() > depth)
            {
                const auto remaining = draw_pipe.size() - depth;
                for (size_t i = 0; i < remaining; ++i)
                {
                    draw_pipe.push_back(Scope_Order::Body);
                }
            }
        }

        template <Scope_Order Order, bool Print_New_Line>
        void Print(auto &&...args)
        {
            Base_Print<Order, Print_New_Line>(std::forward<decltype(args)>(args)...);
        }

        void Body(auto &&...args)
        {
            Print<Scope_Order::Body, true>(std::forward<decltype(args)>(args)...);
        }

        void Last(auto &&...args)
        {
            Print<Scope_Order::Last, true>(std::forward<decltype(args)>(args)...);
        }

        void Body_Simple(auto &&...args)
        {
            Print<Scope_Order::Body, false>(std::forward<decltype(args)>(args)...);
        }

        void Last_Simple(auto &&...args)
        {
            Print<Scope_Order::Last, false>(std::forward<decltype(args)>(args)...);
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

        [[nodiscard]] Block Nest()
        {
            Block b(
                depth + 1,
                draw_pipe,
                stream
            );

            draw_pipe[depth] = Scope_Order::Body;
            return b;
        }

        ~Block() = default;
    };
}