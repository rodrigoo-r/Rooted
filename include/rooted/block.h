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

#include "draw_pipe.h"
#include "scope.h"

namespace Rooted
{
    class Block
    {
    public:
        using PrintCollection =
            std::initializer_list<Celery::Str::External>;

    protected:
        DrawPipe &draw_pipe;
        Celery::Trait::VeryLarge depth;

        template<ScopeOrder>
        void BasePrint(
            const PrintCollection &
        );

    public:
        Block(
            Celery::Trait::VeryLarge,
            DrawPipe &
        );

        template <ScopeOrder Order>
        void Print(const PrintCollection &desc);

        void Body(const PrintCollection &desc)
        {
            Print<ScopeOrder::Body>(desc);
        }

        void Last(const PrintCollection &desc)
        {
            Print<ScopeOrder::Last>(desc);
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