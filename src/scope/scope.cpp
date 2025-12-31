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

#include "rooted/scope.h"
#include "scope.h"

using namespace Rooted;
using namespace std;

template <bool ShowTime>
Scope<ShowTime> Rooted::Line(Celery::Str::External &desc)
{
    using Result = Scope<ShowTime>;
    Result res;



    return res;
}

// Template specialization so the linker can find the correct
// symbols
template
Scope<true> Rooted::Line<true>(
    Celery::Str::External &desc
);

template
Scope<false> Rooted::Line<false>(
    Celery::Str::External &desc
);