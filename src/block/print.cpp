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

template <ScopeOrder Order>
Scope Block::BasePrint(
    const Celery::Str::External &desc
)
{
    Scope res{desc};

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

    Celery::Io::Println(desc);

    // Update pipe state for this depth
    if (depth > 0)
    {
        draw_pipe[depth - 1] =
            Order == ScopeOrder::Last ?
                ScopeOrder::Body :
                ScopeOrder::Last;
    }

    return res;
}

template <ScopeOrder Order>
Scope Block::Print(const Celery::Str::External &desc)
{
    return BasePrint<Order>(desc);
}

// Template instantiations
template Scope Block::BasePrint<
    ScopeOrder::Body
>(const Celery::Str::External &);

template Scope Block::BasePrint<
    ScopeOrder::Last
>(const Celery::Str::External &);

template Scope Block::Print<ScopeOrder::Body>(
    const Celery::Str::External &
);

template Scope Block::Print<ScopeOrder::Last>(
    const Celery::Str::External &
);