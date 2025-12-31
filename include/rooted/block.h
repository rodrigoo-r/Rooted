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
        using VariantScope = std::variant<TimedScope, SimpleScope>;

        DrawPipe &draw_pipe;
        int &lines; // Passed by reference from Factory
        Celery::Trait::VeryLarge depth;
        VariantScope last_scope;

        template<ScopeType Type>
        using ConditionalScope = std::conditional_t<
            Type == ScopeType::Timed,
            TimedScope,
            SimpleScope
        >;

        template<ScopeType Type, ScopeOrder>
        ConditionalScope<Type> BasePrint(
            const Celery::Str::External &
        );

    public:
        Block(
            int &,
            Celery::Trait::VeryLarge,
            DrawPipe &
        );

        TimedScope TimedPrint(const Celery::Str::External &desc);
        SimpleScope Print(const Celery::Str::External &desc);
        [[nodiscard]] Block Nest() const;
        void Done() const;

        ~Block()
        {
            Done();
        }
    };
}