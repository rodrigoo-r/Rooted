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
        DrawPipe &draw_pipe;
        Celery::Trait::VeryLarge depth;

        template<ScopeOrder>
        Scope BasePrint(
            const Celery::Str::External &
        );

    public:
        Block(
            Celery::Trait::VeryLarge,
            DrawPipe &
        );

        template <ScopeOrder Order>
        Scope Print(const Celery::Str::External &desc);

        Scope Body(const Celery::Str::External &desc)
        {
            return Print<ScopeOrder::Body>(desc);
        }

        Scope Last(const Celery::Str::External &desc)
        {
            return Print<ScopeOrder::Last>(desc);
        }

        [[nodiscard]] Block Nest();

        ~Block() = default;
    };
}