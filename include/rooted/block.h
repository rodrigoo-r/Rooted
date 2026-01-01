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

#include <celery/array/vector.h>
#include <celery/string/external.h>
#include <celery/io/io.h>

#include "draw_pipe.h"
#include "scope.h"

namespace Rooted
{
    class Block
    {
    protected:
        DrawPipe &draw_pipe;
        Celery::Trait::VeryLarge depth;

        template<ScopeOrder Order>
        void BasePrint(auto &&...args)
        {
            // Print branch
            if (depth > 0)
            {
                for (int i = 0; i < depth - 1; ++i)
                {
                    if (draw_pipe[i] == ScopeOrder::Last)
                        Celery::Io::Print("│   ");
                    else
                        Celery::Io::Print("    ");
                }

                if constexpr (Order == ScopeOrder::Last)
                    Celery::Io::Print("└── ");
                else
                    Celery::Io::Print("├── ");
            }

            Celery::Io::Print(std::forward<decltype(args)>(args)...);
            Celery::Io::Println();

            // Update pipe state for this depth
            if (depth > 0)
            {
                draw_pipe[depth - 1] =
                    Order == ScopeOrder::Last ?
                        ScopeOrder::Body :
                        ScopeOrder::Last;
            }
        }

    public:
        Block(
            Celery::Trait::VeryLarge,
            DrawPipe &
        );

        template <ScopeOrder Order>
        void Print(auto &&...args)
        {
            BasePrint<Order>(std::forward<decltype(args)>(args)...);
        }

        void Body(auto &&...args)
        {
            Print<ScopeOrder::Body>(std::forward<decltype(args)>(args)...);
        }

        void Last(auto &&...args)
        {
            Print<ScopeOrder::Last>(std::forward<decltype(args)>(args)...);
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