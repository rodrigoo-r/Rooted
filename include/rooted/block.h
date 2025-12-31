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

#include "scope.h"

namespace Rooted
{
    class Block
    {
        Celery::Array::Vector<bool> draw_pipe;
        int &lines; // Passed by reference from Factory
        Celery::Trait::VeryLarge depth;

    public:
        Block(int &, Celery::Trait::VeryLarge);

        template<bool PrintTime, bool IsLast>
        Scope<PrintTime> Print(const Celery::Str::External &desc);
        [[nodiscard]] Block Nest() const;

        void Done() const
        {
            lines = 0;
        }

        ~Block()
        {
            Done();
        }
    };
}