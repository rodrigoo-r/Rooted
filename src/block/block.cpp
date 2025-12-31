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

#include "rooted/block.h"

using namespace Rooted;
using namespace Celery;

Block::Block(
    int &lines_ref,
    const Trait::VeryLarge depth_const
) :
    lines(lines_ref),
    depth(depth_const)
{
    // Ensure draw_pipe is deep enough
    if (depth > 0)
    {
        draw_pipe.Resize(depth);
        for (auto i = 0; i < depth; ++i)
        {
            draw_pipe[i] = false;
        }
    }
}
