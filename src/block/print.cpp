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

#include <celery/io/io.h>

#include "rooted/block.h"
#include "rooted/scope.h"

using namespace Rooted;
using namespace std;

template <bool PrintTime, bool IsLast>
Scope<PrintTime> print_impl(
    DrawPipe &draw_pipe,
    int &lines,
    const Celery::Trait::VeryLarge depth,
    const Celery::Str::External &desc
)
{
    using Result = Scope<PrintTime>;

    Result res;
    res.line = ++lines;
    res.desc = desc;

    // Print branch
    if (depth > 0)
    {
        for (int i = 0; i < depth - 1; ++i)
        {
            if (draw_pipe[i])
                Celery::Io::Print("│   ");
            else
                Celery::Io::Print("    ");
        }

        if constexpr (IsLast)
            Celery::Io::Print("└── ");
        else
            Celery::Io::Print("├── ");
    }

    Celery::Io::Print(desc, '\n');

    // Update pipe state for this depth
    if (depth > 0)
    {
        draw_pipe[depth - 1] = !IsLast;
    }

    return res;
}

TimedScope Block::TimedPrint(const Celery::Str::External &desc)
{
    auto scope = print_impl<true, false>(
        draw_pipe,
        lines,
        depth,
        desc
    );

    last_scope = scope;
    return scope;
}

SimpleScope Block::Print(const Celery::Str::External &desc)
{
    auto scope = print_impl<false, false>(
        draw_pipe,
        lines,
        depth,
        desc
    );

    last_scope = scope;
    return scope;
}