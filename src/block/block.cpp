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
    const Trait::VeryLarge depth_const,
    DrawPipe &draw_pipe_ref
) :
    draw_pipe(draw_pipe_ref),
    lines(lines_ref),
    depth(depth_const)
{
    const auto remaining = depth - draw_pipe.Size();
    for (Trait::VeryLarge i = 0; i < remaining; ++i)
    {
        draw_pipe.PushBack(ScopeOrder::Body);
    }
}
