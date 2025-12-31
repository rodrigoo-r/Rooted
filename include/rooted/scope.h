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

#include <celery/string/external.h>

namespace Rooted
{
    enum class ScopeOrder
    {
        Body,
        Last
    };

    class Scope
    {
        Celery::Str::External desc;

    public:
        void SetDesc(const Celery::Str::External &new_desc)
        {
            desc = new_desc;
        }
    };
}
